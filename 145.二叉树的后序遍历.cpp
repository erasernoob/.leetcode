/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        // pre: mid -> left -> right
        // post: left -> righright -> mid
        stack<TreeNode*> st;
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        st.push(root);
        while(!st.empty()) {
            TreeNode* tmp = st.top();
            res.push_back(tmp->val);
            st.pop();
            if(tmp->left != NULL) {
                st.push(tmp->left);
            }
            if(tmp->right != NULL) {
                st.push(tmp->right);
            }
            
        }
        reverse(res.begin(), res.end());
        return res;
    }

};
// @lc code=end

