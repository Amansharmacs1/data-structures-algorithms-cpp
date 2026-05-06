// LeetCode 155 - Min Stack
// Difficulty: Medium
// Topic: Stack, Design
// Approach: Encoding trick using modified values to track minimum
//
// Problem:
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
// Approach Explanation:
// - Maintain a variable minVal to store current minimum.
// - If a new value is less than minVal, store a modified value: (2*val - minVal)
//   which helps in restoring previous minimum during pop.
// - When popping or accessing top, check if the value is encoded (i.e., < minVal).
// - Decode using reverse formula: previousMin = 2*minVal - encodedValue.
//
// Time Complexity: O(1) for all operations
// Space Complexity: O(1) extra (excluding stack)

class MinStack {
public:
    stack<long long int> s;
    long long int minVal;

    MinStack() {
        minVal = 0;
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        } 
        else {
            if (val < minVal) {
                s.push((long long)2 * val - minVal);
                minVal = val;
            } 
            else {
                s.push(val);
            }
        }
    }
    
    void pop() {
        if (s.top() < minVal) {
            minVal = 2 * minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if (s.top() < minVal) {
            return minVal;
        }
        return s.top();
    }
    
    int getMin() {
        return minVal;
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
