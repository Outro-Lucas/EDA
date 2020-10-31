#ifndef graphL_h
#define graphL_h
#include "graph.h"
using namespace std;
#include <list>
#include <iostream>

class Graphl : public Graph {
private:
    int V; 				// numero de vertices
	list<Edge> *lista; 	// lista de adjacencia
	int *mark;  		//ponteiro para marcar o vetor

public:
    explicit Graphl(int n) {
		this->V = n; 				// atribui o numero de vertices
		lista = new list<Edge>[V]; 	// cria as listas
		mark = new int[V];			// cria o vetor mark
	}
    
    ~Graphl() /*override*/ {
		  delete[] lista;
		  delete[] mark;
	}
    int n() /*override*/ { return V; }
    int m() /*override*/ {  
		int res = 0;
		for (int i = 0; i < V; i++){
			res += lista[i].size();
		}
		return res/2;
	}
	
    std::list<int>& neighbors(int v) /*override*/ {
		std::list<int> *lst = new std::list<int>();
        list<Edge>::iterator it;
   		for (it = lista[v].begin(); it != lista[v].end(); it++){
   			lst->push_back(it->getVertex());
		}
        return *lst;
	}
    
    std::list<Edge>& incidentEdges(int v) /*override*/ { return lista [v]; }
    
    void setEdgeWeight(int v1, int v2, int wgt) /*override*/ {
		list<Edge>::iterator it;

		//primeiro caso com v1
		for (it = lista[v1].begin(); it != lista[v1].end(); it++){
   			if(it->getVertex() == v2){
				   it->setWeight(wgt);
			   }
		}
}
    
	void addEdge(int v1, int v2) /*override*/ {
		lista[v1].push_back(Edge());
		list<Edge>::iterator it;
		
		it = lista[v1].end();
		it--;
		it->setEnpoint(v2);

	 }
	 
    void delEdge(int v1, int v2) /*override*/ {
		//list<Edge>::iterator it;
		//Erro no codigo, nao implementado
/**
		//primeiro caso com v1
		for (it = lista[v1].begin(); it != lista[v1].end(); it++){
   			if(it->getVertex() == v2){
				   lista.remove((it));
			   }
		}
		
		//segundo caso com v2
		for (it = lista[v2].begin(); it != lista[v2].end(); it++){
   			if(it->getVertex() == v1){
				   lista.remove(it);
			   }
		}*/
	}
    
    bool isEdge(int v1, int v2) /*override*/ {
		list<Edge>::iterator it;
		for (it = lista[v1].begin(); it != lista[v1].end(); it++){
   			if(it->getVertex() == v2){
				   return true;
			   }
		}
		return false;
	}

    int weight(int v1, int v2) /*override*/ {
		list<Edge>::iterator it;
		for (it = lista[v1].begin(); it != lista[v1].end(); it++){
   			if(it->getVertex() == v2){
				   return it->getWeight();
			   }
		}
		return -1;
	}
	
    int getMark(int v) /*override*/ { return mark[v]; }
    
	void setMark(int v, int value) /*override*/ {
		mark[v] = value;
	}

	//Questao 2
    Graph* transposto() {
		 Graph *grafo = new Graphl(V);
		 list<int>::iterator it;
		for(int i = 0; i < V; i++){
			list<int> lista = neighbors(i);
		
		for(it=lista.begin(); it != lista.end(); it++){
			grafo->addEdge(*it, i);
			grafo->setEdgeWeight(*it, i, weight(i, *it));
		}
	}
		return grafo;
	}
	
	//Questao 3
	//Nao consegui implementar a tempo a funcao para se encaixar na lista por isso esta implementado
	Graph* quadrado(){
		return NULL;
	}
};

#endif