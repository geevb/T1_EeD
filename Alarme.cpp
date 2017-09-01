#include "Alarme.h"

Pista& Alarme::getPista()
{
	return *pista_;
}

Veiculo& Alarme::getVeiculo()
{
	return *veiculo_;
}

int Alarme::getTempo()
{
	return tempo_;
}

bool Alarme::getInsercao()
{
	return bInserir_;
}

// Executar o alarme inserindo o carro de atributo.
void Alarme::realizarAlarme() {
	if (this->getInsercao()) {
		this->getPista().receberCarro(this->getVeiculo());
	} else {
		this->getPista().retirarCarro();
	}
}
