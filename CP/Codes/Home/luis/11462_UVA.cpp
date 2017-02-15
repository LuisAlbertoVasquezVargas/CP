#include<iostream>
#include<cstring>

using namespace std;

void counting(int *a,int *b,int *val,int n,int k)
{
     int *c=new int[k+1];
     memset(c,0,4*(k+1));
     for(int i=0;i<n;++i)c[val[a[i]]]++;
     for(int i=1;i<=k;++i)c[i]+=c[i-1];
     for(int i=n-1;i>=0;--i)b[--c[val[a[i]]]]=a[i];
     delete[] c;
}
bool caso()
{
     int n;
     cin >> n;
     if(n == 0 )return 0;
     int *a = new int[n];
     int *b = new int[n];
     int *val = new int[n];     
     for( int i = 0 ; i < n ; ++i)
     {
          cin >> a[i];
          val[i] = a[i];
     }
     counting(a,b,val,n,100);
     cout<<b[0];
     for( int i = 1 ; i < n ; ++i)
          cout<<" "<<b[i];
     cout<<endl;
     return 1;
}
int main()
{
     while(caso());
}
