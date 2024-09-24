#include<bits/stdc++.h>

using namespace std;

class Stack {
  queue < int > q; // CREATING A QUESE TO IMPLEMENT STACK
  public:
    void Push(int x) // ELEMNT TO BE PUSH INTO QUESE WILL BE COME FROM BELOW 
     {
      int s = q.size(); // STORED THE SIZE OF THW QUESE
      q.push(x); // PUSH THE FIRST ELEMNT IN THE QUESE
      for (int i = 0; i < s; i++) {

        q.push(q.front()); // ELEMENTS WHICH WILL COME AT FRONT IT WILL PUSH THAT TO ABOVE 
        q.pop(); // AND REMOV FROM THAT PLACE
      }
    }
  int Pop() {
    int n = q.front(); // THAT ELEMNT WHICH YOU ARE GOING TO REMOVE STORED IN ' N '
    q.pop();
    return n; // RETURN THAT ELEMNT TO MAIN() FUNCTION
  }
  int Top() {
    return q.front(); // BY LIFO - WHICHEVER ELMENT AT FRONT RETURN THAT
  }
  int Size() {
    return q.size(); // RETURN THE SIZE OF THE QUESE AFTER COMPLEMTING ALL THE OPERATIONS
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
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();

}
