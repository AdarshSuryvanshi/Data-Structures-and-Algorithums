
#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size(); // THE SIZE OF ARRAY
  int index = 0;
  for (auto it: set) {
    arr[index++] = it;
  }
  cout<<" The total no of indexing  int this array is "<<index;
  return k;
}
int main() {
  int n;
  cout<<" Enetr the value of n";
  cin>>n;
  int arr[n];
  
    for ( int i =0; i<n ;i++)
    {
        cin>>arr[i];
    }
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) // k= the size of the array ...vaha tak loop chalega 
  {
    cout << arr[i] << " ";
  }
  
}

