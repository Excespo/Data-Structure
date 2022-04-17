/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
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
    void iter(TreeNode* node, vector<int> & list) {
        if (node == nullptr) return;
        iter(node->left, list);
        list.push_back(node->val);
        iter(node->right, list);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> list;
        iter(root, list);
        return list;
    }
};
// @lc code=end

