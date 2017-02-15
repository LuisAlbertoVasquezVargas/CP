#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

#define MAXN 224
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

int main()
{
	sc( n );
	int x , y;
	while( scanf( "%d%d" , &x , &y ) == 2 )
		x-- , y-- , adj[ y ][ x ] = adj[ x ][ y ] = 1;
	printf( "%d\n" , 2*match() );
	REP( i , n )
		if( m[ i ] != -1 && i < m[ i ] )
			printf( "%d %d\n" , i + 1 , m[ i ] + 1 );
} 


