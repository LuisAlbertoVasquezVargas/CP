#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef vector< int > vi;
typedef vector< vi > vvi;

double get( int curSum , int sum , int n){
	return abs( sum - curSum * n);
}
int main(){
	int C , S;
	while( scanf( "%d%d" , &C , &S ) == 2 ){
		vi v( S );
		REP(i , S) scanf( "%d" , &v[ i ] );
		int sum = accumulate( all( v ) , 0 );
		sort( all(v) );
		reverse( all(v) );
		
		vvi T(C);
		
		int j = 0;
		for( int i = 0 ; i < C ; ++i ){
			int curSum = 0;
			REP( k , 2 ){
				if( j < S ){
					if( get(curSum + v[ j ] , sum , C) <= get( curSum , sum , C) ){
						T[ i ].push_back( v[ j ] );
						curSum += v[ j ];
						j++;
					}else break;
				}else break;
			}
		}
		
	
		
		REP(i , C){
			REP( j , SZ(T[ i ]) ){
				printf( "%d%c" , T[ i ][ j ] , (j + 1 == SZ(T[ i ])? 10 : 32) );
			}
		}
	}
}



