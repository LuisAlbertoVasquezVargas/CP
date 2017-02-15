#include<bits/stdc++.h>
using namespace std;

//http://www.enchantedlearning.com/languages/spanish/Numbers.shtml
int main(){
	int n;
	while(cin >> n){
		
		if(n >= 1 && n <= 10){
			cout << n << '\n';
		}else{
			cout << "Incorrect values\n";
			continue;
		}
		int num = 1;
		int width = 0;
		if(n <= 1) width = 3;
		else if(n <= 3) width = 6;
		else if(n <= 4) width = 9;
		else if(n <= 5) width = 12;
		else if(n <= 6) width = 16;
		else if(n <= 7) width = 17;
		else if(n <= 9) width = 18;
		else if(n <= 10) width = 18;
		
		for(int k = 0; k < n * (width + 1) + 1 ; k++) cout << "-";
		cout << '\n';
		for(int i = 0 ; i < n ; ++i){
			cout << "|";
			for(int j = 0 ; j < n ; ++j){
				int current = width;
				if(num >= 11 && num <= 15){
					if(num == 11) cout << "once" , current -= 4;
					else if(num == 12) cout << "doce" , current -= 4;
					else if(num == 13) cout << "trece" , current -= 5;
					else if(num == 14) cout << "catorce" , current -= 7;
					else if(num == 15) cout << "quince" , current -= 6;
					for(int it = 0; it < current ; ++it) cout << " ";
					cout << "|";
					num ++;
					continue;
				}
				int dozens = num / 10 , units = num % 10;
				if(dozens >= 1 && units){
					if(dozens == 0) ;
					else if(dozens == 1) cout << "dieci" , current -= 5;
					else if(dozens == 2) cout << "veinti" , current -= 6;
					else if(dozens == 3) cout << "treinta y " , current -= 10;
					else if(dozens == 4) cout << "cuarenta y " , current -= 11;
					else if(dozens == 5) cout << "cincuenta y " , current -= 12;
					else if(dozens == 6) cout << "sesenta y " , current -= 10;
					else if(dozens == 7) cout << "setenta y " , current -= 10;
					else if(dozens == 8) cout << "ochenta y " , current -= 10;
					else if(dozens == 9) cout << "noventa y " , current -= 10;
				}
				if(units == 0){
					if(dozens == 0) ;
					else if(dozens == 1) cout << "diez" , current -= 4;
					else if(dozens == 2) cout << "veinte" , current -= 6;
					else if(dozens == 3) cout << "treinta" , current -= 7;
					else if(dozens == 4) cout << "cuarenta" , current -= 8;
					else if(dozens == 5) cout << "cincuenta" , current -= 9;
					else if(dozens == 6) cout << "sesenta" , current -= 7;
					else if(dozens == 7) cout << "setenta" , current -= 7;
					else if(dozens == 8) cout << "ochenta" , current -= 7;
					else if(dozens == 9) cout << "noventa" , current -= 7;
					else if(dozens == 10) cout << "cien" , current -= 4;
				}
				else if(units == 1) cout << "uno" , current -= 3;
				else if(units == 2) cout << "dos" , current -= 3;
				else if(units == 3) cout << "tres" , current -= 4;
				else if(units == 4) cout << "cuatro" , current -= 6;
				else if(units == 5) cout << "cinco" , current -= 5;
				else if(units == 6) cout << "seis" , current -= 4;
				else if(units == 7) cout << "siete" , current -= 5;
				else if(units == 8) cout << "ocho" , current -= 4;
				else if(units == 9) cout << "nueve" , current -= 5;
				
				for(int it = 0; it < current ; ++it) cout << " ";
				cout << "|";
				num ++;
			}
			cout << '\n';
			for(int k = 0; k < n * (width + 1) + 1 ; k++) cout << "-";
			cout << '\n';
		}
	}
}


