#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , K;
	while( scanf( "%d%d" , &n , &K ) == 2 ){
		if( K >= n ) puts( "2" );
		else printf( "%d\n" , (2 * n - 1) / K + 1 );
	}
}


