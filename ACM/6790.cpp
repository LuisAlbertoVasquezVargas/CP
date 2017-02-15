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

#define N 200

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

#define N 200
#define M 200
#define EDG 40000
 
int le[ N + 5 ], ri[ M + 5 ] , distx[ N + 5 ] , disty[ M + 5 ];
int to[ EDG + 5 ], head[ N + 5 ] , NEXT[ EDG + 5 ] , edg;
int n , m;
 
void reset(){
    edg = 0;
    REP( i , n ) head[ i ] = -1;
    REP( i , n ) le[ i ] = -1;
    REP( i , m ) ri[ i ] = -1;
}
void add(int u, int v){
    to[edg] = v; NEXT[edg] = head[u]; head[u] = edg++;
}
bool bfs(){
    bool flag = false;
    REP(i, n) distx[i] = 0;
    REP(i, m) disty[i] = 0;
     
    queue< int >q;
    REP(i, n) if(le[i] == -1) q.push( i );
    while( !q.empty() ){
        int u = q.front(); q.pop();
        for(int e = head[u]; e != -1; e = NEXT[e]){
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
    for(int e = head[u]; e != -1; e = NEXT[e]){
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
int get( string &s ){
	int h = (s[ 0 ] - '0') * 10 + (s[ 1 ] - '0');
	int m = (s[ 3 ] - '0') * 10 + (s[ 4 ] - '0');
	return h * 60 + m;
}
bool in( int a , int b , int x , int y ){
	return a <= x && y <= b;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		cin >> n >> m;
		vi La , Ra , Lb , Rb;
		REP( i , n ){
			string a , b;
			cin >> a >> b;
			int ta = get( a ) , tb = get( b );
			La.pb( ta );
			Ra.pb( tb );
		}
		REP( i , m ){
			string a , b;
			cin >> a >> b;
			int ta = get( a ) , tb = get( b );
			Lb.pb( ta );
			Rb.pb( tb );
		}
		reset();
		REP( i , n ) REP( j , m )
			if( in( La[ i ] , Ra[ i ] , Lb[ j ] , Rb[ j ] ) ){
				add( i , j );
			}
		printf( "%d\n" , match() );
	}
}


