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
     int Largest = arr[n-1];
     int Second_Largest;
    for (int i = n-2;i>=0 ;i--){
        if ( arr[i]!= Largest){
            
            Second_Largest = arr[i];
            break;
        }
        else{

            cout<<" Second-largest does not exitx";
        }   
     }
    cout <<"  Second Largest element in the array is \n"<<Second_Largest;//LIKE THIS WE CAN FIND ANY 
                                                // INDEX ELEMENT
 }
                    void bubble_sort( int arr[],int n)
            {
                for ( int i= n-1; i>=1 ; i -- ) 
                {

                    for ( int j = 0 ;j<= i-1  ; j++) // SWAPING WAS HAPPEN TILL SECOND LAST INDEX
                    {
                        if ( arr[j] > arr[j+1])
                        {
                     int temp = arr[j];
                    arr[j]= arr[j+1];
                    arr[j+1]= temp;
                       
                        }
                    }
                    
                }
            }
