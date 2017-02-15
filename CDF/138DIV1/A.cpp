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
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int main(){
	ios_base :: sync_with_stdio( 0 );
	string s;
	while( cin >> s ){
		int n = SZ(s);
		vpii STACK( 1 , mp( -1 , -1 ) );
		int best = -1 , L , R;
		vi AC( n + 1 );
		REP( i , n ) AC[ i + 1 ] = AC[ i ] + (s[ i ] == '[');
		REP( i , n ){
			char c = s[ i ];
			if( c == '(' || c == '[' ){
				STACK.pb( mp( c , i ) );
			}else{
				if( c == ')' ){
					if( SZ(STACK) && STACK.back().fi == '(' ){
						STACK.pop_back();
						int lo = STACK.back().se + 1;
						int hi = i;
						int cur = AC[ hi + 1 ] - AC[ lo ];
						if( cur > best ){
							best = cur;
							L = lo , R = hi;
						}
					}else {
						STACK.clear();
						STACK.pb( mp( c , i ) );
					}
				}else{//c == ']'
					if( SZ(STACK) && STACK.back().fi == '[' ){
						STACK.pop_back();
						
						int lo = STACK.back().se + 1;
						int hi = i;
						int cur = AC[ hi + 1 ] - AC[ lo ];
						//DEBUG2( lo , hi );
						if( cur > best ){
							best = cur;
							L = lo , R = hi;
						}
					}else {
						STACK.clear();
						STACK.pb( mp( c , i ) );
					}
				}
			}
		}
		
		if( best <= 0 ){
			cout << '0' << '\n' << '\n';
			continue;
		}
		cout << best << '\n';
		cout << s.substr( L , R - L + 1 ) << '\n';
	}
}


