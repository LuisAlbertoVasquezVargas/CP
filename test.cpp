#include <iostream>
#include <cmath> 

using namespace std;
int halla(int arreglo[],int n){
	int x=0,suma,aux,i;
	for(i=0;i<n;i++){
		aux+=abs(arreglo[i]);
	}
	do{
		suma=0;
		x++;
		for(i=0;i<n;i++){
			suma=suma+abs(x-arreglo[i]);
		}
		if(suma+abs(x)<aux+abs(x-1)){
			aux=suma;
		}else{
			x--;
			break;
		}
	}while(1);
	do{
		suma=0;
		x--;
		for(i=0;i<n;i++){
			suma=suma+abs(x-arreglo[i]);
		}
		if(suma+abs(x)<aux+abs(x+1)){
			aux=suma;
		}else{
			x++;
			break;
		}
	}while(1);
	return aux+abs(x);
}
int main(int argc, char *argv[]) {
	int n,m,d,un_num,resto,movimientos=0,i;
	int arreglo[10001];
	cin>>n>>m>>d;
	cin>>un_num;
	resto=un_num%d;
	for(i=0;i<n*m-1;i++){
		cin>>arreglo[i];
		if(arreglo[i]%d!=resto){
			cout<<-1;
			return 0;
		}
	}
	for(i=0;i<n*m-1;i++){
		arreglo[i]-=un_num;
		arreglo[i]/=d;
	}
	
	cout<<halla(arreglo,m*n-1);
	
	
	return 0;
}

