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

    int smallest = arr[0];  // 1ST WE ASSUME 0 TH INDEX IS SMALL THEN CHECK ALL INDEX IF FIND 
    int Second_smallest =INT_MAX;
        for ( int i =0; i<n ;i++) // ANYONE SMALLER THEN ELEMENT OF 0TH INDEX 
    {               
        if (arr[i] < smallest){

            Second_smallest = smallest;
            Second_smallest = arr[i];
        
        }
    }
    cout<<" smallest element inthe arraya is \n"<<smallest;
    
    cout<<"  Second smallest element inthe arraya is \n"<<Second_smallest;

    
        


}