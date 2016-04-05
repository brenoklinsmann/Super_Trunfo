#include "supertrunfo.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
//!Class --> STCard

float convertToFloat(string arg){
	istringstream iss(arg);
	float arg_r = 0;
	iss >> arg_r;
	return arg_r;
}

STCard::STCard(vector<string> attC){
	m_cartaAtributos = attC;
}
STCard::STCard() {}
string STCard::getAtributo(int attC) const{
	return m_cartaAtributos[attC];
}
void STCard::displayCard(){
	cout<<endl;
	cout<<"ID = "<<getAtributo(STCard::atributos_ST::ID)<<endl;
	cout<<"NOME = "<<getAtributo(STCard::atributos_ST::NOME)<<endl;
	cout<<"FABRICANTE/PAÍS DE ORIGEM = "<<getAtributo(STCard::atributos_ST::FABRICANTE)<<endl;
	cout<<"ANO = "<<getAtributo(STCard::atributos_ST::ANO)<<endl;
	cout<<"VELOCIDADE = "<<getAtributo(STCard::atributos_ST::VELOCIDADE)<<endl;
	cout<<"AUTONOMIA = "<<getAtributo(STCard::atributos_ST::AUTONOMIA)<<endl;
	cout<<"COMPRIMENTO = "<<getAtributo(STCard::atributos_ST::COMPRIMENTO)<<endl;
	cout<<"ENVERGADURA = "<<getAtributo(STCard::atributos_ST::ENVERGADURA)<<endl<<endl;

}

//!Class -> STPlayer
STPlayer::STPlayer(string NomeJogador){
	m_nomeJogador = NomeJogador;
}

string STPlayer::name() const{
	return m_nomeJogador;
}

STCard STPlayer::popCard(){
	int sizeCartas = m_cartasJogador.size();
	STCard cartaTopo = m_cartasJogador[sizeCartas - 1];
	m_cartasJogador.resize(sizeCartas - 1);
	return cartaTopo;
}

int STPlayer::chooseRandomAttrib(){
	srand(time(0));
	int atributo = ( rand() % 4 )+4;
	return atributo;
	
}

void STPlayer::addCard(STCard &Carta){
	m_cartasJogador.push_back(Carta);
}

void STPlayer::displayCards(){
	for(int x=0;x<m_cartasJogador.size();x++){
		m_cartasJogador[x].displayCard();
	}
}

int STPlayer::nCards(){
	return m_cartasJogador.size();
}

//! Class --> STGame
void STGame::readDeckFromFile(string arquivoEntrada){
	ifstream arquivo("data/"+arquivoEntrada);
	if(!arquivo.is_open()){
		cout<<"Erro ao abrir o arquivo"<<endl;
		exit(EXIT_FAILURE);
	}
		
	vector<string> atributosCartas;
	string linhasDados;
	int aux = 0;
	while(getline(arquivo, linhasDados)){
		if(linhasDados == "") continue;
		atributosCartas.push_back(linhasDados);
		aux++;
		if(aux == 8){
			STCard cartaDeckOriginal(atributosCartas);
			m_deckOriginal.push_back(cartaDeckOriginal);
			atributosCartas.clear();
			aux = 0;
		}
	}	
}

void STGame::addPlayer(STPlayer &Jogador){
	m_jogadores.push_back(Jogador);
}

void STGame::dealCards(int k){
	if(m_jogadores.size() * k > m_deckOriginal.size()){
		cout<<"Quantidade de cartas insuficiente"<<endl;
		exit(EXIT_FAILURE);
	}
	int deck = 40;
	for(int x=0;x<m_jogadores.size();x++){
		for(int y=0;y<k;y++){
			srand(time(0));
			int carta = rand() % deck;
			m_jogadores[x].addCard(m_deckOriginal[carta]);
			m_deckOriginal.erase(m_deckOriginal.begin() + carta);
			deck--;	
		}
	}
}

void STGame::displayDeck(){
	for(int x=0;x<m_deckOriginal.size();x++){
		m_deckOriginal[x].displayCard();
	}
}

void STGame::displayPlayers(){
	cout<<endl;
	for(int x=0;x<m_jogadores.size();x++){
		cout<<m_jogadores[x].name()<<endl;
		m_jogadores[x].displayCards();	
	}
	cout<<endl;
}

STPlayer STGame::winner()
{
	return m_jogadores[0];

}
//codigo joão!!
/*void STGame::displayCardsOnTable() {
	int tam = Table.size();
	for (int i = 0; i < tam; i++) {
		Table[i].displayCard();	
	}
}

int STGame::displayStatusRound( STPlayer &Player_round) {
	int status_selected = Player_round.chooseRandomAttrib();
	string out;
	switch(status_selected){
		case 4:
			out = "SPEED";
			break;
		case 5:
			out = "VOO";
			break;
		case 6:
			out = "LENGHT";
			break;
		case 7:
			out = "SPREAD";
			break;
	}
	cout << "THE STATUS CHOOSEN IS " << out << endl;
	return status_selected;
}

int STGame::run(){
	int nRound = 1, x1_cards_count = 0;
	int currentPlayer = 0, players_in_game = m_jogadores.size();
	int att_choosen = 0, player_turn_winner = 0;
	float att_of_the_winner = 0;
	while(true){
		// ROUND CONTROLLER
		cout << "------------------------------------------------------" << endl;
		cout << "--------------------- " << nRound << " ROUND ------------------------" << endl;
		cout << "TIME TO " << m_jogadores[currentPlayer].name() << " CHOOSEN A ATTRIBUTE"<< endl;
		displayPlayers();
		att_choosen = displayStatusRound(m_jogadores[currentPlayer]);
		
		// PLAYERS POP CARD AND PUTTING IT ON TABLE
		for(int i = 0; i < players_in_game; i++){
			Table.push_back(m_jogadores[i].popCard());
		}

		cout << endl << "--------------------- CURRENT CARDS IN TABLE ------------------------" << endl;
		displayCardsOnTable();

		// RULES OF THE GAME
		// CHECK HEAD CARD RULES
		player_turn_winner = -1;
		for(unsigned int i = 0; i < Table.size(); i++){
			if(Table[i].getAtributo(0) == "ST") // ST PLAYER, BUT CONTINUE SEARCHING FOR X1 CARDS
				player_turn_winner = i;


			if(Table[i].getAtributo(0).at(1) == '1'){ // CARD X1 SELECTED
				if(player_turn_winner == -1)
					player_turn_winner = i;
				x1_cards_count++;

				}
		}

		if(player_turn_winner == -1 || x1_cards_count > 1) { // IF NOT HAVE PLAYER WINNER, USE POINTS RULES
			if(player_turn_winner == -1)
				player_turn_winner = 0;
				    // SETTING THE FIRST PLAYER IS WINNER
			att_of_the_winner = convertToFloat(Table[player_turn_winner].getAtributo(att_choosen)); // THE CARD WINNER POINTS
			for(unsigned int i = 1; i < Table.size(); i++){

				if(att_of_the_winner < convertToFloat(Table[i].getAtributo(att_choosen))){
					if(x1_cards_count > 1 && Table[i].getAtributo(0).at(1) == '1'){
						att_of_the_winner = convertToFloat(Table[i].getAtributo(att_choosen));
						player_turn_winner = i;
					} else if(x1_cards_count == 0) {
						att_of_the_winner = convertToFloat(Table[i].getAtributo(att_choosen));
						player_turn_winner = i;
					}
				}

			}		
		}
		// ADD CARD FOR THE WINNER
		for(unsigned int i = 0; i < Table.size(); i++){
			m_jogadores[player_turn_winner].addCard(Table[i]);
		}

	}	
		cout << endl << "--------------------- PLAYERS CARDS AFTER THE TURN ENDS ------------------------" << endl;
		displayPlayers();

}*/

