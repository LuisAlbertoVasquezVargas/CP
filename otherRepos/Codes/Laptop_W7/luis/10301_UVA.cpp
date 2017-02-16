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

double X[ N ] , Y[ N ] , R[ N ];
int id[ N ] , F[ N ];

int Find( int x )
{
	if( id[x] == x )return x;
	return id[x] = Find( id[x] );
}
void Union( int x , int y )
{
	int p = Find( x ) , q = Find( y );
	if( p != q )id[p] = q;
}
int main()
{
	int n;
	while( scanf( "%d" , &n ) == 1 && n != -1 )
	{
		REP( i , n )scanf( "%lf%lf%lf" , &X[i] , &Y[i] , &R[i] );
		REP( i , n ) id[i] = i;
		REP( i ,  n )for( int j = i + 1 ; j < n ; ++j )
		{
			double dx = X[j] - X[i] , dy  = Y[j] - Y[i];
			double dist = sqrt( dx*dx + dy*dy );
			double P[3] = { dist , R[i] , R[j] };
			sort( P , P + 3 );
			if( P[2] <= P[0] + P[1] ) Union( i , j );
		}
		clr( F , 0 );
		REP( i , n ) F[Find( i )]++;
		int ans = *max_element( F , F + n );
		printf( "The largest component contains %d ring%s.\n" , ans , (ans==1?"":"s") );
	}
}


