#include "Semaforo.h"


void ligarDesligar(Semaforo pSemaforo) {
	if (pSemaforo.getLigado()) {
		pSemaforo.mudarStatusSemaforo(false);
	} else {
		pSemaforo.mudarStatusSemaforo(true);
	}
}

Semaforo::~Semaforo()
{
}

void Semaforo::mudarStatusSemaforo(const bool& pStatus)
{
	bLigado_ = pStatus;
}

bool Semaforo::getLigado()
{
	return bLigado_;
}
