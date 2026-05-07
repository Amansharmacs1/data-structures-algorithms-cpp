// LeetCode 20 - Valid Parentheses
// Difficulty: Easy
// Topic: Stack, String
// Approach: Stack-based matching of opening and closing brackets
//
// Problem:
// Given a string containing '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
//
// A string is valid if:
// - Open brackets are closed by the same type of brackets
// - Brackets are closed in correct order
//
// Approach Explanation:
// - Use a stack to store opening brackets.
// - If character is opening bracket → push to stack.
// - If closing bracket:
//   - Stack must not be empty.
//   - Top of stack must match corresponding opening bracket.
//   - Otherwise return false.
// - At the end, stack must be empty.
//
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    bool isValid(string str) {
        int n = str.length();

        if (n % 2 != 0) return false;

        stack<char> st;

        for (int i = 0; i < n; i++) {

            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
            } 
            else {
                if (st.empty()) return false;

                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '[' && str[i] == ']') ||
                    (st.top() == '{' && str[i] == '}')) {
                    st.pop();
                } 
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
