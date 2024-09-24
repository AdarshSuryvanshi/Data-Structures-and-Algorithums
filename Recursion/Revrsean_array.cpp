#include <iostream>
using namespace std;
void f( int i,int arr[],int n);
int main()
{
    int n;
    cout<<" The enter value is";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    f(0,arr,n);   //CALL THE FUNCTION
        for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

}
void f( int i,int arr[],int n)
{
    if( i>=n/2)
    {
        return;
    }
    else{
        swap( arr[i],arr[n-i-1]);

        f( i+1,arr,n);
    }
}

    
 




