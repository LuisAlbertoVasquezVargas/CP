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

#define test() cerr<<"hola que hace ?"<<endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector<vi> vvi;

const int MAX_N=256;
const int INF=INT_MAX/3;
string alpha;
vi A;
vi forb(MAX_N);
bool used[MAX_N][2];
int memo[MAX_N][2];
int cost(int a,int b){
	if(b-a+1==1)return 1;
	if(b-a+1==2)return 2;
	return 3;
}
string getCost(int a,int b){
	if(b-a+1==1)return string(1,a);
	if(b-a+1==2)return string(1,a)+string(1,b);
	if(b-a+1==3){
		string s=string(1,a)+string(1,a+1)+string(1,b);
		string t=string(1,a)+string(1,'-')+string(1,b);
		return min(s,t);
	}
	return string(1,a)+string(1,'-')+string(1,b);
}
int CTE1=2,CTE2=1;
int dp(int pos,bool taked){
	if(pos==127)return taked?0:INF;
	if(used[pos][taked])return memo[pos][taked];
	used[pos][taked]=1;
	int &ans=memo[pos][taked]=INF;
	if(A[pos]!=CTE1)ans=min(ans,dp(pos+1,taked));
	for(int k=pos;k<=126;++k){
		//if(count(forb.begin()+pos,forb.begin()+k+1,1))continue;
		if(count(A.begin()+pos,A.begin()+k+1,CTE2)==0)
			ans=min(ans,cost(pos,k)+dp(k+1,1));
	}
	return ans;
}
string rec(int pos,int taked){
	if(pos==127)return "";
	string ans(300,255);
	int target=dp(pos,taked);
	if(A[pos]!=CTE1){
		if(target==dp(pos+1,taked)){
			ans=min(ans,rec(pos+1,taked));
		}
	}
	for(int k=pos;k<=126;++k){
		//if(count(forb.begin()+pos,forb.begin()+k+1,1))continue;
		if(count(A.begin()+pos,A.begin()+k+1,CTE2)==0){
			if(target==cost(pos,k)+dp(k+1,1)){
				ans=min(ans,getCost(pos,k)+rec(k+1,1));
			}
		}
	}
	return ans;
}

void impr(string s){
	cout<<"%["<<s<<"]"<<'\n';
}
int main(){
	alpha+=' ';
	for(int c='a';c<='z';++c) alpha+=c;
	for(int c='A';c<='Z';++c) alpha+=c;
	for(int c='0';c<='9';++c) alpha+=c;
	/*
	forb['-']=1;
	forb[']']=1;
	forb['^']=1;
	*/
	DEBUG(alpha);
	string s;
	while(getline(cin,s)){
		set<char>mySet(all(s));
		s=string(all(mySet));
		A=vi(MAX_N);
		for(auto c:alpha)A[c]++;
		for(auto c:s)A[c]++;
		int start=32;
		clr(used,0);
		int ans1=dp(start,0);
		//DEBUG(dp(start,0));
		string op1=rec(start,0);
		
		swap(CTE1,CTE2);
		clr(used,0);
		int ans2=dp(start,0);
		//DEBUG(dp(start,0));
		string op2="^"+rec(start,0);
		swap(CTE1,CTE2);
		DEBUG2(ans1,ans2);
		DEBUG2(op1,op2);
		if(ans1>=INF){
			impr(op2);
			continue;
		}
		if(ans2>=INF){
			impr(op1);
			continue;
		}
		if(SZ(op1)==SZ(op2)){
			impr(min(op1,op2));
			continue;
		}
		if(SZ(op1)<SZ(op2))impr(op1);
		else impr(op2);
	}
}


