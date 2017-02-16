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

#define test() cerr<<"hola que hace ?"<<endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector<vi> vvi;

int add(string s,int val,map<string,int>&ID,vvi &T){
	if(ID.count(s)){
		int pos=ID[s];
		T[pos].pb(val);
	}else{
		int len=SZ(ID);
		ID[s]=len;
		T[len].pb(val);
	}
	return ID[s];
}
int add(string s,map<string,int>&ID){
	if(!ID.count(s)){
		int len=SZ(ID);
		ID[s]=len;
	}
	return ID[s];
}
int solve(vi &T,bool flag){
	int ans=((!flag)?0:T[0]);
	for(int i=flag;i+1<SZ(T);i+=2){
		if(T[i]+T[i+1]>0)ans+=T[i]+T[i+1];
		else break;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	while(cin>>n>>m){
		map<string,int>ID;
		vvi T(2*n);
		map<int,int>toRev;
		REP(i,n){
			string s;
			int val;
			cin>>s>>val;
			int u=add(s,val,ID,T);
			reverse(all(s));
			int v=add(s,ID);
			toRev[u]=v;
			toRev[v]=u;
		}
		T.resize(SZ(ID));
		for(auto &v:T)sort(all(v));
		/*
		for(auto v:T){
			for(auto x:v)cout<<x<<" ";
			cout<<endl;
		}
		cout<<endl;
		*/
		int cur=0;
		vi pos,neg;
		vvi myTable;
		REP(u,SZ(ID)){
			int v=toRev[u];
			if(u==v){
				reverse(all(T[u]));
				myTable.pb(T[u]);
			}else{
				while(SZ(T[u])&&SZ(T[v])){
					int X=T[u].back();
					int Y=T[v].back();
					if(X+Y>0){
						T[u].pop_back();
						T[v].pop_back();
						cur+=X+Y;
					}else break;
				}
			}
		}
		vvi S(SZ(myTable),vi(2));
		REP(i,SZ(myTable))REP(j,2){
			S[i][j]=solve(myTable[i],j);
			//DEBUG(S[i][j]);
		}
		int sum=0;
		REP(i,SZ(myTable))sum+=S[i][0];
		int ans=cur+sum;
		REP(i,SZ(myTable))
			ans=max(ans,cur+sum-S[i][0]+S[i][1]);
		cout<<ans<<'\n';
	}
}



