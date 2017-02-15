#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef pair< int , int > pii;

int eval( int x , vi &poly , int mod ){
    int ans = 0;
    REP( i , SZ( poly ) ) ans = ( ans * x + poly[ i ] ) % mod;
    return ans;
}
struct Graph{
    int n , timer , top;
    vvi G;
    vi dfsn , pila, inpila , comp;
    Graph(){}
    Graph( int len ){
        timer = top = 0;
        n = len;
        G = vvi( n );
        dfsn = pila = inpila = comp = vi( n );
    }
    void add( int u , int v ){
        G[ u ].pb( v );
    }
    int dfs( int u ){
        int low = dfsn[ u ] = ++timer;
        inpila[ pila[ top ++ ] = u ] = 1;
        
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            if( dfsn[ v ] == 0 ) low = min( low , dfs( v ) );
            else if( inpila[ v ] ) low = min( low , dfsn[ v ] );
        }
        if( low == dfsn[ u ] ){
            int fin;
            do{
                fin = pila[ --top ];
                inpila[ fin ] = 0;
                comp[ fin ] = u;
            }while( fin != u );
        }
        return low;
    }
    void SCC(){
        dfsn = vi( n );
        timer = 0;
        REP( i , n ) if( !dfsn[ i ] ) dfs( i );
    }
};

int get( vi &vis , int idComp , vi &comp ){
    REP( i , SZ( vis ) )
        if( comp[ i ] == idComp && !vis[ i ] ) return i; 
    return -1;
}

const int base = 1000*1000*1000;
void impr( vi &a ){
    printf ("%d", a.empty() ? 0 : a.back());
    for (int i=SZ(a)-2; i>=0; --i)
        printf ("%09d", a[i]);
}
int getLen( vi &a ){
    if( a.empty() ) return 1;
    int r = a.back();
    int ans = 0;
    while( r ){
        r /= 10;
        ans ++;
    }
    ans += 9 *( SZ( a ) - 1 );
    return ans;
}
vi get( string s ){
    vi a;
    for (int i=(int)s.length(); i>0; i-=9)
        if (i < 9)
            a.push_back (atoi (s.substr (0, i).c_str()));
        else
            a.push_back (atoi (s.substr (i-9, 9).c_str()));
    while (a.size() > 1 && a.back() == 0) a.pop_back();
    return a;
}

vi mult1( vi a , int b ){
    int carry = 0;
    for (size_t i=0; i<a.size() || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        long long cur = carry + a[i] * 1ll * b;
        a[i] = int (cur % base);
        carry = int (cur / base);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}


int main(){
    
    freopen( "stable.in" , "r" , stdin );
    freopen( "stable.out" , "w" , stdout );
    
    int R;
    while( sc( R ) == 1 ){
        int n , m;
        sc( n );
        vvi p( 2 );
        p[ 0 ].resize( n + 1 );
        REP( i , n + 1 ) sc( p[ 0 ][ i ] );
        sc( m );
        p[ 1 ].resize( m + 1 );
        REP( i , m + 1 ) sc( p[ 1 ][ i ] );
            
        vector< Graph > G( 2 , Graph( R ) );
        REP( i , 2 ) REP( j , R ) {
      		//DEBUG2( j , eval( j , p[ i ] , R ) );
        	G[ i ].add( j , eval( j , p[ i ] , R ) );
        }
    
        REP( i , 2 ) G[ i ].SCC();      
        
        vvvi STACK( 2 , vvi( R ) );
        REP( i , 2 ) REP( j , R ){
        	//DEBUG2( j , G[ i ].comp[ j ] );
        	STACK[ i ][ G[ i ].comp[ j ] ].pb( j );
        }
        
        vvvi T( 2 );
        REP( i , 2 ) REP( j , R ) if( G[ i ].comp[ j ] == j && (SZ( STACK[ i ][ G[ i ].comp[ j ] ] ) >= 2 || j == eval( j , p[ i ] , R )) ){
        	T[ i ].pb( STACK[ i ][ G[ i ].comp[ j ] ] );
        }
        
        n = SZ( T[ 0 ] ) + SZ( T[ 1 ] );
        vi valid( n , 1 );
        vvi mapa( 2 );
        REP( i , SZ( T[ 0 ] ) ) mapa[ 0 ].pb( i );
        REP( i , SZ( T[ 1 ] ) ) mapa[ 1 ].pb( SZ( T[ 0 ] ) + i );
        vvi adj( n );
        REP( k , 2 ){
		    REP( i , SZ( T[ k ] ) ){
		    	auto v1 = T[ k ][ i ];
		    	bool val = 1;
		    	for( auto x : v1 ){
		    		bool found = 0;
		    		REP( j , SZ( T[ k ^ 1 ] ) ){
		    			auto v2 = T[ k ^ 1 ][ j ];
						for( auto y : v2 )
							if( x == y ){
								found = 1;
								int u = mapa[ k ][ i ];
								int v = mapa[ k ^ 1 ][ j ];
								adj[ u ].pb( v );
								adj[ v ].pb( u );
								break;
							}
						if( found ) break;
					}
					if( !found ) val = 0;
	    		}
	    		if( !val ) valid[ mapa[ k ][ i ] ] = 0;
	    	}
	    }

        vi vis( n );
        queue< int > Q;
        
        REP( i , n ){
        	if( valid[ i ] ) continue;
        	if( vis[ i ] ) continue;

        	Q.push( i );
        	vis[ i ] = 1;
        	while( !Q.empty() ){
        		int u = Q.front(); Q.pop();
        		for( auto v : adj[ u ] ){
        			if( !vis[ v ] ){
        				valid[ v ] = 0;
        				Q.push( v );
        				vis[ v ] = 1;
        			}
        		}
        	}
        }
        int ct = 0;
        vis = vi( n );
        REP( i , n ){
        	if( !valid[ i ] ) continue;
        	if( vis[ i ] ) continue;

        	ct ++;
        	Q.push( i );
        	vis[ i ] = 1;
        	while( !Q.empty() ){
        		int u = Q.front(); Q.pop();
        		for( auto v : adj[ u ] ){
        			if( !vis[ v ] && valid[ v ] ){
        				Q.push( v );
        				vis[ v ] = 1;
        			}
        		}
        	}
        }
        vi ans = get( "1" );
        REP( i , ct ) ans = mult1( ans , 2 );
        impr( ans );
        puts( "" );
    }
}



