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

#define N 20
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
int A[ N ] , P[ N*N ];

bool valid1()
{
	bool inc = 0;
	int j = -1; 
	for( int i = 1 ; i <= n ; ++i )
		if( !A[i] )
		{
			inc = 1, j = i;
			break;
		}
	bool solve = 1;
	for( int i = 1 ; i < j  ; ++i )
		if( !P[ A[i] + A[(i+1)%n] ] ) solve = 0;
	if( j == -1 && !P[ A[1] + A[n] ] ) solve = 0;
	if( inc )return 1;
	return solve;
}

bool valid2()
{
	bool solve = 1;
	for( int i = 1 ; i < n  ; ++i )
		if( !P[ A[i] + A[i+1] ] ) solve = 0;
	if( !P[ A[1] + A[n] ] ) solve = 0;
	return solve;
}


bool prime( int x )
{
	for( int i = 2 ; i*i <= x ; ++i )
		if( x%i == 0 )return 0;
	return 1;
}

void out()
{
	for( int i = 1 ; i <= n ; ++i ) printf( "%d%s" , A[i] , i==n?"\n":" " );
}

void f( int mask , int pos )
{
	//cout << mask << " " << pos << endl;
	if( pos == n + 1 )return;
	if( !valid1() )return;
	if( ones( mask ) == n )
	{
		if( valid2() )
			out();
		return ;
	}
	for( int i = 2 ; i <= n ; ++i )
		if( ( mask &( 1 << i ) ) == 0 )
		{
			if( !P[ A[ pos ] + i ] )continue;
			A[ pos + 1 ] = i ;
			f( mask | ( 1 << i ) , pos + 1 );
			A[ pos + 1 ] = 0;
		}
}

int main()
{
	REP( i , 50 )
		if( prime(i) ) P[i] = 1;
	int tc = 0;
	bool ok = 0;
	while( sc( n ) == 1 )
	{
		if( !ok ) ok = 1;
		else puts( "" );
		me( A , 0 );
		A[1] = 1;
		printf( "Case %d:\n" , ++tc );
		f( 1<<1 , 1 );
	}
}

