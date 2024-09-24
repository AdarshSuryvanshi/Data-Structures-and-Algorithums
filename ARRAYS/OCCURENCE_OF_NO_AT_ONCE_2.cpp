#include<iostream>
using namespace std;
int findOccurence (int arr[],int n);
int main()
{
         int n;
    cout<<"Entre the no of elemts of array";cin>>n;
        
    int arr[n];
     cout << "Enter elements of the  array: ";

    for (int i = 0; i < n; i++)
     {
        cin >> arr[i];
    }

    int ans = findOccurence(arr ,n);
    cout<<" The no which occured at once is  "<<ans;
}
 
 int findOccurence(int arr[] ,int n)
 {

    int large = arr[0]; // FIRST TO FIND LARGE ELEMNTS SO THAT WE CAN MAKE HASHARRAY OF THAT 
    for (int i =0 ;i<n ;i++)// ELLEMTS
    {
        if ( large <arr[i])
        {
            large = arr[i];
        } 
    }

    int Hasharray[large+1] ={0};  // MAXIMUM ELEMENT CHA INDEX BANVALA 
    for ( int i = 0;i<n ;i++)
    {
        Hasharray[arr[i]]++; //TRANSFER ELEMTS
    }

        for ( int i = 0;i<n ;i++)
    {
       if ( Hasharray[arr[i]] ==1)
       {
            return arr[i]; // RETURN THAT INDEX WERE YOU GOT THE 1 & THAT INDEX IS THE NUMBER OCCURED 
                        // AT ONCE
       }

    }

return 0;
 }