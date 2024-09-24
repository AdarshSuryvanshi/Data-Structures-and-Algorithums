//1ST WAY
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> sorted_arrays(int arr1[],int arr2[] ,int n, int m);
int main()
{
    int n;
    cout<<"Entre the no of elemts of array1";cin>>n;
        
    int arr1[n];
     cout << "Enter elements of the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    int m;
    cout<<"Entre the no of elemts array2";cin>>m;

      int arr2[m];

    cout << "Enter elements of the second array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

     vector<int> Intersection =     sorted_arrays(arr1,arr2 ,n,m);

}
vector<int> sorted_arrays(int arr1[],int arr2[] ,int n, int m){

    int visited[m]={0};
    vector<int> ans;
    for(int i =0 ;i< n;i++ ) // ARRY1 OF 0TH INDEX WILL CHECK WITH ALL INDEX OF ARRAY2 ..FIND 
    { // THE COMMON THEN AGAIN ARRY1 OF 1ST INDEX WILL CHECK WITH ALL INDEX OF ARRAY2.SO
        for(int j =0; j<m ;j++) // THIS PROCESS WILL GO ON TO (N-1 )OF ARRAY1
        {
            if( arr1[i]==arr2[j] && visited[j]==0) // ELEMNT IS COMMOM AND UNIQUE IT SHOULD NOT 
            {           // BE REPEATED ...
                ans.push_back(arr1[i]);
                visited[j]=1;
                break;
            }
            if (arr2[j] > arr1[i]) // IF YOU GO BEYOND ARR1 NO LOGIC TO CHECK COMMON ELEMENTS
            {
                break;
            }
        }
    }
         cout<<" This are all the intersection elemnts are here";


    return ans;


}
// TYPE 2  :- 2ND WAY

/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sorted_arrays(int arr1[],int arr2[] ,int n, int m);
int main()
{
    int n;
    cout<<"Entre the no of elemts of array1";cin>>n;
        
    int arr1[n];
     cout << "Enter elements of the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    int m;
    cout<<"Entre the no of elemts array2";cin>>m;

      int arr2[m];

    cout << "Enter elements of the second array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

     int Intersection =     sorted_arrays(arr1,arr2 ,n,m);

}
int sorted_arrays(int arr1[],int arr2[] ,int n, int m){

    int visited[m]={0};
    int ans[m];
    for(int i =0 ;i< n;i++ ) // ARRY1 OF 0TH INDEX WILL CHECK WITH ALL INDEX OF ARRAY2 ..FIND 
    { // THE COMMON THEN AGAIN ARRY1 OF 1ST INDEX WILL CHECK WITH ALL INDEX OF ARRAY2.SO
        for(int j =0; j<m ;j++) // THIS PROCESS WILL GO ON TO (N-1 )OF ARRAY1
        {
            if( arr1[i]==arr2[j] && visited[j]==0) // ELEMNT IS COMMOM AND UNIQUE IT SHOULD NOT 
            {           // BE REPEATED ...
                ans[i] = arr1[i];
                visited[j]=1;
                break;
            }
            if (arr2[j] > arr1[i]) // IF YOU GO BEYOND ARR1 NO LOGIC TO CHECK COMMON ELEMENTS
            {
                break;
            }
        }
    }
         cout<<" This are all the intersection elemnts are here";

    for(int i =0;i<n;i++)
    {
    cout<<ans[i];
    }

    return 0;


}
*/



    



