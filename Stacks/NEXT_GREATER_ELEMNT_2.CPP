 #include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextgreater(int arr[], int n) {
    vector<int> nge(n, -1); // Initialize result with -1
    stack<int> st;

    for (int i = 0; i < 2 * n; i++) { // Use 2 * n for iterating over arr and nge
        while (!st.empty() && arr[st.top()] < arr[i % n]) { // Use i % n to wrap around for arr
            nge[st.top()] = arr[i % n];
            st.pop();
        }
        if (i < n) { // Only push elements from arr into stack
            st.push(i % n);
        }
    }

    return nge;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = nextgreater(arr, n);

    cout << "Next greater elements: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}




/*#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> nextgreater ( int arr[] , vector<int> nge[] ,int n);

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int>nge[n];

    vector<int> ans = nextgreater(arr,nge, n);

    cout << "Next greater elements: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
vector<int> nextgreater(int arr[], vector<int> nge ,int n) {
    stack <int> st;

for ( int i =0 ; i< 2*n ;i++)
{
    while ( ! st.empty() && st.top() <= arr[i % n]) // ALL LESSER ELMNTS THEN ARR[I] WILL REMOVED
    {
        st. pop(); // UNKO POP KARDENGE ...WHICH ALL ARE INSIDE STACK...POP KAR DENGE
    }
    if ( i< n)
    {
        if ( !st.empty())
        {
            nge.push_back( st.top());
        }
        else nge.push_back(-1); // PUSH BACK IT IS ONE TYPE OF COUT FOR VECTORS

        st.push( arr[i % n]); // LAST MAI US ELEMNT KO STACK MAI DAAL DENA
    }
}

    return nge;
}*/