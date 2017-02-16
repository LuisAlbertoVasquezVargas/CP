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

#define MAXN 1000000

using namespace std;

int n,nv;
long long x;
bool prime[MAXN+1];
vector<long long>p;
set<long long>S;
void sieve()
{
	memset(prime, true, sizeof(prime));
	
	prime[0] = false;
	prime[1] = false;
	
	for(int i=2; i*i<=MAXN; i++)
		if(prime[i])
			for(int j=i*i; j<=MAXN; j+=i)
				prime[j]=false;
     for( int i = 2 ; i < MAXN ; ++i )
          if( prime[i] )
               p.push_back(i);
     nv = p.size();
}

int main()
{
     sieve();
     while( cin >> n )
     {
          for( int i = 0 ; i < n ; ++i )
          {
               cin >> x;
               if( x < MAXN && prime[x] )
                    cout<<"NO"<<endl;
               else
               {
                    long long sq = (long long)(sqrt(x)+0.5);
                    if( sq*sq == x && prime[sq] )
                         cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
               }
          }
     }
}
