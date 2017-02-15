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

int X[ N ] , Y[ N ];
int main()
{
	sync;
	int n;
	while( sc( n ) == 1 )
	{
		REP( i , n ) sc( X[ i ] ) , sc( Y[ i ] );
		pii p[ n ];
		REP( i , n ) p[ i ] = mp( abs(X[ i ]) + abs(Y[ i ]) , i );
		sort( p , p + n );
		int ans = 0;
		REP( i , n )
		{
			int ind = p[ i ].se;
			if( X[ ind ] == 0 )
				ans += 4;
			else if( Y[ ind ] == 0 )
				ans += 4;
			else ans += 6;
		}
		printf( "%d\n" , ans );
		REP( i , n )
		{
			int ind = p[ i ].se;
			if( X[ ind ] == 0 )
			{
				printf( "1 %d %c\n" , abs( Y[ ind ] ) , Y[ ind ] >0?'U':'D' );
				puts( "2" );
				printf( "1 %d %c\n" , abs( Y[ ind ] ) , Y[ ind ] >0?'D':'U' );
				puts( "3" );
			}
			else if( Y[ ind ] == 0 )
			{
				printf( "1 %d %c\n" , abs( X[ ind ] ) , X[ ind ] >0?'R':'L' );
				puts( "2" );
				printf( "1 %d %c\n" , abs( X[ ind ] ) , X[ ind ] >0?'L':'R' );
				puts( "3" );
			}
			else
			{
				printf( "1 %d %c\n" , abs( X[ ind ] ) , X[ ind ] >0?'R':'L' );
				printf( "1 %d %c\n" , abs( Y[ ind ] ) , Y[ ind ] >0?'U':'D' );
				puts( "2" );
				printf( "1 %d %c\n" , abs( X[ ind ] ) , X[ ind ] >0?'L':'R' );
				printf( "1 %d %c\n" , abs( Y[ ind ] ) , Y[ ind ] >0?'D':'U' );
				puts( "3" );
			}
		}
	}
}


