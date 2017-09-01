#pragma once
#ifndef ALARME_H
#define ALARME_H

#include "Veiculo.h"
#include "Pista.h"


class Pista;
class Alarme {
public:
	Alarme(Pista &pPista, Veiculo &pVeiculo, int pTempoParaAtivar, bool pInserir) {
		pista_= &pPista;
		veiculo_= &pVeiculo;
		tempo_ = pTempoParaAtivar;
		bInserir_ = pInserir;
	}
	~Alarme() {}

	Pista& getPista();
	Veiculo& getVeiculo();
	int getTempo();
	bool getInsercao();

	void realizarAlarme();

private:
	Pista* pista_;
	Veiculo* veiculo_;
	int tempo_;
	bool bInserir_;
};

#endif //! ALARME_H