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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int A[ N ];
void fill_R( int x , int t , int l , int r , int n , int k )
{
	if( x == l ) return;
	int u = t/( x - l ) , v = t%( x - l );
	REP( i , u ) A[ k + i ] = x;
	A[ k + u ] += v;
}
void fill_L( int x , int t , int l , int r , int n , int k )
{
	if( x == r )return;
	int u = t/( r - x ) , v = t%( r - x );
	REP( i , u ) A[ i ] = r ;
	A[ u ] += v;
}

void solve( int x , int sall , int sk , int l , int r , int n , int k )
{
	REP( i , n )
		if( i < k ) A[ i ] = x;
		else A[ i ] = l;
	//cout << "sall : " << sall << endl;
	fill_L( x , sk - x*k, l , r , n , k );
	fill_R( x , sall - sk - l*(n-k) , l , r , n , k );
	
	REP( i , n ) printf( "%d%s" , A[ i ] , i + 1== n ? "\n":" " );
}
int main()
{
	int n , k , l , r , sall , sk;
	while( sc( n ) == 1 ){
		sc( k ) , sc( l ) , sc( r ) , sc( sall ) , sc( sk );
		for( int x = l ; x <= r ; x++ )
			if( x*k + l*( n - k ) <= sall && sall <= r*( k - 1 ) + x*( n - k + 1 ) 
				&& x*k <= sk && sk <= r*k && ( n - k )*l <= ( sall - sk ) && ( sall - sk ) <= ( n - k )* x )
			{
				//cout << x << endl;
				solve( x , sall , sk , l , r , n , k );
				break;
			}
	}
}


