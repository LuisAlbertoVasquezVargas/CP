#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define N 100100

int n,x;
vector<int>adj[100100];
int f,e;
int dis[100100];
int parent[100100];
ll toi(string s){istringstream is(s);ll x;is>>x;return x;}
string tos(ll t){stringstream st; st<<t;return st.str();} 
int main(){
	scanf("%d",&n);
	int l;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(i==0)f=x,l=x;
		else{
			adj[l].push_back(x);
			if(i==n-1)e=x;
			l=x;
		}
	}
	memset(dis,-1,sizeof(dis));
	memset(parent,-1,sizeof(parent));
	queue<int>Q;
	dis[f]=0;
	Q.push(f);
	while(!Q.empty()){
		int q=Q.front();
		Q.pop();
		for(int i=0;i<adj[q].size();i++){
			int u=adj[q][i];
			//cout<<q<<" "<<u<<endl;
			if(dis[u]==-1){
				dis[u]=dis[q]+1;
				parent[u]=q;
				Q.push(u);
			}
		}
	}
	string res=tos(e);
	while(parent[e]!=-1){
		e=parent[e];		
		res=tos(e)+" "+res;
	}
	cout<<res<<'\n';
}
