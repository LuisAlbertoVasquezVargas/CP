#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back

#define test puts( "******************test****************" );

typedef vector< int > vi;
typedef vector< vi > vvi;

int n;
vi proc( string s ){
	istringstream in( s );
	vi v;
	int x;
	while( in >> x ) v.pb( x );
	return v;
}
int LCS( vi &v ){
	v.insert( v.begin() , -1 );
	n++;
	vvi DP( n + 1 , vi( n + 1 ) );
	for( int pos = n - 1 ; pos >= 0 ; --pos )
		for( int last = pos ; last >= 0 ; last -- )
		{
			int &dev = DP[ pos ][ last ] = DP[ pos + 1 ][ last ];
			if( v[ pos ] > v[ last ] ) dev = max( dev , 1 + DP[ pos + 1 ][ pos ] );
		}
	n--;
	return DP[ 0 ][ 0 ];
}
int main()
{
	string dumm , s;
	while( cin >> n )
	{
		getline( cin , dumm );
		getline( cin , s );
		vi w = proc( s );
		vi mapa( n );
		//REP( i , n ) mapa[ --w[ i ]  ] = i;
		REP( i , n ) mapa[ i ] = --w[ i ];
		while( 1 )
		{
			getline( cin , s );
			if( s == "" ) break;
			vi v = proc( s );
			REP( i , n ) w[ mapa[ i ] ] = --v[ i ];
			printf( "%d\n" , LCS( w ) );
		}
	}
}
