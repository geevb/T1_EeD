#pragma once
#ifndef SISTEMA_H
#define SISTEMA_H

#include "DoublyCircularList.hpp"
#include "Alarme.h"
#include <random>
#include <vector>
#include <iostream>
#include <thread>

class Alarme;
class Pista;
class Sistema
{
public:
	Sistema() {}
	~Sistema() {}

	void loopInsercoes(Pista &pPista1, Pista &pPista2, Pista &pPista3, Pista &pPista4, Pista &pPista5, Pista &pPista6, int i);	
	void loopDeEventos(int pTempoDeExecucao, int tempoTrocarSemaforo, Pista &pPista1, Pista &pPista2, Pista &pPista3, Pista &pPista4, Pista &pPista5, Pista &pPista6, Pista &pPista7, Pista &pPista8,
	Pista &pPista9, Pista &pPista10, Pista &pPista11, Pista &pPista12, Pista &pPista13, Pista &pPista14);
	void loopTransferecias(Pista &pPista11, Pista &pPista12, int i);
	void loopRemocoes(Pista &pPista7, Pista &pPista8, Pista &pPista9, Pista &pPista10, Pista &pPista11, Pista &pPista12);

	void alternarSemaforos(Pista &pPista1, Pista &pPista2, Pista &pPista3, Pista &pPista4, Pista &pPista5, Pista &pPista6, Pista &pPista13, Pista &pPista14, int i, int tempoTrocarSemaforo);
	int calcularNumeroAleatorio(int pMin, int pMax);

	//void adicionarAlarme(const Alarme &pAlarme);
	//void calcularInsercoes(int pTempoDeExecucao, Pista &pPista1, Pista &pPista2, Pista &pPista3, Pista &pPista4, Pista &pPista5, Pista &pPista6);
private:
	std::vector<Alarme> eventos_;
};
#endif //! SISTEMA_H
