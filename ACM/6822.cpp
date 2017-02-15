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
typedef vector< int > vi;

int main(){
	int A , B;
	while( cin >> A >> B ){
		string s;
		cin >> s;
		ll ans = 0;
		deque< char > vec( all( s ) );
		while( !vec.empty() ){
			if( vec.front() == 'B' ){
				vec.pop_front();
				continue;
			}
			if( vec.back() == 'W' ){
				vec.pop_back();
				continue;
			}
			
			int len = SZ(vec);
			ans += min( (ll)A , (ll)(A - B) * (len - 1) );
			vec.pop_back();
			vec.pop_front();
		}
		cout << ans << '\n';
	}
}



