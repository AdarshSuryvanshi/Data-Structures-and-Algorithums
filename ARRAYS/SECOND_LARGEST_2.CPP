#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<" Enetr the value of n";
    cin>>n;
    int arr[n];

    for ( int i =0;i<n ; i++)
    {
        cin>>arr[i];
    }
     // FIND THE LARGEST ELEMENT
    int largest = arr[0];
      for ( int i =0;i<n ; i++)
    {
        if ( largest < arr[i]) // IF SOMEONE GREATER THEN LARGEST CONDITION TRUE
        {
            largest = arr[i];
            
        }
    }
    cout<<" Largest element is \n"<<largest;

        int Second_largest = -1;

        for (int i =0; i<n ;i++){
            
            if( Second_largest < arr[i] && arr[i] != largest)
            {
                Second_largest = arr[i];
            }
        }
    cout<<" Second largest element is \n"<<Second_largest;
    
    
}