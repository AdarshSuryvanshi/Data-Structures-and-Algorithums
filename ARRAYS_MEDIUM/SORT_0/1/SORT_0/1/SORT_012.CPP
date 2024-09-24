#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int SORT ( int arr[] ,int  n );

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

    SORT( arr ,n);
    
}
  int SORT ( int arr[] ,int  n)
{
    int count0 =0;
    int count1 =0;
    int count2 =0;
    for (int i =0 ;i <n ;i++)
    {
        if ( arr[i] == 0) count0 ++;
        
        else if ( arr[i] == 1) count1 ++;
        else count2 ++;
    }

    for (int i =0; i<count0 ;i++)
    {
        arr[i]= 0;
    }
        for (int i =count0; i<count0 + count1 ;i++)
    {
        arr[i]= 1;
    }
        for (int i = count0 +count1; i< n ;i++)
    {
        arr[i]= 2;
    }
    cout <<" The sorted array is";
        for (int i =0  ;i<n ; i++)
    {
        cout<<" "<<arr[i] <<" ";
    }


    return 0;
}