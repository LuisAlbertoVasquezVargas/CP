#include<bits/stdc++.h>

using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )
#define FOR(it,A) for( typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define clr( t , val ) memset( t , val , sizeof( t ) )
#define f(i,x,y) for(int i=x;i<y;i++)
#define pb push_back

#define all(v) v.begin(),v.end()
#define N 101015

#define VIZ(e,x) (orig[e] == x? dest[e] : orig[e])

typedef vector< int > vi;

int n,m,fin;
int orig[N], dest[N], pila[N], top = 0;
vi E[N];
int low[N], dfsn[N], part[N], timer;
int  bicomp[N], nbicomp;

bool col[N];
int tam;
bool edg=0;
int X[N];
vector<int>adj[N];
vector<int>st;

int B;
int BIC[N];
bool vis[N],used[N];
bool ok;

void dfs(int u,int p,int l){
	
	vis[u]=1;

	for(int i=0;i<adj[u].size();i++){
		int to = adj[u][i];
		if(BIC[to]!=B)continue;
		if(!vis[to])dfs(to,p,l+1);
		else if(used[to]&&l%2==0)ok=1;	
	}
	used[u]=1;
	
}

int dfsbcc (int u, int p = -1){
    low[u] = dfsn[u] = ++timer;
    int ch = 0;
    FOR(it, E[u]){
        int e = *it, v = VIZ (e, u);
        if (dfsn[v] == 0){
            pila[top++] = e;
            dfsbcc (v, u);
            low[u] = min (low[u], low[v]);
            ch++;
            if (low[v] >= dfsn[u]){
                part[u] = 1;
                nbicomp++;
                edg=0,tam=0;
                int vert=0,ar=0;
            	st.clear();
                do{
                    fin = pila[--top];
                    int a=orig[fin],b=dest[fin];
                    ar++;
                    st.push_back(a);
                    st.pb(b);
                    bicomp[fin] = nbicomp;
                }while (fin != e);
                sort(all(st));
                B++;
                vert=unique(all(st))-st.begin();st.resize(vert);
                ok=0;
                dfs(st[0],-1,0);
                for(int i=0;i<vert;i++)
                	BIC[st[i]]=B,vis[st[i]]=0;
                
                if(vert%2==1||ok){
                    for(int i=0;i<vert;i++){
                    	col[st[i]]=1;
                    }
                }
            }

        }else if (v!=p && dfsn[v] < dfsn[u]){
            pila[top++] = e;
            low[u] = min (low[u], dfsn[v]);
        }
    }
    return ch;
}
void bcc (){
    f(i,0,n) part[i] = dfsn[i] = 0;
    B=0;
    nbicomp = timer = top = 0;
    f(i,0,n) if (dfsn[i] == 0) part[i] = dfsbcc (i) >= 2;
}

int T;

int a,b;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        f(i,0,n+5)E[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            orig[i]=a;
            dest[i]=b;
            adj[a].pb(b);
            adj[b].pb(a);
            E[a].push_back(i);
            E[b].push_back(i);
        }
        memset(col,0,sizeof(col));
        bcc();
        int ans=0;
        f(i,0,n)
            if(col[i])ans++;
        printf("%d\n",ans);
    }
}
