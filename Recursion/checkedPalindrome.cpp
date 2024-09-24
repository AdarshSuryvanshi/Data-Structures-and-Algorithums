#include<iostream>
using namespace std;
bool fun( int i, string &s); //FOR TRUE AND FALSE
int main()
{
  string s = "madam";
    cout<<" The string is "<<fun(0,s);

}
bool fun( int i, string &s)
{
    if(i>= s.size()/2)
    {
        return true;
    }
    else{
        if(s[i] !=s[ s.size()-i-1] )
        {
            return false;
        }
        else{
            return fun(i+1,s);
        }
    }
}