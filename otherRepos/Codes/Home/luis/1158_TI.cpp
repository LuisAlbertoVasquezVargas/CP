#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<30)
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define fi first
#define se second
#define N 10005
#define ALF 256
int next[N][ALF] , node , T[N] , term[N];
int n , m , k;

char can[55];
string t[55][N];
 
void add(int x,char *s){
    int ac = 0;
    int len = strlen(s);
    for(int i = 0 ; i < len ; i++){
        int v = next[ac][s[i]];
        if( v == 0 ) term[node] = 0 , next[ac][s[i]] = node++;
        ac = next[ac][s[i]];
    }
    term[ac] = 1;
}
 
void aho(){
    queue<int> Q;
    for(int i = 0 ; i < n ; i++){
        int v = next[0][ can[i] ];
        if( v ) T[v] = 0 , Q.push( v );
    }
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        for(int i = 0 ; i < n ; i++){
            int v = next[u][can[i]] , x = next[T[u]][can[i]];
            if( v == 0 ) next[u][can[i]] = x;
            else Q.push( v ) , T[v] = x , term[v] |= term[x];
        }
    }
}
 
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
 
 
string f(int x,int nodo){
    if( term[nodo] ) return "0";
    if( x == m )
        return "1";
    string ret = t[x][nodo];
    if( ret != "" ) return ret;
    ret = "0";
    for(int i = 0 ; i < strlen(can) ; i++){
        int v = next[nodo][ can[i] ];
        ret = suma( ret , f( x + 1 , v ) );
    }
    t[x][nodo] = ret;
    return ret;
}
 
int main(){
    char s[12];
    while( scanf("%d%d%d",&n,&m,&k) == 3 ){
        gets(s);
        gets(can);
        node = 1;
        me( next , 0 );
        for(int i = 0 ; i < k ; i++){
            gets(s);
            add( i , s );
        }
        aho();
        printf("%s\n",f(0,0).c_str());
    }
    return 0;
}
