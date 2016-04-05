#include "supertrunfo.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
int main(int argc, char *argv[]){
	if(argc < 4){
		cout<<"Dados incompletos. Insira todos os dados: arquivo de cartas, jogadores e cartas por jogadores"<<endl;
		exit(EXIT_FAILURE);
	}


	int jogadores, cartasJogadores;
	string nomejogador;

	//!Recebe via linha de comando o nome do arquivo a ser aberto
	string arquivoEntrada = argv[1];
	//!Recebe via linha de comando a quantidade de jogadores
	stringstream(argv[2]) >> jogadores;
	//!Recebe via linha de comando a quantidade de cartas/jogador
	stringstream(argv[3]) >> cartasJogadores;
	//!Verifica se a quantidade de jogadores está no intervalo valido
	if(jogadores > 10 || jogadores <= 1){
		cout<<"Número de jogadores inválido."<<endl; 
		exit(EXIT_FAILURE);
	}
	//!Verifica se a quantidade de cartas/jogador está no intervalo valido
	if(cartasJogadores <= 0 || cartasJogadores > 20){
		cout<<"Número de cartas/jogador inválido"<<endl;
		exit(EXIT_FAILURE);
	}

	STGame myGame;
	//!Ler cartas do arquivo
	myGame.readDeckFromFile(arquivoEntrada);
	//!Imprimi as cartas
	myGame.displayDeck();

	//!Adiciona jogadores ao jogo
	for(int x=1;x<=jogadores;x++){
		cout<<"Digite o nome do jogador "<<x<<endl;
		getline(cin, nomejogador);
		STPlayer NJ(nomejogador);
		myGame.addPlayer(NJ);

	}

	//!Atribui cartas aos jogadores dependendo da quantidade escolhida
	myGame.dealCards(cartasJogadores);
	//!Imprimi os jogadores e suas cartas
	myGame.displayPlayers();	
	
	auto nRounds = myGame.run();
	
	STPlayer winner = myGame.winner();

	
	cout << "\n\n>>>> O vencedor depois de " << nRounds << " rodadas foi o jogador: " << winner.name() << endl;

	
}