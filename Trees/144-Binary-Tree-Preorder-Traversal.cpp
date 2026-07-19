// LeetCode 144 - Binary Tree Preorder Traversal
// Difficulty: Easy
// Topic: Tree, DFS, Recursion
// Approach: Recursive Preorder Traversal
//
// Problem:
// Given the root of a binary tree, return its preorder traversal.
//
// Approach Explanation:
// 1. Visit the current node.
// 2. Recursively traverse the left subtree.
// 3. Recursively traverse the right subtree.
// 4. Store the visited node values in the answer.
//
// Traversal Order:
// Root → Left → Right
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

        ans.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }

};
