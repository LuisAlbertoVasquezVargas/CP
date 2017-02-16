#include <bits/stdc++.h>
#define N 2000
#define pb push_back
using namespace std;
vector<int>adj[N+5];
int inc[N+5];
bool vis[N+5];
vector<int>v;

int main(){
	int n,x;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x;
		if(x!=-1){
			adj[x-1].pb(i);
			inc[i]++;
		}
	}
	//for(int i=0;i<n;++i)cout<<inc[i]<<endl;
	int ct=0;
	while(1){
		bool ok=0;
		for(int i=0;i<n;++i){
			if(!vis[i])ok=1;
		}
		if(!ok)break;
		ct++;
		v.clear();
		for(int i=0;i<n;++i){
			if(!vis[i] && inc[i]==0){
				v.pb(i);
				vis[i]=1;
			}
		}
		int sz=v.size();
		for(int i=0;i<sz;++i){
			int val=v[i];
			for(int j=0;j<adj[val].size();++j){
				int vec=adj[val][j];
				inc[vec]--;
			}
			
		}
	}
	cout<<ct<<endl;
	
}



