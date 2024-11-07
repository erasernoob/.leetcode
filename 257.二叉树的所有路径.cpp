/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
// class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        int val = root->val;
        dfs(root, res, to_string(val));
        return res;
    }
    
    void dfs(TreeNode* node, vector<string>&res, string cur) {
        if(!node->left && !node->right) {
            res.push_back(cur);
        }

        if(node->left) {
            string a = to_string(node->left->val);
            dfs(node->left, res,  cur + "->" + a);
        }

        if(node->right) {
            string b = to_string(node->right->val);
            dfs(node->right, res, cur + "->" + b);
        }
    }

};
// @lc code=end

