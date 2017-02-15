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

bool f( ll n , ll B , ll K ){
	return 4LL * (n - 1LL) * (K + 1LL) - 4LL * K * (K + 1LL) < B;
}
ll solve( ll n , ll B ){
	ll lo = -1 , hi = (n - 1LL)/2LL + 2LL;
	while( hi - lo > 1 ){
		ll med = lo + ((hi - lo) >> 1);
		if( f( n , B , med ) ) lo = med;
		else hi = med;
	}
	return lo;
}

int main(){
	ll n , B;
	while( cin >> n >> B ){
		if( (n & 1) && B == n * n ){
			cout << (n/2LL) + 1 << " " << (n/2LL) + 1 << '\n';
			continue;
		}
		ll K = solve( n , B );
		ll x = K , y = K;
		x ++;
		ll cur = 4LL * (n - 1LL) * (K + 1LL) - 4LL * K * (K + 1LL);
		//DEBUG3( x , y , K );
		B -= cur;
		ll len = n - 2LL * (K + 1);
		ll temp = min( len , B );
		B -= temp;
		y += temp;
		
		temp = min( len - 1 , B );
		B -= temp;
		x += temp;
		
		temp = min( len - 1 , B );
		B -= temp;
		y -= temp;
		
		temp = min( len - 1 , B );
		B -= temp;
		x -= temp;
		x ++ , y ++;
		cout << x << " " << y << '\n';
	}
}


