/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true; // because the empty tree is always the subtree of any tree
        if(!root) return false; // if the root is the null then it can't be the tree definitely
        return dfs(root, subRoot);
    }

    bool dfsH(TreeNode* root, TreeNode* subRoot) {
        // the helper func to identify the node is equal to the subRoot or not 
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val != subRoot-> val) return false;
        
        // left
        bool left = dfsH(root->left, subRoot->left);
        bool right =dfsH(root->right, subRoot->right);
        bool mid = left && right;
        // return mid;
        return left && right; 
    }

    bool dfs(TreeNode* root, TreeNode* subRoot) {
        // consider the root one is the subTree or not ?? 
        // then consider the left child is the subTree or not 
        // then consider the right child

        // postOrder 

        if(!root) return false; // get to the null one
        if(dfs(root, subRoot)) return true;
        bool left = dfsH(root->left, subRoot); // left 
        if(left) return true;
        bool right = dfsH(root->right, subRoot); // right
        if(right) return true;

        return dfs(root->left, subRoot) || dfs(root->right, subRoot); 
        
    }
    
};
// @lc code=end

