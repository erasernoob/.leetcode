/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> stdout;    
    queue<int> stdin;

    MyStack() {


    }
    
    void push(int x) {
        stdin.push(x);
    }
    
    int pop() {
        int res = 0;
        while(true) {
            int tmp = stdin.front();
            stdin.pop();
            if(stdin.empty()) {
                res = tmp;
                break;
            } else stdout.push(tmp);
        }
        
        while(!stdout.empty()) {
            int tmp = stdout.front();
            stdin.push(tmp);
            stdout.pop();
        }
        return res;
    }
    
    int top() {
        int res = 0;
        while(true) {
            int tmp = stdin.front();
            stdout.push(tmp);
            stdin.pop();
            if(stdin.empty()) {
                res = tmp;
                break;
            } 
        }
        
        while(!stdout.empty()) {
            int tmp = stdout.front();
            stdin.push(tmp);
            stdout.pop();
        }
        return res;
    }
    
    bool empty() {
        return stdout.empty() && stdin.empty();

    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

