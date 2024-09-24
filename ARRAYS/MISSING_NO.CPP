#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Entre the no of elemts of array";cin>>n;
        
    int arr[n];
     cout << "Enter elements of the  array: ";

    for (int i = 0; i < n-1; i++) //  THE ARRAY OF size is n-1
     {
        cin >> arr[i];
    }
    
    for (int i =1 ;i<=n ;i++) //HERE I AM CHECKING WITH EACH NUMBER ARE YOU A MISSING ONE 
    {                    // IF THAT NUMBER IS EXIT FLAG WILL CONVERT INTO 1
        int flag =0;  //IF THAT NUMBER IS NOT EXITS THEN FLAG WILL REAMIN 0 .SO THAT IS MISSING
        for(int j =0 ;j<n-1;j++)
        {
            if (arr[j]==i){
            flag =1;
            break;
            }
        }
        if (  flag == 0)
        {
            // IF SOMEONE DOESNOT EXITS IN ARRAY SO IT IS MISSINF SHOW FLAG ==0
            cout<<" The number is missing is"<<i;
        }

    }
}
    
