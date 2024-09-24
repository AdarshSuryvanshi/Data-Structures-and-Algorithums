#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 int findMaximumConscutiness(int a[],int n);
int main()
{
        int N;
    cout<<"Entre the no of elemts of array";cin>>N;
        
    int a[N];
     cout << "Enter elements of the  array: ";

    for (int i = 0; i < N-1; i++) {
        cin >> a[i];
    }

    int ans = findMaximumConscutiness(a, N);
    cout << "The maximum  conscutiness is: " << ans << endl;
    return 0;
}
 int findMaximumConscutiness(int a[],int n)
 {
    int maxi =0;
    int count =0;

    for (int i =0 ;i<n;i++)
    {
        if (a[i]==1)
        {
            count++;
            maxi =max( maxi,count);
        }
        else{

            count =0;
        }
    }
    return maxi;
 }


