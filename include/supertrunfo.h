

#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

class STCard{
private:
	vector<string> m_cartaAtributos;
public:
	enum atributos_ST{ID=0, NOME, FABRICANTE, ANO, VELOCIDADE, AUTONOMIA, COMPRIMENTO, ENVERGADURA};
	//!Construtor
	//!Recebe um vector de strings e atribui ao objeto STCard cada atributo
	STCard(vector<string> );
	//!Construtor
	STCard();
	//!Função para pegar os atributos de uma carta
	//@retorna um atributo da carta, na ordem do eneum
	string getAtributo(int ) const;
	//!Imprimi a carta, todos os atributos seguindo a ordem do enum
	void displayCard();
};
class STPlayer{
private:
	vector<STCard> m_cartasJogador;
	string m_nomeJogador;
public:
	//!Construtor
	//!Recebe uma string com o nome do jogador e define o jogador
	STPlayer(string );
	//@return o nome do jogador
	string name() const;
	//!Função para acessar a carta do topo do monte de cartas do jogador 
	//@return carta no topo do monte e depois remove a mesma
	STCard popCard();
	//!Gera um numero aleatorio [0;7] para acessar um atributo aleatorio
	int chooseRandomAttrib();
	//!Adiciona uma carta ao final do monte de cartas
	void addCard(STCard &);
	//!Imprimi cada carta do jogador
	void displayCards();
	//@return a quantidade de cartas do jogador
	int nCards();

};
class STGame{
private:
	vector<STCard> m_deckOriginal;
	vector<STPlayer> m_jogadores;
	vector<STCard> Table;
public:
	//!Adiciona um jogador ao jogo
	void addPlayer(STPlayer &);
	//!Ler as cartas do arquivo para formar o deck Super Trunfo
	void readDeckFromFile(string );
	//!Imprimi o deck formado com as cartas do lidas do arquivo
	void displayDeck();
	//!Imprmi os jogadores participantes
	void displayPlayers();
	//!Escolhe cartas aleatorias para os jogadores dependendo da quantidade que for escolhida
	void dealCards(int);
	//!Retorna o vencedor do jogo
	STPlayer winner();

	void displayCardsOnTable();

	int displayStatusRound( STPlayer &);

	int run();


};
