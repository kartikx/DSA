/**
 * Implement Two Stacks in a Single Array
 */

#include <iostream>
#include <stack>
#include <exception>

using namespace std;

class TwoStack{

    public:
        TwoStack(int size)
        {
            this->size = size;
            this->s1 = 0;
            this->s2 = 0;
            this->arr = new int[size];
        }

        void pushFront(int val)
        {
            if (this->s1 + this->s2 == this->size)
            {
                throw std::runtime_error("Stack Size Overflow");
            }

            this->arr[s1++] = val;
        }

        void pushBack(int val)
        {
            if (this->s1 + this->s2 == this->size)
            {
                throw std::runtime_error("Stack Size Overflow");
            }

            this->arr[size - (++s2)] = val;
        }

        void popFront()
        {
            if (s1 == 0) {
                throw std::runtime_error("Stack is empty");
            }

            this->arr[s1-1] = 0;
            s1--;
        }
        
        void popBack()
        {
            if (s2==0)
            {
                throw std::runtime_error("Stack is empty");
            }
            this->arr[size - s2] = 0;
            s2--;
        }

        void printArr()
        {
            for (int i=0 ; i<size ; ++i)
            {
                cout << this->arr[i] << " ";
            }
            cout << endl;
        }
    private:
        int size;
        int s1, s2;
        int* arr;
};

int main()
{
    TwoStack s(10);
    s.pushFront(1);
    s.pushBack(10);
    s.pushFront(2);
    s.pushFront(3);
    s.pushFront(4);
    s.pushBack(7);

    s.printArr();
    
    s.pushBack(6);
    s.pushBack(5);
    s.pushBack(1);
    s.pushBack(2);

    s.printArr();

}