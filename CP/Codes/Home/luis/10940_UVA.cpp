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

#define N 500005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;


int J( int n , int k , int i )
{
	/*
	if( i == 1 )return ( k - 1 )%n;
	return ( k + J( n - 1 , k , i - 1 ) )%n;
	*/
	int s = ( k - 1 )%( n - i + 1 ); 
	for( int I = 2 ; I <= i ; ++I )
		s = ( k + s )%( n + I - i );
	return s;
}

int main()
{
	int n;
	/*int V[N];
	for( int i = 100000 ; i <= 500000 ; ++i ) V[i] = J( i , 2 , i );
	test*/
	while( sc( n ) == 1 )
	{
		if( !n )break;
		int p = 31 - __builtin_clz( n );
		int X = ( (n^(1<<p))<<1 );
		printf( "%d\n" , (X==0)?n:X );
	}
}


