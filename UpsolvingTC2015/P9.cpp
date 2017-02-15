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
typedef vector< int > vi;

int toi( string s ){
	istringstream in( s );
	int x;
	in >> x;
	return x;
}
string get( int n , int B ){
	if( !n ) return "0";
	string ans;
	while( n != 0 ){
		int r = n % ( -B );
		n /= ( -B );
		if( r < 0 ){
			r += B;
			n ++;
		}
		ans.pb( '0' + r );
	}
	reverse( all( ans ) );
	return ans;
}
int main(){
	ios_base :: sync_with_stdio(0);
	string s;
	while( getline( cin , s ) ){
		if( s[ 0 ] == 'e' ) break;
		if( s[ 0 ] == 't' ){
			//to-B number
			int B = s[ 3 ] - '0';
			if( B == 1 ) B = 10;
			int n = toi( s.substr( 5 + (B == 10) ) );
			string ans = get( n , B );
			cout << ans << '\n';
		}else{
			//from-2 1010
			int B = s[ 5 ] - '0';
			if( B == 1 ) B = 10;
			string S = s.substr( 7 + (B == 10) );
			int ans = 0;
			REP( i , SZ(S) )
				ans = ans * (-B) + (S[ i ] - '0');
			cout << ans << '\n';
		}
	}
}



