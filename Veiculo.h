#pragma once
#ifndef VEICULO_H
#define VEICULO_H
#include <random>

class Veiculo
{
public:
	// Construtor Padrao
	Veiculo();

	~Veiculo() {}

	Veiculo criarVeiculo();
	int gerarTamanhoVeiculo();

	int getTamanho();
	
private:
	int tamanho_;
	//Pista<Veiculo>* pistaDesejada_;
};
#endif // !VEICULO_H

