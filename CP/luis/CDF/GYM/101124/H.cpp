#include<bits/stdc++.h>
using namespace std;
int N,K,k;
int a,b;
vector<int>num;
vector<vector<int> >v;
vector<int>vaux;
int nxt[100005];
int vis[100005];
int mesa[100005];
int mesa2[100005];
int pos[100005];
void dfs(int u){
	vaux.push_back(u);
	if(vis[nxt[u]]==-1){
		vis[nxt[u]] = k;
		dfs(nxt[u]);
	} 
}

int main(){
	cin >> N >> K;
	memset(vis,-1,sizeof(vis));
	for(int i=0;i<N;i++){
		cin >> a >> b;
		mesa[a] = i+1;
		mesa2[i+1] = a;
		nxt[a] = b;
		num.push_back(a);
	}
	k=0;
	sort(num.begin(),num.end());
	unique(num.begin(),num.end());
	for(int i=0;i<num.size();i++){
		if(vis[num[i]]==-1){
			vis[num[i]] = k;
			vaux.clear();	
			dfs(num[i]);
			v.push_back(vaux);
			k++;
		}
	}
	for(int kk=0;kk<k;kk++){
		for(int i=0;i<v[kk].size();i++){
			pos[v[kk][i]]=i;
		}
	}
	for(int i=0;i<K;i++){
		cin >> a >> b;
		int ans=pos[mesa2[a]];
		ans=(ans+b)%(v[vis[mesa2[a]]].size());
		cout << mesa[v[vis[mesa2[a]]][ans]] <<endl;
	}
}
