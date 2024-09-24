#include <bits/stdc++.h>

using namespace std;

class Stack {
    queue<int> q1;
    queue<int> q2;

public:
    void Push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int  Pop() {
        int n;
        if (!q1.empty()) {
         n = q1 . front();
            q1.pop();
        }
        return n;
    }

    int Top() {
        if (!q1.empty()) {
            return q1.front();
        }
        throw out_of_range("Stack is empty");
    }

    int Size() {
        return q1.size();
    }
};

int main() {
    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);
    
    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element: " << s.Size() << endl;

    s.Pop();
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size() << endl;

    return 0;
}

