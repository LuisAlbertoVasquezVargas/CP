#include<bits/stdc++.h>
#define N 10
#define ll long long
#define INF 10000000000000LL
using namespace std;

ll D[ N+5 ][ N+5 ];
int ind[ N+5 ] , A[ N+5 ];
bool vis[ N+5 ];

int main( ){
	int n , m , t , s ,e , x , y , z;
	while( cin>>n>>m>>t ){
		cin>>s>>e;
		for( int i =0 ; i<n ; ++i ){
			cin>>A[ i ];
			ind[ i ] = i;
		}
		for( int i=0 ; i<n ; ++i ){
			for( int j=0 ; j<n ; ++j ){
				D[ i ][ j ]=INF;
			}
		}
		for( int i =0 ; i<n ; ++i )D[ i ][ i ]=0;
		for( int i=0 ; i<m ; ++i ){
			cin>>x>>y>>z;
			D[ x ][ y ]=z;
			D[ y ][ x ]=z;
		}
		for( int k=0 ; k<n ; ++k ){
			for( int i=0 ; i<n ; ++i ){
				for( int j =0 ; j<n ; ++j ){
					D[ i ][ j ]=min( D[ i ][ j ] , D[ i ][ k ] + D[ k ][ j ] );
				}
			}
		}
		ll val = A[ s ] ,maxi =0 ;
		
		do{
			ll cur = val, temp=0;
			memset( vis , 0 , sizeof( vis ));
			int last = s;
			vis[ last ]=1;
			if( temp + D[ s ][ e ] <= t ) maxi=max( maxi , cur );
			for( int i =0 ; i<n ; ++i ){
				int pos = ind[ i ];
				if( temp + D[ last ][ pos ] + D[ pos ][ e ] <=t ){
					if( vis[ pos ] )continue;
					vis[ pos ]=1;
					maxi=max( maxi , cur + A[ pos ] );
					cur+=A[ pos];
				}
				last = pos;
			}
		}while( next_permutation( ind , ind+n ) );
		cout<<maxi<<endl;
	}
}
