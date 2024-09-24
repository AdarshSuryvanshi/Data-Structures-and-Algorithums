#include<iostream>
using namespace std;
int search(int arr[],int n,int num);
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
    int num;
    cout<<" Enetr the no you want search from this given array";
    cin>>num;
    int val = search(arr,n,num);
    cout<<val;
}

int search(int arr[],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==num) // THIS IS THE PERFECT EXAMPLE WERE YOU GOT THE CORRECT INDEX AND ALSO
        return i;       // GOT -1 IF ELEMENT DOES NOT OCURRED IN THE ARRAY..
    }
    return -1;
}
