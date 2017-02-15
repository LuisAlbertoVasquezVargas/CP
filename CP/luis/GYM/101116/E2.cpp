#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<string> vs;

const int MAX_N=40000;
string name[MAX_N];
int getId(string s,map<string,int>&myMap){
	if(myMap.count(s))return myMap[s];
	int len=SZ(myMap);
	name[len]=s;
	return myMap[s]=len;
}
void fillList(vi &myList,int n,map<string,int>&myMap){
	REP(i,n){
		string s;
		cin>>s;
		int id=getId(s,myMap);
		myList.pb(id);
	}
}
vi G[MAX_N];
int vis[MAX_N];
void initGraph(int n){
	REP(i,n)G[i].clear();
	REP(i,n)vis[i]=0;
}
void add(int u,int v){
	G[u].pb(v);
}
void dfs(int u){
	vis[u]=1;
	for(auto v:G[u])
		if(!vis[v])dfs(v);
}
void impr(vs &v){
	REP(i,SZ(v))
		cout<<v[i]<<char(i+1==SZ(v)?10:32);
}
int main(){
	int cases;
	cin>>cases;
	REP(tc,cases){
		int U,V,m;
		cin>>U>>V>>m;
		map<string,int>myMap;
		vi listU,listV;
		fillList(listU,U,myMap);
		fillList(listV,V,myMap);
		vpii edges;
		REP(i,m){
			string s,t;
			cin>>s>>t;
			int u=getId(s,myMap);
			int v=getId(t,myMap);
			edges.pb({u,v});
		}
		initGraph(SZ(myMap));
		for(auto e:edges)
			add(e.fi,e.se);
		
		for(auto u:listU)
			if(!vis[u])
				dfs(u);
		vs ans;
		for(auto u:listV)
			if(vis[u])ans.pb(name[u]);
		sort(all(ans));
		impr(ans);
	}
}
