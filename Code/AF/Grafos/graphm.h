#ifndef graphM_h
#define graphM_h
#include <stdexcept>
#include "graph.h"
#include <list>
#include <iostream> 
using namespace std;
/**
 * Graphm class. 
 * Implementation for the adjacency matrix representation. 
 */
class Graphm : public Graph {
private:
    int V;                  // number of vertices
    int E;                  // number of edges
    int **matrix;           // pointer to adjacency matrix
    int *mark;              // pointer to mark array
	void checkRange(int v) {
        if(v < 0 || v > V-1) throw std::runtime_error("invalid range for vertex");
    }

public:
    // Constructor
    explicit Graphm( int n ) {
        if(n <= 0) throw std::runtime_error("invalid number of vertices."); 
        V = n;
        E = 0;
        mark = new int[V];
        // Create adjacency matrix 
        matrix = new int*[V];
        for(int i = 0; i < V; ++i)
            matrix[i] = new int[V];
        // Initialize to 0 weights
        for(int i = 0; i < V; ++i)
            for(int j = 0; j < V; ++j)
                matrix[i][j] = 0; 
    } 

    // Destructor
    ~Graphm() /*override*/ { 
        // Return dinamically alocated memory
        delete[] mark; 
        for (int i = 0; i < V; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }

    // Return: the number of vertices and edges respectively
    int n() /*override*/ { return V; }
    int m() /*override*/ { return E; }

    // Return a vector containing vertex v's neighbors
    std::list<int>& neighbors(int v) /*override*/ {
        checkRange(v);
        std::list<int> *lst = new std::list<int>();
		      
        for(int i = 0; i < V; ++i) {
            if(matrix[v][i] != 0) {
                lst->push_back(i);
            }
        }
        return *lst;
    }

    // Return a list containing v's incident edges
    std::list<Edge>& incidentEdges(int v) /*override*/ {
        checkRange(v);
        std::list<Edge> *lst = new std::list<Edge>();
        for(int i = 0; i < V; ++i) {
            if(matrix[v][i] != 0) {
                lst->push_back( Edge(i, matrix[v][i]) );
            }
        }
        return *lst;
    }

    // set the weight of an edge
    // v1, v2: the vertices
    // wgt: the edge weight
    void setEdgeWeight(int v1, int v2, int wgt) /*override*/ {
        checkRange(v1);
        checkRange(v2);
        if(wgt <= 0) 
            throw std::runtime_error("Illegal weight value");
        if(matrix[v1][v2] == 0) 
            E++;
        matrix[v1][v2] = wgt;
    }

    // Add an edge
    void addEdge(int v1, int v2) /*override*/ {
        setEdgeWeight(v1, v2, 1);
    }

    // Delete an edge
    void delEdge(int v1, int v2) /*override*/ { 
        checkRange(v1);
        checkRange(v2);
        if(matrix[v1][v2] != 0)
            E--;
        matrix[v1][v2] = 0;
    }

    // Determine if an edge is in the graph
    virtual bool isEdge(int v1, int v2) /*override*/ { 
        checkRange(v1);
        checkRange(v2);
        return matrix[v1][v2] != 0;
    }

    // Return an edge's weight
    // Return the weight of the edge ij or 
    // 0 if the edge does not exists
    int weight(int v1, int v2) /*override*/ {
        checkRange(v1);
        checkRange(v2);
        return matrix[v1][v2];
    }

    // Get and set the mark value for a vertex
    // v: the vertex
    // val: the value to set
    int getMark(int v) /*override*/ {
        checkRange(v);
        return mark[v]; 
    }

    void setMark(int v, int val) /*override*/ {
        checkRange(v);
        mark[v] = val; 
    }
	//Questao 2
    Graph* transposto() { 
		Graph *grafo = new Graphm(V);
		list<int>::iterator it;
		for(int i = 0; i < V; i++){
			list<int> lista = neighbors(i);
		
		for(it=lista.begin(); it != lista.end(); it++){
			grafo->addEdge(*it, i);
			grafo->setEdgeWeight(*it, i, matrix[i][*it]);
		}
	}
		return grafo;
	}
	
	//Questao 3
	Graph* quadrado(){
		Graph *g2 = new Graphm(V);
		list<int>::iterator it;
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				for (int k = 0; k < V; k++){
					if(matrix[i][k] == 1 && matrix[k][j] == 1){
						g2->addEdge(i, j);
						break;
					}
				}
			}
		}
		return g2;
	}
};

#endif