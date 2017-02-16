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
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-8)

using namespace std;

typedef long double ld;
vector<pair<int,int> >v;
int n,a,b;

int main()
{
		
	//freopen("caravan.in", "r", stdin);
	//freopen("caravan.out", "w", stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		v.push_back(make_pair(a,b));	
	}
	sort(all(v));
	int arriba = v[ 0 ].second - v[ 0 ].first;
	int ff=v[ 0 ].second - v[ 0 ].first;
	int denom = 1;
	int act = v[ 0 ].second, act2 = v[ 0 ].first , k = 1;
	double ans = 1e50;
	for(int i=1;i<n;i++){
		if(v[i].first<= act){
			ff=min(ff,v[i].first-v[i-1].first);
			act=max(act,v[i].second);
			act2=min(act2,v[i].first);
			
			k++;
		}
		else{
			ld cosa = ((1.0*(act-act2))/(1.0*k));
			if( cosa + EPS <ans){
				if(1.0*cosa<1.0*ff){
					denom=k;
					arriba=act-act2;
					ans = cosa;
				}
				else{
					denom=1;
					arriba=ff;
					ans=ff;	
				}
			}	
			ff=v[i].second-v[i].first;
			k=1;
			act=v[i].second;
			act2=v[i].first;
		}
	}
	ld cosa = ((1.0*(act-act2))/(1.0*k));
	if( cosa + EPS <ans){
				if( cosa + EPS <ans){
				if(cosa<1.0*ff){
					denom=k;
					arriba=act-act2;
					ans = cosa;
				}
				else{
					denom=1;
					arriba=ff;
					ans=ff;	
				}
			}	
	}	
			
	printf("%d/%d\n",arriba/__gcd(arriba,denom),denom/__gcd(arriba,denom));
}


