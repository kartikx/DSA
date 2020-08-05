#include <iostream>
#include <stack>

using namespace std;

class SpecialStack{

    public:
        SpecialStack():
            s(stack<int>()),
            minStack(stack<int>())
        {
        }

    void push(int val)
    {
        s.push(val);
        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }

    void pop()
    {
        if (minStack.top() == s.top())
            minStack.pop();
        s.pop();
    }

    int getMin()
    {
        if (s.empty())
            throw runtime_error("Stack is empty");
        return minStack.top();
    }

    int top()
    {
        if (s.empty())
            throw runtime_error("Stack is empty");
        return s.top();
    }

    private:
        stack<int> s;
        stack<int> minStack;
};

int main()
{
    SpecialStack s;
    s.push(1);
    s.push(2);
    s.push(0);
    s.push(3);
    s.push(4);
    s.push(0);
    s.push(5);

    cout << s.getMin() << endl;

    s.pop();
    s.pop();

    cout << s.getMin() << endl;

    s.pop();

    cout << s.getMin() << endl;
}