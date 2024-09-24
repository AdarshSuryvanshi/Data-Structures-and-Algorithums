#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

  // COMPILER WANTS EVRY NUMBER HAVE COUNT 2 ...IF SOMEONE HAVE ONLY 1 IT WILL TERMINATE THAT
    for(int i =0 ;i<n ;i++) // LOOP GO BELOW PRINT THAT NUMBER SAYS THIS IS THE NUMBER OCCURED
    {//                 AT ONCE... FOR EG ARR[] {1 1 2 3 3} THE NO 1 &3 HAVE 
        int num= arr[i]; // COUNT 2 BUT 2 HAS COUNT 1 SO COMPILER GO BELOW PRINT 2.. 
          int count =0;
        for (int j =0 ;j<n ;j++)
        {
            if ( arr[j]==num)
            {
                count++;
            }
        }

        if (count ==1){

            cout<<" this is the no which is occured at once" <<num;
            break;
        }
    }
}
