#include <iostream>
#include <random>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <typeinfo>
#include <limits>


/*
estado: numeroSecreto(fixo, gerado uma vez)
estado : tentativasRestantes(muda a cada rodada)

repita :
    ler palpite do jogador
    comparar palpite com numeroSecreto
    dar feedback(maior, menor, igual)
    diminuir tentativasRestantes
    até(acertou OU tentativas == 0)
    */


void limparConsole();

int newNumberRandom();
void gameLoop(int random_number, int palpite, int* points, int* tentativas, int userResponse, bool* playGame);





enum User {
    sim,
    nao
};


int main()
{

    int palpite = 0;
    int tentativas = 3;
    int userResponse = 1;
    bool playGame = true;
    int points = 0;
    int random_number = newNumberRandom();

    std::cout << "Random number: " << random_number << std::endl;
     gameLoop(random_number, palpite, &points, &tentativas, userResponse, &playGame);

    return 0;



}

void limparConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif


}


int newNumberRandom() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 100);

    int random_number = distrib(gen);

    return random_number;
}
void gameLoop(int random_number, int palpite, int* points, int* tentativas, int userResponse, bool* playGame) {



    while (*playGame)
    {
        limparConsole();
        std::cout << "Random number: " << random_number << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "     Jogo da Adivinhacao     " << "Pontos: " << *points << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "Tentativas: " << *tentativas << std::endl;
        std::cout << "===========================" << std::endl;

        if (*tentativas <= 0) {
            std::cout << "Suas tentativas acabaram!" << std::endl;

            std::cout << "Deseja reiniciar?: 1 = Yes. / 2 = Not. " << std::endl;
            std::cin >> userResponse;
             if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input Invalido! Digite um numero.";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        }
            switch (userResponse)
            {

            case 1:
                *tentativas = 3;
                std::cout << *tentativas;
                continue;
                
            case 2:
                *playGame = false;
                std::cout << "Fim de game.";
                exit(0);

                break;


            default:
                std::cout << "Coloque S ou N";
                break;
            }

        }

        std::cout << "Digite um numero: ";
        std::cin >> palpite;
        

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input Invalido! Digite um numero.";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        }




        if (palpite == random_number) {
            random_number = newNumberRandom();
            std::cout << "Voce acertou!" << std::endl;
            *points = *points + 1;
            *tentativas = 3;

        }
        else if (palpite < random_number) {

            *tentativas = *tentativas - 1;
            std::cout << "Maior" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            limparConsole();

        }
        else {

            *tentativas = *tentativas - 1;
            std::cout << "Menor" << std::endl;
            std::this_thread::sleep_for(std::chrono::microseconds(200));
            limparConsole();

        }


    }

}
