/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    TreeNode* pre = NULL;
    int res = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return res;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root) {
        if(!root) return;
        if(root->left == NULL && root->right == NULL && pre != NULL && pre->left == root) {
            res += root->val;
        }
        pre = root;

        dfs(root->left);
        dfs(root->right);
        
    }

};
// @lc code=end

