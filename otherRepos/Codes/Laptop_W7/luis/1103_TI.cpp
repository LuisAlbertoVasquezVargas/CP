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

int n , ct , m ;
int X[ N ] , Y[ N ] , I[ N ];
bool solve;

void f( int k )
{
	double lo = EPS , hi = 1e9;
	REP( it , 50 )
	{
		int med = ( lo  + hi )/2;
		int cnt = 0;
		REP( i , n )
		{
			double dx = X[k] - X[i] , dy = Y[k] - Y[i];
			double Dist = sqrt( dx*dx + dy*dy );
			if( Dist <= med )cnt++;
		}
		if( cnt <= ct )lo = med;
		else hi = med;
	}
	int cnt = 0;
	m = 0;
	REP( i , n )
	{
		double dx = X[k] - X[i] , dy = Y[k] - Y[i];
		double Dist = sqrt( dx*dx + dy*dy );
		if( Dist <= lo )cnt++ ;
		if( abs( Dist - lo ) <= EPS ) I[m++] = i;
	}
	if( cnt == ct && m == 3 )
	{
		solve = 1;
		REP( i  , m )
			printf( "%d %d\n" , X[I[i]] , Y[I[i]] );
	}
}
int main()
{
	while( sc( n ) == 1 )
	{
		REP( i , n )
			sc( X[i] ) , sc( Y[i] );
		solve = 0;
		ct = n - ( n - 3 )/2;
		REP( i , n )
		{
			if( solve )break;
			f( i );
		}
		if( !solve )puts("0");
	}
}

 
