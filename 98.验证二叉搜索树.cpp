/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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

    // preOrder traversal 
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* node, long long left, long long right) {
        if(!node) return true;
        int x = node->val;
        if(x <= left || x >= right) {
            return false;
        }
        return dfs(node->left, left, node->val) && dfs(node->right, node->val, right);
    }
    

};
// @lc code=end

