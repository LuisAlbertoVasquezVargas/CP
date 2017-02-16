#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )

#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define sync ios_base::sync_with_stdio(false);


typedef pair< int , int > pii;
typedef vector< int > vi;

int toi( string s ){ istringstream in( s ) ; int x ; in >> x; return x; }

#define N 500
#define M 500
#define EDG 250000

int le[ N + 5 ], ri[ M + 5 ] , distx[ N + 5 ] , disty[ M + 5 ];
int to[ EDG + 5 ], head[ N + 5 ] , next[ EDG + 5 ] , edg;
int n , m;

void reset(){
	edg = 0;
	REP( i , n ) head[ i ] = -1;
	REP( i , n ) le[ i ] = -1;
	REP( i , m ) ri[ i ] = -1;
}
void add(int u, int v){
    to[edg] = v; next[edg] = head[u]; head[u] = edg++;
}
bool bfs(){
    bool flag = false;
    REP(i, n) distx[i] = 0;
    REP(i, m) disty[i] = 0;
    
	queue< int >q;
    REP(i, n) if(le[i] == -1) q.push( i );
    while( !q.empty() ){
        int u = q.front(); q.pop();
        for(int e = head[u]; e != -1; e = next[e]){
            int v = to[e];
            if(!disty[v]){
                disty[v] = distx[u] + 1;
                if(ri[v] == -1) flag = true;
                else distx[ri[v]] = disty[v] + 1, q.push( ri[v] );
            }
        }
    }
    return flag;
}
bool dfs(int u){
    for(int e = head[u]; e != -1; e = next[e]){
        int v = to[e];
        if(disty[v] == distx[u] + 1){
            disty[v] = 0;
            if(ri[v] == -1 || dfs(ri[v])){
                le[u] = v;
                ri[v] = u;
                return true;
            }
        }
    }
    return false;
}

int match(){
    int res = 0;
    while(bfs())
        REP( i , n )
            if(le[i] == -1 && dfs(i)) res++;
    return res;
}


int main(){
	sync
	string s , t;
	int cases , cats , dogs , voters;
	cin >> cases;
	REP( tc , cases ){
		cin >> cats >> dogs >> voters;
		vector< pii > catLovers , dogLovers;
		REP( i , voters ){
			cin >> s >> t;
			int a = toi( s.substr( 1 ) ) , b = toi( t.substr( 1 ) );
			a-- , b--;
			if( s[ 0 ] == 'C' )
				catLovers.pb( mp( a , b ) );
			else
				dogLovers.pb( mp( a , b ) );
		}
		n = catLovers.size();
		m = dogLovers.size();
		reset();
		REP( i , n ) REP( j , m )
			if( catLovers[ i ].se == dogLovers[ j ].fi || catLovers[ i ].fi == dogLovers[ j ].se )
				add( i , j );
		int ans = n + m - match();
		cout << ans << '\n';
	}
}


