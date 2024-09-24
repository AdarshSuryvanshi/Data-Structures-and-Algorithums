#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Two_sum ( int arr[] ,int  n , int target);

int main()
{
    int n ;
    cout<<" Enetr the value of n";
    cin>>n;
    int target ;cout <<" Enetr the target"; cin>>target;

    int arr[n];
    cout<<" Enetr the elemnts";

    for (int i =0  ;i<n ; i++)
    {
        cin>>arr[i];
    }

    int ans =Two_sum( arr ,n,target);
    cout<<"  YES ..This array two elemnts sum ==Target ";
}
  int Two_sum ( int arr[] ,int  n,int target)
{
     map <int ,int>mpp;

         for (int i =0 ;i<n ;i++)
{
    int a = arr[i];

    int more = target- a;

    if (mpp.find(more) != mpp.end()) // if MORE IS IN HASHMAP AND IS NOT POINTING TOWARDS LAST 
    {                                                           // ITERATOR
        cout <<" YES WE GOT TARGET AT INDEX";
        cout  <<mpp[more] <<" "<<i; // MORE NAHI USKA ANS WOHI TOH MERA MAIN ARRAY KA INDEX HOGA 
                                    // HASHMAP KA ELEMENT MERA ARRAY KA INDEX HOGA
        
    }
       mpp [a] =i;
 
        
        
    }
    return 0;
}