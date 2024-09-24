#include <bits/stdc++.h>

using namespace std;

class Queue {
    stack<int> input, output;

public:
    void Push(int x) {
        input.push(x);
    }

    int Pop() {
        if (!output.empty()) {
            int val = output.top();
            output.pop();
            return val;
        } else {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            if (output.empty()) {
                cout << "Queue is empty" << endl;
                exit(0);
            }
            int val = output.top();
            output.pop();
            return val;
        }
    }

    int Top() {
        if (!output.empty()) {
            return output.top();
        } else {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            if (output.empty()) {
                cout << "Queue is empty" << endl;
                exit(0);
            }
            return output.top();
        }
    }

    int Size() {
        return input.size() + output.size();
    }
};

int main() {
    Queue q;
    q.Push(3);
    q.Push(4);
    cout << "The element popped is " << q.Pop() << endl;
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.Size() << endl;

    return 0;
}
