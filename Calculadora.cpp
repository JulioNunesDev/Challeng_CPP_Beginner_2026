#include <iostream>
#include <limits>


enum Operation {
	somar = 1,
	subtracao = 2,
	multiplicacao = 3,
	divicao = 4,
	sair = 5
};

double Somar(double a, double b) {
	
	std::cout << "Valor da soma: " << a << "+" << b << ": " << a + b << std::endl;
	return a + b;
}

double Subtracao(double a, double b) {
	std::cout << "Valor da subtracao: " << a << "-" << b << ": " << a - b << std::endl;
	return a - b;
}

double Multiplicacao(double a, double b) {
	std::cout << "Valor da multiplicacao: " << a << "x" << b << ": " << a * b << std::endl;
	return a * b;
}

double Divicao(double a, double b) {
	if (b == 0) {
		std::cout << "Erro na divisao por 0" << std::endl;
		return 0;
	};
	std::cout << "Valor da divicao: " << a << "/" << b << ": " << a / b << std::endl;
	return a / b;
}


int main() {

	double a = 0;
	double b = 0 ;
	int valueOperation = 0;
	bool activeCalculator = true;


	while (activeCalculator)
	{ 
		std::cout << "====================================" << std::endl;
		std::cout << " 1 - Somar" << std::endl;
		std::cout << " 2 - Subtrair" << std::endl;
		std::cout << " 3 - Multiplicar" << std::endl;
		std::cout << " 4 - Dividir" << std::endl;
		std::cout << " 5 - Sair" << std::endl;
		std::cout << "Digite a operacao: " << std::endl;
		std::cin >> valueOperation;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input Invalido! Digite um numero." << std::endl;
			continue;
		}


		if (valueOperation >= Operation::somar && valueOperation <= Operation::divicao) {
			

			std::cout << "Digite o primerio numero: " << std::endl;
			std::cin >> a;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Input Invalido! Digite um numero." << std::endl;
				continue;
			}


			std::cout << "Digite o segundo numero: " << std::endl;
			std::cin >> b;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Input Invalido! Digite um numero." << std::endl;
				continue;
			}
		}

		switch (valueOperation)
		{
			case Operation::somar: Somar(a, b);
			break;
		case Operation::subtracao: Subtracao(a, b);
			break;
		case Operation::multiplicacao: Multiplicacao(a, b);
			break;
		case Operation::divicao: Divicao(a, b);
			break;
			case Operation::sair:
				activeCalculator = false;
			break;
		default:
			std::cout << "Opcao invalida!" << std::endl;
			break;
		}

	}

	return 0;
}
