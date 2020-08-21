# ifndef RBTREE_H
# define RBTREE_H
# include "node.h"

class RBTree {
private :
	Node * root;
	Node * nil;
	
protected :
	void left_rotate ( Node * node );
	void right_rotate ( Node * node ) ;
	void RBinsert ( Node * node );
	void RBinsert_fixUp ( Node * node );
	void RBdelete ( Node *z);
	void RBdelete_fixUp ( Node *z);
	Node * minimum ( Node * node );
	void RBpreorder(Node *node);
	void RBpreorder3();
	int RBheight (Node *node);
	int Heightaux2();
	void delete_all(Node *node);
	void delete_allAux();
	bool searchAux(const Tkey & key , const Tvalue & v);

public :
	RBTree();
	void insert ( const Tkey & key , const Tvalue & v);
	void remove ( const Tkey & key );
	bool search ( const Tkey & key , const Tvalue & v);
	void RBpreorder2();
	int Heightaux1();
	bool empty () const ;
	void delete_allPub();
};
# endif