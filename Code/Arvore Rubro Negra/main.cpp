using namespace std;
#include "item.h"
#include "node.h"
#include "RBTree.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	RBTree a1;
	int opcao = 0;
	int altura, busca;
	int key, key2;
	string value;
	string valor;
	while(opcao != 7){		
		cout<< "----------------------------------" << endl ;
		cout<< "Implementacao Arvore Rubro Negra" << endl;
		cout<< "----------------------------------" << endl;
		cout<< "1. Inserir elemento." << endl;
		cout<< "2. Remover elemento." << endl;
		cout<< "3. Remover todos os elementos." << endl;
		cout<< "4. Percurso em pre-ordem." << endl;
		cout<< "5. Buscar na arvore." << endl;
		cout<< "6. Altura da arvore." << endl; 
		cout<< "7. Sair" << endl;
		cout<< "Entre sua escolha:";
		cin >> opcao; 		
		
		switch(opcao)
		{
		case 1: 
			//inserir
			cout << "Digite o valor da chave: ";
			cin >> key;
			cout << "Digite o valor a ser inserido: ";
			cin >> value;
			a1.insert(key, value);		 
			break;
		
		case 2: 
			//remover
			cout << "Digite o valor da chave: ";
			cin >> key2;
			a1.remove(key2);
			cout << "Valor removido" << endl;
			break;
			 		
		case 3: 
			//remove todas 
			a1.delete_allPub();
			cout << "Todos valores excluidos!";
			break;
		
		case 4: 
			cout << "Pre-ordem: "<< endl;
			a1.RBpreorder2();
			break;

		case 5: 
			//buscar
			cout << "Digite a posicao que deseja encontrar: ";
			cin >> busca;
			cout << "Digite o valor: ";
			cin >> valor;
			if(a1.search(busca, valor)) cout<< "Valor encontrado" << endl;
			else cout << "Valor nao encontrado" << endl;
			break;
		
		case 6: 
			//altura
			altura = a1.Heightaux1();
			cout<< "A altura da arvore eh: " << altura << endl; 
	  		break;
		  	
		case 8: exit(0);
		default:
			break;
		}	
	}
	return 0;	
}