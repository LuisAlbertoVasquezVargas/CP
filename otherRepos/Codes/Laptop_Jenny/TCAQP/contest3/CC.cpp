#include<bits/stdc++.h>

using namespace std;

#define all(v) v.begin(),v.end()
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

map<vi, ll>memo;
struct Pollard_Rho
{
    ll q;
    vi v; 
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
    vi primefact( ull num )
    {
        v.clear();
        q = num;
        factor( num );
        sort( all(v) );
        if( v.empty() ) // primos o 1 
            v.pb( num );
        return v;
    }
}POL; 
int pow( int a , int b , int c ){
    int ans = 1;    
    while( b ){
        if( b&1 ) ans = ( 1LL*ans * a )%c;
        a = ( 1LL*a*a )%c;
        b >>= 1;
    }   
    return ans;
}
bool miller(ll p, int it = 8){
    if(p < 2) return 0;
    if(p != 2 && (p & 1) == 0) return 0;
    int s = p - 1;
    while( (s & 1) == 0) s >>= 1;
    while( it-- ){
        int a = rand() % (p - 1) + 1, temp = s;
        int mod = pow(a, temp, p);
        while(temp != p - 1 && mod != 1 && mod != p - 1){
            mod = ( 1LL* mod*mod )%p;
            temp <<= 1;
        }
        if(mod != p - 1 && (temp & 1) == 0) return 0;
    }
    return 1;
} 

void impr(vi P){
	for(int i=0;i<P.size();i++)
			cout<<P[i]<<" ";
		puts("");
}


ll f(vi v){
	if(v.size()==1)return 1;
	if(memo.count(v)!=0)return memo[v];
	int n=v.size();
	ll ans=0;
	set< vi >S;
	for(int mask=1;mask< ((1<<n)-1);mask++){
		vi a,b;
		for(int i=0;i<n;i++){
			if(mask&(1<<i))a.push_back(v[i]);
			else{
				b.push_back(v[i]);
			}
		}
		if( S.count( a ) && S.count( b ) ) continue;
		S.insert( a ) , S.insert( b );
		if(a==b){
			ans+=f(a)*f(b);
		}
		else{
			ans+=2*f(a)*f(b);
		}
		
	}
	return memo[v]=ans;
}

vi fix(vi v){
	vi a(v);
	int nv = v.size() , cnt = 0;
	for( int i = 0 ; i < nv ; ++i ){
		int ind = i;
		for( int j = i ; j < nv ; ++j )
			if( v[ i ] == v[ j ] ) ind = j , a[ j ] = cnt;
		cnt++;
		i = ind;		
	}
	return a;
}

int main(){
	int n;
	while(scanf("%d",&n)==1){
		vi P = POL.primefact(n);
		P = fix( P );
		impr( P );
		cout<<f(P)<<endl;
	}
}
