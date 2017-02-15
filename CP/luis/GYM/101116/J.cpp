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
typedef vector<vi> vvi;
typedef vector<string> vs;

const int INF=INT_MAX;
void fix(vi &v){
	sort(all(v));
	v.resize(unique(all(v))-v.begin());
}
int getId(int x,vi &v){
	return lower_bound(all(v),x)-v.begin();
}
int solve(vi &x,vi& y,vpii &v){
	int n=SZ(x),m=SZ(y),target=SZ(v)/2+1;
	vvi T(n,vi(m));
	for(auto p:v)
		T[getId(p.fi,x)][getId(p.se,y)]++;
	vvi AC(m,vi(n+1));
	REP(j,m)REP(i,n)AC[j][i+1]=AC[j][i]+T[i][j];
	int ans=INF;
	for(int i1=0;i1<n;++i1)
		for(int i2=i1;i2<n;++i2){
			vi Sy(m);
			REP(j,m)
				Sy[j]=AC[j][i2+1]-AC[j][i1];
			int sum=0;
			for(int j1=0,j2=-1;j1<m;++j1){
				while(j2+1<m&&sum<target)
					sum+=Sy[j2+1],j2++;
				if(sum>=target)
					ans=min(ans,(x[i2]-x[i1])*(y[j2]-y[j1]));
				sum-=Sy[j1];
			}
		}
	return ans;
}
int main(){
	int cases;
	scanf("%d",&cases);
	REP(tc,cases){
		int n;
		scanf("%d",&n);
		vpii v;
		vi X,Y;
		REP(i,n){
			int x,y;
			scanf("%d%d",&x,&y);
			X.pb(x);
			Y.pb(y);
			v.pb({x,y});
		}
		fix(X);
		fix(Y);
		int ans=solve(X,Y,v);
		printf("%d\n",ans);
	}
}


