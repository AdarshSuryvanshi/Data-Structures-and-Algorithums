#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout<<" enetr the string you want";
    cin>>s;
    
    //PRE COMPUTING /PRECALCULATION

     map<char,int>mpp;

     for( int i =0;i<s.size() ;i++)
     {
        mpp[s[i]]++; // WHEN YOUR  ALPHABETMATCH WITH YOUR ARRAY IT WILL +1 TO VALUE
     }

     int Q;
     cout<<" Enetr how much qerise you want";
     cin>>Q;
      while(Q--)
      {
        char ch;
        cout<<" Enetr the alphabet which you want to check";
        cin>>ch;

        cout<<" The apred is "<<mpp[ch]<<" Timse"<<endl;
      }

    

}