#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ( (int)v.size() )

#define mp make_pair
#define fi first
#define se second

#define N 100000

int main(){
	int L = 1e5;
	vector< pair< double , pair< double , double > > > V;
	REP( i , N ){
		int x = rand() %L;
		if( x <= 0 ) continue;
		double X = x/1000.0;
		double Y = 40.0/X;
		V.pb( mp( 32*Y + 50*X , mp( X , Y ) ) );
		//printf( "%.5lf %.5lf %.5lf\n" , X , Y , 32*Y + 50*X );
	}
	sort( all( V ) );
	REP( i , 8 ){
		double X = V[ i ].se.fi;
		double Y = V[ i ].se.se;
		//printf( "%.5lf\n" , V[ i ].fi );
		//printf( "%.5lf %.5lf %.5lf\n" , X , Y , 32*Y + 50*X );
		printf( "%.5lf\n" , 32*Y + 50*X );
	}
}
