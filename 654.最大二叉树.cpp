/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // 1. the index of the max element
        // 2. the beginIndex of the vector & the endIndex of the vector
        // 3. dfs(nums, beginIndex, endIndex)
        return dfs(nums, 0, nums.size());
    }

    int findTheMaxIndex(vector<int>& nums, int begin, int end) {
        int max = INT_MIN;
        int maxIndex = INT_MIN;
        for(begin; begin < end; begin++) {
            if(nums[begin] > max) {
                max = nums[begin];
                maxIndex = begin;
            }
        }
        return maxIndex == INT_MIN ? -1 : maxIndex;
    }

    TreeNode* dfs(vector<int>& nums, int begin, int end) {
        if(begin == end) return NULL;

        int maxIndex = findTheMaxIndex(nums, begin, end);
        int rootValue = nums[maxIndex];
        TreeNode* root = new TreeNode(rootValue);

        root->left = dfs(nums, begin ,maxIndex);
        root->right = dfs(nums, maxIndex + 1 ,end);

        return root;
    }
};
// @lc code=end

