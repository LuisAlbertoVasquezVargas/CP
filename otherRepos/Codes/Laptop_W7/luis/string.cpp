#include <iostream>
#include <string>
#include <sstream>

using namespace std;


string a;
int n;

int main()
{	
	cin>>n;
	getline(cin,a);
	for(int i=0;i<n;i++){
		string msj="";
		getline(cin,a);	
		istringstream in(a);
		string nombre;
		while(in>>nombre){
			msj=msj+nombre[0];
		}
		cout<<msj<<endl;
	}
	
}


