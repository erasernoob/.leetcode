/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (size_t i = 0; i < size; i++) {
                Node* cur = que.front();
                que.pop();
                vec.push_back(cur->val); 
                vector<Node*> c = cur->children;
                for (size_t i = 0; i < c.size(); i++) {
                   que.push(c[i]); 
                }
            }
            res.push_back(vec);
        }
        return res;
        
    }
};
// @lc code=end

