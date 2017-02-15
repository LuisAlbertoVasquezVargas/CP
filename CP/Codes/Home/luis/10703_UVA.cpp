#include<iostream>

using namespace std;
bool a[501][501];
void paint( int minx,int maxx,int miny,int maxy ,bool value)
{
     for( int  i = minx ; i <= maxx ; ++i)
          for( int j = miny ; j <= maxy ; ++j)
               a[i][j] = value;         
}
int cont( int maxx,int maxy)
{
     int s = 0 ;
     for( int  i = 1 ; i <= maxx ; ++i)
          for( int j = 1 ; j <= maxy ; ++j)
               if(a[i][j])s++;
     return s;               
}
int main()
{
     int w,h,n;
     while( 1 )
     {
          cin>>w>>h>>n;
          if( w == 0 ) break;
          paint(1,w,1,h,1);
          for( int i = 0 ; i < n ; ++i )
          {
               int x1,y1,x2,y2;
               cin>>x1>>y1>>x2>>y2;
               paint(min(x1,x2),max(x1,x2),min(y1,y2),max(y1,y2),0);
          }
          int ans = cont(w,h);
          if( ans == 0 )
               cout<<"There is no empty spots.\n";
          else if ( ans == 1 )
               cout<<"There is one empty spot.\n";
          else cout<<"There are "<<ans<<" empty spots.\n";               
     }     
}
