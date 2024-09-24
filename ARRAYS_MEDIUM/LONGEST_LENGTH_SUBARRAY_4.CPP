#include<iostream> // THIS APPROACH IS VALID FOR ELEMNTS IN THE ARRAY are (POSITVE , NEGATIBE AND )
#include<bits/stdc++.h>                                                             // ZERO
using namespace std;     // THIS APPROACH IS BETTER FOR (POSITIVE AND ZERO ELEMNTS)
int lenth_of_subarray(int arr[ ],int n ,int k );
int main()      // THIS APPROACH IS OPTIMAL FOR ( POSITIVE AND NEGATIVE ELEMNTS)
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

    int maxlen =0;
    map<long , int > prefixsum;
    int sum =0; // PREFIXSUM =X
  
    
    for (int i =0 ;i<n ;i++){
    
       
                sum =sum + arr[i];
        
        if ( sum == k) // IF IT IS EAUAL THEN COUNT LENGTH
         
            {
                maxlen =max ( maxlen ,i +1); // STORED THE MAXIMUM LENGTH OF THE SUBARRAYS
            }

            int rem = sum -k; // REMAINIG = X-K;

            if ( prefixsum.find(rem)!=prefixsum.end()){ // REAMAINNING (X-K) KO MAP MAI DOONDHO

 // IF MILA THEN  WE GOT AN ANOTHER SUBARRAY .. FOR LENGTH JUST SUB ( i - rem)

            int length = i - prefixsum[rem]; // index of (x-k)

            maxlen = max ( maxlen  , length); // MAXLENTH WILL GO FROM (Length :-> maxlen) TILL 
            }                                   // IT GETS THE MAXIMUM
            
        if ( prefixsum.find(rem) == prefixsum.end())
        {
            prefixsum[sum] =i; // MAP WILL INCREASED THE SUM AS LOOP RUN FORWARDS 
        }
    }
         
    
    return maxlen;

}