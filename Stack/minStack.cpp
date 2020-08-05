#include <stack>
#include <iostream>

using namespace std;

class MinStack {
    public:
        MinStack() :
            s(stack<int>()),
            min(0)
        {
        }

        void push(int val)
        {
            if (s.empty())
            {
                s.push(val);
                min = val;
            }
            /**
             * I think the choice of the actual function I use is irrelevant,
             * as long as I'm able to retrieve the old M from it, and able
             * to detect that I need to use the inverse of the function when
             * popping elements. The latter is achieved by ensuring that
             * the value inserted into the stack is < x ( = newMinValue).
             */
            else {
                if (val < min) {
                    s.push(2*val - min);
                    min = val;
                }
                else {
                    s.push(val);
                }
            }
        }

        int pop()
        {
            int curr = s.top();
            s.pop();
            if (curr < min) {
                int minOrg = min;
                min = 2*min - curr;
                return minOrg;
            }
            else {
                return curr;
            }
        }

        int getMinimum() {
            return min;
        }
    private:
        stack<int> s;
        int min;
};

class MaxStack {
    public:
        MaxStack() :
            s(stack<int>()),
            max(0)
        {
        }

        void push(int val)
        {
            if (s.empty())
            {
                s.push(val);
                max = val;
            }

            else {
                if (val > max) {
                    s.push(val + max);
                    max = val;
                }
                else {
                    s.push(val);
                }
            }
        }

        int pop()
        {
            int curr = s.top();
            s.pop();
            if (curr > max) {
                int maxOrg = max;
                max = curr - maxOrg;
                return maxOrg;
            }
            else {
                return curr;
            }
        }

        int getMaximum() {
            return max;
        }
    private:
        stack<int> s;
        int max;
};

int main()
{
    MaxStack s;
    s.push(3);
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(0);
    s.push(6);
    s.push(1);
    cout<<"Popped: "<<s.pop()<<endl;
    cout<<"Popped: "<<s.pop()<<endl;
    cout << "Maximum is: " << s.getMaximum() << endl;
    // cout<<"Popped: "<<s.pop()<<endl;
    // cout << "Maximum is: " << s.getMaximum() << endl;
    // cout<<"Popped: "<<s.pop()<<endl;
    // cout<<"Popped: "<<s.pop()<<endl;
    // cout << "Maximum is: " << s.getMaximum() << endl;
    // cout<<"Popped: "<<s.pop()<<endl;
    // cout<<"Popped: "<<s.pop()<<endl;
    // cout << "Maximum is: " << s.getMaximum() << endl;
}