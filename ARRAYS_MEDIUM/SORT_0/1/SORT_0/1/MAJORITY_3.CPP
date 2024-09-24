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
    int count =0; // COUNT THE MAJORITY   ELEMENT IN ALL CONDITION WHICH WE HAVE AASUME
    int element ;

    for ( int i =0 ;i<n ;i++)
    {
        if ( count =0) // STARTING OF NEW BLOCK OF ARRAY
        {
            count =1; // COUNT 1 THE WHATEVER 1ST INDEX IS THERE IN ARRAY
            arr[i] =element; // PLACE 1ST INDEX AS MAJORITY ELEMENT
            
        }

        else if ( arr[i] == element) count++; // IF GOT IN PARTICULAR ARRAY ++ BY 1
        else count--; // IF OTHER ELEMENT COMES -- BY 1
    }
    int count1 =0; // COUNT THE MAJORITY ELEMNT CHECK IT IS EXITS OR NOT

    for ( int i =0 ;i,n ;i++) // CHECK THE GETTEN MAJORITY ELEMNNT IS SACH HAI M.E HAI YA NAHI
    {
        if ( arr[i] == element) count1++;

        if ( count1 > n/2) return element; // IF N/2 SAI BADA HAI THEN YES .. MAJORITY ELEMNT EXITS
    }
    return -1; // OTHERWISE AJORITY ELEMNT  IS NOT EXISTS IN THE ARRAY
}