// LeetCode 150 - Evaluate Reverse Polish Notation
// Difficulty: Medium
// Topic: Stack
// Approach: Stack Simulation
//
// Problem:
// Evaluate the value of an arithmetic expression in
// Reverse Polish Notation (Postfix Expression).
//
// Approach Explanation:
// 1. Traverse each token in the expression.
// 2. If the token is a number, push it onto the stack.
// 3. If the token is an operator:
//    - Pop the top two elements.
//    - Perform the operation in the correct order
//      (first popped is the second operand).
//    - Push the result back onto the stack.
// 4. After processing all tokens, the top of the stack
//    contains the final answer.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int evalRPN(vector<string>& str) {
        int ans=0;
        stack <int> st;
        for(int i=0;i<str.size();i++){
            string ch=str[i];
            if(ch != "+" && ch != "-" && ch != "*" && ch != "/"){
                st.push(stoi(ch));
            }
            else{
                int res=0;
                int b=st.top();
                 st.pop();
                int a=st.top();
                st.pop();
                if(ch=="+") res=a+b;
                else if(ch=="-") res=a-b;
                else if(ch=="*") res=a*b;
                else if(ch=="/") res=a/b;
                st.push(res);
            }
        }
        ans=st.top();
        return ans;
    }
};
