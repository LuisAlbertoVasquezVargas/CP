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

#define EPS (1e-8)
#define eps (1e-50)
#define N 1000000

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long double ld;
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< ld > vld;
typedef vector< vld > vvld;

inline bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
inline bool Less( ld x , ld y ){ return x < y - EPS; }
inline bool LessOrEquals( ld x , ld y ){ return Less( x , y ) || equals( x , y ); }

struct Point{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld dist(){ return hypot(x , y); }
	Point unit(){
		ld d = dist();
		return Point( x/d , y/d );
	}
	Point ort(){ return Point( -y , x ); }
	void impr(){
		printf( "%.15f , %.15f\n" , (double)x , (double)y );
	}
};
typedef Point Vector;
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k ); }

ld dist( const Point &A , const Point &B ){ return (B - A).dist();}
ld dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y ; }
ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }

Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}

vector<Point> circleCircleIntersection( Point O1 , ld r1 , Point O2 , ld r2 ){
	vector <Point> X;
	ld d = dist(O1, O2);
	if(d > r1 + r2 || d < max(r2, r1) - min(r2, r1)) return X;
	else
	{
		ld a = (r1*r1 - r2*r2 + d*d) / (d * 2.0);
		ld b = d - a;
		ld c = sqrt(abs(r1*r1 - a*a));
		Vector V = (O2-O1).unit();
		Point H = O1 + V * a;
		X.push_back(H + V.ort() * c);
		if(c > EPS) X.push_back(H - V.ort() * c);
	}
	return X;
}
Point get( Point P2 , ld R2 , Point Pk , ld Rk , ld R ){
	vector< Point > vec = circleCircleIntersection( P2 , R2 + R , Pk , Rk + R );
	for( auto P : vec )
		if( area( P2 , Pk , P ) >= -EPS ) return P;
	assert( 0 );
}
void solve( Point P1 , ld R1 , Point P2 , ld R2 , Point Pk , ld Rk , Point &P , ld &R ){
	ld lo = 0.0 , hi = Rk;
	REP( it , 30 ){
		ld med = (lo + hi)/2.0;
		Point Q = get( P2 , R2 , Pk , Rk , med );
		if( Q.dist() + med <= R1 ) lo = med;
		else hi = med;
	}
	P = get( P2 , R2 , Pk , Rk , lo );
	R = lo;
}
void impr( ld x , ld y , ld z ){
	printf( "%.15f , %.15f %.15f\n" , (double)x , (double)y , (double)z );
}

int main(){
	ll N0 , P, M, B , cases;
	cin >> cases >> N0 >> P >> M >> B;
	vi consultas;
	REP( tc , cases ){
		N0 = (P * N0) % M + B;
		consultas.pb( N0 );
	}
	vector< Point > V( N + 5 );
	vld R( N + 5 );
	Point P1 , P2 , P3 , Pn;
	ld R1 , R2 , R3 , Rn;
	
	cin >> R1 >> R2 >> R3 >> Rn;
	ld cte = R1;
	R1 /= cte , R2 /= cte , R3 /= cte , Rn /= cte;
	P1 = Point( 0.0 , 0.0 );
	P2 = Point( 0.0 , R1 - R2 );
	vector< Point > vec = circleCircleIntersection( P1 , R1 - R3 , P2 , R2 + R3 );
	REP( i , SZ( vec ) ){
		ld x = vec[ i ].x , y = vec[ i ].y;
		if( x <= EPS ){
			P3 = vec[ i ];
			break;
		}
	}
	Pn = get( P2 , R2 , P3 , R3 , Rn );
	//impr( Pn.x , Pn.y , Rn );
	
	V[ 1 ] = P1;
	R[ 1 ] = R1;
	V[ 2 ] = P2;
	R[ 2 ] = R2;
	V[ 3 ] = P3;
	R[ 3 ] = R3;
	V[ 4 ] = Pn;
	R[ 4 ] = Rn;
	
	for( int i = 5 ; i <= N ; i ++ ){
		solve( P1 , R1 , P2 , R2 , Pn , Rn , Pn , Rn );
		V[ i ] = Pn;
		R[ i ] = Rn;
		printf( "%.20f\n" , (double)(R[i]/R[i-1]) );
	}
	ld ans = 0;
	for( auto n : consultas ) 
		if( n <= N ) ans += R[ n ];
		else ans += R[ N ];
	printf( "%.6f\n" , (double)(ans * cte) );
}



