#include<iostream>
#include<queue>
#include<cstring>
#define MAXR 1000
#define MAXC 1000

using namespace std;

int M[MAXR][MAXC];
int D[MAXR*MAXC];
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};

int main(){
    while(1){
    int R,C,rows,r0,c0,r,c,n,l,m;
        memset(M,0,sizeof(M));
        memset(D,-1,sizeof(D));    
        cin>>R>>C;
        if(R==0&&C==0)break;
        cin>>rows;
        for(int i=1;i<=rows;++i){
            cin>>r>>n;
            for(int j=1;j<=n;++j){
            
                cin>>c;    
                M[r][c]=1;
            }    
        }
        cin>>r0>>c0;
/*        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
                cout<<M[i][j];
            cout<<endl;
        }
  */      
        queue<int>Q;
    //Invariante    
        Q.push(r0*C+c0);
        D[r0*C+c0]=0;        
    //    
        while(!Q.empty()){
            int idx=Q.front();
            Q.pop();
            r= idx/C;
            c= idx%C;
            for(int k=0;k<4;++k){
                int nr = r+dx[k];
                int nc = c+dy[k];
                int nidx=nr*C+nc;
                if(nr >= 0 && nr < R && nc >= 0 && nc < C && D[nidx]==-1&&M[nr][nc]==0){
                    Q.push(nidx);    
                    D[nidx]=D[idx]+1;
                }            
            }
        }    
        cin>>l>>m;
        cout<<D[(l)*C+m]<<endl;
    }        
      
}
