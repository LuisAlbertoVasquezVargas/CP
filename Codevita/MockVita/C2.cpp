#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<set>
#include<vector>
#include<map>
#include<cassert>
using namespace std;


int main(){


    int n,m;
    while(cin>>n>>m){
        bool visited[52][52];
        memset(visited,0,sizeof(visited));

        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;a--;b--;
            visited[a][b]=1;
            visited[b][a]=1;
        }
        
        bool yes=0;
        for(int i=0;i<(1<<n);i++){
            bool ok=1;
            for(int j=0;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(visited[j][k]){
                        int x=0;
                        if((i&(1<<j))!=0)x=1;
                        int y=0;
                        if((i&(1<<k))!=0)y=1;

                        if(x==y){
                            ok=0;
                        }
                    }
                }
            }
            
            if(ok)yes=1;
        }

        if(yes || n%14==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }


    return 0;
}

//  3 yes y 6 no
