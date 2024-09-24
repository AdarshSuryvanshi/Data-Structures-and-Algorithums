#include <bits/stdc++.h>
using namespace std;

void Find_union(int arr1[], int arr2[], int n);

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr1[n];
    int arr2[n];

    cout << "Enter elements of the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter elements of the second array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    Find_union(arr1, arr2, n);

    return 0;
}

void Find_union(int arr1[], int arr2[], int n) {
    set<int> st;

    // Insert elements from arr1 into the set
    for (int i = 0; i < n; i++) {
        st.insert(arr1[i]);
    }

    // Insert elements from arr2 into the set
    for (int i = 0; i < n; i++) {
        st.insert(arr2[i]);
    }

    // Output the elements in the union
    cout << "The elements in the union array are as follows: ";
    for (auto it = st.begin(); it != st.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}