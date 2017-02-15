#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

pair<int,int>v[1000];
int n,x,y;

int main()
{
     while( cin >> n )
     {
          for( int i = 0 ; i < n ; ++i )
          {
               cin >> x >> y;
               v[i] = make_pair(-y,-x);
          }
          sort(v,v+n);
          int play = 1;
          int point = 0;
          int it = 0;
          while( play > 0 && it < n )
          {
               int ny = -v[it].first;
               int nx = -v[it].second;
               play+=ny;
               point+=nx;
               it++;
               play--;
          }
          cout<<point<<endl;
     }
}
