#include <bits/stdc++.h>
using namespace std; 

/*
 * Speed up standard I/O operations for Online Assessments
 */
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

// Debugging helper (active during local runs)
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

void insert(string &s,  char temp){
 s.insert(s.begin(), temp);
}
void reverseString(string &s) {
    //Reverse a string with recursion
    //Base case
    if(s.empty()) return;

    char temp = s.back();
    s.pop_back();
    //Hypothesis : that the below func works

    reverseString(s);

    //Induction : make the hypothesis work;
    insert(s, temp);
}

int main() {
    FAST_IO;
    string s;
    cin>>s;
    //we have i/p ready
    int t = 1;
    // cin >> t; // Uncomment if problem has multiple test cases
    while (t--) {
        reverseString(s);
        cout<<s<<"\n";
    }

    return 0;
}