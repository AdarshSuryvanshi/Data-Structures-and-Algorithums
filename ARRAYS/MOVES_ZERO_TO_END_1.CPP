#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
       int n;
    cout<<" Enetr the n";
    cin>>n;
    int arr[n];
    cout<<" Enetr the elements";
     int no_of_zeros =0;

     for ( int i =0;i<n ;i++)
    {
        cin>>arr[i];
    }

    int temp[n];  //TO STORE ALL THE NON ZERO ELEMENTS IN THE TEMP VARAIBLE
    for(int i = 0; i < n ; i++ )
    {
        if(arr[i]!=0){

            temp [i]=arr[i];
            no_of_zeros++;
        }
    }
    cout<<no_of_zeros;
       for(int i=0 ;i<no_of_zeros;i++)
    {
        arr[i]= temp[i];  // ALL THE NON ZERO STORED AT FRONT 
    }
    
    for ( int i=no_of_zeros; i < n; i++)
    {
        arr[i]=0;  // ALL THE ZEROS ARE STORED AT LAST
    }

    cout<<" after the all the zeros placing at end";
         for ( int i =0;i<n ;i++)
    {
        cin>>arr[i];
    }

        


    

}