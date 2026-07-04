// LeetCode 225 - Implement Stack using Queues
// Difficulty: Easy
// Topic: Stack, Queue, Design
// Approach: Single Queue Rotation
//
// Problem:
// Implement a Last-In-First-Out (LIFO) stack using only
// the standard operations of a queue.
//
// Approach Explanation:
// 1. Maintain a single queue.
// 2. When pushing a new element:
//    - Insert it at the back of the queue.
//    - Rotate the previous elements to the back so that
//      the newly inserted element comes to the front.
// 3. The front of the queue always represents the top
//    of the stack.
// 4. Pop removes the front element.
// 5. Top returns the front element.
//
// Time Complexity:
// Push  : O(n)
// Pop   : O(1)
// Top   : O(1)
// Empty : O(1)
//
// Space Complexity: O(n)

class MyStack {
public: 
    queue<int> que;
    
    MyStack() {
        
    }
    
    void push(int x) {
        int n=que.size();
        que.push(x);
       for(int i=0;i<n;i++){
            que.push(que.front());
            que.pop();
        }
        
    }
    
    int pop() {
        if (empty()) return -1;
        int res=que.front();
        que.pop();
        return res;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
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

