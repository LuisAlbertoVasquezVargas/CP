#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string s;
int main()
{
     while(1)
     {
          cin >> s;
          if( s == "#" ) break;
          vector<char>v;
          int n = s.size() ;
          
          for( int i = 0 ; i < n ; ++i )
               v.push_back(s[i]);
               int cont = 0;
          do
          {
               if( cont == 1 )
               {
                    for( int i = 0 ; i < n ; ++i )
                         cout<<v[i];               
                    cout<<endl;
               }
               cont++;
               if (cont > 2 )break;
          }
          while(next_permutation(v.begin(),v.end()));
          if( cont == 1 )
               cout<<"No Successor\n";               
     }     
}
