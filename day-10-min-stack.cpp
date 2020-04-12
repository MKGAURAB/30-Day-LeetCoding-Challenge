#include <bits/stdc++.h>

using namespace std;

class MinStack
{
    stack<long> st;
    long minElement;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        stack<long>().swap(st);
    }

    void push(int x)
    {
        if (st.empty())
        {
            st.push(x);
            minElement = x;
            return;
        }

        if (x < minElement)
        {
            st.push(2l * x - minElement);
            minElement = x;
        }
        else
        {
            st.push(x);
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long top = st.top();
        st.pop();

        if (top < minElement)
        {
            minElement = 2l * minElement - top;
        }
    }

    int top()
    {
        long top = st.top();

        return top < minElement ? minElement : top;
    }

    int getMin()
    {
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
