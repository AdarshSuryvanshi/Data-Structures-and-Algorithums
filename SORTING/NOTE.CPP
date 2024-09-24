// IF YOUR ARRAY IS ALREADY SORTED THEN BY USING THIS TECHINIQ 
//YOUR LOOP NOT GOING TO RUN FOR N TIMS IT IS ONLY GOOING TO RUN ONCE..
//IF IT FOUND THAT ARRAY IS ALREADY SORTED THEN IT IS NOT GOING TO RUN.
// DIRECTLY GOES OUT OF THE LOOP............
#include<iostream>
using namespace std;
 void  bubble_sort ( int arr[], int n);
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
    bubble_sort( arr,n); // in calling funcion there is no this [] in array 
                            // only in prototype and defination..
    for ( int i =0; i<n ; i++)
    {
        cout<<arr[i] <<" ";
    }

 }
                    void bubble_sort( int arr[],int n)
            {
                for ( int i= n-1; i>=1 ; i -- ) 
                {
                        int didswap ;

                    for ( int j = 0 ;j<= i-1  ; j++) // SWAPING WAS HAPPEN TILL SECOND LAST INDEX
                    {
                        if ( arr[j] > arr[j+1])
                        {
                     int temp = arr[j];
                    arr[j]= arr[j+1];
                    arr[j+1]= temp;
                    didswap= 1; /////////////// DIIDIDIDISSSSSAWAWAWAWPPP
                       
                        }
                    }
                    if ( didswap == 0)
                    {
                        break;
                    }
                    
                }
            }