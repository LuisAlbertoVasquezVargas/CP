#include<cstdio>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < (n) ; i++ )

#define N 1000000

int id[ N + 5 ] , Rank[ N + 5 ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ));}
void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	if(pa != pb)
	{
		if(Rank[pa] < Rank[pb]) id[pa] = pb;
		else if(Rank[pa] > Rank[pb]) id[pb] = pa;
		else
		{
			id[pb] = pa;
			Rank[pa]++;
		}
	}
}
inline int get( int i , int j , int n ){
	return i * ((n << 1) + 1) + j;
}
char S[ 605 ][ 305 ];
int main(){
	int n;
	while( scanf( "%d" , &n ) == 1 ){
		REP( i , 2 * n - 1 ) scanf( "%s" , S[ i ] );
		//DEBUG( SZ(S[ 0 ]) );
		REP( i , n << 1 ) REP( j , (n << 1) + 1 ){//(2*n)x(2*n+1)
			int u = get( i , j , n );
			id[ u ] = u , Rank[ u ] = 1;
		}
		
		
		for( int i = 1 ; i <= 2 * n - 1 ; ++i ){
			for( int j = 1 ; j <= n ; ++j ){
				int x = i , y = 2 * j - ((i&1));
				//DEBUG2( x , y );
				int a = get( x - 1 , y - 1 , n );
				int b = get( x - 1 , y     , n );
				int c = get( x     , y - 1 , n );
				int d = get( x     , y     , n );
				if( S[ i - 1 ][ j - 1 ] == 'V' ){
					Union( a , c );
					Union( b , d );
				}else{
					Union( a , b );
					Union( c , d );
				}
			}
		}
		
		//(2*n)x(2*n+1)
		for( int j = 1 ; j + 1 < (n << 1) + 1 ; j += 2 ){
			Union( get( 0 , j , n ) , get( 0 , j + 1 , n ) );
			Union( get( 2 * n - 1 , j , n ) , get( 2 * n - 1 , j + 1 , n ) );
		}
		
		for( int i = 1 ; i + 1 < (n << 1) ; i += 2 ){
			Union( get( i , 0 , n ) , get( i + 1 , 0 , n ) );
		}
		
		for( int i = 0 ; i + 1 < (n << 1) ; i += 2 ){
			Union( get( i , 2 * n , n ) , get( i + 1 , 2 * n , n ) );
		}
		int ans = 0;
		REP( i , (n << 1) ) REP( j , (n << 1) + 1 ){//(2*n)x(2*n+1)
			int u = get( i , j , n );
			if( Find( u ) == u ) ans ++;
		}
		printf( "%d\n" , --ans );
	}
}




