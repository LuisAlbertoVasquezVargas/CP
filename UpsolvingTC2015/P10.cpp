#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;

#define N 200

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;
typedef vector< ld > vld;

const ld INF = 1e100;
const ld EPS = 1e-8;
const ld PI = acos(-1.0);

inline bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
inline bool Less( ld x , ld y ){ return x < y - EPS; }
inline bool LessOrEquals( ld x , ld y ){ return Less( x , y ) || equals( x , y ); }

struct Point{
	ld x , y;
	Point(){ x = y = 0; }
	ld dist(){ return hypot( x , y );}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	void impr(){
		DEBUG2( x , y );
	}
};
typedef Point Vector;
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator / ( const Point &A , const ld &k ){ return Point( A.x / k , A.y / k ); }
Point operator * ( const Point &A , const ld &k ){ return Point( A.x * k , A.y * k ); }

bool operator == ( const Point &A , const Point &B ){ 
	return equals( A.x , B.x ) && equals( A.y , B.y ); 
}
ld dist( const Point &A , const Point &B ){ return (B - A).dist(); }
ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }

Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}

bool between( const Point &A , const Point &B , const Point &P ){
	return 	min( A.x , B.x ) < P.x + EPS && P.x < max( A.x , B.x ) + EPS &&
			min( A.y , B.y ) < P.y + EPS && P.y < max( A.y , B.y ) + EPS;
}
bool onSegment( const Point &A , const Point &B , const Point &P ){
	return abs( area( A , B , P ) ) < EPS && between( A , B , P );
}
bool intersects( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	ld A1 = area( P3 , P4 , P1 );
	ld A2 = area( P3 , P4 , P2 );
	ld A3 = area( P1 , P2 , P3 );
	ld A4 = area( P1 , P2 , P4 );
	if( ( ( A1 > EPS && A2 < -EPS ) || ( A1 < -EPS && A2 > EPS ) ) && 
		( ( A3 > EPS && A4 < -EPS ) || ( A3 < -EPS && A4 > EPS ) ) ) return 1;
	if( onSegment( P3 , P4 , P1 ) ) return 1;
	if( onSegment( P3 , P4 , P2 ) ) return 1;
	if( onSegment( P1 , P2 , P3 ) ) return 1;
	if( onSegment( P1 , P2 , P4 ) ) return 1;
	return 0;
}
bool sameLine( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	return equals( area(P1, P2, P3) , 0.0 ) && equals( area(P1, P2, P4) , 0.0 );
}
typedef vector< Point > Polygon;
bool pointInPoly( const Polygon &Poly , const Point &A ){
    int nP = Poly.size() , cnt = 0;
    REP( i , nP ){
    	int inf = i , sup = ( i + 1 )%nP;
    	if( onSegment( Poly[ inf ] , Poly[ sup ] , A ) ) return 0;
    }
    REP( i , nP ){///te da yes si esta adentro del poligono en el borde y afuera es incierto D:
        int inf = i , sup = ( i + 1 )%nP;
        if( Poly[ inf ].y > Poly[ sup ].y ) swap( inf , sup );
        if( Poly[ inf ].y <= A.y && A.y < Poly[ sup ].y )
            if( area( A , Poly[ inf ] , Poly[ sup ] ) > EPS )
                cnt++;
    }
    return cnt & 1;
}
vi G[ N + 5 ]; 
vld C[ N + 5 ];
bool possible( const Point &A , const Point &B , vector< Point > &P , int n ){
	if( A == B ) return 1;
	Point C = (A + B)/2.0;
	if( pointInPoly( P , C ) ) return 0;
	REP( i , n ){
		Point C = P[ i ] , D = P[ (i + 1)%n ];
		if( !intersects( A , B , C , D ) ) continue;
		if( sameLine( A , B , C , D ) ) continue;
		Point I = lineIntersection( A , B , C , D );
		if( I == A || I == B ) continue;
		return 0;
	}
	return 1;
}

int n;

struct Node{
    int id ;
    ld dist;
    Node( int id , ld dist ) : id( id ) , dist( dist ) {}
};
bool operator < ( const Node &a , const Node &b ){ return a.dist > b.dist; }
void add( int u , int v , ld w ){
	G[ u ].pb( v );
	C[ u ].pb( w );
	
	G[ v ].pb( u );
	C[ v ].pb( w );
	//DEBUG3( u , v , w );
}
ld dijkstra(){
	int s = n , t = n + 1;
	vld dist( n + 2 , INF );
	priority_queue< Node > Q;
	dist[ s ] = 0;
    Q.push( Node( s , 0 ) );
    while( !Q.empty() ){
        Node U = Q.top() ; Q.pop();
        int u = U.id ;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            ld w = C[ u ][ i ];
            if( dist[ u ] + w < dist[ v ] ){
                dist[ v ] = dist[ u ] + w;
                Q.push( Node( v , dist[ v ] ) );
            }
        }
    }
	return dist[ t ];
}
ld L = 0;
int VL , VP;
bool f( ld timer , vector< Point > &P ){
	ld t = timer * VL;
	ld r = (ld)floor( t / L );
	t -= r * L;
	ld cur = 0;
	Point X(INF , INF);
	REP( i , n ){
		Point A = P[ i ] , B = P[ (i + 1)%n ];
		ld dx = dist( A , B );
		if( cur - EPS <= t && t <= cur + dx + EPS ){
			ld delta = t - cur;
			X = (A * (dx - delta) + B * (delta) )/dx;
			break;
		}
		cur += dx;
	}

	REP( i,  n + 1 ){
		Point A = P[ i ] , B = X;
		if( possible( A , B , P , n ) ){
			ld w = dist( A , B );
			w /= VP;
			add( i , n + 1 , w );
		}
	}
	ld ans = dijkstra();
	REP( i,  n + 1 ){
		Point A = P[ i ] , B = X;
		if( possible( A , B , P , n ) ){
			G[ i ].pop_back();
			C[ i ].pop_back();
			
			G[ n + 1 ].pop_back();
			C[ n + 1 ].pop_back();
		}
	}
	
	return ans <= timer;
}
int tc = 0;
void doit( ld x ){
	int t = (int)(x * 60 + 0.5);
	printf("Case %d: Time = %d:%.2d\n", ++tc , t/60, t%60);
}
int main(){
	while( sc( n ) == 1 ){
		if( !n ) break;
		REP( i , N ) G[ i ].clear() , C[ i ].clear();
		vector< Point > P;
		REP( i , n + 1 ){
			int x , y;
			sc( x ) , sc( y );
			P.pb( Point( x , y ) );
		}
		sc( VL ) , sc( VP );
		
		Point Q = P.back();
		for( int i = 0 ; i < n ; ++i ){
			for( int j = i + 1 ; j < n ; ++j ){
				Point A = P[ i ] , B = P[ j ];
				
				if( possible( A , B , P , n ) ){
					
					ld w = dist( A , B );
					//DEBUG3( i , j , w );
					w /= VP;
					//DEBUG3( i , j , w );
					add( i , j , w );
				}
			}
		}
		REP( i,  n ){
			Point A = P[ i ] , B = Q;
			if( possible( A , B , P , n ) ){
				ld w = dist( A , B );
				w /= VP;
				add( i , n , w );
			}
		}
		
		L = 0;
		REP( i , n ){
			Point A = P[ i ] , B = P[ (i + 1)%n ];
			L += dist( A , B );
		}
		
		//cout << f( 2 , P ) << endl;
		
		ld lo = 0 , hi = 1e18;
		REP( it , 150 ){
			ld med = (lo + hi)/2.0;
			if( f( med , P ) ) hi = med;
			else lo = med;
		}
		doit( hi );
	}
}


