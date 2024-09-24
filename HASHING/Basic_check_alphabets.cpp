//TO CHECK HOW MANY TIMSE YOUR ENTRED ALPHABET IS APPRED IN A GIVEN ARRAY
#include <iostream>
using namespace std;
int fun(char c , string &s); //ARRAYS AND STRING IS CALL BY REFRENCE
int count=0; // TO COUNT YOUR ENTRED ALPHABET IS MANY TIMES ENTER IN A GIVEN ARRAY
int main()
{
    char c;
    cout<<" enetr the character you want to check";
    cin>>c;
    string s ="ababacd";
    cout<<"the character apred is \n"<< fun(c,s);    
}
int fun( char c, string &s)
{
    for (int i =0 ; i<s.size();i++) //   THIS CODE IS FOR HOW MANY TIMES THE ARRAY WHICH
    {                       // I HAVE TAKE HERE .THE ALPHABET WHICH I TAKE INPUT
        if (s[i]==c )   //WILL GIVE ME HOW MANY TIMES THAT ALPHABET WILL 
        {                   // APPERED IN THIS ARRAY
            count++;
        }
      
    }
      
            return count;

    
}