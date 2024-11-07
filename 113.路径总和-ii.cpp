/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res; 
        if(!root) return res;
        vector<int> state;
        state.push_back(root->val);
        int sum = root->val;
        dfs(root, targetSum, res, state, sum);
        return res;
    }

    void dfs(TreeNode* node, int targetSum, vector<vector<int>>& res, vector<int> state, int sum)  {
        if(!node) return;
        if(!node->left && !node->right) {
            // get to the leaf node
            if(sum == targetSum) {
                res.push_back(state);
            }
        }

        if(node->left) {
        state.push_back(node->left->val);
        dfs(node->left, targetSum, res, state, sum + node->left->val);
        state.pop_back();
        }
        if(node->right) {
           state.push_back(node->right->val);
         dfs(node->right, targetSum, res, state, sum + node->right->val);
         state.pop_back();
 
        }

   }
};
// @lc code=end

