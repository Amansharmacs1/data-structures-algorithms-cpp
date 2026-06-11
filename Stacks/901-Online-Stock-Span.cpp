// LeetCode 901 - Online Stock Span
// Difficulty: Medium
// Topic: Stack, Monotonic Stack
// Approach: Monotonic Decreasing Stack
//
// Problem:
// Design a data structure that collects daily stock prices and
// returns the span of the stock's price for the current day.
//
// Span:
// Number of consecutive days (including today)
// where price <= today's price.
//
// Approach Explanation:
// Maintain a stack of {price, span} pairs.
// While stack top price <= current price:
//   - Merge its span into current span
//   - Pop it
//
// Push current {price, span} onto stack.
//
// Time Complexity:
// Amortized O(1) per next() call
//
// Space Complexity:
// O(n)

class StockSpanner {
    stack<pair<int,int>> st;

public:
    StockSpanner() {
    }

    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};
