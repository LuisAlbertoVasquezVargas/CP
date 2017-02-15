#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ(v) ((int)v.size())

#define mp make_pair
#define fi first
#define se second

#define M 1000000

#define test puts( "************test**************" );

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

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
	ST(){}
	ST( vi &v ){
		n = SZ( v );
		total = 0;
		REP( i , n ) total += v[ i ];
		T.resize( 4*n );
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
	int x1 , x2 , y1 , y2;
	rect(){}
	rect( int x1 , int x2 , int y1 , int y2 ) : x1( x1 ) , x2( x2 ) , y1( y1 ) , y2( y2 ) {}
};

bool intersection( rect A , rect B , rect &C ){
	if( A.x1 > B.x1 ) swap( A , B );
	if( B.x1 > A.x2 ) return 0;
	C.x1 = B.x1 , C.x2 = A.x2;
	if( A.y1 > B.y1 ) swap( A , B );
	if( B.y1 > A.y2 ) return 0;
	C.y1 = B.y1 , C.y2 = A.y2;
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
	st = ST( v );
	
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
			int lo = 2 * getInd( L , E[ j ].lo );
			int hi = 2 * getInd( L , E[ j ].hi );
			st.update( lo , hi , E[ j ].t == 0 ? +1 : -1 );
		}
		ans += (ll)st.area() * (ll)delta;
		i = ind;
	}
    return ans;
};

int n;
int X[ M + 5 ] , Y[ M + 5 ];
int f( int t ){
	vector< rect > rectangles;
	rect r , A( -t ,  +t , -t , +t );
	REP( i , n ){
		int x = X[ i ] , y = Y[ i ];
		
		rect B( x - t , x + t , y - t , y + t );
		if( intersection( A , B , r ) ){
			rectangles.pb( r );
		}
	}
	return unionRect( rectangles ) == (ll)(2*t+1)*(ll)(2*t+1);
}

int main(){
	/*
    int x , y , tc = 0 , n;
    while( cin >> n ){
		int a1 , b1 , a2 , b2;
	    vector< rect > rectangles;
	    REP( i , n ){
	        scanf ( "%d%d%d%d" , &a1 , &b1 , &a2 , &b2 );
	        rectangles.pb( rect( a1 , a2 , b1 , b2 ) );
	    }
	    printf( "%d\n" , unionRect( rectangles ) );
	}*/
	int x , y , tc = 0 ;
    while( sc( n ) == 1 ){
    	if( n == -1 ) break;
	    REP( i , n ){
	        sc( x ) , sc( y );
	        X[ i ] = x , Y[ i ] = y;
	    }
	    printf( "Case %d: " , ++ tc );
	    int lo = 0 , hi = 1e6 + 1;
	    
		if( f( lo ) ){
			printf( "%d\n" , lo );
			continue;
		}
		
		if( !f( hi ) ){
			puts( "never" );
			continue;
		}
	    while( hi - lo > 1 ){
	    	int mid = (lo + hi)>>1;
			if( f( mid ) ) hi = mid;
			else lo = mid;
		}
		printf( "%d\n" , hi );
	}
}

