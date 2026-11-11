param(
    [string]$Source = ""
)

$ErrorActionPreference = "Continue"

# Resolve source file
if (-not $Source) {
    if (Test-Path "solution.cpp") {
        $Source = (Resolve-Path "solution.cpp").Path
    } else {
        $cppFiles = Get-ChildItem -Filter *.cpp -Recurse -File | Sort-Object LastWriteTime -Descending
        if ($cppFiles.Count -gt 0) {
            $Source = $cppFiles[0].FullName
        } else {
            Write-Host "Error: No .cpp file specified or found." -ForegroundColor Red
            exit 1
        }
    }
}

if (-not (Test-Path $Source)) {
    Write-Host "Error: File '$Source' not found." -ForegroundColor Red
    exit 1
}

$SourceItem = Get-Item $Source
$fileDir = $SourceItem.DirectoryName
$fileName = $SourceItem.Name
$fileBase = [System.IO.Path]::GetFileNameWithoutExtension($fileName)
$exePath = Join-Path $fileDir "$fileBase.exe"
$compiler = "C:\msys64\mingw64\bin\g++.exe"

Write-Host ">>> Compiling $fileName (-std=c++17 -O2)..." -ForegroundColor Cyan
$compileSw = [System.Diagnostics.Stopwatch]::StartNew()
& $compiler -std=c++17 -O2 -Wall -Wextra -DLOCAL "$($SourceItem.FullName)" -o "$exePath"
$compileSw.Stop()

if ($LASTEXITCODE -ne 0) {
    Write-Host ">>> Compilation Failed!" -ForegroundColor Red
    exit $LASTEXITCODE
}

Write-Host ">>> Compilation OK ($($compileSw.ElapsedMilliseconds) ms)" -ForegroundColor Green
Write-Host ("-" * 45) -ForegroundColor DarkGray

# Check for input.txt in file directory, then workspace root
$inputPath = Join-Path $fileDir "input.txt"
if (-not (Test-Path $inputPath)) {
    $inputPath = Join-Path (Get-Location).Path "input.txt"
}

$outputPath = Join-Path $fileDir "output.txt"

$hasInput = $false
if (Test-Path $inputPath) {
    $rawInput = Get-Content -Raw $inputPath -ErrorAction SilentlyContinue
    if ($rawInput -and $rawInput.Trim().Length -gt 0) {
        $hasInput = $true
    }
}

$runSw = [System.Diagnostics.Stopwatch]::StartNew()
if ($hasInput) {
    Write-Host "[Running with $($inputPath)]" -ForegroundColor Yellow
    Push-Location $fileDir
    try {
        cmd /c "`"$exePath`" < `"$inputPath`" > `"$outputPath`""
        $runSw.Stop()
        $exitCode = $LASTEXITCODE

        Write-Host "`n[Output from output.txt]:" -ForegroundColor DarkCyan
        if (Test-Path $outputPath) {
            $outContent = Get-Content -Raw $outputPath
            if ($outContent) {
                Write-Host $outContent.TrimEnd() -ForegroundColor White
            }
        }
    } finally {
        Pop-Location
    }
} else {
    Write-Host "[Interactive mode - enter input below:]" -ForegroundColor Yellow
    & "$exePath"
    $runSw.Stop()
    $exitCode = $LASTEXITCODE
}

Write-Host ("-" * 45) -ForegroundColor DarkGray
if ($exitCode -eq 0) {
    Write-Host ">>> SUCCESS (Exit code 0) | Runtime: $($runSw.ElapsedMilliseconds) ms" -ForegroundColor Green
} else {
    Write-Host ">>> RUNTIME ERROR (Exit code: $exitCode) | Runtime: $($runSw.ElapsedMilliseconds) ms" -ForegroundColor Red
}
