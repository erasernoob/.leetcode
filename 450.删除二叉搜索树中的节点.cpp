/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    // 1 none 2 left 3 right 4 left and right
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if traversal to the null node
        if(!root) return NULL;
        if(root->val == key) {
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            if(!left && !right) {
                return NULL;
            }
            if(!left && right != NULL) return right;
            if(!right && left != NULL) return left;
            TreeNode *cur = root->right;
            while(cur->left) {
                cur = cur->left;
            }
            cur->left = root->left;
            return cur;
        } 

        if(root->val > key) { 
            root->left = deleteNode(root->left, key);
        } 
        if(root->val < key) { 
            root->right = deleteNode(root->right, key);
        }
        return root;


    }
};
// @lc code=end

