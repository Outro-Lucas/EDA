using namespace std;
#include "avl.h"
#include "item.h"
#include "avl.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
using std::vector;
using std::cout;
using std::endl;

string inverte(string str){
	string temp, aux;
	int i;
	for(i = 0; i < str.size(); i++){
		if (str[i] != '/'){
			temp = temp + str[i];
		} else {
			break;
		}
	}
			aux = temp;
			if(aux.size() == 1){
				aux = "0"+aux;
			}
			temp = "";
			
	for(i = i+1; i < str.size(); i++){
		if (str[i] != '/'){
			temp = temp + str[i];
		} else {
			break;
		}
	}
		if(temp.size() == 1){
		temp = "0"+temp;
	}

	aux = aux + "/" + temp;
	temp = "";
	
	for(i = i+1; i < str.size(); i++){
		if (str[i] != '/'){
			temp = temp + str[i];
		} else {
			break;
		}
	}
	aux = temp + "/" + aux;	
	return aux;
}

int main(int argc, char** argv)
{
	Node *ArvCpf = NULL;
	Node *ArvNome = NULL;
	Node *ArvData = NULL;
	Node *aux = NULL;
	vector<Pessoa *> p;
	int j = 0;
	string d, m, y, aux1, aux2;
	char opcao;
	string busca;
	string pegaCpf, pegaNome, pegaSobrenome, pegaData, pegaCidade, temp, line; //variaveis de guarda
	int i; // variavel indice
	
	ifstream arq("data.csv");
	if (arq.is_open()){
		while( getline(arq, line)) {
			temp = "";
			for (i = 0; i < line.size(); i++){
				if (line[i] != ','){
					temp = temp + line[i];
				} else {
					break;
				}
			}
			pegaCpf = temp;

			//pegando o nome
			temp = "";
			for(i = i+1; i < line.size(); i++){
				if (line[i] != ','){
					temp = temp + line[i];
				} else {
					break;
				}
			}
			pegaNome = temp;
			
			//pegando o sobreome
			temp = "";
			for(i = i+1; i < line.size(); i++){
				if (line[i] != ','){
					temp = temp + line[i];
				} else {
					break;
				}
			}
			pegaSobrenome = temp;
			//cout << p.sobrenome << endl;
			
			//pegando a data de nascimento
			temp = "";
			for(i = i+1; i < line.size(); i++){
				if (line[i] != ','){
					temp = temp + line[i];
				} else {
					break;
				}
			}
			pegaData = temp;
			//cout << p.data << endl;
			
			//pegando a cidade
			temp = "";
			for(i = i+1; i < line.size(); i++){
				if (line[i] != ','){
					temp = temp + line[i];
				} else {
					break;
				}
			}
			pegaCidade = temp;
			
			p.push_back(new Pessoa(pegaCpf, pegaNome, pegaSobrenome, pegaData, pegaCidade));
			
			ArvCpf = avl_insert(ArvCpf, pegaCpf, p[j]);
			ArvNome = avl_insert(ArvNome, pegaNome, p[j]);
			ArvData = avl_insert(ArvData, inverte(pegaData), p[j]);
			j++;
		}
	} else {
		cout << "Arquivo invalido" << endl;
	} 
	
		while(opcao != 4){		
		cout<< "----------------------------------" << endl ;
		cout<< "Implementacao Arvore AVL" << endl;
		cout<< "----------------------------------" << endl;
		cout<< "1. Buscar CPF." << endl;
		cout<< "2. Buscar por nome." << endl;
		cout<< "3. Buscar por intervalo de tempo." << endl;
		cout<< "4. Sair" << endl;
		cout<< "Entre sua escolha:";
		cin >> opcao; 		
		
		switch(opcao)
		{
		case '1': 
			cout << "DIGITE O CPF: ";
			cin >> busca;
			aux = avl_search(ArvCpf, busca);
			if(aux != NULL)
				cout << aux->data->getCpf() << "," 
					 << aux->data->getNome() << "," 
					 << aux->data->getSobreome() << "," 
					 << aux->data->getDataNasc() << "," 
					 << aux->data->getCidade() << endl;
			else 
				cout << "CPF NAO ENCONTRADO!" << endl;	 
			break;
			 		
		case '2': 
			cout << "DIGITE O NOME: ";
			cin >> busca;
			searchName(ArvNome, busca);
			break;
		
		case '3': 
			cout << "INFORME A PRIMEIRA DATA:" << endl;
			cout << "DIA: ";
			cin >> d;
			cout << endl;
			cout << "MES: ";
			cin >> m;
			cout << endl;
			cout << "ANO: ";
			cin >> y;
			
			aux1 = m + "/" + d + "/" + y;
			aux1 = inverte(aux1);
			
			cout << "INFORME A SEGUNDA DATA:" << endl;
			cout << "DIA: ";
			cin >> d;
			cout << endl;
			cout << "MES: ";
			cin >> m;
			cout << endl;
			cout << "ANO: ";
			cin >> y;
			
			aux2 = m + "/" + d + "/" + y;
			aux2 = inverte(aux2);
			
			searchDate(ArvData, aux1, aux2);
			break;
		  	
		case '4': exit(0);
		default:
			cout << "ENTRADA INVALIDA!" << endl; 
			break;
		}	
	}
	
	return 0;	
}