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

    for ( int i =0 ;i<n ; i++)
    {
        if( arr[i] >= arr[i-1]){

            // NOTHING TO PRINT JUST CHECK IS MY NEXT ELEMENT GREATER THAN OR EAUAL TO ME.
        }   //  IF YES  AND ALL THE NEXT ELEMENTS ARE GREATER THEN OR EQUAL 
        // TO THEIR PREVOIUS ELEMENT THEN ARRAY IS SORTED 
        else {
                cout<<" Array is not sorted";
        }

    }
    // IN THIS IF YOU DIDN'T GET ANT ERROR IT MEANS CODE CORRCT ARRAY IS SORTED
    // IF YOU GET ANY ERROR THAT MEANS ARRAY IS NOT SORTED
    

}