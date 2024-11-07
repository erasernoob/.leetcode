/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int res = 0;
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 1);
        return res;
    }

    void dfs(TreeNode* node, int cur) {
        if(!node) return;
        res = res > cur ? res : cur;
        
        dfs(node->left, cur+ 1);
        dfs(node->right, cur + 1);
    }
        
};
// @lc code=end

