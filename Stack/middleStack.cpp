#include <iostream>
#include <list>

using namespace std;

class MiddleStack{

    public:
        MiddleStack() 
            :s(list<int>())
        {
        }

        void push(int val)
        {
            if (s.empty())
            {
                s.push_back(val);
                middle = s.begin();
                return;
            }

            s.push_back(val);

            if (s.size() % 2 == 0)
            {
                middle++;
            }
        }

        void pop()
        {
            if (s.empty())
            {
                throw runtime_error("Stack is empty, invalid operation");
            }

            if (s.size() % 2 == 0)
                middle--;
            s.pop_back();
        }

        void getMiddleElement() {
            if (s.empty())
            {
                throw runtime_error("Stack is empty, invalid operation");
            }
            cout << "Middle Element is: " << *middle << endl;
        }

        // This should change the middle element but how?
        void deleteMiddleElement() {
            if (s.empty())
            {
                throw runtime_error("Stack is empty, invalid operation");
            }
            auto tempMiddle = middle;
            if (s.size() % 2 == 1) {
                advance(middle, 1);
            }
            else {
                advance(middle, -1);
            }
            s.erase(tempMiddle);
        }

        void printStack() {
            for (auto it = s.cbegin() ; it!=s.cend(); ++it)
            {
                cout << *it << " " ;
            }
            cout << endl;
        }
 
    private:
        list<int> s;
        list<int>::iterator middle;
};

int main() {
    // list<int> l{1, 2, 3, 4, 5};
    // auto it = l.begin();
    // advance(it, 2);

    // auto temp = it;
    // l.erase(it);
    // advance(it, 1);

    MiddleStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // s.push(5);

    s.getMiddleElement();
    s.deleteMiddleElement();
    s.getMiddleElement();
}