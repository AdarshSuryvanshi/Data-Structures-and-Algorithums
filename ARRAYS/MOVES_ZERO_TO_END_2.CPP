#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<" enetr the n";
    cin>>n;
    int arr[n];
    for (int i =0;i<n ;i++)
    {
        cin>>arr[i];
    }

    int j= -1; // WE HAVE INITIALIZE J AS -1..IF THERE WILL BE ZERO ELEMENT IT WILL NOT EXCUTED
    for ( int i =0;i<n;i++)
    {
        if ( arr[i]==0){

            j=i;
            break;
        }
    } 

    for( int i=j+1;i<n; i++)
    {
        if ( arr[i]!=0)
        {
            swap(arr[i],arr[j]); // ITS A IN BULIT FUNCTION SWAP ANY TWO NUMBERS OR INDEX
            j++;
        }
    } 
        cout<<" after the all the zeros placing at end";
    
        for ( int i = 0; i<n ;i++)
    {
        cout<< arr[i] <<" ";
    }
}