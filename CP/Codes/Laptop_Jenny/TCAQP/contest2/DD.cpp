    #include<bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef unsigned long long ull;
    #define REP( i , n ) for( int i = 0 ; i < n ; ++i )
    #define MAXN 10000
     
    int N,x;
    int E[10010],p[10010],f[10010];
     
    void sieve(){
    for(int i=2;i*i<=MAXN;i++)
    if(!p[i])
    for(int j=i*i;j<=MAXN;j+=i)
    p[j]=i;
    }
     
    string tos(ull t){stringstream st; st<<t;return st.str();}
     
    int mob(int num){
    int cnt=0;
    while(1){
    int xx=0;
    int P=p[num];
    if(P==0){
    cnt++;
    num=1;
    break;
    }
    while(num%P==0){
    xx++;
    num/=P;
    }
    if(xx>=2)return 0;
    cnt++;
    }
    if(num>1)cnt++;
    if(cnt%2==0)return 1;
    else return -1;
    }
     
    long long comb( int n , int k )
    {
    if(n<4)return 0;
    if( k > n - k ) k = n - k;
    ll C = 1;
    REP( i , k ) C = C * ( n - i )/( 1 + i );
    return (C);
    }
     
    int main(){
    sieve();
    while(scanf("%d",&N)==1){
    memset(E,0,sizeof(E));
    for(int i=0;i<N;i++){
    scanf("%d",&x);
    for(int j=1;j*j<=x;j++){
    if(x%j==0){
    int dv=x/j;
    E[j]++;
    if(j*j!=x)E[dv]++;
    }
    }
    }
     
    long long ans=0;
    for(int i=2;i<=10000;i++){
    ans+=(((mob(i))*comb(E[i],4)));
    }
    cout<<comb(N,4)+ans<<endl;
     
    }
    }
     
