#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#define MAXN 100000

using namespace std;

int n,m,p,q;
long long x,y,a,b,g;
long long gcd(long long a, long long b)
{
     if( b == 0 )return a;
     return gcd(b,a%b);     
}
vector < pair <long long, long long> > primeFact(long long N)
{
	vector < pair <long long, long long> > V;
	
	for(long long i=2; i*i<=N; i++)
	{
		long long a=0;
		while(N%i==0)
		{
			N/=i;
			a++;
		}
		if(a!=0) V.push_back(make_pair(i, a));
	}
	if(N>1) V.push_back(make_pair(N, 1));
	
	return V;
}
vector < long long > f(vector < pair <long long, long long> > v )
{
     int n = v.size();
     vector<long long>w;
     if( n == 0 )
     {
          w.push_back(1);
          return w;     
     }
     for( int i = 0 ; i < n ; ++i )
     {
          long long a = v[i].first;
          long long b = v[i].second;
          long long temp;
          long long cnt = 1;
          while(cnt<=b)
          {
               temp = 1;
               while(temp*a<=10000000LL&&cnt<=b)
                    temp*=a,cnt++;
               w.push_back(temp);
          }
     }
     return w;    
}
int main()
{
     while( cin >> n >> m )
     {
          x = y = 1;
          for( int i = 0 ; i < n ; ++i )
          {
               cin >> a;
               x*=a;
          }
          for( int i = 0 ; i < m ; ++i )
          {
               cin >> b;
               y*=b;
          } 
          g = gcd(x,y);
          x/=g;
          y/=g;
          vector < long long > v1 = f(primeFact(x));
          vector < long long > v2 = f(primeFact(y));
          p = v1.size();
          q = v2.size();
          cout<<p<<" "<<q<<endl;
          for( int i = 0 ; i < p ; ++i )
               cout<<v1[i]<<" ";
          puts("");
          for( int i = 0 ; i < q ; ++i )
               cout<<v2[i]<<" "; 
          puts("");              
     }
}
