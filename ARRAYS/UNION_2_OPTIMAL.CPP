#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> sorted_arrays(int arr1[],int arr2[] ,int n, int m);
int main()
{
    int n;
    cout<<"Entre the no of elemts of array1";cin>>n;
        
    int arr1[n];
     cout << "Enter elements of the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    int m;
    cout<<"Entre the no of elemts array2";cin>>m;

      int arr2[m];

    cout << "Enter elements of the second array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

     vector < int > Union =     sorted_arrays(arr1,arr2 ,n,m);

     cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union)
    cout << val << " ";


    

}
    vector<int> sorted_arrays(int arr1[],int arr2[] ,int n ,int m)
    {
         int i = 0, j = 0; // pointers

  vector < int > Union; // Uninon vector
  
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])

        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left from arry1 
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // IF any element  left from arry2 
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;

    }