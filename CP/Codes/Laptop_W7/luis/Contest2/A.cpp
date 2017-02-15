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

#define N 205

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
string tos(int t){stringstream st; st<<t;return st.str();}
string F[ N ] , DP[ N ] , TWO[ N ];

string P(int num,int k){
	string r="1";
	for(int i=k;i<=num;i++)
		prod(r,tos(i));
	return r;
}

string F2(int n){
	string temp="0";
	for(int i=0;i<=(n-1);i++){
		temp=suma(temp,P(n,i));
		//cout<<P(n,i)<<endl;
	}
	return temp;	
}

int main()
{
	//derangements.in
	//derangements.out
	//freopen("derangements.in", "r", stdin);
	//freopen("derangements.out", "w", stdout);
	int n;
	cin >> n;
	F[ 0 ] = "1";
	for( int i = 1 ; i < N ; ++i ) F[ i ] = prod( F[ i - 1 ] , tos( i ) );
	DP[ 1 ] = "0";
	DP[ 2 ] = "1";
	for( int i = 3 ; i < N ; ++i ) DP[ i ] = prod( tos( i - 1 ) , suma( DP[ i - 1 ] , DP[ i - 2 ] ) );
	TWO[ 0 ] = "1";
	string TWO2 = "2";
	for( int i = 1 ; i < N ; ++i ) TWO[ i ] = prod( TWO[ i - 1 ] , TWO2 ); 
	string temp = "0";
	for( int i = 0 ; i < n ; ++i ) temp = suma( temp , TWO[ i ] );
	string temp2 = prod( temp , DP[ n ] );
	string ans = suma( temp2 , F2(n) );
	cout << ans << endl;
}



