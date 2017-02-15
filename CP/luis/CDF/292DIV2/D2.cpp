#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define all(v) v.begin(),v.end()

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long double ld;
const int MAX_N=2000;
bool used[MAX_N+1][MAX_N+1];
ld memo[MAX_N+1][MAX_N+1];
ld p;
int t;
int n;
ld dp(int timer,int cnt){
	if(timer==t)return n-cnt;
	if(used[timer][cnt])return memo[timer][cnt];
	used[timer][cnt]=1;
	ld &ans=memo[timer][cnt]=0;
	ans+=p*dp(timer+1,max(0,cnt-1));
	ans+=(1-p)*dp(timer+1,cnt);
	return ans;
}
int main(){
	while(cin>>n>>p>>t){
		clr(used,0);
		printf("%.10f\n",(double)dp(0,n));
	}
}


