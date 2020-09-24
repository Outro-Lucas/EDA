#include <iostream>
#include <queue>
#include <iostream>
#include <cstddef>
#include <string>
#include "avl.h"
#include <sstream>
#include "item.h"
using std::cout;
using std::endl;


struct Node {
    string key;
    Pessoa *data;
    int height;
    Node *left;
    Node *right;
};

string avl_getKey(Node *node) {
    return node->key;
}
//Retorna a chave que está contida no nó; 

Pessoa * avl_getValue(Node *node) {
    return node->data;
}
//Retorna o valor que está contido no nó;

Node *avl_search(Node *node, string key){
	if(node == NULL) 
		return NULL;
	if (key < node->key) 
		return avl_search(node->left, key);
	else if (key > node->key)
		return avl_search(node->right, key);
	else
		return node;
}
//Retorna o ponteiro para o nó se a chave for encontrada;
//Caso contrário retorna apenas nulo;

void searchName(Node *p, string key){
	bool hit = true;
	
	if(p == NULL)
		return;
	
	for (int i=0; i < key.size(); i++){
		if(key[i] != p->key[i]){
			hit = false;
			break;
		}
	}
	
	if(hit){
		cout << p->data->getCpf() << "," 
			 << p->data->getNome() << "," 
			 << p->data->getSobreome() << "," 
			 << p->data->getDataNasc() << "," 
			 << p->data->getCidade() << endl;
 }
 	
	if(key > p->key)
 	 	 searchName(p->right, key);
 	  
	else if(p->right != NULL && key[0] == p->right->key[0])
 	  	 searchName(p->right, key);
    
	if (key < p->key)
 	   	 searchName(p->left, key);
 	    
	else if(p->left != NULL &&key[0] == p->left->key[0])
  	 	 searchName(p->left, key);
}


void searchDate(Node *p, string data1, string data2){				
	if(p == NULL)
		return;
	
	if(p->key >= data1 && p-> key <= data2){
		cout << p->data->getCpf() << "," 
			 << p->data->getNome() << "," 
			 << p->data->getSobreome() << "," 
			 << p->data->getDataNasc() << "," 
			 << p->data->getCidade() << endl;
	}
	
	if(p->key <= data2)
			searchDate(p->right, data1, data2);

	if(p->key >= data1)
			searchDate(p->left, data1, data2);
			
}

int avl_height (Node *node){
	if(node == NULL) return 0;
	else return node->height;
}
//Retorna a altura da árvore;

int avl_size(Node *node) {
 	if(node == NULL) return 0;
 	else return 1 + avl_size(node->left) +
 	avl_size(node->right);
 }
//Retorna o tamanho da árvore;

int balance(Node *node) {
 	if(node == NULL) return 0;
 		return avl_height(node->right) - avl_height(node->left);
}
//Calcula o fator de balaceamento atraves da subtracao das
//alturas das subarvores esquerda e direita do no.
 
bool avl_empty(Node *node){//Verifica se a árvore está vazia.
	return (node == NULL);
} 
 
Node *avl_clear(Node *node){
	if(node != NULL){
		node->left = avl_clear(node->left);
		node->right = avl_clear(node->right);
		cout << "Removendo chave" << node->key << endl;
		delete node;
	}
	return NULL;
}

Node *rightRotation(Node *node) {//Rotação Direita
 	Node *u = node->left;
 	node->left = u->right;
 	u->right = node;
 	// atualiza alturas dos nós
	node->height = 1 + max(avl_height(node->left), avl_height(node->right));
 	u->height = 1 + max(avl_height(u->left),
 	avl_height(u->right));
 
 return u; // nova raiz
}

Node *leftRotation(Node *node) {//Rotação Esquerda
 	Node *u = node->right;
 	node->right = u->left;
 	u->left = node; 
 	// atualiza alturas dos nós
 	node->height = 1 + max(avl_height(node->left),
 	avl_height(node->right));
 	u->height = 1 + max(avl_height(u->left),
 	avl_height(u->right));
 
 return u; // nova raiz
 }
 
Node* alocateNode(string key, Pessoa *data){//Aloca um nó
    Node *node = new Node;
    node->key = key;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *fixup_node(Node *p, string key){
    int bal = balance(p); //obtem balanco de node
    
    if(bal < -1 && key < p->left->key)
        return rightRotation(p);
    else if(bal < -1 && key > p->left->key){
        p->left = leftRotation(p->left);
        return rightRotation(p);
    }
    else if(bal > 1 && key >= p->right->key)
        return leftRotation(p);
    else if(bal > 1 && key <= p->right->key){
        p->right = rightRotation(p->right);
        return leftRotation(p);
    }
    return p;
}

Node *avl_insert(Node *p, string key, Pessoa *data){
    if(p == NULL)
		return alocateNode(key, data);
    if(key < p->key)
        p->left = avl_insert(p->left, key, data);
    else if(key >= p->key)
        p->right = avl_insert(p->right, key, data);
    else
        return p; //nao permite chaves repetidas
    
    //atualiza altura deste ancestral p
    p->height = 1 + std::max(avl_height(p->left), avl_height(p->right));
    p = fixup_node(p, key); //Regula o no
    return p;
}

