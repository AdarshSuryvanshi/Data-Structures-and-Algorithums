#include<iostream>
#include <bits/stdc++.h>
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
    map <int,int> mpp; // IT CONTAINS A KEY AND VALUE

        for (int i =0 ;i<n; i++)
        {
            mpp[arr[i]]++; // ++ WILL GO TO THAT PARTICULAR INDEX INCREASED THAT ELEMENTS BY 1
                             // IT CONTAINS KEY=ACTUAL INTEGER && VALUE = FREAUENCY(OCUURENCE)
        }

        for (auto it : mpp)
        {   
            
            if (it .second == 1){ // SECOND MEANS VALUE ...& FIRST MEANS  KEY (JISKA VALUE 1 USKA )

                return it.first;// KEY KO PRINT KARO
            }
        
        }

  return 0;
 }