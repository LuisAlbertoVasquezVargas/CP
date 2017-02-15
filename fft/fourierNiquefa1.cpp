#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test puts("************test************");
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define PI acos( -1.0 )
#define MAXN 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double lf;

const lf eps=1e-8,pi=acos(-1.0);
struct cp{
    lf a,b;
    cp(){}
    cp(lf a,lf b):a(a),b(b){}
    cp operator+(const cp&x)const{return (cp){a+x.a,b+x.b};}
    cp operator-(const cp&x)const{return (cp){a-x.a,b-x.b};}
    cp operator*(const cp&x)const{return (cp){a*x.a-b*x.b,a*x.b+b*x.a};}
};
void rev(cp *a,int n){
    int i,j,k;
    for (i=1,j=n>>1;i<n-1;i++){
        if(i<j)std::swap(a[i],a[j]);
        for (k=n>>1;j>=k;j-=k,k>>=1);j+=k;
    }
}
void dft(cp *a,int n,int flag=1){
    rev(a,n);
    for (int m=2;m<=n;m<<=1)
    {
        cp wm=(cp){cos(flag*2*pi/m),sin(flag*2*pi/m)};
        for (int k=0;k<n;k+=m)
        {
            cp w=(cp){1.0,0.0};
            for (int j=k;j<k+(m>>1);j++,w=w*wm)
            {
                cp u=a[j],v=a[j+(m>>1)]*w;
                a[j]=u+v;
                a[j+(m>>1)]=u-v;
            }
        }
    }
}
void mul(cp *a,cp *b,int n){
    dft(a,n);dft(b,n);
    for (int i=0;i<n;i++)a[i]=a[i]*b[i];
    dft(a,n,-1);for (int i=0;i<n;i++)a[i].a/=n;
}

