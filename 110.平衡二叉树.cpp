/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        // what we want is the height of the tree
        // yes just get the height of the left and right node when it's wrong return false
        // postOrder traversal
        return dfs(root) != -1;
    }

    // if not right return -1
    int dfs(TreeNode* node) {
        if(!node) return 0;
        if(!node->left && !node->right) return 1;

        int left = dfs(node->left);
        if(left == -1) return -1;
        int right = dfs(node->right);
        if(right == -1) return -1;
        if(abs(right - left) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }

    
};
// @lc code=end

