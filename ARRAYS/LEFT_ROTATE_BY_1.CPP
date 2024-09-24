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

   int temp = arr[0]; // WE HAVE STORED ELEMENT OF 0TH INDEX IN TEMP VARAIBLE

   for ( int i = 1 ;i< n ; i++) // 0TH INDEX TOH TEMP MAI GAYA SO START FROM 1ST INDEX TILL (N-1)
   {

    arr2[i-1]=arr[i]; // ALL ELEMENTS WILL STORE ONE STEP BACWARD INDEX IN ARRAY

   } 
    arr2[n-1] = temp; // ELEMENT OF 0HT INDEX STORED IN LAST INDEX

    cout<<" Elements after the Rotating array to left by 1 place ";

        for ( int i = 0; i<n ;i++)
    {
        cout<<arr2[i];
    }

}