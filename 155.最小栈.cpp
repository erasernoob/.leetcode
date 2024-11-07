/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public 
    void getNext(vector<int> nums) {
        
        

    }


public:
    stack<int> s;
    stack<int> min_stack;
    MinStack() {

    }
    void push(int val) {
        s.push(val);
        if(min_stack.empty() || min_stack.top() >= val) {
            min_stack.push(val);
        }
    }
    
    void pop() {
        if(s.top() == min_stack.top()) {
            min_stack.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

