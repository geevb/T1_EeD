#pragma once
#include "Veiculo.h"

Veiculo::Veiculo() {
	tamanho_ = gerarTamanhoVeiculo() +3;
}

int Veiculo::gerarTamanhoVeiculo() {
	std::random_device rd;  // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(1, 6); // Faixa de pMin até pMax
	double numeroAleatorio = dis(gen);
	return (int)numeroAleatorio;
}

Veiculo Veiculo::criarVeiculo() {
	return Veiculo();
}

int Veiculo::getTamanho() {
	return tamanho_;
}

