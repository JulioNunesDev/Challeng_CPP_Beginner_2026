#include <iostream>
#include <limits>

bool ChecarVitoria(char tabuleiro[3][3], char jogador) {

	for (int i = 0; i < 3; i++) {
		if (tabuleiro[i][0] == jogador &&
			tabuleiro[i][1] == jogador &&
			tabuleiro[i][2] == jogador)
			return true;
	}

	for (int i = 0; i < 3; i++) {
		if (tabuleiro[0][i] == jogador &&
			tabuleiro[1][i] == jogador &&
			tabuleiro[2][i] == jogador)
			return true;
	}

	if (tabuleiro[0][0] == jogador &&
		tabuleiro[1][1] == jogador &&
		tabuleiro[2][2] == jogador)
		return true;

	if (tabuleiro[0][2] == jogador &&
		tabuleiro[1][1] == jogador &&
		tabuleiro[2][0] == jogador)
		return true;

	return false;
}

int main() {

	char tabuleiro[3][3] = { {'0','1','2'}, {'3','4','5'}, {'6','7','8'} };
	int posicao;
	char jogadorAtual = 'O';

	while (true) {

		std::cout << std::endl;
		std::cout << "=====================Tabuleiro=====================" << std::endl;
		std::cout << "Vez do Player: " << jogadorAtual << std::endl;
		std::cout << std::endl;

		std::cout << "Digite a posicao 0 a 8: ";
		std::cin >> posicao;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Digite uma posicao numerica!" << std::endl;
			continue;
		}

		if (posicao >= 0 && posicao <= 8) {
			int linha = posicao / 3;
			int coluna = posicao % 3;

			if (tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] != 'O') {
				tabuleiro[linha][coluna] = jogadorAtual;

				if (ChecarVitoria(tabuleiro, jogadorAtual)) {
					system("cls");
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							std::cout << " " << tabuleiro[i][j];
							if (j < 2) std::cout << " |";
						}
						std::cout << std::endl;
						if (i < 2) std::cout << "-----------" << std::endl;
					}
					std::cout << "O Player: " << jogadorAtual << " Ganhou!" << std::endl;
					std::cin.ignore();
					std::cin.get();
					break;
				}

			}
			else {
				std::cout << "Posicao ocupada!" << std::endl;
				continue;
			}

		}
		else {
			std::cout << "Posicao invalida!" << std::endl;
			continue;
		}

		jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';

		system("cls");

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << " " << tabuleiro[i][j];
				if (j < 2) std::cout << " |";
			}
			std::cout << std::endl;
			if (i < 2) std::cout << "-----------" << std::endl;
		}

		int vazias = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O')
					vazias++;

		if (vazias == 0) {
			std::cout << "Empate!" << std::endl;
			std::cin.ignore();
			std::cin.get();
			break;
		}
	}

	return 0;
}
