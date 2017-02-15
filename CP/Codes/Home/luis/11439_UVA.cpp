#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 70
typedef vector< int > vi;

#define MAXN 70
int n;
bool adj[MAXN][MAXN];
int p[MAXN],m[MAXN],d[MAXN],c1[MAXN], c2[MAXN];
int q[MAXN], *qf, *qb;

int pp[MAXN];
int f(int x) {return x == pp[x] ? x : (pp[x] = f(pp[x]));}
void u(int x, int y) {pp[f(x)] = f(y);}

int v[MAXN];

void path(int r, int x){
    if (r == x) return;

    if (d[x] == 0){
        path(r, p[p[x]]);
        int i = p[x], j = p[p[x]];
        m[i] = j; m[j] = i;
    }
    else if (d[x] == 1){
        path(m[x], c1[x]);
        path(r, c2[x]);
        int i = c1[x], j = c2[x];
        m[i] = j; m[j] = i;
    }
}

int lca(int x, int y, int r){
    int i = f(x), j = f(y);
    while (i != j && v[i] != 2 && v[j] != 1){
        v[i] = 1; v[j] = 2;
        if (i != r) i = f(p[i]);
        if (j != r) j = f(p[j]);
    }
    
    int b = i, z = j;
    if(v[j] == 1) swap(b, z);

    for (i = b; i != z; i = f(p[i])) v[i] = -1;
    v[z] = -1;
    return b;
}

void shrink_one_side(int x, int y, int b){
    for(int i = f(x); i != b; i = f(p[i])){
        u(i, b);
        if(d[i] == 1) c1[i] = x, c2[i] = y, *qb++ = i;
    }
}

bool BFS(int r){
    for(int i=0; i<n; ++i)
      pp[i] = i;
    
    memset(v, -1, sizeof(v));
    memset(d, -1, sizeof(d));
    
    d[r] = 0;
    qf = qb = q;
    *qb++ = r;

    while(qf < qb){
        for(int x=*qf++, y=0; y<n; ++y){
            if(adj[x][y] && m[y] != y && f(x) != f(y)){
                if(d[y] == -1){
                    if(m[y] == -1){
            path(r, x);
            m[x] = y; m[y] = x;
            return true;
                    }
                    else{
            p[y] = x; p[m[y]] = y;
            d[y] = 1; d[m[y]] = 0;
            *qb++ = m[y];
                    }
                }
                else if(d[f(y)] == 0){
          int b = lca(x, y, r);
          shrink_one_side(x, y, b);
          shrink_one_side(y, x, b);
                }
          }
    }
  }
  
    return false;
}

int match(){
    memset(m, -1, sizeof(m));
    int c = 0;
    for (int i=0; i<n; ++i)
        if (m[i] == -1)
            if (BFS(i)) c++;
            else m[i] = i;
    
    return c;
}

int values[ N + 5 ][ N + 5 ];
vi V;
bool F( int pos ){
	clr( adj , 0 );
	for( int i = 0 ; i < n ; ++i )
		for( int j = i + 1 ; j < n ; ++j )
			if( values[ i ][ j ] >= V[ pos ] ) adj[ i ][ j ] = adj[ j ][ i ] = 1;
	return 2 * match() == n;
}
int main()
{
	int cases , val ;
	sc( cases );
	REP( tc , cases ){
		sc( n );
		n = (1<<n);
		V.clear();
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++ j ){
				sc( val );
				values[ i ][ j ] = val;
				V.pb( val );
			}
		sort( all( V ) );
		int nv = unique( all( V ) ) - V.begin();
		int lo = 0 , hi = nv - 1;
		if( F( hi ) ){
			printf( "Case %d: %d\n" , tc + 1 , V[ hi ] );
			continue;
		}
		while( hi - lo > 1 ){
			int med = (lo + hi)>>1;
			if( F( med ) ) lo = med;
			else hi = med;
		}
		printf( "Case %d: %d\n" , tc + 1 , V[ lo ] );
	}
}


