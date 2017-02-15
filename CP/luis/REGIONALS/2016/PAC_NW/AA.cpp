#include<bits/stdc++.h>
#define N 505
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
#define DEBUG3( x , y,z ) cerr << #x << "=" << x << " " << #y << "=" << y << " "<<#z << "=" << z<< endl;
using namespace std;
	
int p[N], temp[N][N], D[N][N], trans[N][N];
int s[N], f[N], t[N];

const int MAX_N=1005;
#define M 1005
#define EDG 1000005

int le[ MAX_N + 5 ], ri[ M + 5 ] , distx[ MAX_N + 5 ] , disty[ M + 5 ];
int to[ EDG + 5 ], head[ MAX_N + 5 ] , Next[ EDG + 5 ] , edg;
//int n , m;

void reset(int n,int m){
	edg = 0;
	REP( i , n ) head[ i ] = -1;
	REP( i , n ) le[ i ] = -1;
	REP( i , m ) ri[ i ] = -1;
}
void add(int u, int v){
    to[edg] = v; Next[edg] = head[u]; head[u] = edg++;
}
bool bfs(int n,int m){
    bool flag = false;
    REP(i, n) distx[i] = 0;
    REP(i, m) disty[i] = 0;
    
	queue< int >q;
    REP(i, n) if(le[i] == -1) q.push( i );
    while( !q.empty() ){
        int u = q.front(); q.pop();
        for(int e = head[u]; e != -1; e = Next[e]){
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
    for(int e = head[u]; e != -1; e = Next[e]){
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

int match(int n){
    int res = 0;
    while(bfs(n,n))
        REP( i , n )
            if(le[i] == -1 && dfs(i)) res++;
    return res;
}

int main(){
		
	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
		
		for(int i = 0; i < n; i++)scanf("%d", &p[i]);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				
				scanf("%d", &temp[i][j]);
				if(i == j)D[i][j] = 0;
				else D[i][j] = temp[i][j] + p[j];
			}
		}
		
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					
					if(D[i][j] > D[i][k] + D[k][j])D[i][j] = D[i][k] + D[k][j];	
				}
			}
		}
		//DEBUG2(D[0][1],D[1][0]);

		for(int i = 0; i < m; i++){
			
			scanf("%d%d%d", &s[i], &f[i], &t[i]);
			s[i]--; f[i]--;
		}
		
		int u, v;

		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++){
				if(i==j){
					trans[i][i]=1;
					continue;
				}
				if(t[i] >= t[j]){
					trans[i][j]=0;
					continue;
				}
				u = f[i], v = s[j];
				if(t[i] + temp[s[i]][f[i]] + p[f[i]] + D[u][v] <= t[j])trans[i][j] = 1;
				else trans[i][j] = 0;
			}
		}
		
		/*
		for(int k = 0; k < m; k++){
			for(int i = 0; i < m; i++){
				for(int j = 0; j < m; j++){
					trans[i][j] = trans[i][j] || (trans[i][k]&&trans[k][j]);
				}
			}
		}
		*/
		//REP(i,m)REP(j,m)DEBUG3(i,j,trans[i][j]);
		//m nodos
		reset(m,m);
		REP(u,m)REP(v,m){
			if(u==v)continue;
			//DEBUG2(u,v);
			if(trans[u][v])add(u,v);
		}
		int ans=m-match(m);
		
		printf("%d\n", ans);
		
	}
}
