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
typedef pair< int , int > pii;
typedef vector< int > vi;

#define MAX_V 500
const int INF = 100000;
int V,W,cost[MAX_V][MAX_V];
int lx[MAX_V],ly[MAX_V];
int max_match,xy[MAX_V],yx[MAX_V],PREV[MAX_V];
bool S[MAX_V],T[MAX_V];
int slack[MAX_V],slackx[MAX_V];
int q[MAX_V],head,tail;

void init_labels(){
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    REP( x , V )
        REP( y , W )
            lx[x] = max(lx[x],cost[x][y]);
}

void update_labels(){
    int x,y,delta = INT_MAX;
	
    for(y = 0;y<W;++y) if(!T[y]) delta = min(delta,slack[y]);
    for(x = 0;x<V;++x) if(S[x]) lx[x] -= delta;
    for(y = 0;y<W;++y) if(T[y]) ly[y] += delta;
    for(y = 0;y<W;++y) if(!T[y]) slack[y] -= delta;
}

void add_to_tree(int x, int prevx){
    S[x] = true;
    PREV[x] = prevx;
	
    for(int y = 0;y<W;++y){
        if(lx[x]+ly[y]-cost[x][y]<slack[y]){
            slack[y] = lx[x]+ly[y]-cost[x][y];
            slackx[y] = x;
        }
    }
}

void augment(){
    int x,y,root;
    head = tail = 0;
    memset(S,false,sizeof(S));
    memset(T,false,sizeof(T));
    memset(PREV,-1,sizeof(PREV));
    
    for(x = 0;x<V;++x){
        if(xy[x]==-1){
            q[tail++] = root = x;
            PREV[root] = -2;
            S[root] = true;
            break;
        }
    }
	
    for(y = 0;y<W;++y){
        slack[y] = lx[root]+ly[y]-cost[root][y];
        slackx[y] = root;
    }
	
    while(true){
        while(head<tail){
            x = q[head++];
			
            for(y = 0;y<W;++y){
                if(cost[x][y]==lx[x]+ly[y] && !T[y]){
                    if(yx[y]==-1) break;
					
                    T[y] = true;
                    q[tail++] = yx[y];
                    add_to_tree(yx[y],x);
                }
            }
			
            if(y<W) break;
        }
		
        if(y<W) break;
		
        update_labels();
        head = tail = 0;
		
        for(y = 0;y<W;++y){
            if(!T[y] && slack[y]==0){
                if(yx[y]==-1){
                    x = slackx[y];
                    break;
                }
				
                T[y] = true;
				
                if(!S[yx[y]]){
                    q[tail++] = yx[y];
                    add_to_tree(yx[y],slackx[y]);
                }
            }
        }
		
        if(y<W) break;
    }
	
    ++max_match;
	
    for(int cx = x,cy = y,ty;cx!=-2;cx = PREV[cx],cy = ty){
        ty = xy[cx];
        yx[cy] = cx;
        xy[cx] = cy;
    }
}

int hungarian(){
    int ret = 0;
    max_match = 0;
    memset(xy,-1,sizeof(xy));
    memset(yx,-1,sizeof(yx));
	
    init_labels();
    REP( i , V ) augment();
    REP( x , V ) ret += cost[x][xy[x]];
	
    return ret;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( V ) , sc( W );
		int m;
		sc( m );
		//W = V;
		REP( x , V ) REP( y , W ) cost[ x ][ y ] = -INF;
		REP( i , m ){
			int u , v , w ;
			sc( u ) , sc( v ) , sc( w );
			cost[ u ][ v ] = -w;
		}
		if( tc ) puts( "" );
		printf( "%d\n" , -hungarian() );
	}
}


