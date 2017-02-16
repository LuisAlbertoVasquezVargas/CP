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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " <<#z << "=" << z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector<pii> vpii;
typedef vector< int > vi;

const int MAX_N=210;
const double INF=1e15;
pii P[MAX_N];
double mat[MAX_N][MAX_N];
double getDist(int a,int b){
	return hypot(P[a].fi-P[b].fi,P[a].se-P[b].se);
}
void addEdge(int a,int b,double v){
	mat[a][b]=mat[b][a]=min(mat[a][b],getDist(a,b)/v);
}
void add(int &n,vpii vec){
	REP(i,SZ(vec))P[n+i]=vec[i];
	REP(i,SZ(vec)-1)
		addEdge(n+i,n+i+1,40.0);
	n+=SZ(vec);
}
int main(){
	REP(i,MAX_N)REP(j,MAX_N)mat[i][j]=INF;
	REP(i,MAX_N)mat[i][i]=0;
	int s=0,t=1,n=2;
	cin>>P[s].fi>>P[s].se;
	cin>>P[t].fi>>P[t].se;
	
	pii p;
	while(cin>>p.fi>>p.se){
		vpii vec(1,p);
		while(cin>>p.fi>>p.se){
			if(p==mp(-1,-1))break;
			vec.pb(p);
		}
		add(n,vec);
	}
	REP(i,n)REP(j,n)addEdge(i,j,10);
	REP(k,n)REP(i,n)REP(j,n)
		mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
	printf("%.d\n",(int)round(mat[s][t]*60.0/1e3));
}


