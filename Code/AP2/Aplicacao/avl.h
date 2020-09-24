#ifndef AVL_H
#define AVL_H
#include<iostream>
#include <string>
#include "item.h"

struct Node;

string avl_getKey(Node *node);

Pessoa *avl_getValue(Node *node);

Node *avl_search(Node *node, string key);

void searchName(Node *p, string key);

void searchDate(Node *p, string data1, string data2);

void avl_level_traversal(Node *node);

int avl_height(Node *node);

int avl_size(Node *node);

int balance(Node *node);

bool avl_empty(Node *node);

Node *avl_clear(Node *node);

Node *rightRotation(Node *node);

Node *leftRotation(Node *node);

Node* alocateNode(string key, Pessoa *data);

Node *fixup_node(Node *p, int key);

Node *avl_insert(Node *p, string key, Pessoa *data);

#endif 