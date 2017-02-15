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

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		vll v;
		REP( i , n ){
			int x;
			sc( x );
			v.pb( x );
		}
		map< ll , ll > L , R;
		for( auto b : v )
			R[ b ] ++;	
		ll ans = 0;
		for( auto b : v ){
			R[ b ] --;
			if( b % K == 0 ){
				ans += L[ b / K ] * R[ b * K ];
			}
			L[ b ] ++;
		}	
		
		cout << ans << '\n';
	}
}



