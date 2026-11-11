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


void insert(stack<int> &st, int temp){
  //Base case
  if(st.empty() || st.top() <= temp){
    st.push(temp);
    return;
  }

  //Hypothesis
  int val = st.top();
  st.pop();
  
  insert(st, temp);

  //Induction
  st.push(val);
}
void sortStack(stack <int> &st) {
    //This program is to sort a stack using recursion.
    //it'll be more like the sorting for an array we solved
    //much more similar to earlier one but with the stack.
    if(st.empty()) return; //Base case

    int temp = st.top();
    st.pop();
    //Hypothesis
    sortStack(st);
    //induction
    insert(st, temp);
}

int main() {
    FAST_IO;
    //Stack
    stack<int> st;
    st.push(4);
    st.push(2);
    st.push(3);
    st.push(1);

    //we have our stack ready we can operate on this.
    int t = 1;
    // cin >> t; // Uncomment if problem has multiple test cases
    while (t--) {
        sortStack(st);

        //once we sorted the stack 
        //print it out

        while(!st.empty()){
            cout<<st.top()<<"\n";
            st.pop();
        }
    }

    return 0;
}