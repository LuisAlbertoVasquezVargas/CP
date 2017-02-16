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
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-8)

using namespace std;
struct Pollard_Rho
{
	ull q;
	vull v;	
	Pollard_Rho(){}
	Pollard_Rho( ull x ) {
		q = x;
	}
	ull gcd(ull a, ull b){
	    if(b == 0) return a;
	    return gcd( b , a % b );
	}
	ull mul(ull a,ull b,ull c){
	    ull x = 0, y = a % c;
	    while(b > 0){
	        if(b%2 == 1){
	            x = (x+y)%c;
	        }
	        y = (y*2)%c;
	        b /= 2;
	    }
	    return x%c;
	}
	ull modd(ull a,ull b,ull c){
	    ull x=1,y=a; 
	    while(b > 0){
	        if(b%2 == 1){
	            x=mul(x,y,c);
	        }
	        y = mul(y,y,c); 
	        b /= 2;
	    }
	    return x%c;
	}
	bool Miller(ull p,int iteration){
	    if(p<2){
	        return false;
	    }
	    if(p!=2 && p%2==0){
	        return false;
	    }
	    ull s=p-1;
	    while(s%2==0){
	        s/=2;
	    }
	    for(int i=0;i<iteration;i++){
	        ull a=rand()%(p-1)+1,temp=s;
	        ull mod=modd(a,temp,p);
	        while(temp!=p-1 && mod!=1 && mod!=p-1){
	            mod=mul(mod,mod,p);
	            temp *= 2;
	        }
	        if(mod!=p-1 && temp%2==0){
	            return false;
	        }
	    }
	    return true;
	}
	ull rho(ull n){
	    if( n % 2 == 0 ) return 2;
	    ull x = 2 , y = 2 , d = 1;
	    int c = rand() % n + 1;
	    while( d == 1 ){
	        x = (mul( x , x , n ) + c)%n;
	        y = (mul( y , y , n ) + c)%n;
	        y = (mul( y , y , n ) + c)%n;
	        if( x - y >= 0 ) d = gcd( x - y , n );
	        else d = gcd( y - x , n );
	    }
	    return d;
	}
	void factor(ull n){
	    if (n == 1) return;
	    if( Miller(n , 10) ){
	        if(q != n) v.push_back(n);
	        return;
	    }
	    ull divisor = rho(n);
	    factor(divisor);
	    factor(n/divisor);
	}
	vull primefact( ull num )
	{
		v.clear();
		q = num;
		factor( num );
		sort( all(v) );
		if( v.empty() ) // primos o 1 
			v.pb( num );
		return v;
	}
};
int main()
{
	ull num;
	while( cin >> num )
	{
		if( num == -1 )break;
		Pollard_Rho obj = Pollard_Rho();
		vull v = obj.primefact( num );
		FOR( o , v )
			cout << "    " << *o << endl;
		puts("");
	}
}
