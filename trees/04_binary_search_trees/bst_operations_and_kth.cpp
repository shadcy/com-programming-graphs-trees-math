#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
 * Binary Search Tree (BST) Core Operations:
 * 1. Insert into BST: O(h)
 * 2. Validate BST (with valid range [min_val, max_val]): O(N)
 * 3. K-th Smallest Element in BST (Inorder Traversal): O(N) or O(h + k)
 * 4. Lowest Common Ancestor in BST: O(h)
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// 2. Validate BST
bool isValidBST(TreeNode* root, long long min_val, long long max_val) {
    if (!root) return true;
    if (root->val <= min_val || root->val >= max_val) return false;
    return isValidBST(root->left, min_val, root->val) &&
           isValidBST(root->right, root->val, max_val);
}

// 3. Find K-th smallest using Inorder traversal
void inorderKth(TreeNode* root, int& k, int& ans) {
    if (!root || k <= 0) return;
    inorderKth(root->left, k, ans);
    k--;
    if (k == 0) {
        ans = root->val;
        return;
    }
    inorderKth(root->right, k, ans);
}

// 4. LCA in BST (exploits ordering: if both < root go left, if both > root go right)
TreeNode* lcaBST(TreeNode* root, int p, int q) {
    if (!root) return nullptr;
    if (p < root->val && q < root->val) return lcaBST(root->left, p, q);
    if (p > root->val && q > root->val) return lcaBST(root->right, p, q);
    return root;
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    TreeNode* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }

    bool valid = isValidBST(root, LLONG_MIN, LLONG_MAX);
    cout << "Is Valid BST: " << (valid ? "YES" : "NO") << "\n";

    int kth_ans = -1;
    int k_copy = k;
    inorderKth(root, k_copy, kth_ans);
    cout << k << "-th smallest element: " << kth_ans << "\n";
}

int main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

