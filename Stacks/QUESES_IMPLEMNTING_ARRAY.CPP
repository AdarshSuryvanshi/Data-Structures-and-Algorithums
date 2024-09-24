

#include <bits/stdc++.h>
using namespace std;

class Queses {
    int size;
    int *arr;
    int top, count, rare, front;
public:
    Queses() {
        top = -1;
        size = 1000;
        arr = new int[size];
        count = 0;
        rare = 0;
        front = 0;
    }

    ~Queses() {
        delete[] arr;
    }

    int push(int x) {
        if (count == size) cout<<" Queses is full "; return -1; 

        arr[rare % size] = x;
        rare++;
        count++;
        return 0;
    }

    int pop() {
        if (count == 0) {
            cout << "Queue is empty" << endl; // Corrected message
            return -1; // Indicate failure
        }
        int value = arr[front % size];
        front++;
        count--;
        return value;
    }

    int Top() {
        if (count == 0) return -1; // Corrected to use `==`
        return arr[front % size];
    }

    int Size() {
        return count; // Return the actual count
    }
};

int main() {
    Queses s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of Queue before deleting any element: " << s.Top() << endl;
    cout << "Size of Queue before deleting any element: " << s.Size() << endl;
    cout << "The element deleted is: " << s.pop() << endl;
    cout << "Size of Queue after deleting an element: " << s.Size() << endl;
    cout << "Top of Queue after deleting an element: " << s.Top() << endl;
    return 0;
}