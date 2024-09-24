#include<iostream>
using namespace std;
 void  slection_sort ( int arr[], int n);
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
    slection_sort( arr,n); // in calling funcion there is no this [] in array 
                            // only in prototype and defination..
    for ( int i =0; i<n ; i++)
    {
        cout<<arr[i] <<" ";
    }

 }
                    void slection_sort( int arr[],int n)
            {
                for ( int i=0 ; i<n-2 ; i++) // SWAPING WAS HAPPEN TILL SECOND LAST INDEX
                {
                        int MAX =i ;//LET US CONSIDER WHATEVER THE 1ST IS MINIMUM COMPARE
                                     // WITH OTHERS AND SWAP IT .IF FOUND LESS THAN MINIMUM.. 

                    for ( int j =i ;j< n-1 ; j++) // SWAPING HAPPENS BETWEEN 1ST AND LAST INDEX LIKE.
                    {
                        if ( arr[j] > arr[MAX]){
                        MAX = j;
                        }
                    }
                    int temp = arr[i];
                    arr[i]= arr[MAX];
                    arr[MAX]= temp;
                }
            }