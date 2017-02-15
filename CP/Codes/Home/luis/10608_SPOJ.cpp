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
#define MOD 10009
#define N 1005
 
ll t[100][4][4];
 
ll f(int x,int a,int b){
    if( x == 0 )
        return 1;
    
    ll &ret = t[x][a][b];
    if( ret != -1 ) return ret;
    ret = 0;
    
    if( a < 3 )
        ret += f( x - 1 , a + 1 , max( 0 , b - 1 ) );
    if( b < 3 )
        ret += f( x - 1 , max( 0 , a - 1 ) , b + 1 );
    
    return ret;
}
 
int main(){
    me(t,-1);
    ll n;
    while( cin >> n ){
        int tam = 1;
        while( n > f( tam , 0 , 0 ) ){
            n -= f( tam , 0 , 0 );
            tam++;
        }
        string ans = "";
        int a = 0 , b = 0 , size = tam;
        for(int i = 0 ; i < size ; i++){
            if( a == 3 ){
                ans += "b";
                a--, b++;
                tam--;
                continue;
            }
            ll r = f( tam - 1 , a + 1 , max( 0 , b - 1 ) );
            if( n <= r ){
                a++, b = max( 0 , b - 1 );
                ans += "a";
            }
            else{
                ans += "b";
                a = max( 0 , a - 1 ) , b++;
                n -= r;
            }
            tam--;
        }
        cout << ans << endl;
    }
    return 0;
}
