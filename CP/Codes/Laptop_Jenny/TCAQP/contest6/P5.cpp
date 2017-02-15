#include<cstdio>
#include<algorithm>
#include<iostream>
#define ll long long
#define MOD 10001
using namespace std;
ll  A[500] , B[500];

void gcdext( ll &g , ll &x , ll &y , ll a , ll b ){
    if( b == 0 )
        g = a , x = 1 , y = 0;
    else gcdext( g , y , x , b , a%b ) , y = y - ( a/b )*x;
}
// From number theoretic algorithms .ppt
  
// ax = b (mod n)
// gcdext( g , x , y, a , n );
// if( b%g == 0 ) return x*( b/g ) ;
// return -1; 


int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;++i){
		scanf("%lld",&A[2*i+1]);
	}
	
	if(t>=2){
		for(ll i=0;i<=10000;++i){
			ll b;
			ll num=  A[3] -  ( ( (i *i)%MOD ) *  A[1] ) %MOD;
			num=(num+MOD)%MOD;
			ll den=i+1;
			den=den%MOD;
			ll g,x,y;
			gcdext( g, x, y, den, MOD );
			if(num%g==0){
				b=x*(num/g);
				b=(b+MOD)%MOD;
				//completo
				B[1]=A[1];
				for(int j=2;j<=2*t;++j){
					B[j]=(i * B[j-1] + b )%MOD;
				}
				//check
				bool ok=1;
				for(int j=1;j<=2*t;++j){
					if( (j&1) &&A[j]!=B[j]){
						ok=0;break;
					}
				}
				if(ok){
					for(int j=1;j<=2*t;++j){
						if(j%2==0){
							printf("%lld\n",B[j]);
						}
					}
					break;
				} 
			}
		}
	}
	else{
		printf("%lld\n",A[1]);
	}
}
