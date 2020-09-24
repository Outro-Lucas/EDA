# include <iostream>
# include <stack> // para a preorder
# include "item.h"
# include "node.h"
# include "RBTree.h"
using std :: cout ;
using std :: endl ;

// Construtor
RBTree::RBTree() {
	nil = new Node;
	nil -> key = 0;
	nil -> left = nil -> right = nil -> parent = nil ;
	nil -> color = BLACK ;
	root = nil ;
}

// Rotacao esquerda
void RBTree :: left_rotate ( Node * x) {
	Node * y = x -> right ;
	x -> right = y -> left ;
	 if (y -> left != nil )
		y -> left -> parent = x;
		y -> parent = x -> parent ;
	 if (x -> parent == nil ) {
		root = y;
		} 
	 else if (x == x -> parent -> left ) {
		x -> parent -> left = y;
		} else {
			x -> parent -> right = y ;
	}
	y -> left = x ;
	x -> parent = y;
}

//Rotacao direita
void RBTree :: right_rotate ( Node *x) {
	 Node * y = x -> left ;
			x -> left = y -> right ;
	if (y -> right != nil ){
		y -> right -> parent = x ;
		y -> parent = x -> parent ;
	}		
	if (x -> parent == nil ) {
		root = y;
} 	
	else if (x == x -> parent -> right ) {
		x -> parent -> right = y ;
	} else {
		x -> parent -> left = y;
}
		y -> right = x;
		x -> parent = y;
}

/**
* Recebe referências para uma nova chave e valor e
* insira um novo nó na árvore com esses valores
* se a chave não for repetida
*/

void RBTree :: insert ( const Tkey & key , const Tvalue & v) {
// Aloca um novo node
Node * newNode = new Node;
	newNode -> key = key ;
	newNode -> value = v;
	newNode -> left = newNode -> right = nil ;
	newNode -> parent = nil ;
	
	RBinsert ( newNode );
}

void RBTree :: RBinsert ( Node *z ) {
	Node * father = nil;
	Node * son = root;
	while ( son != nil ) {
	father = son;
	if(z -> key == son -> key ) { // Diferent from Cormen
	delete z; // Repeated keys not allowed
	return;
}
	son = (z -> key < son -> key ) ? son -> left : son -> right ;
}
	z -> parent = father ;
	if ( father == nil )
	root = z;
	else if (z -> key < father -> key )
	father -> left = z;
else father -> right = z ;
	z -> left = z -> right = nil ;
	z -> color = RED ;
	// Fix Red Black Tree violations
	RBinsert_fixUp(z);
}


void RBTree :: RBinsert_fixUp(Node *z) {
while (z -> parent -> color == RED ) {
	if (z -> parent == z -> parent -> parent -> left ) {
 	 	  Node * uncle = z -> parent -> parent -> right ;
		if ( uncle -> color == RED ) { // Case 1a
 	 	  	  z -> parent -> color = BLACK ; // Case 1a
		  	  uncle -> color = BLACK ; // Case 1a
 	 	  	  z -> parent -> parent -> color = RED ; // Case 1a
 	 	  	  z = z -> parent -> parent ; // Case 1a
 	 	 } else {
 	 	 	 if (z == z -> parent -> right ) { // Case 2a
 	 	  	  	  z = z -> parent ; // Case 2a
 	 	  	  	  left_rotate (z) ; // Case 2a
			}
 	 	 z -> parent -> color = BLACK ; // Case 3a
 	 	 z -> parent -> parent -> color = RED ; // Case 3a
 	 	 right_rotate (z -> parent -> parent ); // Case 3a
 	 }
}
 	 else { /* Simetrico ao codigo acima */ 
		Node * uncle = z -> parent -> parent -> left;
			if ( uncle -> color == RED ) { // Case 1a
 	 	  	  z -> parent -> color = BLACK ; // Case 1a
		  	  uncle -> color = BLACK ; // Case 1a
 	 	  	  z -> parent -> parent -> color = RED ; // Case 1a
 	 	  	  z = z -> parent -> parent ; // Case 1a
 	 	 } else {
 	 	 	 if (z == z -> parent -> left ) { // Case 2a
 	 	  	  	  z = z -> parent ; // Case 2a
 	 	  	  	  right_rotate (z) ; // Case 2a
			}
 	 	 z -> parent -> color = BLACK ; // Case 3a
 	 	 z -> parent -> parent -> color = RED ; // Case 3a
 	 	 left_rotate (z -> parent -> parent ); // Case 3a
}	  
}
}
root -> color = BLACK ; // Guarantee Property 2
}

void RBTree :: RBpreorder(Node* node){
	if(node != nil) {
 		cout << "(" << node->key << ", " <<
 		node->value << ")" << endl;
 		RBpreorder(node->left);
 		RBpreorder(node->right);
	}
}

void RBTree :: RBpreorder2(){
	RBpreorder3();
}

void RBTree :: RBpreorder3(){
	Node * aux = root;
	RBpreorder(aux);
}

void RBTree :: remove ( const Tkey & key ) {
 Node * p = root ;
 while (p != nil && p -> key != key ) {
	p = ( key < p -> key ) ? p -> left : p -> right ;
}
	if(p != nil ) RBdelete (p);
}
 
// Recebe ponteiro para no z e o remove da arvore
void RBTree :: RBdelete ( Node *z ) {
 Node * y; // aponta no que sera removido
 Node * x; // aponta no que tomara o lugar de y
 if(z -> left == nil || z -> right == nil ) y = z;
 	 else y = minimum (z -> right ); // pega o sucessor de z
 if(y -> left != nil ) x = y -> left ;
 	 else x = y -> right ;

 	 x->parent = y->parent; // ajusta o pai

 if(y->parent == nil){
 		root = x;
 } else {
 		if( y == y->parent->left) y->parent->left = x;
 		else y->parent->right = x;
 }
 

 if(y!= z){
 	z->key = y->key;
 	z->value = y->value;
 } 
 if(y->color == BLACK) RBdelete_fixUp (x); // Conserta possiveis estragos
	delete y;




	
}
  
void RBTree :: RBdelete_fixUp ( Node *x) {
	while (x != root && x -> color == BLACK ) {
		if (x == x -> parent -> left ) { // x is a left child
			Node * w = x -> parent -> right ;
		if (w -> color == RED ) { // Case 1
			w -> color = BLACK ; // Case 1
			x -> parent -> color = RED ; // Case 1
			left_rotate (x -> parent ); // Case 1
			w = x -> parent -> right ; // Case 1
}

		if (w -> left -> color == BLACK && // Case 2
			w -> right -> color == BLACK ) { // Case 2
			w -> color = RED ; // Case 2
			x = x -> parent ; // Case 2
} else {
		if (w -> right -> color == BLACK ) { // Case 3
			w -> left -> color = BLACK ; // Case 3
			w -> color = RED ; // Case 3
			right_rotate ( w); // Case 3
			w = x -> parent -> right ; // Case 3
}

			w -> color = x -> parent -> color ; // Case 4
			x -> parent -> color = BLACK ; // Case 4
			w -> right -> color = BLACK ; // Case 4
			left_rotate (x -> parent ); // Case 4
			x = root ;
		}
	}
		else { /* Simmetric to the case above */ }
}
		x -> color = BLACK ;
}

Node * RBTree :: minimum ( Node * node ) {
 while ( node -> left != nil ) {
	node = node -> left ;
 }
	return node ;
}

int RBTree :: RBheight (Node *node){
		if(node == nil) return 0;
		if(node->left == nil && node->right == nil) return 1;
		int esq = RBheight(node->left);
		int dir = RBheight(node->right);
		if(esq>dir) return esq+1;
		return dir+1;
	}
	
int RBTree :: Heightaux1(){
	return Heightaux2();
}

int RBTree :: Heightaux2(){
	Node * aux = root;
	return RBheight(aux);
}

void RBTree :: delete_all(Node *node){
	if(node != nil){
		delete_all(node->left);
		delete_all(node->right);
		RBdelete(node);
	}
}

void RBTree :: delete_allAux(){
	delete_all(root);
}

void RBTree :: delete_allPub(){
	delete_allAux();
}

bool RBTree :: search( const Tkey & key , const Tvalue & v){
	searchAux(key, v);
}

bool RBTree :: searchAux (const Tkey & key , const Tvalue & v){
	Node * p = root;
	while(p!= nil && p -> key != key){
		p = ( key < p -> key ) ? p -> left : p -> right ; 
	}
	if(p != nil && p->value == v) return true;
	else false;
}