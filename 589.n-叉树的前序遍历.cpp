/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == NULL) return res;
        preOrderHelper(root, res);
        return res;
    }
    
    void preOrderHelper(Node* root, vector<int>& res) {
        if(root == NULL) return;
        res.push_back(root->val);
        vector<Node*> child = root->children;
        for(auto it : child) {
            preOrderHelper(it, res);
        }
    }
};
// @lc code=end

