#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; ++i)
#define SZ(v) ((int)v.size())
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

void impr(vi &v){
	REP(i,SZ(v))printf("%d%c",v[i],(i+1==SZ(v)?10:32));
}
int get(vvi &index,int forb,int tope,int m){
	REP(k,m){
		if(k==forb)continue;
		if(SZ(index[k])>tope)return k;
	}
	return -1;
}

void solve2(vvi &index,vi &others,int n,int m,int tope,vi &v){
	int steps=0;
	REP(k,m){
		while(SZ(index[k])<tope){
			int pos=get(index,k,tope,m);
			if(pos!=-1){
				int last=index[pos].back();
				index[pos].pop_back();
				v[last]=k;
				steps++;
				index[k].pb(last);
			}else{
				assert(!others.empty());
				int p=others.back();
				others.pop_back();
				v[p]=k;
				steps++;
				index[k].pb(p);
			}
		}
	}
	printf("%d %d\n",tope,steps);
	REP(i,n)v[i]++;
	impr(v);
}

void solve(vi &v,int n,int m){
	int x=n/m;
	vi others;
	vvi index(m);
	REP(i,n)
		if(v[i]<m) index[v[i]].pb(i);
		else others.pb(i);
	solve2(index,others,n,m,x,v);
	
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		vi A(n);
		REP(i,n)scanf("%d",&A[i]),A[i]--;
		solve(A,n,m);
	}
}



