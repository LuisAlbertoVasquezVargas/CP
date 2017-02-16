#include<iostream>
#include<algorithm>

using namespace std;
int n,x0;
void caso()
{
     int mini,maxi,x,y;
     bool ok = 1;
     for( int i = 0 ; i < n ; ++i)
     {
          cin >> x >> y;
          if( i == 0 )
          {
               mini = min(x,y);
               maxi = max(x,y);     
          }
          else 
          {
               if( mini <= min(x,y) && min(x,y) <= maxi )
                    mini = min(x,y);
               if( mini <= max(x,y) && max(x,y) <= maxi )
                    maxi = max(x,y);                    
               if( mini > max(x,y) ||  maxi < min(x,y) ) ok = 0;
          }

     }
     if( ok )
          if( mini <= x0 && x0 <= maxi)
               cout<<"0\n";
          else
               cout<<min(abs(x0-mini),abs(x0-maxi))<<"\n";
     else
          cout<<"-1\n";
}
int main()
{
     while( cin >> n >> x0 )     
          caso();
}
