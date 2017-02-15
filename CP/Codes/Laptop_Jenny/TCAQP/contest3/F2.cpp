#include<bits/stdc++.h>

using namespace std;

#define MAXN 101000

int L[MAXN],a[MAXN];
int d[MAXN],parent[MAXN];
int n;
vector<int>adj[MAXN];
int x;

int main(){
	scanf("%d",&n);
	memset(L,-1,sizeof(L));
	memset(d,-1,sizeof(d));
	memset(parent,-1,sizeof(parent));
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		a[i]=x;
		if(i==0){
			L[x]=0;
		}
		else{
			adj[i-1].push_back(i);
			if(L[x]!=-1)adj[L[x]].push_back(i);
			L[x]=i;
		}
	}
	
	deque<int>Q;
	d[0]=0;
	Q.push_front(0);
	int last;
	while(!Q.empty()){
		int q=Q.front();
		Q.pop_front();
		if(a[q]==a[n-1]){
			last=q;
			break;
		}
		for(int i=0;i<adj[q].size();i++){
			int v=adj[q][i];
			if(d[v]==-1){
				if(a[v]==a[q]){
					d[v]=d[q];
					parent[v]=q;
					Q.push_front(v);
				}
				else{
					d[v]=d[q]+1;
					parent[v]=q;
					Q.push_back(v);
				}	
			}
		}
		
	}
	
	vector<int>res2,res;
	
	while(last!=-1){
		//cout<<last<<endl;
		res2.push_back(a[last]);
		last=parent[last];
	}

	res.push_back(res2[0]);
	for(int i=1;i<res2.size();i++){
		if(res2[i]!=res2[i-1]){
			res.push_back(res2[i]);
		}
	}
	
	for(int i=res.size()-1;i>=0;i--){
		printf("%d%c",res[i],i==0?'\n':' ');
	}
}
