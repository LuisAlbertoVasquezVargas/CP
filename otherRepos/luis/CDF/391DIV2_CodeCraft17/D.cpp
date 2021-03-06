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
typedef vector<int> vi;
typedef vector<vi> vvi;

int getAsNumber(string &s,int lo,int hi){
	int ans=0;
	for(int k=lo;k<=hi;++k){
		if(ans>=100)break;
		ans=ans*2+(s[k]=='1');
	}
	return ans;
}
const int MAXN=75;
const int MAXM=20;
const int MOD=(int)1e9+7;
int T[MAXN][MAXN];
int memo[MAXN][1<<20];
bool used[MAXN][1<<20];
bool isValidMask(int mask){
	if(mask==0)return 0;
	int ones=__builtin_popcount(mask+1);
	return ones==1;
}
int n;
int dp(int pos,int mask){
	//DEBUG2(pos,mask);
	if(pos==n)return isValidMask(mask);
	if(used[pos][mask])return memo[pos][mask];
	used[pos][mask]=1;
	int &dev=memo[pos][mask]=isValidMask(mask);
	for(int k=pos;k<n;++k){
		//DEBUG3(pos,k,T[pos][k]);
		if(T[pos][k]>=1&&T[pos][k]<=20){
			//DEBUG(T[pos][k]);
			dev=(dev+dp(k+1,mask|(1<<(T[pos][k]-1))));
			if(dev>=MOD)dev-=MOD;
		}
	}
	return dev;
}

int main(){
	//REP(i,20)DEBUG2(i,isValidMask(i));
	string s;
	while(cin>>n>>s){
		for(int i=0;i<n;++i)
			for(int j=i;j<n;++j){
				T[i][j]=getAsNumber(s,i,j);
				//DEBUG3(i,j,T[i][j]);
			}
		clr(used,0);
		int ans=0;
		REP(i,n){
			ans=(ans+dp(i,0));
			if(ans>=MOD)ans-=MOD;
		}
		printf("%d\n",ans);
	}
}


