

#include<bits/stdc++.h>

using namespace std;


//Function to return precedence of operators
int prec(char c) {
  if (c == '^')
    return 1;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 3;
  else
    return -1;
}

// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string s) {

  stack < char > st; //For stack operations, we are using C++ built in stack
  string ans;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    // If the scanned character is
    // an operand, add it to output string.
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      ans = ans +c;

    // If the scanned character is an
    // ‘(‘, push it to the stack.
    else if (c == '(')
      st.push('(');

    // If the scanned character is an ‘)’,
    // pop and to output string from the stack
    // until an ‘(‘ is encountered.
    else if (c == ')') {
      while (st.top() != '(') {
        ans = ans+ st.top();
        st.pop();
      }
      st.pop();
    }

    //If an operator is scanned
    else {
      while (!st.empty() && prec(s[i]) <= prec(st.top())) // APNE HISAB SAI PRECEDENCE CHANGE  
      {                                                     // KARNI HOGI
        ans = ans + st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  // Pop all the remaining elements from the stack
  while (!st.empty()) {
    ans = ans+ st.top();
    st.pop();
  }

  cout << "Prefix expression: " << ans << endl;
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp);
  return 0;
}

