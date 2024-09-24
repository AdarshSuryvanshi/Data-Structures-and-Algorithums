#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<" Enetr the value of n";
    cin>>n;
    int arr[n];

    for ( int i =0; i<n ;i++)
    {
        cin>>arr[i];
    }

    int largest = arr[0];
        for ( int i =0; i<n ;i++)
    {
        if ( largest < arr[i]){

            largest =arr[i];
        }
    }
    cout<<" Largest element inthe arraya is \n"<<largest;

    
        


}