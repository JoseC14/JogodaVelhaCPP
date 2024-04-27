//FUNCOES DO JOGO DA VELHA

/* ESCOLHER O OU X
   MARCAR
   CHECAR SE GANHOU
   ATUALIZAR O JOGO
*/

#include <iostream>

void BeginMsg(){
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "-           JOGO DA VELHA           -" << std::endl;
	std::cout << "-------------------------------------" << std::endl;

	std::cout << "Nesse Jogo Bola Começa primeiro" << std::endl;
}


int Check(){
	int num;
	std::cout << "Digite o numero correspondente a casa do jogo: " << std::endl;
	std::cin >> num;
	return num;
}

bool updateVelha(int check, int player, char velha[3][3])
{
	int cont = 0;

	if(check < 0 || check > 9)
	{
		std::cout << "Casa inválida" << std::endl;
		return true;
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(cont == check)
			{
				 if(velha[i][j] != 'O' && velha[i][j] != 'X')
				 {
					 if(player == 1)
					 {
						 velha[i][j] = 'X';
						return true;
					 }

					 if(player == 2)
					 {
						 velha[i][j] = 'O';
						 return true;
					 }
				 }
				 else{
					 std::cout << "Casa já foi marcada!" << std::endl;
					 return true;
				 }
			}

		   cont++;
		}
	}

	std::cout << "Velha!" << std::endl;
	return false;

}


void PrintVelha(char velha[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			std::cout << velha[i][j] << " ";
		}

		std::cout << std::endl;
	}
}
/*

    Suponhamos que eu tenha um vetor
    O O X
    O O X
    O X X

    Como vou saber que o Jogo deu velha ou alguem ganhou?
    transformando o vetor bidimensional em um unidimensional temos...
    O X X O O X X X O
    então quais são os casos possíveis?
    três simbolos seguidos no inicio é um. no indice 3 e no indice 7 sao outro..
    um simbolo no começo outro no meio e outro no final é outro...
    O O X O O X X O X
    Um simbolo intercalando de dois em dois é outro...
    O O X O O X O X X



*/
bool HasWinned(char velha[3][3]) {
    // GANHOU HORIZONTALMENTE
    if ((velha[0][0] == velha[0][1]) && (velha[0][1] == velha[0][2])) return true;
    if ((velha[1][0] == velha[1][1]) && (velha[1][1] == velha[1][2])) return true;
    if ((velha[2][0] == velha[2][1]) && (velha[2][1] == velha[2][2])) return true;

    // GANHOU VERTICALMENTE
    if ((velha[0][0] == velha[1][0]) && (velha[1][0] == velha[2][0])) return true;
    if ((velha[0][1] == velha[1][1]) && (velha[1][1] == velha[2][1])) return true;
    if ((velha[0][2] == velha[1][2]) && (velha[1][2] == velha[2][2])) return true;

    // GANHOU DIAGONALMENTE
    if ((velha[0][0] == velha[1][1]) && (velha[1][1] == velha[2][2])) return true;
    if ((velha[2][0] == velha[1][1]) && (velha[1][1] == velha[0][2])) return true;

    return false;
}


void WinText(int player)
{
    std::cout << "------------------------------------" << std::endl;
    std::cout << "- JOGADOR " << player <<" GANHOU!  -" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}
