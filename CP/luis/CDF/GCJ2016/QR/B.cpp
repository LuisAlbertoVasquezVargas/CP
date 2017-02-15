#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define all( v ) v.begin() , v.end()
#define SZ(v) ((int)v.size())

int f( string s ){
	vector< char > v( all( s ) );
	int ans = 0;
	while( 1 ){
		if( SZ( v ) == 0 ) return ans;
		while( SZ( v ) && v.back() == '+' ) v.pop_back();
		s = string( all( v ) );
		//cout << s << endl;
		if( SZ( v ) ){
			int pos = find( all( v ) , '-' ) - v.begin();
			int len = v[ 0 ] == '-' ? SZ( v ) : pos;
			reverse( v.begin() , v.begin() + len );
			REP( i , len )
				if( v[ i ] == '+' ) v[ i ] = '-';
				else v[ i ] = '+';
			ans ++;
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(0);
	int cases;
	cin >> cases;
	REP( tc , cases ){
		string s;
		cin >> s;
		cout << "Case #" << tc + 1 << ": " << f( s ) << '\n';
	}
}


