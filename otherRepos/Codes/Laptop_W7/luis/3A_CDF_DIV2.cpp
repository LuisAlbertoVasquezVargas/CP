#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define pb push_back

typedef vector< string > vs;

void impr( vs v ){
	int nv = v.size();
	cout << nv << '\n';
	REP( i , nv ) printf( "%s%c" , v[ i ].c_str() , 10 );
}

int main()
{
	string t , s;
	while( cin >> s >> t ){
		int x = s[ 0 ] - 'a' , y = s[ 1 ] - '1';
		int X = t[ 0 ] - 'a' , Y = t[ 1 ] - '1';
		vs ans;
		while( x < X && y < Y ) x++ , y++ , ans.pb( "RU" );
		while( x < X && y > Y ) x++ , y-- , ans.pb( "RD" );
		while( x > X && y < Y ) x-- , y++ , ans.pb( "LU" );
		while( x > X && y > Y ) x-- , y-- , ans.pb( "LD" );
		while( x < X && y == Y ) x++ , ans.pb( "R" );
		while( x > X && y == Y ) x-- , ans.pb( "L" );
		while( x == X && y < Y ) y++ , ans.pb( "U" );
		while( x == X && y > Y ) y-- , ans.pb( "D" ); 
		impr( ans );
		
	}
}
