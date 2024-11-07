/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * c
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
    int maxValue = -1;
    int findBottomLeftValue(TreeNode* root) {
        // don't care the traversal order just find the left and biggest 
        dfs(root, 1);
        return maxValue == -1 ? root->val : maxValue;
        
    }

    void dfs(TreeNode* node, int cur) {
        if(!node) return;
        if(!node->left && !node->right) {
            if(res < cur) {
             res = cur;
             maxValue = node->val;
          }
        }

        dfs(node->left, cur+1);
        dfs(node->right, cur + 1);
        
    }
   
};
// @lc code=end

