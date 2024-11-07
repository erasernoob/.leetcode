/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> input;    
    stack<int> output;

    MyQueue() {

    }
    
    void push(int x) {
        input.push(x);
    }
    
    // 只有在输出栈为空的时候才向其中加入数据
    int pop() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int s = output.top();
        output.pop();
        return s ;
    }
    
    int peek() {
        int s = pop();
        output.push(s);
        return s;
    }
    
    bool empty() {
        return input.empty() && output.empty();

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

