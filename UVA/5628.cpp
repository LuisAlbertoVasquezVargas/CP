#include <bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i=0 ; i < n ; i++ )
#define SZ(v) ((int)(v).size())
#define all( v ) v.begin(),v.end()
#define pb push_back

#define N 50

typedef long long ll;

string M[ N + 5 ];
bool vis[ N + 5 ][ N + 5 ];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };
int n , m;
bool valid( int x , int y ){
	return 0 <= x && x < n && 0 <= y && y < m ;
}

//qac == 0 estoy en asterisco *
//qac == 1 estoy en X y solo me interesa pintar X
int ans = 0;
void dfs( int x, int y , int qac ){  // qac ==0 :v     qac==1 ( pintar )
	vis[ x ][ y ] = 1 ;
	REP( k , 4 ){
		int nx = x + dx[ k ];
		int ny = y + dy[ k ];
		
		if( !vis[ nx ][ ny ] && valid( nx , ny )  ){
			if( M[ nx ][ ny ] == '*' && qac == 0 ){
				dfs( nx , ny , 0 ) ;
				continue;
			}
			if( M[ nx ][ ny ] == 'X' && qac == 0 ){
				dfs( nx , ny , 1 ) ; // solo pintalo (just do it !)
				ans ++;
				continue;
			}
			if( M[ nx ][ ny ] == '*' && qac == 1 ){
				dfs( nx , ny , 0 );
				continue;
			}
			if( M[ nx ][ ny ] == 'X' && qac == 1 ){
				dfs( nx , ny , 1 ) ;
				continue;
			}
		}
	}
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	int Throw = 0;
	while( cin >> m >> n ){
		if( n == 0 && m == 0 ) break ;
		Throw ++ ;
		
		REP( i , n ) REP( j , m ) vis[ i ][ j ] = 0;
		
		REP( i , n ) cin >> M[ i ];
		REP( i , n ) REP( j , m ) if( M[ i ][ j ] == '.' ) vis[ i ][ j ] = 1;
		
		vector<int> v;
	
		REP( j , m ){
			REP( i , n ){
				if( !vis[ i ][ j ] && M[ i ][ j ] == '*' ){
					//siempre empiezo pintando en el borde del dado , luego pinto los puntitos >.< 
					ans = 0;
					dfs( i , j , 0 );
					v.push_back( ans ); 
				}
			}
		}
		
		sort( all( v ) ) ;
		cout << "Throw " << Throw << '\n';
		
		
		REP( i , SZ(v) ) 
			cout << v[ i ] << char( (i + 1 == v.size() ) ? 10 : 32 );
		cout << '\n';
	}	
}


