#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))
#define pb push_back
#define SZ(v) ((int)v.size())

#define v1 ( ( node << 1) + 1 )
#define v2 ( v1 + 1 )
#define med ( ( a + b ) >> 1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

typedef long long ll;

const int N = 1e5;
const ll INF = (ll)1e15;

struct Node{
	ll best , der , izq , sum;
	Node(){
		sum = 0;
		izq = der = best = -INF;
	}
	Node( ll val ): best( val ) , der( val ) , izq( val ) , sum( val ) {};
} T[ 4 * N ];
Node operator +( const Node &a , const Node &b ){
	Node ans;
	ans.sum = a.sum + b.sum;
	if(ans.sum < -INF) ans.sum = -INF;
	ans.der = max( b.der , b.sum + a.der );
	if(ans.der < -INF) ans.der = -INF;
	ans.izq = max( a.izq , a.sum + b.izq );
	if(ans.izq < -INF) ans.izq = -INF;
	ans.best = max( a.best , b.best );
	ans.best = max( ans.best , a.der + b.izq );
	if(ans.best < -INF) ans.best = -INF;
	return ans;
}
int A[N + 5];
void build_tree( int node , int a , int b ){
	if( a == b ){
		T[ node ] = Node( A[ a ] );
		return;
	}
	build_tree( LEFT );build_tree( RIGHT );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
void update( int node , int a , int b , int x , ll val ){
	if( x > b || a > x ) return;
	if( a == b ){
		T[ node ] = Node( val );
		return;
	}
	update( LEFT , x , val );update( RIGHT , x , val );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
Node query( int node , int a , int b , int lo , int hi ){
	if( lo > b || a > hi ) return Node();
	if( a >= lo && hi >= b ) return T[ node ];
	return query( LEFT , lo , hi ) + query( RIGHT , lo , hi );
}
const ll myINF = (ll)1e13;
int main(){
	int n;
	while(scanf("%d",&n) == 1){
		REP(i,n) scanf("%d",&A[i]);
		build_tree(0,0,n-1);
		REP(i,n){
			int pos;
			scanf("%d",&pos);
			pos --;
			update(0,0,n-1,pos,-INF);
			printf("%lld\n",max(0LL,query(0,0,n-1,0,n-1).best));
		}
	}
}


