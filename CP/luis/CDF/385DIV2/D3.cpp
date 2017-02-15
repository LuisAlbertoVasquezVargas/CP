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
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi mat;
int n;
vi query(vi I){
	if(!SZ(I))return vi(n,INT_MAX);
	printf("%d\n",SZ(I));
	fflush(stdout);
	REP(i,SZ(I))printf("%d%c",1+I[i],(i+1==SZ(I))?10:32);
	fflush(stdout);
	
	vi ans;
	REP(i,n){
		int mini=INT_MAX;
		scanf("%d",&mini);
		ans.pb(mini);
	}
	return ans;
}
vi T[10][2],S[10][2];
vi ans(n,INT_MAX);
void build(int loX,int hiX,int loY,int hiY,int lvl){
	if(loX==hiX||loY==hiY)return;
	assert(lvl<10);
	int medX=(loX+hiX)>>1,medY=(loY+hiY)>>1;
	for(int y=loY;y<=medY;++y)T[lvl][1].pb(y);
	for(int y=medY+1;y<=hiY;++y)T[lvl][0].pb(y);
	build(loX,medX,loY,medY,lvl+1);
	build(medX+1,hiX,medY+1,hiY,lvl+1);
}

void solve(int loX,int hiX,int loY,int hiY,int lvl){
	if(loX==hiX||loY==hiY)return;
	assert(lvl<10);
	int medX=(loX+hiX)>>1,medY=(loY+hiY)>>1;
	
	for(int x=loX;x<=medX;++x)
		ans[x]=min(ans[x],S[lvl][0][x]);
	for(int x=medX+1;x<=hiX;++x)
		ans[x]=min(ans[x],S[lvl][1][x]);
	solve(loX,medX,loY,medY,lvl+1);
	solve(medX+1,hiX,medY+1,hiY,lvl+1);
}
int main(){
	cin>>n;
	
	/*
	mat=vvi(n,vi(n));
	REP(i,n)REP(j,n)mat[i][j]=rand()%((int)1e9);
	REP(i,n)mat[i][i]=0;
	*/
	
	ans=vi(n,INT_MAX);
	
	build(0,n-1,0,n-1,0);

	REP(i,10)REP(j,2)
		S[i][j]=query(T[i][j]);
	
	solve(0,n-1,0,n-1,0);
	
	puts("-1");
	fflush(stdout);
	REP(i,n){
		printf("%d\n",ans[i]);
		fflush(stdout);
	}
}


