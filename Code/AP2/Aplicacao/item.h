#ifndef ITEM_H
#define ITEM_H
using namespace std;
#include <string>

//typedef std::string Tkey;
//typedef std::string Tvalue;

class Pessoa{
	private:
		std::string cpf;
		std::string nome;
		std::string sobrenome;
		std::string dataNasc;
		std::string cidade;
	public:
		string getCpf(){
			return cpf;
		}
		
		string getNome(){
			return nome;
		}
		
		string getSobreome(){
			return sobrenome;
		}
		
		string getDataNasc(){
			return dataNasc;
		}
		
		string getCidade(){
			return cidade;
		}
		
		Pessoa(string Cpf, string Nome, string Sobrenome, string DataNasc, string Cidade){
			cpf = Cpf;
			nome = Nome;
			sobrenome = Sobrenome;
			dataNasc = DataNasc;
			cidade = Cidade;
		}
};

#endif