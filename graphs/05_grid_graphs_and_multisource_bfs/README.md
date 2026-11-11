# 2D Grid Graphs & Multi-Source BFS

## What is Multi-Source BFS?
When you have multiple sources (e.g. all burning trees, all rotten fruits, all water cells) and want to find the minimum distance to all other cells:
- **Mistake**: Run BFS from each source one-by-one $\rightarrow O(K \times R \times C) \approx$ TLE.
- **Solution**: Push **all sources into the queue initially at time 0**, then run a single BFS $\rightarrow O(R \times C)$ linear time!

## Direction Arrays
```cpp
int dr[] = {-1, 1, 0, 0}; // Up, Down, Left, Right
int dc[] = {0, 0, -1, 1};
// 8 directions (including diagonals):
int dr8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
```

## Problems to Practice
- LeetCode 994: Rotting Oranges
- LeetCode 542: 01 Matrix
- LeetCode 286: Walls and Gates
- LeetCode 1162: As Far from Land as Possible

