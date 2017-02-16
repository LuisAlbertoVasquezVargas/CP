#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define mp make_pair

#define fi first
#define se second

#define N 105

typedef vector< pair< string , int > >vsi;
int A[ N ];

int main()
{
	int n , m ;
	while( cin >> n )
	{
		REP( i , n ) cin >> A[ i ];
		sort( A , A + n );
		reverse( A , A + n );
		cin >> m;
		vsi v( m );
		REP( i , m ) {
			string operation;
			int team;
			cin >> operation >> team;
			v[ i ] = mp( operation , team );
		}
		int ans1 = 0 , ans2 = 0 , it = 0;
		REP( i , m ){
			int ind = i;
			for( int j = i ; j < m ; ++j )
				if( v[ i ].se == v[ j ].se ) ind = j;
				else break;
			sort( v.begin() + i , v.begin() + ind + 1 );
			reverse( v.begin() + i , v.begin() + ind + 1 );
			for( int j = i ; j <= ind ; ++j ){
				//cout << v[ j ].fi << " " << v[ j ].se << endl;
				if( v[ j ].se == 1 )
				{
					if( v[ j ].fi == "p" ) ans1 += A[ it++ ];
					else it++;
				}
				else
				{
					if( v[ j ].fi == "p" ) ans2 += A[ it++ ];
					else it ++;
				}
			}
			//cout << endl;
			i = ind;
		}
		cout << ans1 - ans2 << '\n';
	}
}
