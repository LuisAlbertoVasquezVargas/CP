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
#include <climits>
#include <cctype>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 10
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
void f( vector< string > s )
{
	for( int i = 0 ; i < N/2 ; ++i )
		if( i == 0 )
			cout << "(" << s[i];
		else if( i == N/2 - 1 )
			cout << ", " << s[i] << ")" << endl;
		else cout << ", " << s[i];	
}
int main()
{
	int tc;
	while( cin >> tc )
	{
		for( int t = 0 ; t < tc ; ++t )
		{
			vector< string >s(N);
			vi A(N) , D(N);
			for( int i = 0 ; i < N ; ++i )
				cin >> s[i] >> A[i] >> D[i];
			vi v(N,0);
			for( int i = 5 ; i < N ; ++i )v[i] = 1;
			int bestA = 0 , bestD = 0;
			vector< string > bestA_( 5 , string( 1 , 'z' + 1) ),bestD_;
			do
			{
				int cntA = 0 , cntD = 0;
				vector<string>temp,temp2;
				for( int i = 0 ; i < N ; ++i )
					if( v[i] ) cntA += A[i] , temp.pb(s[i]);
					else	cntD += D[i], temp2.pb(s[i]);
				sort( all( temp ) );
				sort( all( temp2 ) );				
				if( cntA > bestA )
				{
					bestA = cntA;
					bestD = cntD;
					bestA_ = temp;
					bestD_ = temp2;
				}
				else if( cntA == bestA )
				{
					if( cntD > bestD )
					{
						bestD = cntD;
						bestA_ = temp;
						bestD_ = temp2;						
					}
					else if( cntD == bestD )
					{
						if( temp < bestA_ )
						{
							bestA_ = temp;
							bestD_ = temp2;							
						}
					}
				}
			}while( next_permutation( all(v) ) );
			cout << "Case " << t + 1 << ":" << endl;
			f( bestA_ );
			f( bestD_ );
		}	
	}
}
