/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    int cnt = 0;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // how to construct a binary tree by a array ???  using the index of begin and end in recursion
        return dfs(nums, 0, nums.size() - 1);
        
    }


    TreeNode* dfs(vector<int>& nums, int begin, int end) { 
        if(begin > end ) return NULL; // ?? 
        
        int mid = begin + ((end - begin) / 2);
        int val = nums[mid];
        TreeNode* root = new TreeNode(val);
        
        root->left = dfs(nums, begin, mid - 1);
        root->right = dfs(nums, mid + 1, end);

        return root;
    }


};
// @lc code=end

