#include<iostream>
#include<cstring>

using namespace std;
int acum[10];     
void present()
{
     string s;
     for( int i = 9 ; i >= 0 ; --i)
          for( int j = 0 ; j < acum[i] ; ++j )
               s+='0'+i;     
     if(s[0] == '0' )
          cout<<"0\n";
     else cout<<s<<endl;
}
int main()
{
     int n,sum;
                
     while( cin >> n )
     {
          memset(acum,0,sizeof(acum));
          sum=0;
          for( int i = 0 ; i < n ; ++i )
          {
               int x;
               cin >> x;
               sum+=x;
               acum[x]++;
          }
          
          if(acum[0] == 0)
          {
               cout<<"-1\n";
               continue;     
          }
          else
          {
               if( sum%3 == 0 )
               {
                    present();
               }
               else if( sum%3 == 1 )
               {
                    if( acum[1]||acum[4]||acum[7])
                    {
                         for(int i = 1; i<= 7 ; i+=3)
                              if(acum[i])
                              {
                                   acum[i]--;
                                   break;     
                              }
                         present();
                    } else
                    {
                         int two = 2;
                         for( int i = 2 ; i <= 8&&two ; i+=3)
                              while(acum[i]&&two)
                              {
                                   acum[i]--;
                                   two--;     
                              }
                         present();
                    } 
               }else
               {
                    if( acum[2]||acum[5]||acum[8])
                    {
                         for(int i = 2 ; i<= 8 ; i +=3)
                              if(acum[i])
                              {
                                   acum[i]--;
                                   break;     
                              }
                         present();
                    } else
                    {
                         int one = 2;
                         for( int i = 1 ; i <= 7&&one ; i+=3)
                              while(acum[i]&&one)
                              {
                                   acum[i]--;
                                   one--;     
                              }
                         present();
                    }                     
                    
               }
          }
     }
}
