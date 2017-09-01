#pragma once
#ifndef GUI_H
#define GUI_H

#include <iostream>
#include "Pista.h"

class Gui
{
 public:
	Gui() {}
	~Gui() {}
	void apresentacao();
	int perguntarTempoTrocaSemaforo();
	int perguntarTempoExecucaoTotal();
	void mostrarInformacoesFinais(Pista &pVO1Leste, Pista &pVN1Sul, Pista &pVS1Norte, Pista &pVN2Sul,
		Pista &pVS2Norte, Pista &pVL1Oeste, Pista &pVO1Oeste, Pista &pVN1Norte, Pista &pVS1Sul, 
		Pista &pVN2Norte, Pista &pVS2Sul, Pista &pVL1Leste, Pista &pVC1Oeste, Pista &pVC1Leste);
 private:
};
#endif //! GUI_H

