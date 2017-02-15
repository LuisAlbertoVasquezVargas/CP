#include<bits/stdc++.h> // jala una gran cantidad de libreria.
using namespace std; // ahorra recopiar algunas cosas de las librerias.

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )  // propias funciones por defecto.

#define clr( t , val ) memset( t , val , sizeof( val ) )

#define N 15
#define INF (1<<29)
#define EPS (1e-8)

int n;
bool done[ 1 << N ][ N ][ N ] ;
double memo[ 1 << N ][ N ][ N ];

double dist[ N ][ N ];
double dp( int mask , int ini , int pos )
{
	double &dev = memo[ mask ][ ini ][ pos ];// el &te dal el estado del nodo - toma la foto.
	if( !done[ mask ][ ini ][ pos ] ) // arreglo booleano, si me dice que esta calculado o no, el estado.
	{
		done[ mask ][ ini ][ pos ] = 1;
		dev = INF;// es un valor grande 
		
		// calculo del camino
		for( int i = 0 ; i < n ; ++i ){
			if( i == pos ) continue;// cuando llega al nodo saltas al siguiente
			if( i == ini )
			{
				if( mask == ((1<<n) - 1) ) dev = dist[ pos ][ i ];// si encuentro un camino y quiero ir al inicio (cuadno haya recorrido todo el camino) -- caso base
			}
			else if( !(mask&(1<<i)) )
			{
				dev = min( dev , dist[ pos ][ i ] + dp( mask^(1<<i) , ini , i ) );
			}
		}
	}
	return dev;
	
}
bool solve = 0; // 0 que todavia no encuentro el primer camino, y 1 que lo encuentra.
vector< int > path;
void rec( int mask , int ini , int pos ) 
{
	if( solve ) return;
	double dev = dp( mask , ini , pos );
	for( int i = 0 ; i < n ; ++i ){
		if( i == pos ) continue;
		if( i == ini )
		{
			if( mask == ((1<<n) - 1) ) {
				path.push_back( pos );
				solve = 1; // encontro el camino
				break;
			}
		}
		else if( !(mask&(1<<i)) )
		{
			if( abs( dp( mask , ini , pos ) - dist[ pos ][ i ] - dp( mask^(1<<i) , ini , i ) ) < EPS ) // cuando se trabaja en numeros reales
	// hay errores de presicion.
			{
				path.push_back( pos ); // voy llenando un arreglo, en este caso van a ser los nodos del primer camino que encontrò.
				rec( mask^(1<<i) , ini , i );
				break;
			}
		}
	}
}
// muestra las respuestas.
int main()

{
	cin >> n;
	REP( i , n ) REP( j , n )
		cin >> dist[ i ][ j ];
	clr( done , 0 ); // no el calculado nada en lo anterios
	cout << dp( 1 , 0 , 0 ) << endl;// leo la rpta.
	rec( 1 ,0 , 0 );
	REP( i , path.size() )
		cout << path[ i ] << " " ;
	cout << endl;
	double S = 0;
	REP( i , path.size() )S += dist[ path[ i ] ][ path[ (i + 1)%path.size() ] ];
	cout << S << endl;
}
