#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define pb push_back
#define N 100000
using namespace std;

int pat[N+5],n;
int X[N+5],Y[N+5];
bool apar[N+5];

void INIT(){
    for(int i=0;i<n;++i)pat[i]=i;
}
 
int FIND(int x){
    if(pat[x]!=x){
        pat[x]=FIND(pat[x]);
    }
    return pat[x];
}
void UNION(int x,int y){
    int px=FIND(x);
    int py=FIND(y);
    pat[px]=py;
}
 
int numComp(){
    int ct=0;
    for(int i=0;i<n;++i){
        if(FIND(i)==i)ct++;
    }
    return ct;
}

int main(){
	int m,x,q;
	scanf("%d%d",&n,&m);
	memset(apar,0,sizeof(apar));
	INIT();
	for(int i=0;i<m;++i){
		scanf("%d%d",&X[i],&Y[i]);
		X[i]--,Y[i]--;
	}
	scanf("%d",&q);
	vector<int>v;
	while(q--){
		scanf("%d",&x);
		x--;
		apar[x]=1;
		v.pb(x);
	}
	for(int i=0;i<m;++i){
		if(!apar[i]){
			UNION(X[i],Y[i]);
		}
	}
	int comp=numComp();
	int sz=v.size(),res=0;
	vector<int>sol;
	for(int i=sz-1;i>=0;i--){
		res++;
		sol.pb(comp);
		int val=v[i];
		if(FIND(X[val])!=FIND(Y[val])){
			comp--;
			UNION(X[val],Y[val]);
		}
	}
	reverse(sol.begin(),sol.end());
	for(int i=0;i<sol.size();++i){
		if(i==0)printf("%d",sol[i]);
		else printf(" %d",sol[i]);
	}
	puts("");
}
