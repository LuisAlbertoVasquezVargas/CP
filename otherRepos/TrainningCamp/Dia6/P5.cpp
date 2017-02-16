#include<bits/stdc++.h>
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

#define INF (1<<30)

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

struct flowGraph{
	int n , m , s , t , E;
	vi to , cap , NEXT;//maxe * 2
	vi last , now , dist;// maxv
	flowGraph(){}
	flowGraph( int n , int m , int s , int t ) : n( n ) , m( m ) , s( s ) , t( t ) {
		to = cap = NEXT = vi( 2 * m + 5 );
		last = now = dist = vi( n + 5 );
		E = 0;
		last = vi( n + 5 , -1 );
	}
	void add( int u , int v , int uv , int vu = 0 ){
		to[ E ] = v ; cap[ E ] = uv ; NEXT[ E ] = last[ u ] ; last[ u ] = E ++;
		to[ E ] = u ; cap[ E ] = vu ; NEXT[ E ] = last[ v ] ; last[ v ] = E ++;
	}
	bool bfs(){
		REP( i , n ) dist[ i ] = INF;
		queue< int > Q;
		dist[ t ] = 0;
		Q.push( t );
		while( !Q.empty() ){
			int u = Q.front() ; Q.pop();
			for( int e = last[ u ] ; e != -1 ; e = NEXT[ e ] ){
				int v = to[ e ];
				if( cap[ e ^ 1 ] && dist[ v ] >= INF ){
					dist[ v ] = dist[ u ] + 1;
					Q.push( v );
				}
			}
		}
		return dist[ s ] < INF;
	}
	int dfs( int u , int f ){
		if( u == t ) return f;
		for( int &e = now[ u ] ; e != -1 ; e = NEXT[ e ] ){
			int v = to[ e ];
			if( cap[ e ] && dist[ u ] == dist[ v ] + 1 ){
				int ret = dfs( v  , min( f , cap[ e ] ) );
				if( ret ){
					cap[ e ] -= ret;
					cap[ e ^ 1 ] += ret;
					return ret;
				}
			}
		}
		return 0;
	}
	ll maxFlow(){
		ll flow = 0;
		while( bfs() ){
		
			REP( i , n ) now[ i ] = last[ i ];
			while( 1 ){
				int f = dfs( s , INF );
				if( !f ) break;
				flow += f;
			}
		}
		return flow;
	}
};

const int MAXN = 512;

int n , m;
char A[MAXN][MAXN];
map<pair<pair<int,int>,pair<int,int> >, int > memo_Node;

int dx[] = {1,1,-1,-1};
int dy[] = {-1,1,-1,1};

// n , m
int id = 0;
int getId( int a , int b ){
	return a * m + b;
}
int NNode(int u , int v){
	if(memo_Node[u][v] != -1)return memo_Node[u][v];
	int ans = n * m + id;
	id ++;
	return memo_Node[u][v]=ans;
}

int Bnode(int u , int v){
  return m * u + v;	
}

int Wnode(int u ,int v){
	return getId( u , v );
}

bool make_nodes(){
  int source = 500 * 500 * 6 - 1;
  int sink = 500 * 500 * 6 - 2;
  flowGraph G( 500 * 500 * 6 , 500 * 500 * 6 , source , sink );
  
  memo_Node.clear();
  
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if( A[i][j] == 'W'){
        for(int x=0; x<4; ++x){
          int u = i + dx[x] , v = j + dy[x];
          if( u >= 0 && v >= 0 && u < n && v < m){
            if( A[u][v] == 'W'){
              int node1 = NNode(i,v), node2 = NNode(u,j);
              G.add(node1 , Wnode(u,v) , 1);	
              G.add(node1 , Wnode(i,j) , 1);
			  G.add(node2 , Wnode(u,v) , 1);	
              G.add(node2 , Wnode(i,j) , 1);
			  G.add(Wnode(u,v),sink , 1);
			  G.add(Wnode(i,j),sink , 1);
            }
		  }
		}
	  }
    }
  }
  int cnt = 0;
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if( A[i][j] == 'B'){
      	cnt ++;
        G.add(Bnode(i,j) , NNode(i,j) , 2);
        G.add(source,Bnode(i,j),2);
	  }
	}
  }
  int flow = G.maxFlow();
  
  return flow == 2*cnt;
}

int main(){
  int T;
  scanf("%d",&T);
  while( T-- ){
  	id = 0;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i)
      for(int j=0; j<m; ++j)
        cin>>A[i][j];
    bool ans = make_nodes();
    puts( ans ? "YES" : "NO" );
    
  }
}
