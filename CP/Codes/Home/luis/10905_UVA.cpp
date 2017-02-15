#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool cmp( string si,string sj )
{
     string p = si + sj;
     string t = sj + si;     
     return p > t;
}
bool caso()
{
     int n;
     cin >> n ;
     if( n == 0 ) return 0;
     vector<string> v(50);     
     for( int i = 0 ; i < n ; ++i )
          cin >> v[i];
     sort(v.begin(),v.begin()+n,cmp);
     for( int i = 0 ; i < n ; ++i )
          cout<<v[i];
     cout<<"\n";
     return 1;
}
int main()
{
     while(caso());     
}
