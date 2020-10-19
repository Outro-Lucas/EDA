#include <iostream>
#include <queue> 
#include <stdio.h> 
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std; 
  
class Graph { 
private: 
    // numero de vertices 
    int n; 
  
    // matriz de adjacencia 
	int **g; 
  
public: 
	
	
    // constutor 
    Graph(int x) 
    { 
        n = x; 
  
        //inicializar cada elemento da matriz de adjacência para zero
        //construtor matriz adjacencia
		g = new int*[n];
		for (int i = 0; i < n; ++i)
   	    g[i] = new int[n];
   	
        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < n; ++j) { 
                g[i][j] = 0; 
            } 
        } 
    }
	~Graph(){
		for (int i = 0; i < n; ++i)
    		delete [] g[i];
			delete [] g;
	} 
  
    void addEdge(int x, int y) 
    { 
        // verifica se o vértice está se conectando a si mesmo
        if (x == y) { 
        } 
        else { 
            // liga os vertices 
            g[y][x] = 1; 
            g[x][y] = 1; 
        } 
    }
	
	bool isBipartite(){
		int color[n], i; // vetor que guarda a cor
		for(int c = 0; c < n; c++){
			color[c] = 0;
		}
		color[0] = 1;
		queue <int> number;
		number.push(0);
		
		while(!number.empty()){
			
		i = number.front(); // acessa o proximo elemento da lista
		number.pop(); // remove o proximo elemento da lista
            for (int j = 0; j < n; ++j) { 
                if(g[i][j] == 1){
					if(color[j] == 0){
						number.push(j);
					}
					
					if(color[i] == 1){
						if(color[j] == 1) return false;
						else color[j] = 2;
					}
				
					if(color[i] == 2){
						if(color[j] == 2) return false;
						else color[j] = 1;
					}
				}
            } 
        }       
        cout << "SIM" << endl;
        for (int i = 0; i < n; i++){
			if(color[i] == 1){
				cout << i << " " << 'R' << endl; // a cor Vermelha representada pelo numero 1
			} else{
				cout << i << " " << 'B' << endl; // a cor Azul representada pelo numero 2
			}
		}
        return true;
        
	} 

};
  
int main() 
{  	
	
  	int x, y;
	std::ifstream file("grafos.txt"); 
	if (!file) {
    //erro durante leitura
	}

	while (true){
    int value;
    
	if (!(file >> value)) {
      break;
	}
	if(value == 0) return 0;
	
    Graph g(value); //Criando o Grafo
    
	do{
    	file >> x;
    	file >> y;
    	g.addEdge(x, y);
	}while(x != 0 || y != 0);//verifica se os valores lidos na linha sao '0 0'. Se sim encerra o laco.	
	
	if(g.isBipartite() == false){
		cout << "NAO" << endl;
	}
  } 
}