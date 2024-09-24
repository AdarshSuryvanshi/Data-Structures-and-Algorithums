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

    int largest = arr[0];
    int Second_largest = -1; // UNLESS ARRAY SHOULD NOT CONTAING ANY NEG NUMBER.
     
    for ( int i =0;i<n ; i++)
    {
        if (arr[i] > largest)
        {
            Second_largest = largest;
            largest = arr[i]; 
        }
     else if ( arr[i] < largest && arr[i] > Second_largest)
        {
            Second_largest = arr[i];
        }


    } 
    cout<<"Largest element is \n"<<largest;
    cout<<" Second largest element is \n"<<Second_largest;
}       