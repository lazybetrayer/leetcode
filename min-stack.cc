// https://oj.leetcode.com/problems/min-stack/

class MinStack {
    stack<int> stk;
    stack<int> min_stk;
public:
    void push(int x) {
        stk.push(x);
        if (min_stk.empty() || x <= min_stk.top()) {
            min_stk.push(x);
        }
    }
    void pop() {
        int n = stk.top();
        stk.pop();

        if (n == min_stk.top()) {
            min_stk.pop();
        }
    }
    int top() {
        return stk.top();
    }
    int getMin() {
        return min_stk.top();
    }
};
