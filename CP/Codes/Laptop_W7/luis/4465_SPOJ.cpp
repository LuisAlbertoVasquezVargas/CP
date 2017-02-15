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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

struct Point
{
	int x, y;
	Point(){}
	Point( int x , int y ):x( x ) , y( y ){}
	void read(){ sc( x ) , sc( y ); }
};
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
int cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
int area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}

bool between(const Point &A, const Point &B, const Point &P)
{
    return  P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
            P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y) ;
}
bool onSegment(const Point &A, const Point &B, const Point &P)
{
    return area(A, B, P) == 0 && between(A, B, P);
}
bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4)
{
    double A1 = area(P3, P4, P1);
    double A2 = area(P3, P4, P2);
    double A3 = area(P1, P2, P3);
    double A4 = area(P1, P2, P4);
    
    if( ((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) && 
        ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0))) 
            return true;
    
    else if(A1 == 0 && onSegment(P3, P4, P1)) return true;
    else if(A2 == 0 && onSegment(P3, P4, P2)) return true;
    else if(A3 == 0 && onSegment(P1, P2, P3)) return true;
    else if(A4 == 0 && onSegment(P1, P2, P4)) return true;
    else return false;
}

int n;
Point A[ N ] , B[ N ];

int id[ N ];
int Find( int x ){
	if( x == id[ x ] ) return x;
	return id[ x ] = Find( id[ x ] );
}
void Union( int x , int y )
{
	int p = Find( x ) , q = Find( y );
	if( p != q ) id[ p ] = q;
}
void doit()
{
	REP( i , n ) id[ i ] = i;
	REP( i , n )
		for( int j = i + 1 ; j < n ; ++j )
			if( intersects( A[ i ] , B[ i ] , A[ j ] , B[ j ] ) )
				Union( i , j ); 
}
void solve( int x , int y ){
	puts( Find( x ) == Find( y ) ? "YES":"NO" );
}
void input()
{
	sc( n );
	int Q;
	sc( Q );
	REP( i , n ) A[ i ].read() , B[ i ].read();
	doit();
	while( Q-- )
	{
		int x , y;
		sc( x ) , sc( y );
		x-- , y--;
		solve( x , y );
	}
}

int main()
{
	int tc;
	sc( tc );
	while( tc-- )
		input();
}


