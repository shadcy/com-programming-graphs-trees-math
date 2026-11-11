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

class TreeNode{
    public:
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
    
};

int heightofTree(TreeNode* root){
  if(root == nullptr) return 0;

  int lh = heightofTree(root->left);
  int rh = heightofTree(root->right);

  return 1 + max(lh, rh);
}

// Helper to construct a binary tree from level-order traversal (-1 represents NULL)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < (int)nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < (int)nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void solve() {
    cout << "========================================\n";
    cout << "       TESTING heightofTree()           \n";
    cout << "========================================\n\n";

    // 1. Test from input.txt (if provided)
    vector<int> input_vals;
    int val;
    while (cin >> val) {
        input_vals.push_back(val);
    }

    if (!input_vals.empty()) {
        TreeNode* input_root = buildTree(input_vals);
        cout << "[Input Tree from input.txt]\n";
        cout << "Nodes (level-order): ";
        for (int x : input_vals) cout << (x == -1 ? "null" : to_string(x)) << " ";
        cout << "\nCalculated Height: " << heightofTree(input_root) << "\n\n";
    }

    // 2. Built-in Test Cases for Edge Cases & Standard Trees
    cout << "--- Running Built-in Test Suite ---\n\n";

    // Test 1: Empty Tree
    TreeNode* t1 = nullptr;
    cout << "Test 1 (Empty Tree):        Height = " << heightofTree(t1) 
         << " | Expected = 0 " << (heightofTree(t1) == 0 ? "[PASS]" : "[FAIL]") << "\n";

    // Test 2: Single Node
    TreeNode* t2 = new TreeNode(10);
    cout << "Test 2 (Single Node [10]):   Height = " << heightofTree(t2) 
         << " | Expected = 1 " << (heightofTree(t2) == 1 ? "[PASS]" : "[FAIL]") << "\n";

    // Test 3: Balanced Tree
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */
    TreeNode* t3 = buildTree({1, 2, 3, 4, 5, 6, 7});
    cout << "Test 3 (Balanced, 3 levels): Height = " << heightofTree(t3) 
         << " | Expected = 3 " << (heightofTree(t3) == 3 ? "[PASS]" : "[FAIL]") << "\n";

    // Test 4: Right-Skewed Tree (Linked-list shape)
    /*
        1 -> 2 -> 3 -> 4
    */
    TreeNode* t4 = buildTree({1, -1, 2, -1, 3, -1, 4});
    cout << "Test 4 (Right-Skewed, 4 n):  Height = " << heightofTree(t4) 
         << " | Expected = 4 " << (heightofTree(t4) == 4 ? "[PASS]" : "[FAIL]") << "\n";

    // Test 5: Unbalanced Tree
    /*
             1
           /   \
          2     3
         / \
        4   5
           /
          6
    */
    TreeNode* t5 = buildTree({1, 2, 3, 4, 5, -1, -1, -1, -1, 6});
    cout << "Test 5 (Unbalanced, 4 lvl):  Height = " << heightofTree(t5) 
         << " | Expected = 4 " << (heightofTree(t5) == 4 ? "[PASS]" : "[FAIL]") << "\n\n";

    cout << "========================================\n";
    cout << "       ALL TESTS COMPLETED!             \n";
    cout << "========================================\n";
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