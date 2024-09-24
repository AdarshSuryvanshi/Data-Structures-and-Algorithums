// IT IS FOR  LOWER CASE AND UPPER CASE 
// THIS CODE WILL EXCUTE UPPER AND LOWEER CASE BOTH

#include <iostream>
using namespace std;
int main()
{
    string s;
    cout<<" Enter the string  you wanted";
    cin>>s;

    // PRECOMPUTATION /PRE CALCULATIONS;
     int hash[256] ={0};
     for ( int i= 0; i< s.size();i++)
     {
        hash[s[i]]++; // IF THEY FOUND ALPHABET +1 THEY WILL DO
     }

     int Q; //QUERIES
     cout<<" Enter hoe many quesies you want";
     cin>> Q;

    while( Q--)
    {
        char ch;
        cout<<"\n Enetr the characetr \n";
        cin>>ch;
        cout<<"\nThe alphabet you appred is apred"<<hash[ch]<<" times";
    }


}
//BASICALLY IT IS GOES TO EVERY ALPHABET DIRECTLY AND PRINT THE VALUE . WHICH 
// IS OVER THERE ON THAT PARTICULAR INDEX EG= IF IS "A" SO GO TO INEX NO  65 
//  AND PRINT THE VALUE ON THAT INCEX DIRECTLY.