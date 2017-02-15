#include<bits/stdc++.h>

using namespace std;

#define VIZ(e,x) (orig[e] == x? dest[e] : orig[e])

const int MAXN = 512;
const int MAXE = 50050;

bool valid[MAXE];
int id[ MAXN ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}

int N , M;
vector<pair<int,pair<int,int> > >edges;
vector<int>E[MAXN];
int orig[MAXE] , dest[MAXE];
int a,b,c;

int getCost(int fac){
  for(int i=0; i<=N; ++i)
    id[i] = i;
  int cost = edges[fac].first;
  Union(edges[fac].second.first , edges[fac].second.second);
  for(int i=0; i<edges.size(); ++i){
    int u = edges[i].second.first , v = edges[i].second.second;
	  if( Find(u) != Find(v) ){
	    cost += edges[i].first;
	    Union(u,v);
	    valid[i] = 1;
	  } 
  }
  return cost;
}

int getCost2(int fac){

 for(int i=0; i<=N; ++i)
    id[i] = i;
  int cost = 0;
  
  for(int i=0; i<edges.size(); ++i){
  	if( i == fac)continue;
    int u = edges[i].second.first , v = edges[i].second.second;
	  if( Find(u) != Find(v) ){
	    cost += edges[i].first;
	    Union(u,v);
	    valid[i] = 1;
	  } 
  }
  return cost;
}

int main(){
  while( scanf("%d%d",&N,&M) == 2){
  	edges.clear();
  	for(int i=0; i<=N; ++i)
  	  E[i].clear() , id[i] = i;
  	memset(valid,0,sizeof(valid));
    for(int i=0; i<M; ++i){
	  scanf("%d%d%d",&a,&b,&c);
	  a--; b--;
	  edges.push_back( make_pair(c,make_pair(a,b)));
	  orig[i] = a;
	  dest[i] = b;
	  E[a].push_back(i);
	  E[b].push_back(i);
	}
	sort(edges.begin(), edges.end());
	int cost = 0;
	for(int i=0; i<edges.size(); ++i){
	  int u = edges[i].second.first , v = edges[i].second.second;
	  if( Find(u) != Find(v) ){
	    cost += edges[i].first;
	    Union(u,v);
	    valid[i] = 1;
	  } 
	}
	int ans1 = 0 , ans2 = 0;
	for(int i=0; i<edges.size(); ++i){
	  if( valid[i] == 1){
	    if(getCost2(i) != cost){
	      ans1++ , ans2 += edges[i].first;
		}
	  }
	}
	printf("%d %d\n",ans1,ans2);
	
  }
}
