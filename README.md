# Super Trufo
- Implementação do Super Trufo feito em C++ lendo dados via linha de comando e arquivos.

# O que foi feito
- Class STCard completa.
- Class STPlayer completa. 
- Class STGame apenas os metodos readDeckFromFile, addPlayer, dealCards, displayDeck, displayPlayers, winner.

# O que não foi feito
- Os metodos da classe STGame run, displayStatusRound, displayCardsOnTable.

# Criadores
- Breno Klinsmann Medeiros
- Mateus Santiago Ferreira Costa


# Tópicos visto em sala
- Class (construtores, get, set..)
- Leitura de arquivos, leitura de dados via linha de comando
- Bibliotecas para auxilio no desenvolvimento como vector, sstream

# Como compilar
- Para compilar o SuperTrunfo use:

	- g++ -std=c++11 -I include src/drive.cpp src/supertrunfo.cpp -o bin/gameplay
	
- Depois de compilar execute:
	- ./bin/gameplay cards.dat "numero de jogadores" "Numeros de cartas por jogador"
	- EX: ./bin/gameplay cards.dat 3 4
	- Executa com 3 jogadores com 4 cartas para cada

# Nosso código
	- Infelizmente não tivemos tempo suficiente para termina-lo a tempo mas ficou com a maioria das funções prontas,
	  das que já foram citadas acima, por esse fato o programa não executará os rouds do super trunfo pela falta do
	  método run, então o que ele está executando é a leitura de todas as cartas e distribui aleatóriamente cartas para
	  os jogadores em quantidades iguais.  	 
		
