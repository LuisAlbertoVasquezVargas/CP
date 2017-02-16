#include<iostream>
#include<vector>

using namespace std;

int k,n,m;
long long cont;
string s;
vector<long long>v;
long long tri(long long x)
{
     x*=(x+1);
     return x/2;
}
int main()
{
     while( cin >> k >> s)
     {
          v.clear();
          n = s.size();
          for( int i = 0 ; i < n ; ++i )
               if(s[i] == '1')v.push_back(i);
          m = v.size();
          cont = 0;
          if( k == 0 )
          {
               for( int j = 1 ; j < m ; ++j )
                    cont+=tri(v[j]-v[j-1]-1);
//               cout<<cont<<endl;
//               cout<<tri(v[0])<<" "<<tri(n-1-v[m-1])<<endl;
               if(m)
                    cont+=tri(v[0])+tri(n-1-v[m-1]);
               else cont = tri(n);
          }else
               for( int i = 0 , j = k - 1 ; j < m ; ++i,j = i + k - 1 )
               {
                    long long a = (i==0?0:v[i-1]+1);
                    long long b = (j==m-1?n-1:v[j+1]-1);
                    cont += ((v[i]-a+1)*(1+b-v[j]));
               }
          cout<<cont<<endl;
     }     
}
