#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define MAXN 100000
#define LOGMAX 21
using namespace std ;
char t[MAXN];
int m,m1,m2;
/////////////////////////SUFFIX UlTRA FAST /////////////////////
char s[MAXN];
int suf[MAXN],lcp[MAXN],ind[MAXN],siz[60],beg[60];
int n;
int M[MAXN][LOGMAX];
void rmq(){
    for(int i=0;i<n;i++)M[i][0]=lcp[i];
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
    int k = (30-__builtin_clz(r));
    while( (1<<k) <= r ) k++;
    k--;
    if(  M[xx][k]  < M[yy - (1<<k) + 1 ][ k ]  ) 
        return M[xx][k];
    return M[yy - (1<<k) + 1 ][ k ];
}
void counting(int* a,int *b,int *val,int n,int k){
        int* c=new int[1+k];
        memset(c,0,sizeof(int)*(1+k));
        for(int i=0;i<n;++i)c[val[a[i]]]++;
        for(int i=1;i<=k;++i)c[i]+=c[i-1];
        for(int i=n-1;i>=0;--i)b[--c[val[a[i]]]]=a[i];
        delete[] c;
}
 
void suffix(int* val,int* suf,int n,int k){
        val[n]=val[n+1]=val[n+2]=0;
        int n0=(n+2)/3,n2=n/3,n02=n0+n2;
        int *val12=new int[n02+3];
        int *suf12=new int[n02+3];
        for(int i=0,j=0;i<n+(n%3==1);++i)if(i%3)val12[j++]=i;
        counting(val12,suf12,val+2,n02,k);
        counting(suf12,val12,val+1,n02,k);
        counting(val12,suf12,val,n02,k);
        int a=-1,b=-1,c=-1,ct=0;
        for(int i=0;i<n02;++i){
                int ind=suf12[i];
                if(val[ind]!=a or val[ind+1]!=b or val[ind+2]!=c)++ct;
                val12[(ind%3==1)?ind/3:ind/3+n0]=ct;
                a=val[ind],b=val[ind+1],c=val[ind+2];
        }
        if(ct==n02){
                val12[n02]=0;
                for(int i=0;i<n02;++i){
                        suf12[val12[i]-1]=i;
                }
        }
        else{
                suffix(val12,suf12,n02,ct);
                for(int i=0;i<n02;++i){
                        int ind=suf12[i];
                        val12[ind]=i+1;
                }
        }
        int *val0=new int[n0];
        int *suf0=new int[n0];
        for(int i=0,j=0;i<n02;++i){
                int ind=suf12[i];
                if(ind<n0)val0[j++]=ind*3;
        }
        counting(val0,suf0,val,n0,k);
        a=0,b=(n%3==1),c=0;
        #define comp1(a1,b1,a2,b2) (((a1)!=(a2))?((a1)<(a2)):((b1)<(b2)))
        #define comp2(a1,b1,c1,a2,b2,c2) (((a1)!=(a2))?((a1)<(a2)):(((b1)!=(b2))?((b1)<(b2)):((c1)<(c2))))
        #define get(i) ((i)<n0?(3*i+1):(3*(i-n0)+2))
        while(a<n0&&b<n02){
                int ind0=suf0[a],ind12=get(suf12[b]);
                if(ind12%3==1?comp1(val[ind0],val12[ind0/3],val[ind12],val12[suf12[b]+n0]):
                comp2(val[ind0],val[ind0+1],val12[ind0/3+n0],val[ind12],val[ind12+1],val12[suf12[b]-n0+1]))suf[c++]=ind0,a++;
                else suf[c++]=ind12,b++;
        }
        while(a<n0)suf[c++]=suf0[a++];
        while(b<n02)suf[c++]=get(suf12[b]),b++;
        delete [] val12; delete [] suf12; delete [] val0; delete [] suf0;
}
void lcp1(int *lcp,int *pos,int n)
{
     int *rank = new int[n+3];
     for(int i=0;i<n;++i)rank[pos[i]]=i;
     	int h=0;
     	for(int i=0;i<n;++i)if(rank[i]){
     		int j=pos[rank[i]-1];
     		while(s[i+h]==s[j+h])++h;
     		lcp[rank[i]-1]=h;
     		if(h)h--;
     	}
     lcp[n-1] = 0;
     delete [] rank;
} 
void _suffix()
{
        int *val=new int[n+3];
        for(int i=0;i<n;++i)val[i]=s[i];
        suffix(val,suf,strlen(s),127);     
} 
void _lcp()
{
     lcp1(lcp,suf,n);     
}

int main()
{
     int tc;
     while( scanf("%d",&tc) == 1 && tc )
     {
          s[0] = 0;
          for( int i = 0; i < tc ; ++i )
          {
               scanf("%s",t);
               m1 = strlen(s);
               strcat(s,t);
               siz[i] = strlen(t);
               string a;
               a+=' '+i;
               strcat(s,a.c_str());
               m2 = strlen(s);
               beg[i] = m1;
               for( int j = m1 ; j <= m2 ; ++j )
                    ind[j] = i;
          }
          n = strlen(s);
          _suffix();
          _lcp();
          rmq();
          int cnt = 0;
          /*
          printf("%s\n",s);
          for( int i = 0 ; i < n ; ++i )       
               printf("%d",ind[i]);
          puts("");                                      
          for( int i = 0 ; i < n ; ++i )       
               printf("%d",i);               
          puts("");                       
          for( int i = 0 ; i < n ; ++i )
               printf("%d\n",beg[i]);  
               */        
          for( int i = tc ; i < n ; ++i )
          {
               if( beg[ind[suf[i]]] == suf[i] )
               {
                    int x = siz[ind[suf[i]]];
                    if( lcp[i] != x )
                         continue;
                    int lo = i ; 
                    int hi =  n - 1;
                    while( hi - lo > 1 )
                    {
                         int med = lo + ( hi - lo )/2;
                         if( query(i,med) == x )     
                              lo = med;
                         else hi = med;
                    }
                    printf("%d * %d\n",lo-i+1,suf[i]);
                    cnt+=(lo-i+1);
               }
          }          
          puts("");
          
          for( int i = 0 ; i < n ; ++i )
               printf("%s  %d\n",s+suf[i],lcp[i]);
          printf("%d\n",cnt);
          puts("***************");
     }
}
