#include<iostream>
#include<cmath>
using namespace std;
int main(){
     
     int n;

     cin>>n;
     
     int k = n/3;
		
	if(n % 3 == 2) k++;
		
	cout<<k/12<<" "<<k%12<<endl;
	
}
