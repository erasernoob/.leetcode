/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        // iterator implement the preorder Travel
        vector<int> res;
        stack<TreeNode*> st;
        // left -> mid -> right
        TreeNode* cur = root;
        while(cur != NULL || !st.empty()) {
            if(cur != NULL) {
                st.push(cur);
                cur = cur->left; // left
            } else {
                cur = st.top();

                res.push_back(cur->val);

                st.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};
// @lc code=end

