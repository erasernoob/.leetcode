/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // 公共祖先就是找到一个左孩子大于其中一个节点，以及右孩子小于其中一个节点的情况
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val < p->val && root->val < q.val) {
            TreeNode* left = klowestCommonAncestor(root->left);
            if(left != NULL) return left;
        }

        if(root->val > p->val && root->val > q.val) {
            TreeNode* right = lowestCommonAncestor(root->right);
            if(right != NULL) return right;
        }

        return root;
    }
};
// @lc code=end

