#include<stdio.h>
#include<string.h>
char t[1024][2048],u[2049]; 
void f(int n,int fil,int col)
{
    if(n==1){
        t[fil][col]=t[fil-1][col+1]='/';
        t[fil][col+3]=t[fil-1][col+2]='\\';
        t[fil][col+1]=t[fil][col+2]='_';
        return;
    }
    f(n-1,fil,col);
    f(n-1,fil,col+(1<<n));
    f(n-1,fil-(1<<(n-1)),col+(1<<(n-1)));
}
int main()
{
     memset(t,' ',sizeof(t));
     f(10,(1<<10)-1,0);
     while(1)
     {
          int n;
          scanf("%d",&n);
          if(n == 0)break;
          int L = (1<<n),i;
          for(i=0;i<L;++i)
          {
               strncpy(u,t[1024-L+i],L+i+1);
               u[L+i+1]=0;
               printf("%s\n",u);
          }
          puts("");          
     }
}
