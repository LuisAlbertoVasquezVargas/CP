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
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< pii > vpii;

int main(){
	ios_base :: sync_with_stdio( 0 );
	ll A , B;
	while( cin >> A >> B ){
		if( !A && !B ) break;
		A = (A / 5LL) * 5LL;
		if( B % 5 == 0 ){
			B += 5;
		}else{
			B = ((B - 1LL)/5LL + 1LL) * 5LL;
		}
		//DEBUG2( A , B );
		cout << (B - A) / 5LL << '\n';
	}
}


