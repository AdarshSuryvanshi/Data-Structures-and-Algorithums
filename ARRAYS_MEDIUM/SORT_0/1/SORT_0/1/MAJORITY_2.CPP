#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Majority ( int arr[] ,int  n );

int main()
{
    int n ;
    cout<<" Enetr the value of n";
    cin>>n;
  

    int arr[n];
    cout<<" Enetr the elemnts";

    for (int i =0  ;i<n ; i++)
    {
        cin>>arr[i];
    }

    int ans= Majority( arr ,n);
    cout<<"  The majority elemnt is " << ans;
}
  int Majority ( int arr[] ,int  n)
{
    map <int , int> mpp;
    for (int i =0 ;i< n ; i++) // MAP DATA STRUCTURE FOR STORING ALL THE ELEMNT AND HASHING 
    
    {
        mpp[arr[i]]++;
    }

    for ( auto it : mpp)
    {
        if ( it.second > n/2) // THE ELEMNT WHICH HAS HIGHEST VALUE THAT CORRESPONDING KEY IS
        {                           // IS THE HIGHEST ELEMENT 
            cout<< " The occurence of the elemnt is ="<<it .second;
            return it.first;
        }
    }
    return -1;
}