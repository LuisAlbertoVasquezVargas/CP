#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<vector>
#include<utility>

using namespace std;
int n,m,it = 0;
string s,p[1000],t;
double a,b;
bool ok = 1;
bool caso()
{
     cin >> n >> m;
     if( n == 0 ) return 0;
     if(ok) ok = 0;
     else 
          cout<<"\n";     
     getline(cin,s);     

     for( int i = 0 ; i < n ; ++i )
          getline(cin,s);

     vector< pair <double,pair<double,int> > >v(1000);             
     for( int i = 0 ; i < m ; ++i )
     {
          getline(cin,p[i]);          
          cin >> a >> b;
          getline(cin,t);            
          for( int j = 0 ; j < b ; ++j )
               getline(cin,t);            

          v[i] = make_pair( -b,make_pair(a,i));
     }
     sort(v.begin(),v.begin()+m);
     cout<<"RFP #"<<++it<<"\n"<<p[v[0].second.second]<<"\n";
     return 1;
}
int main()
{
     while(caso());
}
