#include<iostream>
#include<algorithm>
#define MAXN 1000

using namespace std;

int x[MAXN],y[MAXN],r[MAXN],xa,ya,xb,yb,n,X,Y,cont;
int g(int x)
{
     return x*x;
}
bool f(int x1,int x2,int y1,int y2,int r)
{
     return (g(x1-x2)+g(y1-y2) <= g(r));
}
void proc()
{
     for( int i = 0 ; i < n ; ++i )
          if( f(X,x[i],Y,y[i],r[i]))
          {
               cont++;
               return;
          }     
}
int main()
{
     while( cin >> xa >> ya >> xb >> yb >> n )
     {
          for( int i = 0 ; i < n ; ++i )
               cin >> x[i] >> y[i] >> r[i];
          if( xa > xb )
               swap(xa,xb),swap(ya,yb);
          cont = 0;
          for(X = xa ; X <= xb ; ++X )
          {
               Y = ya;     
               proc();
               Y = yb;     
               proc();                       
          }
          if( ya > yb )
               swap(ya,yb);
          for(Y = ya + 1 ; Y < yb ; ++Y )
          {
               X = xa;     
               proc();
               X = xb;     
               proc();
          }          
          cout<<((xb-xa+yb-ya)<<1)-cont<<endl; 
     }
}
