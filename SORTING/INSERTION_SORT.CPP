#include<iostream>
using namespace std;
 void insertion_sort ( int arr[], int n);
 int main()
 {
    int n;
    cout<< " Enter the value of n";
    cin>>n;

    int arr[n];
    for ( int i =0; i<n ; i++)
    { 
       // cout<<" Enetr the elemrnts of array";
        cin>>arr[i];
    }
    insertion_sort( arr,n); // in calling funcion there is no this [] in array 
                            // only in prototype and defination..
    for ( int i =0; i<n ; i++)
    {
        cout<<arr[i] <<" ";
    }

 }
                    void insertion_sort( int arr[],int n)
            {
                for ( int i =0 ;i<n-1 ; i++) 
                {
                        int j =i;
                    while( j>0 && arr[j-1]> arr[j] ) //IF YOU COULD DO J>=0 THEN IT WILL SHOW 
                            // RUN TIME ERROR BECAUSE ..SOMETIMES 0-1 = -1
                    {
                    int temp = arr[j-1];
                    arr[j-1]= arr[j];
                    arr[j]= temp;
                    j--;
                    }

                    
                }
            }