#include<iostream>
#include<string>

using namespace std;

int main()
{

          string s,t;

     while( cin>>s>>t )
     {
          int n = s.size();
          int m = t.size();
          
          int i=0;     
          for( int j = 0 ; j < m ; ++j)     
               if(t[j]==s[i])i++;
               
          if( i == n ) cout<<"Yes\n";
          else cout<<"No\n";                         
     }
}
