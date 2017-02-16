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

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int m , n ;
double memo[ N ][ N ];
bool done[ N ][ N ];
int P[ N ] , I[ N ] , t[ N ];

double dp( int pos , int money )
{
	if( pos == n ) return 0;
	double &dev = memo[ pos ][ money ];
	if( !done[ pos ][ money ] )
	{
		done[ pos ][ money ] = 1;
		dev = 0;
		for( int s = 0 ; s <= money ; ++s )
			dev = max( dev , round( ( I[ pos ] + 1.0*t[ pos ]*s/( 10.1 + s ) )*P[ pos ]/100.0 ) + dp( pos + 1 , money - s ) );
	}
	return dev;
}
string tos( int x )
{
	stringstream out;
	out << x;
	return out.str();
}
string f( int pos , int money )
{
	if( pos == n ) return "";
	double dev = dp( pos , money );
	int u = -1;
	for( int s = 0 ; s <= money ; ++s )
	{
		double temp = round( ( I[ pos ] + 1.0*t[ pos ]*s/( 10.1 + s ) )*P[ pos ]/100.0 );
		if( dev == temp + dp( pos + 1 , money - s ) ) u = s;
	}
	if( u == -1 ) return "";
	return tos( pos ) + ":" + tos( u ) + ( pos + 1 == n ? "": " " ) + f( pos + 1 , money - u );
}
int main()
{
	int tc = 1;
	while( scanf( "%d%d" , &m , &n ) == 2 )
	{
		if( n == 0 && m == 0 )break;
		REP( i , n )
			scanf( "%d%d%d" , &P[ i ] , &I[ i ] , &t[ i ] );
		clr( done , 0 );
		printf( "Case %d: %d\n" , tc++ , (int)round( dp( 0 , m ) ) );
		printf( "%s\n" , f( 0 , m ).c_str() );
	}
}


