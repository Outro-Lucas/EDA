#include <iostream>
#include "graph.h"
#include "graphm.h"
#include "graphl.h"
#include <list>
#include <stdio.h> 
using namespace std;

int main(){
	
	// Creating a path with 8 vertices 
	int N = 8;
	Graph *grafoM; 		//grafo matriz
	Graph *grafoL;		//grafo lista
	Graph *Quad;		//grafo para calcular o quadrado matriz
	Graph *Tgm;			//grafo transposta
	Graph *TgmL;		//grafo transposta da Lista
	Graph *QuadL;		//grafo para calcular o quadrado lista
	
	// Criando
	grafoM = new Graphm( N );
	Tgm = new Graphm( N );
	Quad = new Graphm( N );
	grafoL = new Graphl( N );
	TgmL = new Graphl( N );
	QuadL = new Graphl ( N );
	
	// Adding edges Matrix
	for(int i = 0; i <= N-2; ++i) {
		grafoM->addEdge(i, i+1);
	}

	//Adding edges List
	for(int i = 0; i <= N-2; ++i) {
		grafoL->addEdge(i, i+1);
	}
	
	cout << "GRAFO MATRIZ ADJACENTE:" << endl;
		// Printing the neighbours of each vertex	
	for(int i = 0; i <= N-1; ++i) {
		cout << "Vizinhos do " << i << ": ";
		
			list<int> lista = grafoM->neighbors( i );
			list<int>::iterator it;
			
		for( it=lista.begin(); it != lista.end(); it++ ) {
			cout << *it << " ";
		}
		cout << endl;
	}
	
		cout << endl;//Quebra de linha
		Tgm = grafoM->transposto();
		
		cout << "GRAFO TRANSPOSTO MATRIZ ADJACENTE:" << endl;
	// Printing the neighbours of each vertex	
	for(int i = 0; i <= N-1; ++i) {
		cout << "Vizinhos do " << i << ": ";
		
			list<int> lista = Tgm->neighbors( i );
			list<int>::iterator it;
			
		for( it=lista.begin(); it != lista.end(); it++ ) {
			cout << *it << " ";
		}
		cout << endl;
	}
		cout << endl;//Quebra de linha
		
		
	Quad = grafoM->quadrado(); // passo para o grafo os valores obtidos da funcao
	
	//Da um erro na hora de procurar todos os vizinhos conectados e retorna apenas um deles
	cout << "QUADRADO DO GRAFO MATRIZ ADJACENTE:" << endl;
	// Printing the neighbours of each vertex	
	for(int i = 0; i <= N-1; ++i) {
		cout << "Vizinhos do " << i << ": ";
		
			list<int> lista = Quad->neighbors( i );
			list<int>::iterator it;
			
	for( it=lista.begin(); it != lista.end(); it++ ) {
		cout << *it << " ";
		}
		cout << endl;
	}
	   	cout << endl;
	   	
	cout << "GRAFO LISTA ADJACENTE:" << endl;
		// Printing the neighbours of each vertex	
	for(int i = 0; i <= N-1; ++i) {
		cout << "Vizinhos do " << i << ": ";
		
			list<int> lista = grafoL->neighbors( i );
			list<int>::iterator it;
			
		for( it=lista.begin(); it != lista.end(); it++ ) {
			cout << *it << " ";
		}
		cout << endl;
	}
	
		cout << endl;//Quebra de linha
		
		TgmL = grafoL->transposto();
		
	cout << "GRAFO TRANSPOSTO LISTA ADJACENTE:" << endl;
	// Printing the neighbours of each vertex	
	for(int i = 0; i <= N-1; ++i) {
		cout << "Vizinhos do " << i << ": ";
		
			list<int> lista = TgmL->neighbors( i );
			list<int>::iterator it;
			
		for( it=lista.begin(); it != lista.end(); it++ ) {
			cout << *it << " ";
		}
		cout << endl;
	}
		

		return 0;
}