#include<cstdio>
#include<vector>
#include<iostream>
#define pb push_back
#define N 1000000
using namespace std;
vector<int>adj[N+1];
vector<int>v,apar;
int pos[N+1],tam[N+1],last;

bool check(){
	int sz=v.size();
	apar.clear();
	for(int i=0;i<sz;++i){
		int val=v[i];
		if(pos[val]>=tam[val])return 0;
		apar.pb(val);
		//search
		int ind=lower_bound( adj[val].begin() + pos[val] , adj[val].begin() +tam[val] , last)-adj[val].begin();
		if(ind>=tam[val])return 0;
		if(adj[val][ind]>last){
			last=adj[val][ind];
			pos[val]=ind+1;
		}
		else return 0;
	}
	return 1;
}


int main(){
	int n,x,q,m;
	while( scanf("%d",&n) ==1 ){
		for(int i=0;i<=N;++i)adj[i].clear();
		for(int i=0;i<n;++i){
			scanf("%d",&x);
			adj[x].pb(i);
		}
		for(int i=0;i<=N;++i){
			tam[i]=adj[i].size();
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d",&m);
			v.clear();
			for(int i=0;i<m;++i){
				scanf("%d",&x);
				v.pb(x);
			}
			last=-1;
			bool vale=check();
			for(int i=0;i<apar.size();++i){
				pos[ apar[i] ]=0;
			}
			if(vale)puts("TAK");
			else puts("NIE");
		}
	}
}
