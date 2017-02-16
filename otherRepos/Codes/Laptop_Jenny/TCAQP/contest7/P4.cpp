#include<cstdio>
#include<stack>
#include<vector>
#include<cstring>
#include<iostream>
#define N 2005
#define pb push_back
using namespace std;

int n,m;
char cad1[10], cad2[10];
vector<int>adj[N];
int tiempo[N+5],low[N+5],scc[N+5],comp=0,num=0;
stack<int>st;

int tos(char * s){
	int sz=strlen(s);
	int ret=0;
	for(int i=1;i<sz;++i){
		ret= ret * 10 + (s[i]-'0');
	}
	return ret;
}

int mask(int x){
	if(x>=n)return x-n;
	return x+n;
}


  
void dfs(int u){
   tiempo[u]=num,low[u]=num++,st.push(u);
   for(int i=0;i<adj[u].size();++i){
      int v=adj[u][i];
      if(tiempo[v]==-1){
         dfs(v),low[u]= min( low[u], low[v]);
      }
      else if(scc[v]==-1){
         low[u]= min( low[u], low[v]);
      }
   }
   if(low[u]==tiempo[u]){
      while(scc[u]!=comp){
         int x=st.top();
         st.pop();
         scc[x]=comp;
      }
      comp++;
   }
} 



int main(){
	while(scanf("%d%d",&n,&m)==2){
		//cout<<"vale: ";
		//cout<<n<<" "<<m<<endl;
		for(int i=0;i<2*n;++i){
			adj[i].clear();
			tiempo[i]=-1;
			scc[i]=-1;
		}
		for(int i=0;i<m;++i){
			scanf("%s %s",cad1,cad2);
			int x=tos(cad1);
			int y=tos(cad2);
			x--,y--;
			int n1,n2;
			if(cad1[0]=='-')n1=mask(x);
			else n1=x;
			if(cad2[0]=='-')n2=mask(y);
			else n2=y;
			adj[mask(n1)].pb(n2);
			adj[mask(n2)].pb(n1);
		}
		num=0,comp=0;
		for(int i=0;i<2*n;++i){
			if(tiempo[i]==-1){
				dfs(i);
			}
		}
		int ok=1;
		for(int i=0;i<n;++i){
			if(scc[i]!=-1 && scc[i]==scc[mask(i)]){
				ok=0;
			}
		}
		scanf("\n");
		printf("%d\n",ok);
	}
}
