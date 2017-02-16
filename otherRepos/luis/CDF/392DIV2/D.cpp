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

int B,n;
string s;
const int MAX_LEN=60;
const int INF=INT_MAX/2;
bool used[MAX_LEN];
int memo[MAX_LEN];
int dp(int pos){
	if(pos==n)return 0;
	if(used[pos])return memo[pos];
	used[pos]=1;
	int &ans=memo[pos]=INF;
	ll cur=0;
	for(int k=pos;k<n;++k){
		cur=cur*10LL+(s[k]-'0');
		if(cur>=B)break;
		if(s[pos]=='0'&&k-pos+1>1)break;
		ans=min(ans,1+dp(k+1));
	}
	return ans;
}
ll best;
void rec(int pos){
	if(pos==n)return;
	ll cur=0;
	for(int k=pos;k<n;++k){
		cur=cur*10LL+(s[k]-'0');
		if(cur>=B)break;
		if(s[pos]=='0'&&k-pos+1>1)break;
		if(dp(pos)==1+dp(k+1)){
			//DEBUG(cur);
			best=best*(ll)B+cur;
			rec(k+1);
			return;
		}
	}
	assert(0);
}
int main(){
	while(cin>>B>>s){
		n=SZ(s);
		clr(used,0);
		dp(0);
		//DEBUG(dp(0));
		best=0;
		rec(0);
		cout<<best<<'\n';
	}
}


