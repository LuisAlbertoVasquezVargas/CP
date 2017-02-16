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
typedef pair< int , int > pii;
typedef vector< int > vi;

const int MAX_N=2005;
const ll MOD=(1LL<<31)-1;
int n;
int A[MAX_N];
bool used[MAX_N][MAX_N];
ll memo[MAX_N][MAX_N];
ll dp(int pos,int last){
	if(pos>=n)return 1;
	if(used[pos][last])return memo[pos][last];
	used[pos][last]=1;
	ll &ans=memo[pos][last]=0;
	if(A[last]<A[pos-1]){
		if(A[pos]<A[last])ans=dp(pos+1,pos-1);
		else if(A[last]<A[pos]&&A[pos]<A[pos-1]){
			ans=dp(pos+1,pos-1)+dp(pos+1,last);
			if(ans>=MOD)ans-=MOD;
		}else{
			ans=dp(pos+1,last);
		}
	}else{
		if(A[pos]<A[pos-1])ans=dp(pos+1,last);
		else if(A[last]>A[pos]&&A[pos]>A[pos-1]){
			ans=dp(pos+1,pos-1)+dp(pos+1,last);
			if(ans>=MOD)ans-=MOD;
		}else{
			ans=dp(pos+1,pos-1);
		}
	}
	return ans;
}
int main(){
	while(scanf("%d",&n)==1){
		n++;
		REP(i,n)scanf("%d",&A[i]);
		clr(used,0);
		printf("%d\n",(int)dp(2,0));
	}
}



