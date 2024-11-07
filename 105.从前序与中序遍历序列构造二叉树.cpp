/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& inorder, int inBegin, int inEnd, vector<int>& preorder, int preBegin, int preEnd) {
        if(preBegin == preEnd) return NULL;

        int rootValue = preorder[preBegin];
        TreeNode* root = new TreeNode(rootValue);


        int midIndex = 0;
        for(midIndex = inBegin; midIndex < inEnd; midIndex++) {
            if(inorder[midIndex] == rootValue) break;
        }

        // start to cut the inOrder arr
        int inLeftBegin = inBegin;
        int inLeftEnd = midIndex;
        int inRightBegin = midIndex + 1;
        int inRightEnd = inEnd;

        int preLeftBegin = 1 + preBegin;
        int preLeftEnd = 1 + preBegin + inLeftEnd - inLeftBegin;
        int preRightBegin = preLeftEnd;
        int preRightEnd = preEnd;


        // get left and right
        root->left = traversal(inorder, inLeftBegin, inLeftEnd, preorder, preLeftBegin, preLeftEnd);
        root->right = traversal(inorder, inRightBegin, inRightEnd, preorder, preRightBegin, preRightEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!inorder.size() || !preorder.size()) return NULL;
        return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }
};
// @lc code=end

