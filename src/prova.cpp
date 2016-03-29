#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;


class STCard {
	public:
		enum atributos_sT {ID, NOME, PAIS, ANO, VELOCIDADE, VOO, COMPRIMENTO, ENVERGADURA, ATRIBUTO_EXTRA};

		STCard ( vector<string> att )
		{					
			atributos = att;
			
		}

		string getAtributos (atributos_sT att)
		{
			 return atributos[att];
		}

		void displayCard()
		{
			cout << "ID = " << getAtributos(STCard::atributos_sT::ID) << endl;
			cout << "NOME = " << getAtributos(STCard::atributos_sT::NOME) << endl;
			cout << "PAIS = " << getAtributos(STCard::atributos_sT::PAIS) << endl;
			cout << "ANO = " << getAtributos(STCard::atributos_sT::ANO) << endl;
			cout << "VELOCIDADE = " << getAtributos(STCard::atributos_sT::VELOCIDADE) << endl;
			cout << "VOO = " << getAtributos(STCard::atributos_sT::VOO) << endl;
			cout << "COMPRIMENTO = " << getAtributos(STCard::atributos_sT::COMPRIMENTO) << endl;
			cout << "ENVERGADURA = " << getAtributos(STCard::atributos_sT::ENVERGADURA) << endl;

		}

	private:
		
	vector<string> atributos;  	

};

class STPlayer{
	public:
		STPlayer ( string nome ) 
		{
			nome_jogador = nome;
		}

		string name()
		{
			return nome_jogador;
		}

		string popCard ()
		{
			
		}	
		//popCard : remove e retorna a carta no topo do monte de cartas do jogador.

	private:
		string nome_jogador;
		vector<STCard> cartas ;

};


int main () 
{
	vector<string> xx;
	ifstream filecard;
	string dataLine;
	filecard.open("cards.dat");
	if(filecard.is_open()){
		while (getline(filecard, dataLine)){
			xx.push_back(dataLine);
		}
	}
	STCard CardTeste(xx);
	CardTeste.displayCard();
	filecard.close();



}