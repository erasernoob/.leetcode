/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& inorder, int inBegin, int inEnd, vector<int>& postorder, int postBegin, int postEnd) {
        // follow the [)princple to update the two vector's index
        if(postBegin == postEnd) return NULL;

        int midIndex = 0;
        for(midIndex = inBegin; midIndex < inEnd; midIndex++) {
            if(inorder[midIndex] == postorder[postEnd - 1]) break;
        }
        TreeNode* root = new TreeNode(inorder[midIndex]);

        int inLeftBegin = inBegin;
        int inLeftEnd = midIndex;
        int inRightBegin = midIndex + 1;
        int inRightEnd = inEnd;

        int postLeftBegin = postBegin;
        int postLeftEnd = postBegin + inLeftEnd - inLeftBegin;
        int postRightBegin = postLeftEnd;
        int postRightEnd = postEnd - 1;

        root->left = traversal(inorder, inLeftBegin, inLeftEnd, postorder, postLeftBegin, postLeftEnd);
        root->right = traversal(inorder, inRightBegin, inRightEnd, postorder, postRightBegin, postRightEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!inorder.size() || !postorder.size()) return NULL;
        // use the index to do the cut 
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end

