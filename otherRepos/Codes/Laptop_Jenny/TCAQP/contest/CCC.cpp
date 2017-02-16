#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, int>memo;

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
/*
vi doit( int n ){
    vi p , e;
    vi divisors( 1000 );
    primefact( n , p , e );
    int cnt = 1; 
    divisors[0] = 1;
    int k = e.size();
    //REP( i , k ) cout << p[ i ] << " " << e[ i ] << endl;
    for( int i = 0 ; i < k ; i++ ){
        int m = cnt;
        for( int j = 0 ; j < e[i] ; j++ ){
            int sz = j * m ;
            for( int a = 0 ; a < m ; a++ ) divisors[ cnt++ ] = p[ i ] * divisors[ a + sz ]; 
        }
    }
    divisors.resize( cnt );
    return divisors;
} */

vi D;

void getdiv(int cur,vi &fact,int s,int e){
	if(s==e)D.push_back(cur);	
	else{
		int m;
		for(m =s+1;m<e&&fact[m]==fact[s];m++);
		for(int i=s;i<=m;i++){
			getdiv(cur,m,e);
			cur*=fact[s];
		}
	}
}
ll f(int n){
	ll ans=0;
	if(memo.count(n)!=0)return memo[n];
	vi fact = POL(n);
	D.clear();
	getdiv(1,fact,0,fact.size());
	for(int i=0;i<D.size();i++){
		if(D[i]*D[i]==n){
			ans+=f(D[i])*f(D[i]);
		}
		else{
			ans+=2*f(D[i])*f(n/D[i]);
		}
	}
	return memo[n]=ans;
}

int main(){
	while(scanf("%d",&N)==1){
		cout<<f(N)<<endl;
	}
}
