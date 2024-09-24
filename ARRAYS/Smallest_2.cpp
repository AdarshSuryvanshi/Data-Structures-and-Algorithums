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

    int smallest = arr[0]; // 1ST WE ASSUME 0 TH INDEX IS SMALL THEN CHECK ALL INDEX IF FIND 
        for ( int i =0; i<n ;i++) // ANYONE SMALLER THEN ELEMENT OF 0TH INDEX 
    {               // 
        if ( smallest > arr[i]){

            smallest =arr[i];// THAT BECOME SMALLEST ELEMENT
        }
    }
    cout<<" smallest element inthe arraya is \n"<<smallest;

    
        


}