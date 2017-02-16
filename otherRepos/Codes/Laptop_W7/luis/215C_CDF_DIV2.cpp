#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

char s[ N ];
int X[ N ] , Y[ N ] , Z[ N ];
int main()
{
	while( scanf( "%s" , s ) == 1 ){
		int ns = strlen( s );
		REP( i , ns ) X[ i + 1 ] = X[ i ] + (s[i] == 'x'); 
		REP( i , ns ) Y[ i + 1 ] = Y[ i ] + (s[i] == 'y'); 
		REP( i , ns ) Z[ i + 1 ] = Z[ i ] + (s[i] == 'z');
		int Q;
		sc( Q );
		while( Q-- ){
			int x , y ;
			sc( x ) , sc( y );
			int cntx = X[ y ] - X[ x - 1 ];
			int cnty = Y[ y ] - Y[ x - 1 ];
			int cntz = Z[ y ] - Z[ x - 1 ];
			int sz = y - x + 1 ;
			if( sz <= 2 ){
				puts( "YES" );
				continue;
			}
			if( sz%3 == 0 ){
				puts( (cntx == sz/3 && cnty == sz/3 && cntz == sz/3) ? "YES":"NO" );
				continue;
			}
			if( sz%3 == 1 ){
				puts( (cntx == sz/3 && cnty == sz/3 && cntz == sz/3 + 1) ||
					  (cntx == sz/3 && cnty == sz/3 + 1 && cntz == sz/3) || 
					  (cntx == sz/3 + 1 && cnty == sz/3 && cntz == sz/3) ? "YES":"NO" );
				continue;
			}
			if( sz%3 == 2 ){
				puts( (cntx == sz/3 && cnty == sz/3 + 1 && cntz == sz/3 + 1) ||
					  (cntx == sz/3 + 1 && cnty == sz/3 && cntz == sz/3 + 1) || 
					  (cntx == sz/3 + 1 && cnty == sz/3 + 1 && cntz == sz/3) ? "YES":"NO" );
				continue;
			}
		}
	}
}


