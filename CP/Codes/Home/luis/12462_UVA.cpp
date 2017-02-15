#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define MAXN 100000
#define MAXLOG 16

using namespace std;

int n,c;
long long maxi;
int M[MAXN][MAXLOG],A[MAXN],B[MAXN],N[30][MAXN][MAXLOG],loga[MAXN];

void proceed(){
    for(int i=0;i<n;i++)M[i][0]=A[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            if(M[i][j-1]<M[i+(1<<(j-1))][j-1]) 
                M[i][j]=M[i][j-1];
            else M[i][j]=M[i+(1<<(j-1))][j-1];
        }
    }    
}
int query(int xx,int yy){
    if( yy < xx ) swap( xx , yy );
    int r = yy - xx + 1;
    int k = loga[r];
    if(  M[xx][k]  < M[yy - (1<<k) + 1 ][ k ]  ) 
        return M[xx][k];
    return M[yy - (1<<k) + 1 ][ k ];
}
void proceed2(){
     for( int k = 0 ; k < c ; ++k ) 
          for( int i=0 ; i<n ; i++ )
               N[k][i][0]=1;
     for(int i=0;i<n;i++)N[B[i]][i][0]=0;
     for( int k = 0 ; k < c ; ++k )
          for(int j=1;(1<<j)<=n;j++){
               for(int i=0;i+(1<<j)-1<n;i++){
                    if(N[k][i][j-1]<N[k][i+(1<<(j-1))][j-1]) 
                         N[k][i][j]=N[k][i][j-1];
                    else N[k][i][j]=N[k][i+(1<<(j-1))][j-1];
               }
          }    
}
int query2(int p,int xx,int yy){
    if( yy < xx ) swap( xx , yy );
    int r = yy - xx + 1;
    int k = loga[r];
    if(  N[p][xx][k]  < N[p][yy - (1<<k) + 1 ][ k ]  ) 
        return N[p][xx][k];
    return N[p][yy - (1<<k) + 1 ][ k ];
}
int allcolor(int x,int y)
{
     int ok = 1;
     for( int i = 0 ; i < c ; ++i )
          if(query2(i,x,y)==1)ok = 0;
     return ok;     
}
int BS1(int lo , int i)
{
     int nlo = lo;
     int nhi = i;
     if(query(lo,i) == A[i]) return lo;
     while( nhi - nlo > 1 )
     {
          int med = (nlo + nhi) >> 1;
          if( query(med,i) == A[i])
               nhi = med;
          else nlo = med;
     }
     return nhi;
}
void proc()
{
     loga[1]=0;
     for(int i=1;i<=14;i++)
     for(int j=1<<i;j<(1<<(i+1));j++ ) loga[j]=i;
     for(int j=1<<15;j<MAXN;j++ ) loga[j]=15;     
}
int BS2(int i , int hi)
{
     int nlo = i;
     int nhi = hi;
     if(query(i,hi) == A[i])return hi;
     while( nhi - nlo > 1 )
     {
          int med =(nlo + nhi) >> 1;
          if( query(i,med) == A[i])
               nlo = med;
          else nhi = med;     
     }
     return nlo;
}

int main()
{
     proc();
     while( scanf("%d%d",&n,&c)==2 )
     {
          if( n == 0 && c == 0)return 0;
          for( int i = 0 ; i < n ; ++i )
               scanf("%d", &A[i]);
          for( int i = 0 ; i < n ; ++i )
               scanf("%d", &B[i]);
          maxi = 0;
          proceed();
          proceed2();
          for( int i = 0 ; i < n ; ++i )
          {
               int lo = BS1(0,i);
               int hi = BS2(i,n-1);
               long long w,h;
               if(allcolor(lo,hi) == 0)continue;
               w = hi - lo + 1;
               h = A[i];
               maxi = max(maxi,h*w);
          }
          printf("%lld\n",maxi);
     }
}
