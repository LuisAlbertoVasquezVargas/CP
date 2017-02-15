#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define NN 2000
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int M[NN+1][NN+1],sum[NN+1][NN+1];

int N,W,L;


void precal(){
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			sum[i][j]=(M[i][j]==1)+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
}

bool pred(int n){
	
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(i-(n-1)>=1 && j-(n-1)>=1){
				int val=sum[i][j]-sum[i-n][j] - sum[i][j-n] + sum[i-n][j-n];
				if(val<=L)return 1;
			}
		}
	}
	return 0;
}

int search(){
	int lo=1,hi=N;
	if(pred(hi)==1)return hi;
	if(pred(lo)==0)return 0;
	//cout<<lo<<" --> "<<hi<<endl;
	while(hi-lo>1){
		int mid=(hi+lo)/2;
		if(pred(mid)==0)hi=mid;
		else lo=mid;
	}
	//cout<<"res: "<<lo<<endl;
	return lo;	
}


void doit(){
	int x,y;
	cin>>N>>W>>L;
	//cout<<N<<" "<<W<<" "<<L<<endl;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			M[i][j]=0;
		}
	}
	for(int i=0;i<W;++i){
		cin>>x>>y;
		//cout<<x<<"-- "<<y<<endl;
		M[x][y]=1;
	}
	precal();
	/*for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cout<<" "<<sum[i][j];
		}
		puts("");
	}*/
	
	int res=search();
	cout<<res*res<<endl;
}

int main(){
	int t;
	cin>>t;
	//cout<<t<<endl;
	while(t--){
		doit();
	}
}


