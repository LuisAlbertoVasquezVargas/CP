#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define all( v ) v.begin() , v.end()

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define test puts( "***************test***************");

typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

vpii sol;
int ns;
string s;
vi vis , L , R;

void output(){
	sort( all( sol ) );
	sol.resize( unique( all( sol ) ) - sol.begin() );
	int nsol = sol.size();
	printf( "%d\n" , nsol );
	REP( i , nsol ) printf( "%d %d\n" , sol[ i ].fi + 1 , sol[ i ].se + 1 );
}
void insert( int lo , int hi ){
	if( hi < lo ) swap( lo , hi );
	if( (lo + 1)%ns != hi && (hi + 1)%ns != lo ) sol.pb( mp( lo , hi ) );
}
void impr()
{
	REP( i , ns ) 
		if( !vis[ i ] ){
			for( int j = i ; ; j = R[ j ] ){
				cout << j << " ";
				if( R[ j ] == i ) break;
			}
			cout << endl;
			break;
		}
}
int main()
{
	while( cin >> ns >> s )
	{
		REP( i , ns ) 
			if( s[ i ] == 'R' ) s[ i ] = '0';
			else if( s[ i ] == 'G' ) s[ i ] = '1';
			else s[ i ] = '2';
		vis = vi( ns ) , L = vi( ns ) , R = vi( ns );
		REP( i , ns ) L[ i ] = ( i - 1 + ns )%ns;
		REP( i , ns ) R[ i ] = ( i + 1 )%ns;
		sol.clear();
		REP( it , ns - 3 ){
			//impr();
			bool solve = 0;
			vi cnt( 3 );
			REP( i , ns ) if( !vis[ i ] ) cnt[ s[ i ] - '0' ]++;
			REP( target , 3 ) 
				if( cnt[ target ] == 1 )
				{
					//cout << "target : " << target << endl;
					REP( i , ns ) 
						if( !vis[ i ] && s[ i ] - '0' == target )
						{
							for( int j = R[ R[ i ] ] ; ; j = R[ j ] ){
								insert( i , j );
								if( R[ j ] == i ) break;
							}
							//test
							break;
						}
					solve = 1;
					break;
				}
			//cout << "Solve : " << solve << "at : " << it << endl;
			if( solve ) break;
			int ind;
			REP( i , ns ) 
				if( !vis[ i ] ) {
					ind = i;
					break;
				}
			for( int j = ind ; ; j = R[ j ] ){
				int prev = L[ j ] , next = R[ j ];
				if( s[ prev ] != s[ j ] && s[ j ] != s[ next ] && s[ next ] != s[ prev ] )
				{
					vis[ j ] = 1;
					insert( prev , j );
					insert( j , next );
					insert( next , prev );
					R[ prev ] = next , L[ next ] = prev;
					break;
				}
				if( R[ j ] == ind ) break;
			}
		}
		output();
	}
}

