#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void sort_array ( int arr[ ], int n);

int main()
{

    int n ;
    cout<<" Enetr the value of n";
    cin >> n;

    int arr[n];
    cout<<" Enetr the elemnts of array";

    for ( int i =0 ;i<n ;i++)
    {
        cin>> arr[i];

    }
    sort_array( arr ,n);
}

void sort_array ( int arr[ ], int n)
{
    int mid =0 ;int low =0 ;int high =n-1;

    while ( mid <= high)
    {
        if ( arr[mid] == 0)
        {
            swap ( arr[low] , arr[mid]); // IT ALWAYS SHIFT FROM RIGHT TO LEFT

            mid++; low++;
        }
        
        else if ( arr[mid] == 1) mid++;
        else {
            swap ( arr[mid] , arr[high]);
            high --;
        }
    }
    cout <<" The sorted array is";
    
        for (int i =0  ;i<n ; i++)
    {
        cout<<" "<<arr[i] <<" ";
    }

    }