#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()

void impr( vector< string > v ){
	int nv = v.size();
	REP( i , nv ) cout << v[ i ] << '\n';
}
int main()
{
	string s;
	bool ok = 0;
	while( cin >> s ){
		if( ok ) puts( "" );
		else ok = 1;
		set< string > Set;
		int n = s.size();
		vector< string > v;
		string temp;
		for( int i = n - 1 ; i >= 0 ; --i ){
			string t = s;
			char c = s[ i ];
			t.erase( t.begin() + i );

			temp = t + c;

			if( !Set.count( temp ) ) {
				v.pb( temp );
				//v.pb( temp ) , Set.insert( temp );
			}
			for( int j = n - 3 ; j >= 0 ; --j ){
				temp = t.substr( 0 , j +  1 ) + c + t.substr( j + 1 );
				//cout << "TEMP " << temp << endl;
				//if( !Set.count( temp ) ) v.pb( temp ) , Set.insert( temp );
				if( !Set.count( temp ) ) {
					v.pb( temp );
					//v.pb( temp ) , Set.insert( temp );
				}
			}
			temp = c + t;

			//if( !Set.count( temp ) ) v.pb( temp ) , Set.insert( temp );
			if( !Set.count( temp ) ) {
				v.pb( temp );
				//v.pb( temp ) , Set.insert( temp );
			}
		}
		temp = s;
		reverse( all( temp ) );
		v.pb( temp ) , Set.insert( temp );		
		reverse( all( v ) );		
		impr( v );
	}
}
