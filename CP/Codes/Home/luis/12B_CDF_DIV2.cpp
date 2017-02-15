#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
     string s,t,p;
     while( cin >> s >> p )
     {
          sort(s.begin(),s.end());          
          int pos = 0;
          int n = s.size();
          for( int i = 0 ; i < n ; ++i )
               if( s[i] != '0' )
               {
                    pos = i;
                    break;
               }
          if( pos == 0 )
          {
               t = s;
          }else 
          {
               char c = s[pos];
               s.erase(s.begin()+pos);
               t = c + s;               
          }
          if( t == p )
               cout<<"OK\n";
          else cout<<"WRONG_ANSWER\n";               
     }
}
