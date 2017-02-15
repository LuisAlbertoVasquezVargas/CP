#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )


#define mp make_pair
#define fi first

const int MAXN = 3005;
const int INF = (1<<30);
const int MAXQ = 10005;

vector<pair<int,pair<int,int> > >E;
int id[MAXN] , N , M , Q;
bool valid[MAXN*MAXN];
int adj[MAXN][MAXN];
long long Acum[MAXQ];
int Rank[ MAXN ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void Union(int a, int b)
{
    int pa = Find(a);
    int pb = Find(b);
    if(pa != pb)
    {
        if(Rank[pa] < Rank[pb]) id[pa] = pb;
        else if(Rank[pa] > Rank[pb]) id[pb] = pa;
        else
        {
            id[pb] = pa;
            Rank[pa]++;
        }
    }
}
void init(){
  for(int i=0; i<N; ++i)
    id[i] = i , Rank[ i ] = 0;
}

long long mst(int newar, int newcost) {
  long long tot_cost = 0LL;
  init();
  bool used = false;
  for(int i=0; i<E.size(); ++i){
    int u = E[i].second.first, v = E[i].second.second, cost = E[i].first;
	if( i == newar){
	  continue;
    }
    if( newcost != -1 && newcost <= cost && !used ){
      used = 1;
      cost = newcost;
	  u = E[newar].second.first , v =E[newar].second.second; 
      i--;
	}
    if( Find(u) != Find(v) ){
      tot_cost = tot_cost + 1LL*cost;
      Union(u,v);
      if( newar == -1)valid[i] = 1;
	}
  }
  return tot_cost;
}

int a,b,c;
set<int>queries;
vector<int>cost_queries[MAXN*MAXN];

long long peso_sin_arist;
int lo, hi ,mid;
int main(){
  while( scanf("%d%d",&N,&M) == 2){
    if( N == 0 && M == 0 )break;
    init();
    E.clear();
    for(int i=0; i<M; ++i){
      scanf("%d%d%d",&a,&b,&c);
	  if( b < a ) swap(a,b);
	  E.push_back(make_pair(c,make_pair(a,b)));	
	  cost_queries[i].clear();
	  valid[i] = 0;
    }
    sort(E.begin(),E.end());//O(N*NlogN)
    for(int i=0; i<E.size(); ++i){
      int u = E[i].second.first, v =E[i].second.second;
      adj[u][v] = adj[v][u] = i;
	}
    long long icost = mst(-1,-1);//O(N*N)
	int ar;
    double ans = 0.0;
    scanf("%d",&Q);
    queries.clear();
    for(int i=0; i<Q; ++i){//O(Q)
    	scanf("%d%d%d",&a,&b,&c);
    	if( b < a ) swap(a,b);
		ar = adj[a][b];
		if( valid[ar] == 1){
    	  queries.insert(ar);
    	  cost_queries[ar].push_back(c);
		}
    	else{
    	  ans += 1.0*icost;
		}
	}
	
	peso_sin_arist ;
	lo , hi , mid;
	for(set<int>::iterator it = queries.begin() ; it != queries.end(); ++it){
	  ar = *it;
	  sort(cost_queries[ar].begin(),cost_queries[ar].end());
	  Acum[0] = cost_queries[ar][0];
	  for(int i=1; i<cost_queries[ar].size(); ++i){
	    Acum[i] = Acum[i-1] + 1LL*cost_queries[ar][i];
	  }
	  
	  peso_sin_arist = mst(ar,INF);
	  
	  lo = 0 , hi = int(cost_queries[ar].size())-1; 
	  if( peso_sin_arist == mst(ar,cost_queries[ar][lo])){
	    ans += (peso_sin_arist * (1LL*hi-lo+1LL));
	    continue;
	  }
	  
	  
	  if( peso_sin_arist != mst(ar,cost_queries[ar][hi])){
	    ans += (Acum[hi] + (1LL*icost - 1LL*E[ar].first) )*(1LL*hi-lo+1LL);
		continue;	
	  }
	  
	  while( hi > lo + 1 ){
	    mid = (hi + lo)>>1;
	    if( peso_sin_arist == mst(ar,cost_queries[ar][mid]) )
	      hi = mid;
	    else lo = mid;
	  }
	  ans += (1LL*lo+1LL)*(Acum[lo] + (1LL*icost - 1LL*E[ar].first));
	  ans += ((long long)(cost_queries[ar].size()) - hi)*peso_sin_arist;
	}
	printf("%.4f\n",1.0*ans/Q);
  }
}


