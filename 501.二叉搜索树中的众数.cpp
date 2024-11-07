/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int cnt = 0;
    int maxCnt = 0;
    vector<int> res;
    TreeNode* pre;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode* node) {
        if(!node) return;
        
        dfs(node->left);
        if(!pre) cnt = 1;
        if(pre) {
            if(pre->val == node->val) cnt++;
            else cnt = 1;
        } 
        if(cnt == maxCnt) {
            res.push_back(node->val);
        } else if(cnt > maxCnt) {
            res.clear();
            maxCnt = cnt;
            cnt = 1;
            res.push_back(node->val);
        }
        pre = node;

        dfs(node->right);
    }
};

// @lc code=end

