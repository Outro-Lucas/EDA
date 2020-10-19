#include <iostream>
#include <list>
#include <queue> 
#include <stdio.h> 
#include <string.h>
#include <fstream>
#include <sstream>
#include <algorithm> // função find

using namespace std;

class Grafo
{
	int V; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências
	vector<vector <int> > vec;

public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
	int busca(int n); //passado um inteiro ira realizar a busca dos vertices
	void buscaAux(); //auxilia para chamar a funcao busca para todos
};

Grafo::Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
	adj[v2].push_back(v1);
}

int Grafo::busca(int n){
		list<int>::iterator it;
		int vet[V], i, sum=0;
		for(int c = 0; c < V; c++){
			vet[c] = -1;
		}
		vet[n] = 1;
		queue <int> lista;
		lista.push(n);
		
		while(!lista.empty()){
		i = lista.front(); // acessa o proximo elemento da lista
		lista.pop(); // remove o proximo elemento da lista
		
		//percorrendo a list
		for (it=adj[i].begin(); it != adj[i].end(); it++){
			if(vet [(*it)] == -1){
				lista.push((*it));
				if(vet[i] == 1){
					vet[(*it)] = 0;
				} else {
					vet[(*it)] = 1;
					}
				}
			}
		}
		for(int c = 0; c < V; c++){
			sum = sum + vet[c];
		}
		//		cout << "SUM: " << sum << endl;
		for(int j = 0; j < vec.size(); j++){
				bool flag = true;
			for (int a = 0; a < vec[j].size(); a++){
				if(vec[j][a] != vet[a]){
					flag = false;
					break;
				}
			}
			if(flag == true){
					return -1;
				}
		}
		vec.push_back( vector <int>());
		for (int j = 0; j < V; j++){
			vec[vec.size()-1].push_back(vet[j]);
		}
		return sum;


	}
	
void Grafo::buscaAux(){
	int res = -1, maxRes = -1;
	bool test = false;
	
	for(int i = 0; i < V; i++){
		res = busca(i);
		if(res > maxRes){
			maxRes = res;
			test = false;	
		} 
		else if(res == maxRes) test = true;
	}
	   if(test){
		   cout << maxRes << " " << "NAO" << endl;
	   } else{
		   cout << maxRes << " " << "SIM" << endl;
	   }

}

int main(){
	int n, x, y, i;
	string line, temp;
	ifstream arq("grafos.txt");
	if (arq.is_open()){
		while(true){	
		vector<string> p; // vector pra guardar os valores
		arq >> n;
		if(n == 0) return 0;
		Grafo g(n); // criando o grafo
		string boss; // pega o nome do chefe do arquivo		
		getline(arq, line);
		getline(arq, line);
		p.push_back(line);
		// vai percorrer o arquivo e ler as linhas apos o numero de funcionarios e o nome do chefe
		for(int c = 0; c < n-1; c++){
			getline(arq, line);	
			temp = "";
			for (i = 0; i <= line.size(); i++){
				if (line[i] != ' '){
					temp = temp + line[i];
				} else {
					break;
				}
			}
			
		//verifica a primeira palavra
		if(std::find(p.begin(), p.end(), temp ) != p.end()){	
			for(int j = 0; j < p.size(); j++){
				if(p[j] == temp){
					x = j;
					break;
				}
			}
			} else{
				p.push_back(temp);
				for(int j = 0; j < p.size(); j++){
					if(p[j] == temp){
					x = j;
					break;
					}
				}
			}
			//ler o espaco
			temp = "";
			for (i = i+1; i<line.size(); i++){
				if (line[i] != '\n'){
					temp = temp + line[i];
				} else {
					break;
				}
			}
			
			//verifica a segunda palavra
			if(std::find(p.begin(), p.end(), temp ) != p.end())
			{
				for(int j = 0; j < p.size(); j++){
					if(p[j] == temp){
					y = j;
					break;
					}
				}
				
			} else{
				p.push_back(temp);
				for(int j = 0; j < p.size(); j++){
					if(p[j] == temp){
					y = j;
					break;
					}
				}
			}
			
			g.adicionarAresta(x, y);
			}
			g.buscaAux();
		}
	}
			
			
	return 0;
}