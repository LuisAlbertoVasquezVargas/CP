#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define N 100
#define MOD 8

typedef long long ll;
typedef vector< int > vi;

bool used[ N + 5 ][ 2 ][ MOD + 5 ];
bool memo[ N + 5 ][ 2 ][ MOD + 5 ];
string s;
int n;
bool dp( int pos , int start , int mod ){
	if( pos == n ){
		if( start ) return (mod == 0);
		return 0;
	}
	if( used[ pos ][ start ][ mod ] ) return memo[ pos ][ start ][ mod ];
	used[ pos ][ start ][ mod ] = 1;
	bool &dev = memo[ pos ][ start ][ mod ] = 0;
	if( start ){
		dev |= dp( pos + 1 , 1 , mod );
		dev |= dp( pos + 1 , 1 , (mod * 10 + (s[ pos ] - '0'))%8 );
	}else{
		dev |= dp( pos + 1 , 0 , mod );
		if( s[ pos ] != '0' ) 
			dev |= dp( pos + 1 , 1 , (mod * 10 + (s[ pos ] - '0'))%8 );
	}
	return dev;
}
string t;
void rec( int pos , int start , int mod ){
	if( pos == n ){
		if( start ) return;
		return;
	}
	if( start ){
		if( dp( pos + 1 , 1 , mod ) ){
			rec( pos + 1 , 1 , mod );
			return;
		}
		if( dp( pos + 1 , 1 , (mod * 10 + (s[ pos ] - '0'))%8 ) ){
			t.pb( s[ pos ] );
			rec( pos + 1 , 1 , (mod * 10 + (s[ pos ] - '0'))%8 );
			return;
		}
	}else{
		if( dp( pos + 1 , 0 , mod ) ){
			rec( pos + 1 , 0 , mod );
			return;
		}
		if( s[ pos ] != '0' ){
			if( dp( pos + 1 , 1 , (mod * 10 + (s[ pos ] - '0'))%8 ) ){
				t.pb( s[ pos ] );
				rec( pos + 1 , 1 , (mod * 10 + (s[ pos ] - '0'))%8 );
				return;
			}
		}
	}
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	while( cin >> s ){
		n = SZ(s);
		bool zero = 0;
		REP( i , n )
			if( s[ i ] == '0' ){
				zero = 1;
				break;
			}
		if( zero ){
			cout << "YES\n";
			cout << "0\n";
			continue;
		}
		clr( used , 0 );
		if( !dp( 0 , 0 , 0 ) ){
			cout << "NO\n";
			continue;
		}
		
		t.clear();
		rec( 0 , 0 , 0 );
		cout << "YES\n";
		cout << t << '\n';
	}
}


