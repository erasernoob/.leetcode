/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int sum = root->val;
        return dfs(root, targetSum, sum);

    }

    bool dfs(TreeNode* node, int targetSum, int sum) {
        sum += node->val;
        if(!node->left && !node->right) {
            if(targetSum == sum) return true;
        }


        bool left, right;
        if(node->left) left = dfs(node->left, targetSum, sum);
        if(node->right) right = dfs(node->right, targetSum, sum);
        return left || right;
    }
};
// @lc code=end

