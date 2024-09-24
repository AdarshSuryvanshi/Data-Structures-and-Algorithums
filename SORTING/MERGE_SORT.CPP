#include <iostream>
#include <bits/stdc++.h> 
void merge_sort( vector<int>&arr,int low ,int high);
  void merge( vector<int>& arr ,int low , int mid ,int high);

using namespace std;
int main()
{
        vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    merge_sort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;


}
    
    void merge_sort( vector<int>&arr , int low ,int high)
    {
        int mid = (low + high )/2 ;
        merge_sort( arr,low,mid);
        merge_sort(arr, (mid+1) ,high);
        merge( arr,low , mid, high);
        
    }

    void merge( vector<int>& arr ,int low , int mid ,int high)
    {
        if ( low >= high){
            
            return ;
        }
        else{
               int left = low;
              int  right = mid+1;
              vector<int>temp;

            while(left <= mid && right <= high )
            {
                if ( arr[left] <= arr[right])
                {
                    temp.push_back( arr[left]);
                    left++;

                }
                else {

                    temp.push_back(arr[right]);
                    right++;
                }
            }

            while ( left <= mid)
            {
                temp.push_back( arr[left]);
                    left++;
            }
            while( right <= high)
            {
                 temp.push_back(arr[right]);
                    right++;
            }

            for( int i =low; i< high;i++)
            {
                arr[i]=temp [i - low];
            }
        }
        
    }
    