/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        // postOrder Traversal
        if(!root) return 0;
        vector<Node*> nodes = root->children;
        // int max = INT_MIN;
        // can't not set the max to be the INT_MIN 
        // because the minimal depth of the empty tree is 0
        int max = 0;
        for(auto node : nodes) {
            int tmp = maxDepth(node);
            max = max < tmp ? tmp : max;
        }
        return max + 1;
    }
};
// @lc code=end

