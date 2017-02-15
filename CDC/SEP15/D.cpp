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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

double get( double p , int n ){
	return (pow( p , n + 1 ) - 1.0) / (p - 1.0);
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int n;
		double p;
		cin >> n >> p;
		double P = p * p;
		double S = get( p , n - 1 );
		double ans1 = get( P , (n - 1)/2 );
		double ans2 = S - ans1;
		ans1 *= 1e9 , ans2 *= 1e9;
		printf( "%.14f %.14f\n" , ans1 , ans2 );
	}
}


