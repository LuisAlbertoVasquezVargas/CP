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
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector<vi> vvi;

const int MAX_N=26*2*2;
vvi G;
int timer , top;
int dfsn[ MAX_N + 5 ] , pila[ MAX_N + 5 ] , inpila[ MAX_N + 5 ] , comp[ MAX_N + 5 ];

int dfs( int u ){
	int low = dfsn[ u ] = ++timer;
	inpila[ pila[ top ++ ] = u ] = 1;
	for(auto v : G[ u ]){
		if( dfsn[ v ] == 0 ) low = min( low , dfs( v ) );
		else if( inpila[ v ] ) low = min( low , dfsn[ v ] );
	}
	if( low == dfsn[ u ] ){
		int fin;
		do{
			fin = pila[ --top ];
			inpila[ fin ] = 0;
			comp[ fin ] = u;
		}while( fin != u );
	}
	return low;
}

void SCC(int n){
	clr( dfsn , 0 );
	top = timer = 0;
	REP( i , n ) if( !dfsn[ i ] ) dfs( i );
}
void initGraph(int n){//n boolean variables
	G=vvi(2*n);
}
void add(int var1,int not1,int var2,int not2){
	int id1=2*var1+not1;
	int id2=2*var2+not2;
	G[id1^1].pb(id2);
	G[id2^1].pb(id1);
}
void equalZero(int var1){
	add(var1,1,var1,1);
}
void equalOne(int var1){
	add(var1,0,var1,0);
}
void sumOne(int var1,int var2){
	add(var1,0,var2,0);
	add(var1,1,var2,1);
}
bool check(int n){//n boolean variables
	SCC(2*n);
	REP(i,n)
		if(comp[2*i] == comp[2*i + 1])
			return 0;
	return 1;
}
struct restriction{
	int A,B,player,cnt;
	restriction(){}
	restriction(int A,int B,int player,int cnt):A(A),B(B),player(player),cnt(cnt){}
};
int solve(vector<restriction>&v){
	int cnt=0;
	for(int x=0;x<26;++x)
		for(int y=x+1;y<26;++y)
			for(int z=y+1;z<26;++z){
				initGraph(2*26);
				REP(k,26){
					if(k==x||k==y||k==z){
						equalZero(k);
						equalZero(26+k);
						continue;
					}
					sumOne(k,26+k);
				}
				for(auto r:v){
					int A=r.A;
					int B=r.B;
					int player=r.player;
					int cnt=r.cnt;
					if(player)A+=26,B+=26;
					//DEBUG3(A,B,cnt);
					if(cnt==2){
						equalOne(A);
						equalOne(B);
					}
					if(cnt==0){
						equalZero(A);
						equalZero(B);
					}
					if(cnt==1){
						sumOne(A,B);
					}
				}
				if(check(2*26))cnt++;
			}
	return cnt;
}
int main(){
	//ios_base::sync_with_stdio(0);
	int n;
	while(cin>>n){
		vector<restriction>v;
		REP(i,n){
			string s;
			int player,cnt;
			cin>>s>>player>>cnt;
			v.pb(restriction(s[0]-'A',s[1]-'A',player-1,cnt));
		}
		cout<<solve(v)<<'\n';
	}
}


