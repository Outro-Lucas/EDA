using namespace std;
#include "avl.h"
#include "item.h"
#include "avl.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	Node* a1 = NULL;
	Node* a2 = NULL;
	int opcao = 0;
	int k = 0;
	int altura = 0;
	string key, value;
	string busca;
	while(opcao != 8){		
		cout<< "----------------------------------" << endl ;
		cout<< "Implementacao Arvore AVL" << endl;
		cout<< "----------------------------------" << endl;
		cout<< "1. Inserir elemento na arvore." << endl;
		cout<< "2. Apagar todas as folhas da arvore." << endl;
		cout<< "3. Percurso em pre-ordem." << endl;
		cout<< "4. Percurso em in-ordem." << endl;
		cout<< "5. Percurso em pos-ordem." << endl;
		cout<< "6. Buscar na arvore." << endl;
		cout<< "7. Altura da arvore." << endl; 
		cout<< "8. Sair" << endl;
		cout<< "Entre sua escolha:";
		cin >> opcao; 		
		
		switch(opcao)
		{
		case 1: 
			cout << "Digite o valor da chave: ";
			cin >> key;
			cout << "Digite o valor a ser inserido: ";
			cin >> value;
			a1 = avl_insert(a1, key, value);		 
			break;
			 		
		case 2: 
			a1 = delete_all(a1); 
			cout << "Todos valores excluidos!";
			break;
		
		case 3: 
			cout << "Pre-ordem: "<< endl;
			avl_preorder(a1); 
			break;
		
		case 4: 
			cout << "Em ordem: " << endl;
			avl_inorder(a1); 
			break;
								
		case 5: 
			cout << "Pos-ordem: " << endl;
			avl_postorder(a1); 
			break;
		
		case 6: 
			cout << "Digite o valor que deseja encontrar: ";
			cin >> busca;
			a2 = avl_search(a1, busca);
			if(a2 == NULL)	cout<< "Valor nao encontrado" << endl;
			else cout << "O valor " + a2->value + " foi encontrado." << endl; 
			break;
		
		case 7: 
			altura = avl_height(a1);
			cout<< "A altura da árvore AVL é: " + altura << endl; 
	  		break;
		  	
		case 8: exit(0);
		default:
			break;
		}	
	}	
	return 0;	
}