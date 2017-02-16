#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<utility>
#include<vector>

using namespace std;
string s,t,p,q;
string f(string s)
{
     int n = s.size();
     for( int i = 0; i < n ; ++i )
          s[i] = toupper(s[i]);
     return s;
}
void caso()
{
     getline(cin,s);
     getline(cin,s);
     int n,m,b,x,y;
     cin >> n >> m >> b;
     map<string,int>M;          
     for( int i = 0 ; i < n ; ++i )
     {
          cin >> t >> x;
          M[t] = x;
     }
     vector< pair<int,string> >v;     
     for( int i = 0 ; i < m ; ++i )
     {    
          getline(cin,p);          
          getline(cin,p);
          int r;
          cin >> r;
          int cost = 0;
          for( int j = 0 ; j < r ; ++j )
          {
               cin >> q >> y;
               cost+=M[q]*y;
          }
          if( cost <= b )
          {
               v.push_back(make_pair(cost,p));
          }  
     }
     sort(v.begin(),v.end());
     int L = v.size();
     cout<<f(s)<<endl;
     if( L == 0 )
     {
          cout<<"Too expensive!\n\n";
     }
     else
     {
          for( int i = 0 ; i < L ; ++i )
               cout<<v[i].second<<endl;
          cout<<endl;
     }   
}
int main()
{
     int t;
     cin >> t;
     for( int i = 0 ; i < t ; ++i )     
          caso();
}
