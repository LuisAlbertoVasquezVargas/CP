#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define SZ( v ) ((int)(v).size())

#define MAXE 1000000
#define MAXV 1000000

int next[ MAXE + 5 ] , to[ MAXE + 5 ] , last[ MAXV + 5 ] , E;
void addEdge( int u , int v ){
    next[ E ] = last[ u ] , to[ E ] = v , last[ u ] = E++;
}
int vis[ MAXV + 5 ] , used[ MAXV + 5 ];
int in[ MAXV + 5 ] , out[ MAXV + 5 ] , cant = 0;

void dfs( int u ){
    if( vis[ u ] ) return;
    vis[ u ] = true;
    cant++;
    for( int e = last[ u ] ; e != -1 ; e = next[ e ] ) 
		dfs( to[ e ] );
}
int nodes[ MAXV + 5 ];
int main(){
	int cases , n = 26;
	cin >> cases;
	REP( tc , cases ){
		int m ;
		cin >> m;
		
		E = 0;
		clr( last , -1 );
		clr( in , 0 ) , clr( out , 0 );
		clr( used , 0 );
		
		int top = 0 ;
		REP( i , m ){
			string s;
			cin >> s;
			int u = s[ 0 ] - 'a' , v = s[ SZ( s ) - 1 ] - 'a';
			addEdge( u , v );  
			
			if( !used[ u ] ) nodes[ top++ ] = u , used[ u ] = 1;
            if( !used[ v ] ) nodes[ top++ ] = v , used[ v ] = 1;
			     
	    	in[ v ] ++;        
	        out[ u ] ++;
	    }
	    int odd = 0 , root = -1;
        clr( vis , 0 );
        cant = 0;
        
        REP( i , top ){
            int u = nodes[ i ];
            if( abs( (int)(in[ u ] - out[ u ]) ) == 1 ) odd++;
            else if( in[ u ] != out[ u ] ) odd = n + 5; 
            
            if( in[ u ] - out[ u ] == -1 ) root = u;
            else if( root == -1 && in[ u ] == out[ u ] ) root = u;     
        }
        
        dfs( root );

        if( cant == top && odd <= 2 ) cout << "Ordering is possible." << '\n';
        else cout << "The door cannot be opened." << '\n';
	}
}

