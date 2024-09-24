#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<" Enetr the n";
    cin>>n;
    int arr[n];
    cout<<"Enetr the no of places by ehich you want to shit the array";
    int D; cin>>D;
    cout<<"Actual value of D is";
    D= D%n;
    cout<<D;

    for ( int i =0;i<n ;i++)
    {
        cin>>arr[i];
    }

    int arr2[n];
    int temp[D];
    
    for (int i =0; i<D;i++) // WE HAVE STORED ELEMENT FROM 0TH TO (D-1)TH INDEX IN TEMP
    {   
         temp[i] = arr[i];
    } 

   for ( int i = D ;i< n ; i++) // WE HAVE SHIFTED REMAING ELEMENTS FROM DTH INDEX TO (N-1)TH
   {

    arr2[i-D]=arr[i]; // ALL ELEMENTS WILL STORE D STEP BACWARD INDEX IN ARRAY

   } 
   
    for ( int i =n-D ;i<n ;i++)   // ELEMENT FROM 0TH INDEX TO (D)TH INDEX STRORED HERE
    {
        arr2[i] = temp[i-(n-D)];
        
    }

    cout<<" Elements after the Rotating array to left by D place \n";

        for ( int i = 0; i<n ;i++)
    {
        cout<< arr2[i] <<" ";
    }

}