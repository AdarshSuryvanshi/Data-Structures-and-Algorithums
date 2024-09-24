


#include <bits/stdc++.h>
using namespace std;

int getSingleElement(int arr[], int N) ;

int main()
{
             int N;
    cout<<"Entre the no of elemts of array";cin>>N;
        
    int arr[N];
     cout << "Enter elements of the  array: ";

    for (int i = 0; i < N; i++)
     {
        cin >> arr[i];
    }

    int ans = getSingleElement(arr,N);
    cout << "The single element is: " << ans << endl;
    return 0;
}
int getSingleElement(int arr[], int N) {
    //size of the array:
    

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < N; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}




