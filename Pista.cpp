#pragma once
#include "Pista.h"

// Calculo de Frequência da aparição dos carros p/ a Pista em questão.
int Pista::calcularFrequencia(int pNumero0a1, int pFrequencia1, int pFrequencia2) {
	int menorFaixa = pFrequencia1 - pFrequencia2;
	double frequencia = (menorFaixa + (pNumero0a1 * ((pFrequencia2 * 2) + 1)));
	return (int)frequencia;
}

// Calculo da probabilidade de irar para qual pista adjacente.
Pista& Pista::calcularProximaPista() {
    std::vector<int> probabilidades;
    probabilidades.push_back(this->getProbDir());
    probabilidades.push_back(this->getProbEsq());
    probabilidades.push_back(this->getProbFrente());
    std::sort(probabilidades.begin(), probabilidades.end());

    //Posicao [2] contém o valor sortido de maior probabilidade.
    if(probabilidades[2] == this->getProbDir()) { return (*direita_); }
    if(probabilidades[2] == this->getProbEsq()) { return (*esquerda_); } 
    if(probabilidades[2] == this->getProbFrente()) { return (*frente_); }
}

// Definição das pistas adjacentes a pista atual atual e as referentes probabilidades de virar nelas.
void Pista::definirDirecoes(Pista &pF, Pista &pE, Pista &pD, int probF, int probE, int probD) {
	frente_ = &pF;
	esquerda_ = &pE;
	direita_ = &pD;
	probFrente_ = probF;
	probEsq_ = probE;
	probDir_ = probD;
}

// Método para incluir um veiculo proveniente de outra pista
void Pista::receberCarro(Veiculo& carro) {
	if (verificarSeCabe(carro)) {
		carros_.push_front(carro);
		this->inserirTamanhoDoCarro(carro.getTamanho());
		this->incrementarCarrosEntraram();
		//std::cout << "\nTamanho do carro inserido: " << carro.getTamanho() << std::endl;
	} else {
		//std::cout << "\nNao inseri carro de tamanho: " << carro.getTamanho() << std::endl;
	}
}

// Método para remover um veiculo da Lista de carros da pista em questão.
void Pista::retirarCarro() {
	if (carros_.size() != 0) {
		//std::cout << "Carro da pista: " << this->getNomeDaPista() << " removido. " << std::endl;
		this->removerTamanhoDoCarro(carros_.back().getTamanho());
		//Veiculo *carroAdeletar;
		//carroAdeletar = &(carros_.back());
		carros_.pop_back();
		this->incrementarCarrosSairam();
		//delete *carroAdeletar;
	} else {
		//std::cout << "Não há carros na pista: " << this->getNomeDaPista() << std::endl;
	}
}

// Transfere um carro para a Proxima Pista de uma Pista caso o semáforo esteja aberto e haja espaço suficiente na próxima pista.
void Pista::transferirCarro(bool pSemaforoAberto)
{
	if (this->quantidadeDeCarros() > 0) {
	 if (pSemaforoAberto) {
		//std::cout << "Sinal Aberto! \n";
		this->setProximaPista(this->calcularProximaPista());
		if (this->getProximaPista().verificarSeCabe(carros_.back())) {
			this->getProximaPista().receberCarro(carros_.back());
	     	//std::cout << "Carro foi transferido \n";
	     	this->removerTamanhoDoCarro(carros_.back().getTamanho());
		 	this->incrementarCarrosSairam();
		 	this->carros_.pop_back();		 
		} else { /*std::cout << "Sem espaço na proxima pista! \n" ;*/ }
	 } else { /*std::cout << "Sinal Fechado! \n";*/ }
	} else { /*std::cout << "Nao transferi pois estava vazia" << std::endl;*/ }
}




/*
// Adiciona na lista de eventos de sistema um alarme para remoção de veículo.
bool Pista::removerCarroAlarme(int pTempo, Sistema &pSistema)
{
	if (carros_.size() != 0) {
	int tempoParaPercorrer = (int)(this->getTamanhoDaVia() / (this->getVelocidade()/3.6) );
	Alarme* novoAlarme = new Alarme((*this), carros_.back(), (tempoParaPercorrer + pTempo), false);
	pSistema.adicionarAlarme((*novoAlarme));
	this->removerTamanhoDoCarro(carros_.back().getTamanho());
	return true;
	} else {
		std::cout << "Não há carro para remover" << std::endl;
		return false;
	}
}

// Adiciona na lista de eventos de sistema um alarme para inserção de veículos
bool Pista::incluirCarroAlarme(int pTempo, Sistema &pSistema)
{
	if (pTempo % (*this).getFrequencia() == 0) {
		Veiculo* novoVeiculo = new Veiculo();
		int tempoParaPercorrer = (int)(this->getTamanhoDaVia() / (this->getVelocidade()/3.6) );
		Alarme* novoAlarme = new Alarme((*this), (*novoVeiculo), (tempoParaPercorrer + pTempo), true);
		pSistema.adicionarAlarme((*novoAlarme));
		this->inserirTamanhoDoCarro((*novoVeiculo).getTamanho());
		std::cout << "Alarme para a pista: " << this->getNomeDaPista() << " criado. " << std::endl;
		return true;
	} else {
		return false;
	}
}*/

// Retornar a quantidade de elementos dentro da Lista
 int Pista::quantidadeDeCarros() {
	return carros_.size();
}

// Verificar se o Tamanho total da pista comporta o tamanho do carro + o tamanho ocupado.
bool Pista::verificarSeCabe(Veiculo& pVeiculo) {
	return ((pVeiculo.getTamanho() + this->getTamanhoOcupado()) <= this->getTamanhoDaVia());
}

// Acrescentar o tamanho do carro ao tamanho ocupado atual.
void Pista::inserirTamanhoDoCarro(int pTamanhoDoCarro) {
	tamanho_ocupado_ = tamanho_ocupado_ + pTamanhoDoCarro;
}


// Remover o tamanho do carro da do espaço ocupado na pista.
void Pista::removerTamanhoDoCarro(int pTamanhoDoCarro) {
	this->tamanho_ocupado_ = tamanho_ocupado_ - pTamanhoDoCarro;
}



void Pista::incrementarCarrosEntraram() {
	carrosEntraram_++;
}

void Pista::incrementarCarrosSairam() {
	carrosSairam_++;
}

void Pista::desligarSemaforo() {
	this->semaforoLigado_ = false;
}

void Pista::ligarSemaforo() {
	this->semaforoLigado_ = true;
}




Pista &Pista::getPistaEsquerda() { return *esquerda_; }


Pista &Pista::getPistaDireita() { return *direita_; }


Pista &Pista::getPistaFrente() { return *frente_; }


Pista &Pista::getProximaPista() { return *proxima_pista_; }


std::string Pista::getNomeDaPista() { return nome_da_pista_; }


int Pista::getProbEsq() { return probEsq_; }


int Pista::getProbDir() { return probDir_; }


int Pista::getProbFrente() { return probFrente_; }


int Pista::getFrequencia() { return frequencia_; }


int Pista::getVelocidade() { return velocidade_da_via_; }


int Pista::getTamanhoDaVia() { return tamanho_da_via_; }


int Pista::getTamanhoOcupado() { return tamanho_ocupado_; }


int Pista::getCarrosEntraram() { return carrosEntraram_; }


int Pista::getCarrosSairam() { return carrosSairam_; }


bool Pista::getStatusSemaforo() { return semaforoLigado_; }


void Pista::setProximaPista(Pista &pProximaPista) { proxima_pista_ = &pProximaPista; }


void Pista::setStatusSemaforo(bool pStatus) { semaforoLigado_ = pStatus; }
