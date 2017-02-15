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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;
typedef vector< ld > vld;

const int N = 3000;
bool used[ N + 5 ][ N + 5 ];
int memo[ N + 5 ][ N + 5 ];
string S;
int n;
int dp( int a , int b ){
    if( a == b ) return 1;
    if( a > b ) return 0;
    if( used[ a ][ b ] ) return memo[ a ][ b ];
    used[ a ][ b ] = 1;
    int &dev = memo[ a ][ b ] = max( dp( a + 1 , b ) , dp( a , b - 1 ) );
    if( S[ a ] == S[ b ] ) dev = max( dev , 2 + dp( a + 1 , b - 1 ) );
    return dev;
}

int funPal(string s) {
    n = SZ(s);
    S = s;
    clr( used , 0 );

    int ans = 0;
    REP( i , n )
    	ans = max( ans , dp( 0 , i ) * dp( i + 1 , n - 1 ) );
    
    return ans;
}
int main(){
	string s;
	while( cin >> s ) cout << funPal( s ) << endl;	

}


