//TO CHECK HOW MANY TIMSE YOUR ENTRED DIGIT IS APPRED IN A GIVEN ARRAY
#include <iostream>
using namespace std;
int fun(int n,int arr[]);
int count=0; // TO COUNT YOUR ENTRED DIGIT IS MANY TIMES ENTER IN A GIVEN ARRAY
int main()
{
    int n , arr[20]= { 1,3,1,2,2,5};
    cout<<" The  n is";
    cin>>n;
    cout<<" the n appered is "<<" "<<fun(n,arr);
    
}
int fun( int n,int arr[])
{
    for (int i =0 ; i<20;i++) //   THIS CODE IS FOR HOW MANY TIMES THE ARRAY WHICH
    {                       // I HAVE TAKE HERE .THE N NUMBER WHICH I TAKE INPUT
        if (n == arr[i] )   //WILL GIVE ME HOW MANY TIMES THAT NUMBER WILL 
        {                   // APPERED IN THIS ARRAY
            count++;
        }
      
    }
      
            return count;

    
}
