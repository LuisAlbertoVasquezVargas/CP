#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 400000

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int , int > pii;

#define v1 ((node<<1) + 1)
#define v2 (v1+1)
#define med ((a+b)>>1)
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

struct Node{
   	int mini, freq , flag;
   	Node(){ flag = 0 , mini = 1e9 , freq = 0; }
	Node( int mini , int freq , int flag ) : mini( mini ) , freq( freq ) , flag( flag ) {}
};
Node operator + ( const Node &a , const Node &b ){
	if( a.mini != b.mini ){
		if( a.mini < b.mini ) return a;
		return b;
	}
	return Node( a.mini , a.freq + b.freq , 0 );
}
struct ST{
	vector< Node >T;
	int n , total;
	ST(){ T.resize( 4 * N + 5 );}
	void init( vi &v ){
		n = SZ( v );
		total = 0;
		REP( i , n ) total += v[ i ];
		build_tree( v , 0 , 0 , n - 1 );
	}
	
	void build_tree( vi &v , int node , int a ,  int b ){
		if( a == b ){
			T[ node ] = Node( 0 , v[ a ] , 0 );
			return;
		}
		build_tree( v , LEFT ) , build_tree( v , RIGHT );
		T[ node ] = T[ v1 ] + T[ v2 ];
	}
	void push( int node , int a , int b ){
		if( T[ node ].flag == 0 ) return ;
		T[ node ].mini += T[ node ].flag ;
		if( a != b ){
			T[ v1 ].flag += T[ node ].flag;
			T[ v2 ].flag += T[ node ].flag;
		}
		T[ node ].flag = 0;
	}
	int area(){ 
		push( 0 , 0 , n - 1 );
		return T[ 0 ].mini == 0 ? ( total - T[ 0 ].freq ) : total ;
	}
	void update ( int node , int a , int b , int lo , int hi , int val ){
		push( node , a , b );
		if( lo > b || a > hi ) return;
		if( a >= lo && hi >= b ) {
			T[ node ].flag = val;
			push( node , a , b );
			return;	
		}
		update( LEFT , lo , hi , val );
		update( RIGHT , lo , hi , val );
		T[ node ] = T[ v1 ] + T[ v2 ];
	}
	void update( int lo , int hi , int val ){
		update( 0 , 0 , n - 1 , lo , hi , val );
	}
}st;

struct event{
	int x , t , lo , hi;
	event(){}
	event( int x , int t , int lo , int hi ) :x( x ) , t( t ) , lo( lo ) , hi( hi ) {}
};
bool operator < ( const event &a , const event &b ){
	if( a.x != b.x ) return a.x < b.x;
	return a.t < b.t;
}
struct rect{
	ll x1 , x2 , y1 , y2;
	rect(){}
	rect( ll x1 , ll x2 , ll y1 , ll y2 ) : x1( x1 ) , x2( x2 ) , y1( y1 ) , y2( y2 ) {}
	void impr(){ cout << "(" << x1 << "," << x2 << ")  (" << y1 << "," << y2 << ")" << endl;}
};

bool intersection( rect A , rect B , rect &C ){
	if( A.x1 > B.x1 ) swap( A , B );
	if( B.x1 > A.x2 ) return 0;
	C.x1 = B.x1 , C.x2 = min( A.x2 , B.x2 );
	if( A.y1 > B.y1 ) swap( A , B );
	if( B.y1 > A.y2 ) return 0;
	C.y1 = B.y1 , C.y2 = min( A.y2 , B.y2 );
	return 1;
}

int getInd( vi &v , int x ){
	return lower_bound( all( v ) , x ) - v.begin();
}
void impr( vi &v ){
	REP( i , SZ( v ) ) printf( "%d%c" , v[ i ] , i + 1 == SZ( v ) ? 10 : 32 );
}
ll unionRect( vector< rect > rectangles ){
	if( SZ( rectangles ) == 0 ) return 0;
	vector< event > E;
	vi L;
	REP( i , SZ( rectangles ) ){
		rect r = rectangles[ i ];
		int x1 = r.x1 , y1 = r.y1 , x2 = r.x2 , y2 = r.y2;
		E.pb( event( x1 , 0 , y1 , y2 ) );
		E.pb( event( x2 + 1 , 1 , y1 , y2 ) );
		L.pb( y1 ) , L.pb( y2 );
	}
	sort( all( L ) );
	L.resize( unique( all( L ) ) - L.begin() );
	vi v;
	v.pb( 1 );
	for( int i = 1 ; i < SZ( L ) ; ++i ){
		v.pb( L[ i ] - L[ i - 1 ] - 1 );
		v.pb( 1 );
	}
	st.init( v );
    ll ans = 0;
    sort( all( E ) );
    REP( i , SZ( E ) ){
		int ind;
		for( int j = i ; j < SZ( E ) ; ++j )
			if( E[ j ].x == E[ i ].x ) ind = j;
			else break;
		int delta = 0;
		if( ind + 1 < SZ( E ) ) delta = E[ ind + 1 ].x - E[ ind ].x;
		
		for( int j = i ; j <= ind ; ++j ){
			int lo = getInd( L , E[ j ].lo ) << 1;
			int hi = getInd( L , E[ j ].hi ) << 1;
			st.update( lo , hi , E[ j ].t == 0 ? +1 : -1 );
		}
		ans += (ll)st.area() * (ll)delta;
		i = ind;
	}
    return ans;
};

bool f( ll t , vi &x , vi &y ){
	if( t == 0 ) return 1;
	vector< rect > rectangles;
	REP( i , SZ( x ) ) rectangles.pb( rect( x[ i ] - t , x[ i ] + t - 1 , y[ i ] - t , y[ i ] + t -1 ) );
	ll S = unionRect( rectangles );
	//cout << t << " " << S << endl;
	return S == ((ll)(SZ(x)) * 4LL * t);
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		vi x( n ) , y( n );
		REP( i , n ) sc( x[ i ] ) , sc( y[ i ] );
		
		ll lo = 0 , hi = 10000000;
		while( hi - lo > 1 ){
			ll mid = (lo + hi) >>1;
			if( f( mid , x , y ) ) lo = mid;
			else hi = mid;
		}
		printf( "%lld\n" , 2LL * lo );
	}
}


