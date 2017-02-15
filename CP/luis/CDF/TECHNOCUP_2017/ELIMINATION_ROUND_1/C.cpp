#include<bits/stdc++.h>
using namespace std;
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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int N=5;
vi myVec={4 ,6 ,1 ,5 ,5};
int query(int x,int y){
	cout<<"? "<<x+1<<" "<<y+1<<'\n';
	fflush(stdout);
	int ans;
	cin>>ans;
	return ans;
}
void impr(vi &v){
	cout<<"!";
	REP(i,SZ(v))cout<<' '<<v[i];
	cout<<'\n';
	fflush(stdout);
}
int main(){
	int n;
	while(cin>>n){
		vi a(n);
		int q0=query(0,1);
		int q1=query(1,2);
		int q2=query(2,0);
		int T=(q0+q1+q2)/2;
		a[0]=T-q1;
		a[1]=T-q2;
		a[2]=T-q0;
		for(int k=3;k<n;++k)
			a[k]=query(k,k-1)-a[k-1];
		impr(a);
	}
}

