#include<bits/stdc++.h>
using namespace std;

#define all( v ) v.begin() , v.end()


string rev( string s ){
	reverse( all( s ) );
	return s;
}
string s;
int ns;
bool solve()
{
	int sz = 3;
	for( int i = 0 ; i + 3 <= ns ; ++i ){
		string t = s.substr( i , 3 );
		if( t == rev( t ) ){
			for( int j = i + 1 ; j + 4 <= ns ; ++j )
			{
				string p = s.substr( j , 4 );
				if( p == rev( p ) )
					return 1;
			}
			for( int j = i + 1 ; j + 3 <= ns ; ++j )
			{
				string p = s.substr( j , 3 );
				if( p == rev( p ) )
					if( t != p ) {
						//cout << "la concha" << endl;
						return 1;
					}
			}
		}
	}
	for( int i = 0 ; i + 4 <= ns ; ++i ){
		string t = s.substr( i , 4 );
		if( t == rev( t ) ){
			for( int j = i + 1 ; j + 4 <= ns ; ++j )
			{
				string p = s.substr( j , 4 );
				if( p == rev( p ) )
					if( p != t )return 1;
			}
			for( int j = i + 2 ; j + 3 <= ns ; ++j )
			{
				string p = s.substr( j , 3 );
				if( p == rev( p ) )
					return 1;
			}
		}
	}
	
	return 0;
}
int main()
{	
	ios_base::sync_with_stdio( 0 );
	while( cin >> s ){
		ns = s.size();
		if( ns <= 3 ) continue;
		//cout << s << " " << solve( 3 ) << " " << solve( 4 ) << endl;
		bool ans = solve();
		if( ans ) cout << s << '\n';
	}
}
