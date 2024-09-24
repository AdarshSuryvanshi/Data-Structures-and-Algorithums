#include<iostream>
using namespace std;
int lenth_of_subarray(int arr[ ],int n ,int k );
int main()
{
    int n;
    cout<<" Enetr the size of array";
    cin>>n;

    int arr[n];
    cout<<" enetr the elememnts ";
    for (int i =0 ;i<n;i++)
    {
        cin>>arr[i];
    }
    int k ;
    cout<<" Enter the no which is the sum of subarray " ; cin>>k; 
    int ans =  lenth_of_subarray( arr, n,k ); 
    cout<<" Lentght of the longest subarray is ="<<ans;

}
int lenth_of_subarray(int arr[ ],int n, int k ){

    int length =0;
  
    
    for (int i =0 ;i<n ;i++)
    {
        for ( int j =i ;j< n ;j++) // GENRATE ALL THE SUBARRAYS
        {
              int sum =0;
            for (int k =i ;k <=j;k++) // CHECKING WITH THE SUM
            {
                sum =sum + arr[k];
         
            }
                 if ( sum == k) // IF IT IS EAUAL THEN COUNT LENGTH
            {
                length =max ( length ,j-i+1); // STORED THE MAXIMUM LENGTH OF THE SUBARRAYS
            }
        }  
    }
    return length;

}