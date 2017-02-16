#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector< ull > vull;

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
}POL; 
int main()
{
	ull n;
	while( cin >> n ){
		if( n == -1 )break;
		vull v = POL.primefact( n );
		int nv = v.size();
		ull a = 1 , b = 1;
		for( int i = 0 ; i < nv ; ++i ){
			int ind = i;
			for( int j = i ; j < nv ; ++j )
				if( v[ j ] == v[ i ] ) ind = j;
				else break;
			int cnt = ind - i + 1;
			REP( k , cnt/2 ) a *= v[ i ];
			if( cnt %2 ) b *= v[ i ];
			i = ind;
		}
		cout << a << " " << b << '\n';
	}
}
