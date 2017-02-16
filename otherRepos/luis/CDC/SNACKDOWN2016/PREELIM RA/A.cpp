#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for( int i = 0 ; i < n ; ++i)

const int N = 100000;
int A[ N + 5 ];
int main(){
	int cases;
	scanf( "%d" , &cases );
	REP( tc , cases ){
		int n;
		scanf( "%d" , &n );
		REP( i , n ) scanf( "%d" , &A[ i ] );
		bool ok = 0;
		REP( i , n - 2 )
			if( A[ i ] == A[ i + 1 ] && A[ i ] == A[ i + 2 ] ){ 
				ok = 1;
				break;
			}
		puts( ok ? "Yes" : "No" );
	}
}



