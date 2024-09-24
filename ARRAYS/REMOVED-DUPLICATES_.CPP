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

    int i = 0; // 1st  UNIQUE  ELEMENT FOR SURE IS ELEMENT AT 0TH INDEX
    
    for ( int j = 1; j<n ;j++)
    {
        if ( arr[i] != arr[j])
        {
            i++;
            arr[i+1] = arr[j];
        }
    } 
      for ( int i =0; i<n ;i++)
    {
        cout<<arr[i];
    }
}
    