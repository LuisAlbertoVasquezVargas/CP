#include<bits/stdc++.h>
using namespace std;

#define clr( t , val ) memset( t , val , sizeof( t ) )

#define MAX_V 10005
#define MAX_E 10005

int E , s , t ;
int cap[ 2*MAX_E ] , to[ 2*MAX_E ] , next[ 2*MAX_E ];
int last[ MAX_V ] , visited[ MAX_V ];
void clear(){
    clr( last , -1 ); 
    E = 0;
}
void add_edge(int u, int v, int uv, int vu = 0 ){
    to[ E ] = v, cap[ E ] = uv, next[ E ] = last[ u ]; last[ u ] = E++;
    to[ E ] = u, cap[ E ] = vu, next[ E ] = last[ v ]; last[ v ] = E++;
}
int dfs( int v , int f ){
    if(v == t || f <= 0 ) return f;
    if( visited[ v ] ) return 0;
    visited[ v ] = true;
    for(int e = last[ v ] ; e != -1 ; e = next[ e ] ){
        int ret = dfs( to[ e ] , min( f , cap[ e ] ) );
        if( ret > 0 ){
            cap[ e ] -= ret;
            cap[ e^1 ] += ret;
            return ret;
        }
    }
    
    return 0;
}
int max_flow( int source , int sink ){
    s = source, t = sink;
    int f = 0 , x;
    while( 1 ){
        clr( visited , 0 );
        x = dfs( s , INT_MAX );
        if( x == 0 ) break;
        f += x;
    }
    return f;
}
int main()
{
	
}
