// LeetCode 232 - Implement Queue using Stacks
// Difficulty: Easy
// Topic: Stack, Queue, Design
// Approach: Two Stacks (Lazy Transfer)
//
// Problem:
// Implement a First-In-First-Out (FIFO) queue using only
// standard stack operations.
//
// Approach Explanation:
// 1. Maintain two stacks:
//    - input: stores newly inserted elements.
//    - output: stores elements in queue order.
// 2. Push always inserts into the input stack.
// 3. When pop() or peek() is called:
//    - If output is not empty, use its top.
//    - Otherwise, transfer all elements from input
//      to output, reversing their order.
// 4. Each element is transferred at most once,
//    giving an amortized O(1) time per operation.
//
// Time Complexity:
// Push  : O(1)
// Pop   : O(1) amortized
// Peek  : O(1) amortized
// Empty : O(1)
//
// Space Complexity: O(n)

class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
       
    }
    
    int pop() {
        if(!output.empty()){
            int res=output.top();
            output.pop();
            return res;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int res=output.top();
            output.pop();
            return res;
    }
    
    int peek() {
        if(!output.empty()){
           return output.top();
            
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        return output.top();
            
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
