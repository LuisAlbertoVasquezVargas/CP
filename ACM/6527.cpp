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
typedef unsigned long long ull;

ll b = 2;
ll g(ll x ,ll d){
	ll r = 0;
    while( x > 0 ){
		if( x % b == d ) r++;
		x /= b;
    }
	return r;
}
ll f( ll N , ll D){
	if( N <= 0 ) return 0;
	ll U= N/b + (N%b >= D) - (D == 0);
	ll O = b * f( N/b - 1 ,D);
    for(ll i=(N/b)*b; i <= N ; i++ ) O += g( i/b ,D );
	return U+O;    
}
int main(){
	ll A , B;
	while( cin >> A >> B ){
		cout << f( B , 1 ) - f( A - 1 , 1 ) << '\n';
	}
}


