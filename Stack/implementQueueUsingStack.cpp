#include <iostream>
#include <stack>
#include <exception>

using namespace std;

/**
 * You will need two stacks.
 * An un-optimized approach would be to consider
 * the aux. stack as a tool to allow reversal of stack,
 * when Enqueueing, this would give O(1) pop and O(N) push.
 * 
 * Instead we can maintain two stacks always. The top
 * of S1 will give the back. Front will be the top of s2,
 * if non-empty, else do a pile into s2 from s1, and then get the top.
 * This method is sort of cacheing the reverse operation. Which 
 * leads to an O(1) amortized time.
 */ 
class Queue {

    public:
        Queue()
        {
            s1 = stack<int>();
            s2 = stack<int>();
        }

        void push(int val)
        {
            s1.push(val);
            cout << "Pushed: " << val << " Size is: " << s1.size() << "|" << s2.size() << endl;
        }

        void pop()
        {
            if (!s2.empty())
            {
                cout << "Front is: " << s2.top() << endl;
                s2.pop();
            }

            else {
                if (s1.empty())
                    throw runtime_error("Nothing in container");
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }

                cout << "Front is: " << s2.top() << endl;
                s2.pop();
            }

        }
    private:
        stack<int> s1;
        stack<int> s2;
};

int functionBasedDequeue(stack<int>& s)
{
    if (s.empty())
        return -1;

    int curr = s.top();
    s.pop();
    if (s.empty())
    {   
        return curr;
    }

    int poppedVal = functionBasedDequeue(s);
    s.push(curr);
    return poppedVal;
}


int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // this should remove 1.
    cout << "Removed value is: " << functionBasedDequeue(s) << endl;

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}