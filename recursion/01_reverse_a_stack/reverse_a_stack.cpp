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

void insertBottom(stack <int> &st, int temp){
    if(st.empty()){
        st.push(temp);
        return;
    }
    //remove and store elements 
    int val = st.top();
    st.pop();
    
    insertBottom(st, temp);
    st.push(val);
}
void reverseStack(stack <int> &st){
    //given a stack we want to reverse it
    if(st.empty()) return;

    int temp = st.top();
    st.pop();

    reverseStack(st);
    //atp our stack is completely empty and now we need to move to the next step
    insertBottom(st, temp);
}
void solve() {
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4); //this is the test stack of 4 elements
    //Problem Statement : is to get the stack reversed, without using the external array or another stack
    //saving the space, TC doesn;t matter. idk could be a design choice.
    cout<<"Orignal Stack : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    // top -> [4 3 2 1] <- bottom

    //after writing the program to reverse the stack we must be able to print 
    // something like [ 1 2 3 4 ]

    //as out stack is now empty we can fill again

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4); //this is the test stack of 4 elements

    //now we can reverse the given stack
    
    reverseStack(st);
       cout<<"\nReversed Stack : ";
        while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    // top -> [4 3 2 1] <- bottom
}

int main() {
    FAST_IO;

    int t = 1;
    // cin >> t; // Uncomment if problem has multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}