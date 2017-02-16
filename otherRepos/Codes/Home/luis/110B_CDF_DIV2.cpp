#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define PI 3.141592653589793

using namespace std;

int n,x;
vector<int>v;

int main()
{
     while( cin >> n )
     {
          v.clear();
          for( int i = 0 ; i < n ; ++i )
          {
               cin >> x;
               v.push_back(x);
          }
          sort(v.rbegin(),v.rend());
          int s = 0;
          for( int i = 0 ; i < n ; ++i )
               if( i&1 )
                    s-=v[i]*v[i];
               else
                    s+=v[i]*v[i];
          printf("%.10lf\n",PI*s);
     }
}
