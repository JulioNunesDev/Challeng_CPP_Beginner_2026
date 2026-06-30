#include <iostream>
#include <vector>
#include <limits>
#include <string>



enum E_Aluno {
	Cadastrar = 1,
	BuscarAluno = 2,
	RemoverAluno = 3,
	ListarAluno = 4,
	Sair = 5
};


class Aluno {

private:
	int ID = 0;
	std::string Nome = "";
	double Nota = 0.0;



public:


	Aluno(int idAluno, std::string NomeAluno, double notaAluno) {
		this->ID = idAluno;
		this->Nome = NomeAluno;
		this->Nota = notaAluno;
	}


	int getAlunoID() const {
		return this->ID;
}
	std::string getNomeAluno() const {
		return this->Nome;
	}
	
	double getNotaAluno() const {
		return this->Nota;
	}

	void setNotaAluno(double novaNotaAluno) {
		if (novaNotaAluno < 0 || novaNotaAluno > 10) {
			std::cout << "Nota invalida!" << std::endl;
			return;
		}
		this->Nota = novaNotaAluno;
	}

};

int geradorIdNew(const std::vector<Aluno>& lista) {

	if (lista.empty()) {
		std::cout << "Lista Vazia, cadastrando primeiro Aluno." << std::endl;
		return 1;
	}

	auto it = std::max_element(lista.begin(), lista.end(),
		[](const Aluno& a, const Aluno& b) {
		return a.getAlunoID() < b.getAlunoID();
		});

	return it->getAlunoID() + 1;
}

void cadastrarAluno(std::vector<Aluno>& lista) {
	std::cout << "Digite o nome do aluno: ";
	std::string nome;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, nome);
	

	double nota = 0.0;
	std::cout << "Digite a nota do aluno: ";
	std::cin >> nota;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input Invalido!" << std::endl;
		return;
	}
	int newIDAluno = geradorIdNew(lista);

	Aluno newAluno = Aluno(newIDAluno, nome, nota);
	lista.push_back(newAluno);
	std::cout << "Aluno cadastrado com sucesso!" << std::endl;

	

}

void  listarAlunos(const std::vector<Aluno>& lista) {


	if (lista.empty()) {
		std::cout << "Nenhum aluno na lista." << std::endl;
		return;
	}
	std::cout << "======================================" << std::endl;
	std::cout << " Lista de alunos: " << std::endl;
	std::cout << "======================================" << std::endl;
	for (auto i : lista) {
		std::cout << "Id: " << i.getAlunoID() << " Nome: " << i.getNomeAluno() << " Nota: " << i.getNotaAluno() << std::endl;
	}
}

void buscarAluno(const std::vector<Aluno>& lista) {


	int idAluno;
	std::cout << "Digite o ID do Aluno: ";
	std::cin >> idAluno;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input invalido! Digite um id numerico." << std::endl;
		return;
	}

	auto id = std::find_if(lista.begin(), lista.end(),
		[idAluno](const Aluno& a) {
			return a.getAlunoID() == idAluno;
		});

	if (id == lista.end()) {
		std::cout << "Aluno nao encontrado!" << std::endl;
		return ;
	}

	std::cout <<"ID: " << id->getAlunoID() << std::endl;
	std::cout <<"Nome: " << id->getNomeAluno() << std::endl;
	std::cout <<"Nota: " << id->getNotaAluno() << std::endl;
}

void removeAluno(std::vector<Aluno>& lista) {

	if (lista.empty()) {
		std::cout << "Nenhum aluno na lista." << std::endl;
		return;
	}
	int idAluno;
	std::cout << "Digite o ID do Aluno: ";
	std::cin >> idAluno;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input invalido! Digite um id numerico." << std::endl;
		return;
	}
	std::erase_if(lista, [idAluno](const Aluno& la) {
		return la.getAlunoID() == idAluno;
		});

	std::cout << "Aluno removido com sucesso!" << std::endl;
	

}

int main() {
	std::vector<Aluno> Alunos;
	int valueOperation = 0;
	bool activeLoop = true;
	
	while (activeLoop)
	{
		std::cout << "====================================" << std::endl;
		std::cout << " 1 - Cadastrar aluno" << std::endl;
		std::cout << " 2 - Buscar aluno" << std::endl;
		std::cout << " 3 - Remover aluno" << std::endl;
		std::cout << " 4 - Listar alunos" << std::endl;
		std::cout << " 5 - Sair" << std::endl;
		std::cout << "Digite a operacao: ";
		std::cin >> valueOperation;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input Invalido!, Digite um numero." << std::endl;
			continue;
		}

		switch (valueOperation)
		{
		case E_Aluno::Cadastrar: cadastrarAluno(Alunos);
			break;
		case  E_Aluno::BuscarAluno: buscarAluno(Alunos);
			break;
		case  E_Aluno::RemoverAluno: removeAluno(Alunos);
			break;
		case  E_Aluno::ListarAluno: listarAlunos(Alunos);
			break;
		case  E_Aluno::Sair: 
			activeLoop = false;
			break;

		default:  
			std::cout << "Opcao invalida!" << std::endl;
			break;
		}

	}
	

	
	return 0;
}
