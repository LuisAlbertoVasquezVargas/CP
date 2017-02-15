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

#define N 105
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

string P[N][N],T[N][N];
bool cmp( string a , string b )
{
	if( a.size() == b.size() ) return a < b;
	return a.size() < b.size();
}

int main()
{
	/*
	int n;
	REP( i , N )
		P[i][0] = "1" , T[0][i] = "1";
	REP( i , N )
		for( int j = 1 ; j < N ; ++j )
			P[i][j] = prod( P[i][j-1] , tos(i) ) , T[j][i] = P[i][j];
	REP( i , N )REP( j , N )cout << P[i][j] << (j+1==N?"\n":" ");
	while( cin >> n )
	{
		string a , b , c;
		bool ok = 1;
		for( int i = 1 ; ok && i <= 100 ; ++i )
			for( int j = 1 ; ok && j <= 100 ; ++j )
			{
				if( i == j )continue;
				string temp = suma( P[i][n] , P[j][n] );
				//cout << i << " " << j << " " << P[i][n] << " " << P[j][n] << " " << temp << endl;
				if( binary_search( T[n] , T[n] + N , temp , cmp ) )
				{
					a = P[i][n] , b = P[j][n];
					c = *lower_bound( T[n] , T[n] + N , temp , cmp );
					ok = 0;
				}
			}
		if( a.empty() )puts("-1");
		else cout << a << " " << b << " " << c << endl;
	}
	*/
	int n;
	while( cin >> n )
	{
		if( n == 1 )puts("1 2 3");
		else if( n == 2 )puts("3 4 5");
		else puts("-1");
	}
}


