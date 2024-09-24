#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<" Enetr the n";
    cin>>n;
    int arr[n];

    for ( int i =0;i<n ;i++)
    {
        cin>>arr[i];
    }
    int arr2[n];

   int temp = arr[n-1]; // WE HAVE STORED ELEMENT OF N-1TH INDEX IN TEMP VARAIBLE

   for ( int i = n-1 ;i > 1 ; i--) // 0TH INDEX TOH TEMP MAI GAYA SO START FROM 1ST INDEX TILL (N-1)
   {

    arr2[i-1]=arr[i]; // ALL ELEMENTS WILL STORE ONE STEP BACWARD INDEX IN ARRAY

   } 
    arr2[0] = temp; // ELEMENT OF N-1TH INDEX STORED IN ZEROTH INDEX

    cout<<" Elements after the Rotating array to left by 1 place ";

        for ( int i = 0; i<n ;i++)
    {
        cout<<arr2[i];
    }

}