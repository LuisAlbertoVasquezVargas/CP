#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

ld realF(ld b, int x){
	if(x==0)return 1;
	return pow(b,realF(b,x-1));
}
int longPow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a;
		b>>=1;
		a*=a;
	}
	return ans;
}
int longF(int b,int x){
	if(x==0)return 1;
	return longPow(b,longF(b,x-1));
}

int pow(int a, int b, int c){
	if(c==1)return 0;
	//DEBUG3(a,b,c);
	int ans=1;
	while(b){
		if(b&1)ans=((ll)ans*(ll)a)%c;
		b>>=1;
		a=((ll)a*(ll)a)%c;
	}
	return ans;
}
const int MAX_N=(int)1e7;
int memo[MAX_N+1];
int phi(int n){
	if(n==1)return 1;
	if(memo[n])return memo[n];
	int &ans=memo[n]=n;
	for(int i=2;i*i<=n;++i)
		if(n%i==0){
			while(n%i==0)n/= i;
			ans-=ans/i; 
		}
	if(n>1)ans-=ans/n;
	return ans;
}
// a^b%c = a^x%c
// if( b >= phi( c ) ) x = b%phi( c ) + phi( c );
//	else x = b
unordered_map<ll,int>myMap;
int f(int b,int x, int mod){
	//DEBUG3(b,x,mod);
	if(x==0)return 1;
	if(myMap.count((ll)mod*10000LL+x*100LL+b))return myMap[(ll)mod*10000LL+x*100LL+b];
	ld real=realF(b,x-1);
	int myLong=isinf(real)?-1:longF(b,x-1);
	if(real>1e9||myLong>=phi(mod))return myMap[(ll)mod*10000LL+x*100LL+b]=pow(b,phi(mod)+f(b,x-1,phi(mod)),mod);
	return myMap[(ll)mod*10000LL+x*100LL+b]=pow(b,myLong,mod);
}
void print(int n,int x){
	if(n==1)printf("%01d\n",x);
	if(n==2)printf("%02d\n",x);
	if(n==3)printf("%03d\n",x);
	if(n==4)printf("%04d\n",x);
	if(n==5)printf("%05d\n",x);
	if(n==6)printf("%06d\n",x);
	if(n==7)printf("%07d\n",x);
}
int T[101][101][8];
int main(){
	/*
	for(int i=1;i<=10;++i)
		DEBUG(phi(i));
	*/
	
	for(int b=1;b<=100;++b){
		for(int I=1;I<=100;++I){
			for(int n=1;n<=7;++n){
				int mod=1;
				REP(k,n)mod*=10;
				T[b][I][n]=f(b,I,mod);
			}
		}
	}
	int b,I,n;
	while(scanf("%d",&b)==1){
		if(!b)break;
		cin>>I>>n;
		/*
		ll mod=1;
		REP(k,n)mod*=10;
		T[b][I][n]=f(b,I,mod);
		*/
		print(n,T[b][I][n]);
	}
}




