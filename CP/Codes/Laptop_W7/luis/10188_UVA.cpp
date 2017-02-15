#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

string f( vector< string > v )
{
	string ans;
	int nv = v.size();
	REP( i , nv )
	{
		int n = v[ i ].size();
		string temp;
		REP( j , n )
			if( v[ i ][ j ] >= '0' && v[ i ][ j ] <= '9' )
				temp = temp + v[ i ][ j ];
		ans += temp;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio( 0 );
	int n , tc = 0;
	string dummy;
	while( cin >> n )
	{
		if( n == 0 ) break;
		vector< string > S( n );
		getline( cin , dummy );
		REP( i , n ) getline( cin , S[ i ] );
		int m;
		cin >> m;
		vector< string > T( m );
		getline( cin , dummy );
		REP( i , m ) getline( cin , T[ i ] );
		if( T == S )printf( "Run #%d: Accepted\n" , ++tc );
		else
		{
			string a = f( S ) , b = f( T );
			if( a != b ) printf( "Run #%d: Wrong Answer\n" , ++tc );
			else printf( "Run #%d: Presentation Error\n" , ++tc );
		} 
	}
}
