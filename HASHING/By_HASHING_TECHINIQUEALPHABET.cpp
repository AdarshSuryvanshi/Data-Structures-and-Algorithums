// IT IS ONLY FOR LOWER CASE
// THIS CODE WILL ONLY for LOWER CASE

#include <iostream>
using namespace std;
int main()
{
    string s;
    cout<<" Enter the string  you wanted";
    cin>>s;

    // PRECOMPUTATION /PRE CALCULATIONS;
     int hash[26] ={0};
     for ( int i= 0; i< s.size();i++)
     {
        hash[s[i]-'a']++; // IF THEY FOUND ALPHABET +1 THEY WILL DO
     }

     int Q; //QUERIES
     cout<<" Enter hoe many quesies you want";
     cin>> Q;

    while( Q--)
    {
        char ch;
        cout<<" Enetr the characetr \n";
        cin>>ch;
        cout<<"\nThe alphabet you appred is apred"<<hash[ch-'a']<<" times";
    }


}