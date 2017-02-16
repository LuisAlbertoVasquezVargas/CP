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

const int MAX_N=1000;
const int INF=INT_MAX/2;
int A[MAX_N];
int T[8][MAX_N][MAX_N];
void init(int n){
	clr(T,-1);
	REP(color,8){
		REP(pos,n){
			T[color][pos][0]=pos;
			for(int cnt=0,pos2=pos;pos2<n;++pos2){
				if(A[pos2]==color){
					cnt++;
					T[color][pos][cnt]=pos2+1;
				}
			}
		}
	}
}
int X,n;
bool used[MAX_N][1<<8];
int memo[MAX_N][1<<8];
int dp(int pos,int mask){
	if(mask==(1<<8)-1)return 0;
	if(pos==n)return -INF;
	if(used[pos][mask])return memo[pos][mask];
	int &ans=memo[pos][mask]=-INF;
	REP(color,8){
		if(!(mask&(1<<color))){
			if(T[color][pos][X]!=-1)
				ans=max(ans,X+dp(T[color][pos][X],mask|(1<<color)));
			if(T[color][pos][X+1]!=-1)
				ans=max(ans,X+1+dp(T[color][pos][X+1],mask|(1<<color)));
		}
	}
	return ans;
}
int solve(int x){
	X=x;
	clr(used,0);
	return dp(0,0);
}
int bs(){
	int lo=0,hi=n/8;
	if(solve(hi)>0)return solve(hi);
	while(hi-lo>1){
		int med=(lo+hi)>>1;
		if(solve(med)>0)lo=med;
		else hi=med;
	}
	return solve(lo);
}
int main(){
	while(scanf("%d",&n)==1){
		REP(i,n)scanf("%d",&A[i]),A[i]--;
		init(n);
		printf("%d\n",bs());
	}
}


