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

#define test() cerr<<"hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef vector<ll> vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector<vi>vvi;

struct Point{
	ll x , y;
	Point(){ x = y = 0; }
	Point( ll x , ll y ) : x( x ) , y( y ) {}
	void print(){ printf( "punto : %.4f %.4f\n" , double(x) , double(y) );}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
bool operator ==( const Point &A , const Point &B ){ return A.x==B.x&&A.y==B.y; }

ll dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y ; }
ll cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
ll area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }

bool between( const Point &A , const Point &B , const Point &P ){
	return 	min( A.x , B.x ) <= P.x && P.x <= max( A.x , B.x ) &&
			min( A.y , B.y ) <= P.y && P.y <= max( A.y , B.y );
}
bool onSegment( const Point &A , const Point &B , const Point &P ){
	return abs( area( A , B , P ) ) <= 0 && between( A , B , P );
}
bool intersects( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	ll A1 = area( P3 , P4 , P1 );
	ll A2 = area( P3 , P4 , P2 );
	ll A3 = area( P1 , P2 , P3 );
	ll A4 = area( P1 , P2 , P4 );
	if( ( ( A1 > 0 && A2 < 0 ) || ( A1 < 0 && A2 > 0 ) ) && 
		( ( A3 > 0 && A4 < 0 ) || ( A3 < 0 && A4 > 0 ) ) ) return 1;
	if( onSegment( P3 , P4 , P1 ) ) return 1;
	if( onSegment( P3 , P4 , P2 ) ) return 1;
	if( onSegment( P1 , P2 , P3 ) ) return 1;
	if( onSegment( P1 , P2 , P4 ) ) return 1;
	return 0;
}
bool bfs(vvi &G,int n){
	queue<int>Q;
	vi color(n,-1);
	REP(s,n){
		if(color[s]!=-1)continue;
		Q.push(s);
		color[s]=0;
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			for(auto v:G[u]){
				if(color[v]==-1){
					color[v]=color[u]^1;
					Q.push(v);
				}else{
					if(color[u]==color[v])return 0;
				}
			}
		}
	}
	return 1;
}
void solve(vector<Point>&A,vector<Point>&B){
	int n=SZ(A);
	vvi G(n);
	REP(j,n)REP(i,j){
		if(A[i]==A[j])continue;
		if(intersects(A[i],B[i],A[j],B[j])){
			G[i].pb(j);
			G[j].pb(i);
		}
	}
	puts(bfs(G,n)?"possible":"impossible");
}
int main(){
	int wells,pipes;
	while(scanf("%d%d",&wells,&pipes)==2){
		vector<Point>W(wells);
		REP(i,wells){
			int x,y;
			scanf("%d%d",&x,&y);
			W[i]=Point(x,y);
		}
		vector<Point>A(pipes),B(pipes);
		REP(i,pipes){
			int idS,x,y;
			scanf("%d%d%d",&idS,&x,&y);
			idS--;
			A[i]=W[idS];
			B[i]=Point(x,y);
		}
		solve(A,B);
		
	}
}





