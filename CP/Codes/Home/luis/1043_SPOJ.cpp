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

struct Node
{
	ll  best  , bestL  , bestR , sum ;
	Node(){}
	Node( int x ){ best = bestL = bestR = sum = x ;}
}NEUTRAL;
Node operator +(const Node &L, const Node &R)
{
	Node ans;
	ans.sum = L.sum + R.sum;
	ans.bestL = max( L.bestL , L.sum + R.bestL );
	ans.bestR = max( R.bestR , R.sum + L.bestR );
	ans.best = max( L.best , R.best );
	ans.best = max( ans.best , L.bestR + R.bestL );
	return ans;
}
struct ST
{
	int SZ;
	vector< Node >T, A;
	ST(){}
	ST( vector< Node >&B ){	
		SZ = B.size();
		T = vector< Node >( 4*SZ );
		A = B;
		build_tree( 0 , 0 , SZ - 1 );
	}
	void build_tree( int node , int a , int b )
	{
		int v1 = 2*node + 1 , v2 = 2*node + 2 , med = ( a + b )/2;	
		if( a == b )
		{
			T[ node ] = A[a];
			return;	
		}
		build_tree( v1 , a , med );
		build_tree( v2 , med + 1 , b );
		T[ node ] = T[ v1 ] + T[ v2 ];
	}
	Node query( int node , int a , int b , int x , int y )
	{
		int v1 = 2*node + 1 , v2 = 2*node + 2 , med = ( a + b )/2;
		if( x > b || a > y )return NEUTRAL;
		if( a >= x && y >= b )
			return T[ node ];
		Node op1 = query( v1 , a , med , x , y ) , op2 = query( v2 , med + 1 , b , x , y );
		if( op1.best == -INF )return op2;
		if( op2.best == -INF )return op1;		
		return op1 + op2;
	}
	Node query( int x , int y ){ return query( 0 , 0 , SZ - 1 , x , y ); }			
};

int main()
{
	NEUTRAL.best = NEUTRAL.bestL = NEUTRAL.bestR = -INF;
	NEUTRAL.sum = 0LL;	
	int n , x , q , lo , hi;	
	scanf( "%d" , &n ) ;
	vector< Node > v( n );
	for( int i = 0 ; i < n ; ++i )
		scanf( "%d" , &x ) ,v[i] = Node( x );
	ST st = ST( v );
	scanf( "%d" , &q );	
	while( q-- )
	{
		scanf( "%d%d" , &lo , &hi );
		lo--;hi--;
     	printf( "%d\n" , st.query( lo , hi ).best ) ;        
	}
}
