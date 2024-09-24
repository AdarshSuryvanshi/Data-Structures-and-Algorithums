#include<iostream>
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
    
                
    for (int i =0 ;i<n ;i++) // EVERY ELEMENT OF I CHECK WITH J IS THERE HAVING ANOTHER ELEMNTS
    {                        //  ARRAY THAT .SUM WITH INDEX I+J == TARGET
        for ( int j = i+1 ;j<n ;j++)
        {
            
            
            if ( arr[i] + arr[j] == target ) //UPER KA I AND FIND KIYA HAU 
            {
                cout<<" YES WE GOT TARGET";
                cout<<" The index are "<<i<<" "<<j;
            }
            

            
        }
        
        
    }
    return 0;
}