#include <iostream>
#include <vector>
using namespace std;

// Function prototype
vector<int> nextgreater(int arr[], int n);

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

vector<int> nextgreater(int arr[], int n) {
    vector<int> nge(n, -1); // Initialize all elements with -1 and as we found greater change that
                                            // elemnt with -1
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                nge[i] = arr[j]; // Found the next greater element
                break;
            }
        }
    }

    return nge;
}
