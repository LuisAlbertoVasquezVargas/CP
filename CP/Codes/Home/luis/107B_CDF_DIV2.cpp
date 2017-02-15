#include<iostream>
#include<algorithm>

using namespace std;

int n, k, l, c, d, p, nl, np;
int a[3];

int main()
{
     while( cin >> n >> k >> l >> c >> d >> p >> nl >> np )
     {
          a[0] = (k*l)/(n*nl);
          a[1] = (c*d)/n;
          a[2] = p/(n*np);
          sort(a,a+3);
          cout<<a[0]<<endl;
     }
}
