#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF 1<<29

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef long double ld;
typedef vector< ld > vld;

struct frac{
    ll num , den;
    frac(){}
    frac( ll a , ll b ){
        assert( !(a == 0 && b == 0) );
        if( b == 0 ){
            num = 1 , den = 0;
        }else if( a == 0 ){
            num = 0 , den = 1;
        }else{
            if( b < 0 ) a = -a , b = -b;
            ll g = __gcd( abs( a ) , abs( b ) );
            num = a/g , den = b/g;
        }
        
    }
};

bool operator <( const frac &a , const frac &b ){
    if( a.num != b.num ) return a.num < b.num;
    return a.den < b.den;
}
bool operator == ( const frac &A , const frac &B ){ return A.num == B.num && A.den == B.den;}

struct Point{
    ll x , y;
    Point( ll x , ll y ) : x( x ) , y( y ) {}
    ll dist2(){  return x * x + y * y; }
    frac slope(){
        return frac( y , x );
    }
};
bool operator < ( const Point &A , const Point &B ){ return A.x != B.x ? A.x < B.x : A.y < B.y; }
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
ll cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x;}
ll area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
ll dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y;}
ll dist2( const Point &A , const Point &B ){ return (B - A).dist2();}

int main(){

}


