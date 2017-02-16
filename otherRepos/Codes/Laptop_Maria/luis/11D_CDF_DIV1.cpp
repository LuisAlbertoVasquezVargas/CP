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
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 19
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , tail ;
vvi ADJ;
ll memo[ 1<<N ][ N + 5 ];

ll dp( int mask , int last )
{
	if( mask&(1<<tail) )return ones( mask ) > 2 ;
	ll &dev = memo[ mask ][ last ];
	if( dev == -1 )
	{
		dev = 0;
		FOR( v , ADJ[last] ) 
			if( *v >= tail && (mask&( 1 << *v )) == 0 )dev += dp( mask xor ( 1 << *v ) , *v );			
	}
	return dev;
}
int main()
{
	while( sc( n ) == 1 )
	{
		sc( m );
		ADJ.clear();
		ADJ.resize( n );
		REP( i , m )
		{
			int x , y;
			sc( x ) , sc( y );
			x -- , y --;
			ADJ[ x ].pb( y );
			ADJ[ y ].pb( x );
		}
		ll ans = 0;
		REP( i , n )
		{
			me( memo , -1 );
			tail = i;
			ans += dp( 0 , i );
		}
		cout << ans/2 << '\n';
	}
}

