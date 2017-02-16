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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

ll n;
int m;

int main()
{
	while( cin >> n ){	
		vector<long long>v;
		for(int i=0;i<60;i++){
			long long z=(1LL<<i)-1;
			if(z>n)break;
			
			long long lo=0;
			long long hi=n-z+1;
			
			
			for(int caso=0;caso<100;caso++){
				long long me=(lo+hi)/2;
				if((z+me)==0  ){
					lo=me;continue;
				}
				
				if(  (2*me+1)>(n/(z+me)) )
					hi=me;
				else 
					lo=me;
			}
			
			for(int j=lo;j<=hi;j++)
				if( (2*j+1)*(z+j)==n)
					if(j>=0)
					v.push_back( (1LL<<i)*(2*j+1) );
			
		}
		
		sort(v.begin(),v.end());
		
		if(v.size()==0){
			cout<<-1<<endl;
		}else{
		
			for(int i=0;i<v.size();i++)
				cout<<v[i]<<endl;
		}
	}
	return 0;
}


