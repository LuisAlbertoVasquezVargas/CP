#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define all(v) v.begin(),v.end()

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef vector<int> vi;

const int MAX_N=2000;
bool used[MAX_N+1][MAX_N+1];
double memo[MAX_N+1][MAX_N+1];
int n;
double dp(int x,int y){
	//sDEBUG2(x,y);
	if(x==n&&y==n)return 0;
	if(used[x][y])return memo[x][y];
	used[x][y]=1;
	double &ans=memo[x][y]=x*y;
	if(x+1<=n)ans+=(n-x)*(y)*(1+dp(x+1,y));
	if(x+1<=n&&y+1<=n)ans+=(n-x)*(n-y)*(1+dp(x+1,y+1));
	if(y+1<=n)ans+=(x)*(n-y)*(1+dp(x,y+1));
	ans/=(n*n-x*y);
	return ans;
}
int main(){
	int m;
	while(scanf("%d%d",&n,&m)==2){
		vi rows(n),cols(n);
		REP(i,m){
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			rows[x]=1;
			cols[y]=1;
		}
		clr(used,0);
		printf("%.10f\n",dp(count(all(rows),1),count(all(cols),1)));
	}
}


