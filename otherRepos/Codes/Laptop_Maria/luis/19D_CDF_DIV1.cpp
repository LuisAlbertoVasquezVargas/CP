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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int Q[N] , X[N] , Y[N];
char s[N];

struct Node
{
	int  best;
	Node(){}
	Node( int x ){ best = x ;}
}NEUTRAL;
Node operator +(const Node &L, const Node &R)
{
	Node ans;
	ans.best = min( L.best , R.best );	
	return ans;
}
struct ST
{
	int SZ;
	vector< Node >T, A;
	ST(){}
	ST( int n ){	
		SZ = n;
		T = vector< Node >( 4*SZ );
		A = vector< Node >( SZ , INF );
		build_tree( 0 , 0 , SZ - 1 );
	}
	void build_tree( int node , int a , int b )
	{
		int v1 = (node<<1) + 1 , v2 = v1 + 1 , med = ( a + b )>>1;	
		if( a == b )
		{
			T[ node ] = A[a];
			return;	
		}
		build_tree( v1 , a , med );
		build_tree( v2 , med + 1 , b );
		T[ node ] = T[ v1 ] + T[ v2 ];
	}
	int query( int node , int a , int b , int x , int y )
	{
		int v1 = (node<<1) + 1 , v2 = v1 + 1 , med = ( a + b )>>1;
		if( x > b || a > y )return NEUTRAL;
		if( a >= x && y >= b )
			return T[ node ];
		int op1 = query( v1 , a , med , x , y ) , op2 = query( v2 , med + 1 , b , x , y );
		if( op1.best == INF )return op2;
		if( op2.best == INF )return op1;		
		return op1 + op2;
	}
	int query( int x , int y ){ return query( 0 , 0 , SZ - 1 , x , y ); }			
};

int main()
{
	int n , m ;
	NEUTRAL.best = -INF;
	while( scanf( "%d" , &n ) == 1 )
	{
		REP( i , n )
		{
			scanf( "%s" , s , &X[i] , &Y[i] );
			if( s[0] == 'a' )Q[i] = 0;
			else if( s[0] == 'f' )Q[i] = 1;
			else Q[0] = 2;
		}
		vector< pii >V( n );
		REP( i , n ) V[i] = pii( X[i] , Y[i] );
		sort( all( V ) );
		m = unique( all( V ) ) - V.begin();
		V.resize( m );
		map< pii , int >M;
		vi W( m );
		REP( i , m ) M[V[i]] = i , W[i] = V[i].fi;
		ST st( m );
	}
}

