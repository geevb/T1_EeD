#pragma once
class Semaforo
{
public:
	Semaforo() {}
	Semaforo(signed char pTipo) : tipo_{pTipo} {}
	~Semaforo();

	
	void mudarStatusSemaforo(const bool& pStatus);

	bool getLigado();


private:
	bool bLigado_ = false;
	signed char tipo_; // 0 = Aferente, 1 = Eferente
};

