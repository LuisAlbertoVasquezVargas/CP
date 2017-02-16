#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define test puts( "********test*****");

#define all( v ) v.begin() , v.end()
#define pb push_back

typedef vector< int > vi;

int main()
{
	ios_base::sync_with_stdio( 0 );
	string dummy;
	int cases;
	cin >> cases;
	REP( u , cases )
	{
		if( u ) cout << endl;
		int n , x;
		cin >> n;
		getline( cin , dummy );
		vector< string > CandidateNames( n );
		REP( i , n ) getline( cin , CandidateNames[ i ] );
		string s;
		vector< vi > votes;
		while( 1 )
		{
			getline( cin , s );
			if( s == "" )break;
			istringstream in( s );
			vi v;
			REP( i , n )
			{
				in >> x;
				v.pb( --x );
			}
			votes.pb( v );
		}
		int nvotes = votes.size();
		vi vis( n );
		while( 1 )
		{
			vi cnt( n );
			REP( i , nvotes )
			{
				int candidate;
				REP( j , n )
					if( !vis[ votes[ i ][ j ] ] )
					{
						candidate = votes[ i ][ j ];
						break;
					}
				cnt[ candidate ] ++;
			}
			int maxi = *max_element( all( cnt ) ) , mini = *min_element( all( cnt ) );
			if( maxi == mini ) break;
			if( 2*maxi > nvotes )
			{
				REP( i , n )if( cnt[ i ] != maxi ) vis[ i ] = 1;
				break;
			}
			REP( i , n )if( cnt[ i ] == mini ) vis[ i ] = 1;
		}
		vector< string > ans;
		REP( i , n )
			if( !vis[ i ] ) ans.pb( CandidateNames[ i ] );
		int nans = ans.size();
		REP( i , nans )
			cout << ans[ i ] << ( i + 1 == nans ? "\n":" " ); 
	}
}
