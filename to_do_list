#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>




struct Tarefa {
	int id = 0;
	std::string name;
	bool feita = false;
};

int proximoId(const std::vector<Tarefa>& Lista);
void AddToList(std::vector<Tarefa>& Lista, Tarefa Itens);
void RemoveToList(int id, std::vector<Tarefa>& Lista);
void EditToList(int id, std::vector<Tarefa>& Lista);
void salvarArquivo(const std::vector<Tarefa>& Lista);


std::vector <Tarefa> carregarArquivo();


int main() {

	std::vector<Tarefa> Lista =  carregarArquivo();
	Tarefa NewItem = {proximoId(Lista), "Comer algo doce", false};
	


	AddToList(Lista, NewItem);
	EditToList(1, Lista);
	RemoveToList(1, Lista);

	

	for (auto l : Lista) {
		std::cout << l.id << "|" << l.name << "|" << l.feita << std::endl;
	}

	return 0;
}

int proximoId(const std::vector<Tarefa>& Lista) {

	if (Lista.empty()) {
		return 1;
	}

	auto it = std::max_element(Lista.begin(), Lista.end(),
		[](const Tarefa& a, const Tarefa& b) {
			return a.id < b.id;
		});

	return it->id + 1;
}




void AddToList(std::vector<Tarefa>& Lista, Tarefa Itens) {
	 int id = Lista.size();
	 Lista.push_back({Itens});
	 std::cout << "Item Adicionado: " << Itens.id << " " << Itens.name << " " << Itens.feita << std::endl;
	 salvarArquivo(Lista);

	

};


void RemoveToList(int id, std::vector<Tarefa>& Lista) {
	
	std::erase_if(Lista, [id](const Tarefa& l) {
		
		return l.id == id;
	});

	std::cout << "Tarefa " << id << " removida (se existia)." << std::endl;
	salvarArquivo(Lista);

	

};

void EditToList(int id, std::vector<Tarefa>& Lista) {


	auto idItemNew = std::find_if(Lista.begin(), Lista.end(), [id](const Tarefa& l) {
		return l.id == id;
		});


	if (idItemNew == Lista.end()) {
		std::cout << "Tarefa nao encontrada!" << std::endl;
		return;
	};

	idItemNew->feita = !idItemNew->feita;

	salvarArquivo(Lista);

	std::cout << "Tarefa " << idItemNew->id << " agora esta marcada como: "
		<< (idItemNew->feita ? "feita" : "pendente") << std::endl;

};

void salvarArquivo(const std::vector<Tarefa>& Lista) {
	std::ofstream outFile("Lista.txt", std::ios::out);


	if (!outFile) {

		std::cerr << "Error algo abrir o arquivo!" << std::endl;
		return;
	}

	for (const auto& l : Lista) {
		outFile << l.id << "|" << l.name << "|" << l.feita << std::endl;
	}

	outFile.close();

}

std::vector <Tarefa> carregarArquivo() {
	std::vector <Tarefa> lista;

	std::ifstream Arquivo("Lista.txt");


	if (!Arquivo) {
		std::cerr << "Arquivo nao encontrado, comecando lista vazia." << std::endl;
		return lista;
	}
	std::string linha;
	while (std::getline(Arquivo, linha)){
		std::stringstream ss(linha);
		std::string idStr, name, feitaStr;

		// id | Name | False

		std::getline(ss, idStr, '|');
		std::getline(ss, name, '|');
		std::getline(ss, feitaStr, '|');

		Tarefa t;
		t.id = std::stoi(idStr);
		t.name = name;
		t.feita = (std::stoi(feitaStr) != 0);

		lista.push_back(t);
	}

	Arquivo.close();
	return lista;
}
