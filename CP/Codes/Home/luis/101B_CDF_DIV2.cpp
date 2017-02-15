#include<iostream>

using namespace std;
int a,x,y;
int f()
{
     if( y <= 0 ) return -1;
     if( y <= a + a && y != 0 && x + x <= a && x + x >= -a )
          if( y%a == 0 || x + x == a || x + x == -a )
               return -1;
          else return y/a +1;
     else
     {
          int ny = y - a - a;
          int k = ny/a;
          if( ny%a != 0 )
               if( k%2 == 0 )
                    if( x > -a && x < a && x != 0 )
                         return 2+(k/2)*3+(x<0?1:2);
                    else return -1;
               else if( x + x > -a && x + x < a )
                    return 2+2+(k/2)*3+1;
               else return -1;
          else return -1;
     }     
}
int main()
{
     while( cin >> a >> x >> y )
          cout<<f()<<endl;
}
