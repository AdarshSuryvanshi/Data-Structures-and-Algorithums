


#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}


/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> Two_sum ( vector<int> arr ,int  n , int target);

int main()
{
    int n ;
    cout<<" Enetr the value of n";
    cin>>n;
    int target ;cout <<" Enetr the target"; cin>>target;

    vector<int> arr;
    cout<<" Enetr the elemnts";

    for (int i =0  ;i<n ; i++)
    {
        arr.push_back(arr[i]);
    }

    vector<int> ans =Two_sum( arr ,n,target);
    cout<<"  YES ..This array two elemnts sum ==Target ";
}
  vector<int> Two_sum ( vector<int> arr ,int  n,int target)
{
    

 int left =0; // i index
 int right =n-1; // j index;

 sort (arr.begin(),arr.end());

 while ( left < right)
 {
    int sum  = arr[left] + arr[right];

    if (sum == target)
    {
        cout <<" Yes";
    }
    else if ( sum > target) left++;
    else right --;
 }

    return arr;
}*/