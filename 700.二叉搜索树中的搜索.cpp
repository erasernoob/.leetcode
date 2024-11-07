/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root, val);
    }

    TreeNode* dfs(TreeNode* root, int val) {
        if(!root) return NULL;
        
        if(root->val == val) return root;
        TreeNode* result;
        result = dfs(root->left, val);
        result  = dfs(root->right, val);
        return result;




    }
};
// @lc code=end

