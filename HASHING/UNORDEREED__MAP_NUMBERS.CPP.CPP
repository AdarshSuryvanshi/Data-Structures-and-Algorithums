#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; 
    cout<<" entr the value of n";
    cin>>n;
    int arr[n];

    for (int i =0;i<n;i++)
    {   cout<<" Enetr the array";
        cin>>arr[i];

    }
    
    //PRE COMPUTING /PRECALCULATION

     map<int,int>mpp;

     for( int i =0;i<n ;i++)
     {
        mpp[arr[i]]++; // WHEN YOUR NUMBER MATCH WITH YOUR ARRAY IT WILL +1 TO VALUE
     }

     int Q;
     cout<<" Enetr how much qerise you want";
     cin>>Q;
      while(Q--)
      {
        int number;
        cout<<" Enetr the number which you want to check";
        cin>>number;

        cout<<" The apred is "<<mpp[number]<<" Timse"<<endl;
      }

    

}