#include<iostream>
using namespace std;
void Revrese(int arr[],int D,int n);
 void revrse( int arr[],int start,int end);


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
    Revrese(arr,D,n);
          cout<<" Elements after the Rotating array to left by D place \n";

        for ( int i = 0; i<n ;i++)
    {
        cout<< arr[i] <<" ";
    }
}
void Revrese(int arr[],int D,int n)
{
     revrse(arr ,0,D-1);
     revrse( arr ,D,n-1);
     revrse(arr,0,n-1);

}
    void revrse( int arr[],int start,int end){

          while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }


    }