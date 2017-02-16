#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

int main(){
	int cases;
	scanf( "%d" , &cases );
	REP(tc , cases){
		int n;
		scanf( "%d" , &n );
		REP( i , n )
			putchar( 'a' + i % 26 );
		puts( "" );
	}
}


