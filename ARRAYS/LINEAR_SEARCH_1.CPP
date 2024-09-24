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
    int num;
    cout<<" Enetr the no you want search from this given array";
    cin>>num;
    

    for (int i =0 ;i<n ;i++)
    {
        if (arr[i]==num) // CHECKED WITH EACH ELEMENT IS EQUAL WITH NUM IF YES WRITEEN i
        {
            cout<<"The index where this num element find is"<<i;
            break;
        }
        
        
    }
    

        

}