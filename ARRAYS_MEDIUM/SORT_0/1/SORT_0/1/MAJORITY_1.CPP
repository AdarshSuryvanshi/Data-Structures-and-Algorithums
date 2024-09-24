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
    
    for ( int i =0 ;i< n ;i++)
    {
        int count =0;
        
        for ( int j =0 ;j<n ;j++)
        {
            if ( arr[i]== arr[j])
            {
                count++;
            }

            if ( count >n/2)
            {
                cout << " Elemnt occured"<<count  <<"   times";
                return arr[i];
            }
        }

    }
    

    return -1;
}