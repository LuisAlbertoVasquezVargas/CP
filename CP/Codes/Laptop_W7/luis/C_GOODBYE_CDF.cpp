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

#define N 300005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int A[ N ] , B[ N ] , p[ N ];

bool cmp( int i , int j ){
	return A[ i ] < A[ j ];
}
int main()
{
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ) sc( A[ i ] );
		REP( i , n ) p[ i ] = i;
		sort( p , p + n , cmp );
		sort( A , A + n );
		int Limit = A[ 0 ] - 1;
		REP( i , n ){
			int ind = upper_bound( A , A + n , A[ i ] ) - A;
			if( A[ i ] > Limit ){
				for( int j = i ; j < ind ; ++j ) 
					B[ p[ j ] ] = A[ i ] + j - i;
				Limit = B[ p[ ind - 1 ] ];
			}
			else
			{
				for( int j  = i ; j < ind ; ++j )
					B[ p[ j ] ] = Limit + j - i + 1;
				Limit = B[ p[ ind - 1 ] ];
			}
			i = ind - 1;
		}
		REP( i , n ) printf( "%d%s" , B[ i ] , i + 1 == n ? "\n":" " );
	}
}


