#include<bits/stdc++.h>

using namespace std;

#define FOR(i,x,y) for(int i=x;i<y;i++)

char C[240][120];
bool T[240][1040];
bool vis[240][1040];

int color[240][1040];
int timer=0,caso=0;

int H,W;

map<int,char>mapp;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int tr(char c){
	if(c>='0'&&c<='9'){
		return c-'0';
	}
	else{
		return c-'a'+10;
	}
}



void dfsc(int x,int y){
	vis[x][y]=1;

	color[x][y]=timer;
	for(int i=0;i<4;i++){
		int u=x+dx[i],v=y+dy[i];
		if(u>=0&&v>=0&&u<H&&v<4*W&&!T[u][v]){
			if(!vis[u][v])dfsc(u,v);
		}
	}
}

set<int>s;

void dfsf(int x,int y){
	
	vis[x][y]=1;
	
	for(int i=0;i<4;i++){
		int u=x+dx[i],v=y+dy[i];
		if(u>=0&&v>=0&&u<H&&v<4*W){
			if(T[u][v]&&!vis[u][v])dfsf(u,v);
			else{
				if(!T[u][v])s.insert(color[u][v]);
			}
		}
	}
}

int main(){
	
	mapp[2]='A';
	mapp[4]='J';
	mapp[6]='D';
	mapp[5]='S';
	mapp[1]='W';
	mapp[3]='K';
	
	while(scanf("%d%d",&H,&W)==2){
		if(H==0&&W==0)break;
		timer=0;
		memset(color,0,sizeof(color));
		FOR(i,0,H)
			FOR(j,0,W){
				cin>>C[i][j];	
			}
			
		int pt;
		
		FOR(i,0,H){
			pt=W*4-1;
			for(int j=W-1;j>=0;j--){
				int numb=tr(C[i][j]);
				int x=0;
				while(x<4){
					T[i][pt]=numb%2;
					x++;
					numb/=2;
					pt--;
				}
			}
		}
		/*
		FOR(i,0,H){
			FOR(j,0,4*W){
				cout<<T[i][j];
			}
			puts("");
		}	*/
		
		memset(vis,0,sizeof(vis));
		dfsc(0,0);
		dfsc(H-1,0);
		dfsc(0,4*W-1);
		
		dfsc(H-1,4*W-1);
		
		FOR(i,0,H){
			FOR(j,0,4*W){
				if(!vis[i][j]&&!T[i][j])
					++timer,dfsc(i,j);
			}
		}
		string res="";
		memset(vis,0,sizeof(vis));
		FOR(i,0,H){
			FOR(j,0,4*W){
				if(!vis[i][j]&&T[i][j]){
					s.clear();
					dfsf(i,j);
					res+=(mapp[s.size()]);
				}
			}
		}
		sort(res.begin(),res.end());
		printf("Case %d: ",++caso);
		cout<<res<<endl;
	}
}
