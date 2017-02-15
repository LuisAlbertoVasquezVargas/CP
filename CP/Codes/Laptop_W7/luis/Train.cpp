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
#define EPS (1e-5)

using namespace std;

double cte = 10.0/36.0;
double a1 = 2.7*cte , a2 = 3.8*cte;
double v = 25;
double t1 = ( v/a1 ), t2 = ( v/a2 );
double x = ( 0.5*( a1*t1*t1 + a2*t2*t2 ) );
string s;
int f( int t )
{
	if( t > x ) return (int)round( t1 + t2 + (t - x)/v  );
	return (int)round( sqrt( 2*t*( 1/a1 + 1/a2 ) ) );
}
int a[ 100 ][ 100 ] , b[ 100 ][ 100 ];
void solve( int n , int nv , vi V )
{
	REP( k , n )
	{
		printf( "%d : *****" , k + 1 );
		if( k == 0 )
		{
			int t = 1;
			for( int i = 1 ; i <= nv ; ++i )
			{
				a[ k ][ i ] = t , b[ k ][ i ] = t + f( V[ i - 1 ] );
				printf( " - %5d  %5d" , a[ k ][ i ] , b[ k ][ i ] );
				t = b[ k ][ i ] + 121 ;
			}
		}
		else
		{
			for( int i = 1 ; i <= nv ; ++i )
			{
				if( nv == 1 )
				{
					a[ k ][ i ] = b[ k - 1 ][ i ] + 1;
					b[ k ][ i ] = a[ k ][ i ] + f( V[ i - 1 ] );	
				}
				else if( i == 1 )
				{
					a[ k ][ i ] = a[ k - 1 ][ i + 1 ] + 1;
					b[ k ][ i ] = a[ k ][ i ] + f( V[ i - 1 ] );
				}
				else if( i == nv )
				{
				 	a[ k ][ i ] = max( b[ k ][ i - 1 ] + 121 , b[ k - 1 ][ i ] + 1 );
				 	b[ k ][ i ] = a[ k ][ i ] + f( V[ i - 1 ] );
				}
				else
				{
					a[ k ][ i ] = max( b[ k ][ i - 1 ] + 121 , a[ k - 1 ][ i + 1 ] + 1 );
					b[ k ][ i ] = a[ k ][ i ] + f( V[ i - 1 ] );
				}
				printf( " - %5d  %5d" , a[ k ][ i ] , b[ k ][ i ] );
			}
		}
		puts( " *****" );
	}
}
void doit()
{
	int ns = s.size();
	REP( i , ns ) if( isdigit( s[ i ] ) || s[ i ] == ' ' )continue;
	else
	{
		puts( "ERROR" );
		return;
	}
	istringstream in( s );
	int n , t;
	in >> t;
	if( t >= 1 && t <= 5 ) t++;
	else
	{
		puts( "ERROR" );
		return;
	}
	vi V;
	while( in >> n )
		V.pb( n );
	n = V.size();
	if( n >= 1 && n <= 5 ) n++;
	else
	{
		puts( "ERROR" );
		return;
	}
	if( accumulate( all( V ) , 0 ) != 100000 )
	{
		puts( "ERROR" );
		return;
	}
	n = --t;
	int nv = V.size();
	REP( i , nv ) if( V[ i ] < 500 )
	{
		puts( "ERROR" );
		return;
	}
	solve( n , nv , V );
}
int main()
{
	while( getline( cin , s ) )
		doit();
}

