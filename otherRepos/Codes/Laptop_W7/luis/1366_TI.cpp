#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>

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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;



string suma(const string &a, const string &b)  
{  
    int LA = a.size(), LB = b.size(), L = max(LA, LB), carry = 0; 
      
    string x = string(L, '0');  
      
    while(L--) 
    { 
        LA--; LB--; 
          
        if(LA >= 0) carry += a[LA] - '0';  
        if(LB >= 0) carry += b[LB] - '0';  
          
        if(carry < 10) x[L] = '0' + carry, carry = 0; 
        else x[L] = '0' + carry - 10, carry = 1; 
    } 
      
    if(carry) x = '1' + x;  
    return x; 
}
  
//### PRODUCTO DE CADENAS ################################################################## 
string prod(string a, string b) 
{ 
    if(a=="0" || b=="0") return "0"; 
    else if(a.size()==1) 
    { 
        int m = a[0] - '0'; 
          
        string ans = string(b.size(), '0'); 
          
        int lleva = 0; 
          
        for(int i=b.size()-1; i>=0; i--) 
        { 
            int d = (b[i] - '0') * m + lleva; 
            lleva = d/10; 
            ans[i] += d%10; 
        } 
        if(lleva) ans = (char)(lleva + '0') + ans; 
        return ans; 
    } 
    else if(b.size()==1) return prod(b, a); 
    else
    { 
        string ans = "0"; 
        string ceros = ""; 
        for(int i=a.size()-1; i>=0; i--) 
        { 
            string s = prod(string(1, a[i]), b) + ceros; 
            ceros += "0"; 
            ans = suma(ans, s); 
        } 
        return ans; 
    } 
} 
ll toi(string s){istringstream is(s);ll x;is>>x;return x;}
string tos(ll t){stringstream st; st<<t;return st.str();}
string Fact[ 1005 ];
/*
n==1 return 0;
n==2 return 1;
y para el resto
if(n es par)return (n-1)*f(n-1) +(n-1)
else return (n-1)*f(n-1)
*/
int main()
{
	Fact[ 1 ] = "0";
	Fact[ 2 ] = "1";
	for( int i = 3 ; i < N ; ++i )
		if( i%2==1 )
			Fact[ i ] = prod( Fact[i-1] , tos(i-1) );
		else Fact[i] = suma( tos(i-1) , prod( tos(i-1) , Fact[i-1] ) );
	int n;
	while( cin >> n )
		printf( "%s\n" , Fact[n].c_str() );
}


