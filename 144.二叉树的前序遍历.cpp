/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        s.push(root);
        while(!s.empty()) {
            TreeNode* top = s.top();
            res.push_back(top->val);
            s.pop();
            
            if(top->right) s.push(top->right);
            if(top->left) s.push(top->left);
        }
        return res;
    }

};
// @lc code=end

