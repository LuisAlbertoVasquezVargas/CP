#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 10005
#define inf (1<<30)

typedef vector< int > vi;
typedef pair< int , int > pii;

int n;
vi adj[N], cost[N];
bool vis[N];
 
void dijkstra(int x,vi &d){
    clr(vis,0);
    d[x] = 0;
    priority_queue< pii > Q;
    Q.push( mp( 0 , x ) );
    while( !Q.empty() ){
        pii q = Q.top(); Q.pop();
        int u = q.se , di = -q.fi;
        //cout << u << " " << di << endl;
        if( vis[u] ) continue;
        vis[u] = 1;
        for( int i = adj[u].size() - 1 ; i >= 0 ; i--){
            int v = adj[u][i] , nd = di + cost[u][i];
            if( nd < d[v] ){
                d[v] = nd;
                Q.push( mp( -nd , v ) );
            }
        }
    }
}
 
int main(){
    int bar , chito , nito , m;
    while( scanf("%d%d%d%d%d",&n,&bar,&chito,&nito,&m) == 5 ){
        if( n == -1 ) break;
 
        int a , b , c;
        for(int i = 0 ; i < n + 2 ; i++)
            adj[i].clear() , cost[i].clear();
       
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&a,&b,&c); a--,b--;
            adj[a].pb(b); cost[a].pb(c);
            adj[b].pb(a); cost[b].pb(c);
        }
        bar--,chito--,nito--;
        vi initbar( n + 2 , inf );
        vi initchito( n + 2 , inf );
        vi initnito( n + 2 , inf );
        dijkstra( bar , initbar );
        dijkstra( chito , initchito );
        dijkstra( nito , initnito );
        int dchito = initbar[chito] , dnito = initbar[nito];
        int ans = 0;
 
       
        for(int i = 0 ; i < n ; i++){
            int k = i;
            if( initbar[i] + initchito[i] == dchito and initbar[i] + initnito[i] == dnito ){
                ans = max( ans , initbar[i] );
            }
        }
        dchito -= ans , dnito -= ans;
        printf("%d %d %d\n", ans , dchito , dnito );
       
    }
} 



