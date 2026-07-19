// LeetCode 94 - Binary Tree Inorder Traversal
// Difficulty: Easy
// Topic: Tree, DFS, Recursion
// Approach: Recursive Inorder Traversal
//
// Problem:
// Given the root of a binary tree, return its inorder traversal.
//
// Approach Explanation:
// 1. Recursively traverse the left subtree.
// 2. Visit the current node.
// 3. Recursively traverse the right subtree.
// 4. Store the visited node values in the answer.
//
// Traversal Order:
// Left → Root → Right
//
// Time Complexity: O(n)
// Space Complexity: O(h)
// where h is the height of the tree (recursion stack).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 vector<int> ans;
    void helper(TreeNode* root){
        if(root==NULL) return;

        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
         helper(root);
        return ans;
    }
};
