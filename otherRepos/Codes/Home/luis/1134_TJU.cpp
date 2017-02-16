#include<iostream>
using namespace std;
int a[50];
void w(int i,int j,int k,int l,int m,int n){
cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<" "<<a[m]<<" "<<a[n]<<"\n";
}

int main(){
int z;
bool in=false;
    while(1){
    cin>>z;
    if(z==0)break;    
    if(in){
        cout<<endl;
        }else{
        in=true;
    }
    
    
        for(int i=1;i<=z;i++)cin>>a[i];
        
        for(int i=1;i<=z-5;i++){
            for(int j=i+1;j<=z-4;j++){
                for(int k=j+1;k<=z-3;k++){
                    for(int l=k+1;l<=z-2;l++){
                        for(int m=l+1;m<=z-1;m++){
                            for(int n=m+1;n<=z;n++){
                                w(i,j,k,l,m,n);      
                            }    
                        }    
                    }    
                }                
            }    
        }
      
    }    
    
}
