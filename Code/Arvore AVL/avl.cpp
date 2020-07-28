#include <iostream>
#include <queue>
#include <iostream>
#include <cstddef>
#include "avl.h"
#include "item.h"
using std::cout;
using std::endl;


struct Node {
    Tkey key;
    Tvalue value;
    int height;
    Node *left;
    Node *right;
};

Tkey avl_getKey(Node *node) {
    return node->key;
}
//Retorna a chave que está contida no nó; 

Tvalue avl_getValue(Node *node) {
    return node->value;
}
//Retorna o valor que está contido no nó;

Node *avl_search(Node *node, Tkey key){
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

void avl_preorder(Node *node) {
 	if(node != NULL) {
 		cout << "(" << node->key << ", " <<
 		node->value << ")" << endl;
 		avl_preorder(node->left);
 		avl_preorder(node->right);
 	}
 }
//Imprimi os valores da árvore na seguinte ordem:
//1° Visita a sub-árvore  esquerda;
//2° Visita a raiz;
//3° Visita a sub-árvore direita;
 
void avl_inorder(Node *node) {
 	if(node != NULL) {
 		avl_inorder(node->left);
 		cout << "(" << node->key << ", " <<
 		node->value << ")" << endl;
 		avl_inorder(node->right);
 	}
 }
//Imprimi os valores da árvore na seguinte ordem:
//1° Visita a raiz;
//2° Visita a sub-árvore  esquerda;
//3° Visita a sub-árvore direita;

void avl_postorder(Node *node){
    if(node != NULL){
        avl_postorder(node->left);
        avl_postorder(node->right);
        cout << "(" << node->key << ", " << node->value << ")" << endl;

    }
}
//Imprimi os valores da árvore na seguinte ordem:
//1° Visita a sub-árvore  esquerda;
//2° Visita a sub-árvore direita;
//3° Visita a raiz;
 
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
 
Node* alocateNode(Tkey key, Tvalue value){//Aloca um nó
    Node *node = new Node;
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *fixup_node(Node *p, Tkey key){
    int bal = balance(p); //obtem balanco de node
    
    if(bal < -1 && key < p->left->key)
        return rightRotation(p);
    else if(bal < -1 && key > p->left->key){
        p->left = leftRotation(p->left);
        return rightRotation(p);
    }
    else if(bal > 1 && key > p->right->key)
        return leftRotation(p);
    else if(bal > 1 && key < p->right->key){
        p->right = rightRotation(p->right);
        return leftRotation(p);
    }
    return p;
}

Node  *avl_insert(Node *p, Tkey key, Tvalue value){
    if(p == NULL)
		return alocateNode(key, value);
    if(key < p->key)
        p->left = avl_insert(p->left, key, value);
    else if(key > p->key)
        p->right = avl_insert(p->right, key, value);
    else
        return p; //nao permite chaves repetidas
    
    //atualiza altura deste ancestral p
    p->height = 1 + std::max(avl_height(p->left), avl_height(p->right));
    p = fixup_node(p, key); //Regula o no
    return p;
}

Node *delete_all(Node *node){
	   	if(node == NULL) return NULL; //verifica se não é nulo
	   	if(node->left == NULL && node->right == NULL){ //verifica se ele é apenas uma folha
			   delete node; 
			   return NULL;
		   }
		delete_all(node->left); //delete o lado esquerdo dele
		delete_all(node->right);//delete o lado direito dele
		delete node;			//deleta ele agora já que é uma folha 
		return NULL;
} 
