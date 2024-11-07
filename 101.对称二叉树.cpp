/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
        // find the end point of the recursion
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* left, TreeNode* right) {
        // 1. left == NULL right == NULL true ()
        // 2. !left || !right (one of them is not nullptr)
        // 3. l->val  != r->val (flase)
        // when l->val == r->val can't return true!!!(this will end the recursion)
        if(left == NULL && right == NULL) return true;
        if(!left || !right) return false;
        if(right->val != left->val) {
            return false;
        }
        return helper(left->left,right->right) && helper(left->right, right->left);

    }

};


