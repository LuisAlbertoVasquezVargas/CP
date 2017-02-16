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
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector<pii>vpii;
typedef vector<vpii>vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi I;
void init(int n){
	I=vi(n);
	REP(i,n)I[i]=i;
}
void process(vi &p,int n,bool &others,vvpii &myPairs,vvi &myTriples){
	if(others)return;
	if(p==I)return;
	
	vi vis(n);
	vpii pairs;
	vi triple;
	REP(u,n){
		if(vis[u])continue;
		
		if(p[u]==u){
			vis[u]=1;
			continue;
		}
		if(p[p[u]]==u){
			vis[u]=vis[p[u]]=1;
			pairs.pb(mp(u,p[u]));
			if(SZ(pairs)>=3){
				others=1;
				return;
			}
			continue;
		}
		if(p[p[p[u]]]==u){
			vis[u]=vis[p[u]]=vis[p[p[u]]]=1;
			if(!triple.empty()){
				others=1;
				return;
			}
			triple={u,p[u],p[p[u]]};
			continue;
		}
		others=1;
		return;
	}
	if(!triple.empty()&&!pairs.empty()){
		others=1;
		return;
	}
	if(!triple.empty())myTriples.pb(triple);
	if(!pairs.empty())myPairs.pb(pairs);
}
bool notUseAll(vvpii &myPairs,vvi &myTriples){
	for(auto v:myPairs){
		if(SZ(v)==1)continue;
		assert(SZ(v)==2);
		return 0;
	}
	if(!myTriples.empty())return 0;
	return 1;
}
bool checkPair(pii p,int a,int b){
	return p==mp(a,b)||p==mp(b,a);
}
bool useAll(vvpii &myPairs,vvi &myTriples,int n){
	REP(i,n)REP(j,n){
		if(i==j)continue;
		bool possible=1;
		for(auto v:myPairs){
			bool ok=0;
			for(auto p:v)
				if(checkPair(p,i,j))ok=1;
			if(!ok)possible=0;
		}
		if(!possible)continue;
		for(auto triple:myTriples){
			bool ok=0;
			REP(b,3)REP(a,b)
				if(checkPair(mp(triple[a],triple[b]),i,j))ok=1;
			if(!ok)possible=0;
		}
		if(possible)return 1;
	}
	return 0;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		init(m);
		bool found=0;
		vvpii myPairs;
		vvi myTriples;
		REP(i,n){
			vi p(m);
			REP(j,m)scanf("%d",&p[j]),p[j]--;
			process(p,m,found,myPairs,myTriples);
		}
		if(found){
			puts("NO");
			continue;
		}
		if(notUseAll(myPairs,myTriples)){
			puts("YES");
			continue;
		}
		/*
		for(auto v:myPairs){
			for(auto p:v)DEBUG2(p.fi,p.se);
			cout << endl;
		}
		for(auto t:myTriples)DEBUG3(t[0],t[1],t[2]);
		*/
		if(useAll(myPairs,myTriples,m))puts("YES");
		else puts("NO");
	}
}


