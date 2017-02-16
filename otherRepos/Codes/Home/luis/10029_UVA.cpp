#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back

typedef vector< string > vs;

bool cmp( string a , string b ){
	//return a < b;
	if( !(a < b) ) return 0;
	int na = a.size() , nb = b.size();
	if( na == nb )
	{
		int cnt = 0 , n = a.size();
		REP( i , n ) if( a[ i ] != b[ i ] ) cnt ++;
		if( cnt == 1 ) return 1;
		return 0;
	}
	if( na + 1 == nb )
	{
		///cout << a << " to " << b << endl;
		REP( i , nb ){
			string t = b;
			t.erase( t.begin() + i );
			//cout << "--> : " << t << endl;
			if( t == a ) return 1;
		}
		//cout << endl;
	}
	if( na == nb + 1 )
	{
		REP( i , na ){
			string t = a;
			t.erase( t.begin() + i );
			if( t == b ) return 1;
		}
	}
	return 0;
}
int main()
{
	//ios_base :: sync_with_stdio( 0 );
	vs a;
	string s;
	while( cin >> s ) a.pb( s );
	int n = a.size() , sz = 0;
	string b[ n + 1 ];
	cout << cmp( a[ 0 ] , a[ 1 ] );
	/*cout << cmp( a[ 1 ] , a[ 3 ] ) << endl;
	cout << cmp( a[ 3 ] , a[ 4 ] ) << endl;
	cout << cmp( a[ 4 ] , a[ 5 ] ) << endl;
	cout << cmp( a[ 5 ] , a[ 8 ] ) << endl;*/
	REP( i , n ){
		int j = lower_bound( b , b + sz , a[ i ] , cmp ) - b;
		REP( j , sz ) cout << b[ j ] << ( j + 1 == sz ? "\n" : " " );
		b[ j ] = a[ i ];
		if( j == sz ) sz++;
	}
	cout << sz << '\n';
}
