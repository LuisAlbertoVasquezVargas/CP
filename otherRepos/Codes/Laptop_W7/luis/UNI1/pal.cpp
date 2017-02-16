#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;
string memo[30][30],s;
	bool used[30][30];
	int sz;
	
	bool comp(string a,string b){
		if(a.size()<b.size())return 1;
		if(b.size()<a.size())return 0;
		
		return a<b;
		
	}
	
	string f(int l,int r){
		if(l==r-1){
			if(s[l]==s[r])return string(2,s[l]);
			else{
				return string(1,s[l])+s[r]+s[l];
			}
		}
		if(l==r){
			
			return string(1,s[l]);
		}
		if(l>r)return "";
		
		if(used[l][r])return memo[l][r];
		
		string ans;
		string ansx=string(1000,'z'+1);
		if(s[l]==s[r])ansx=s[l]+f(l+1,r-1)+s[r];
		string ans1 = s[r] + f(l,r-1) + s[r];
		string ans2 = s[l] + f(l+1,r) + s[l];
		if(comp(ans1,ans2))ans=ans1;
		else ans=ans2;
		if(comp(ansx,ans))ans=ansx;
		
		used[l][r]=1;
		return memo[l][r]=ans;
	}
	
	int main () {
		
		cin>>s;
		sz=s.size();
		memset(used,0,sizeof(used));
		
		cout<< f(0,sz-1)<<endl;
	}



