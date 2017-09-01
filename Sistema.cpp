#pragma once
#include "Sistema.h"

// (*VO1Leste), (*VN1Sul), (*VS1Norte), (*VN2Sul), (*VS2Norte), (*VL1Oeste), (*VO1Oeste), (*VN1Norte), (*VS1Sul), (*VN2Norte), (*VS2Sul), (*VL1Leste), (*VC1Oeste), (*VC1Leste));
void Sistema::loopDeEventos(int pTempoDeExecucao, int tempoTrocarSemaforo, Pista &VO1Leste, Pista &VN1Sul, Pista &VS1Norte, Pista &VN2Sul, Pista &VS2Norte, Pista &VL1Oeste, Pista &VO1Oeste, Pista &VN1Norte,
	Pista &VS1Sul, Pista &VN2Norte, Pista &VS2Sul, Pista &VL1Leste, Pista &VC1Oeste, Pista &VC1Leste)
{
	for(int i = 1; i <= pTempoDeExecucao; i++){

	this->alternarSemaforos(VO1Leste, VN1Sul, VS1Norte, VN2Sul, VS2Norte, VL1Oeste, VC1Oeste, VC1Leste, i, tempoTrocarSemaforo);
    this->loopInsercoes(VO1Leste, VN1Sul, VS1Norte, VN2Sul, VS2Norte, VL1Oeste, i);
    this->loopTransferecias(VC1Oeste, VC1Leste, i);
    this->loopRemocoes(VO1Oeste, VN1Norte, VS1Sul, VN2Norte, VS2Sul, VL1Leste);

	}
}

// Controlar o fluxo de abertura e fechamento dos semáforos.
void Sistema::alternarSemaforos(Pista &VO1Leste, Pista &VN1Sul, Pista &VS1Norte, Pista &VN2Sul, Pista &VS2Norte, Pista &VL1Oeste, Pista &VC1Oeste, Pista &VC1Leste, int i, int tempoTrocarSemaforo){
	if (i % tempoTrocarSemaforo == 0){
		if(VO1Leste.getStatusSemaforo() && VC1Leste.getStatusSemaforo()){
			//Desligar o semáforo atualmente ligado.
			VO1Leste.desligarSemaforo();
			VC1Leste.desligarSemaforo();
			//Ligar os próximos semáforos.
			VN1Sul.ligarSemaforo();
			VN2Sul.ligarSemaforo();
			//std::cout << "VO1Leste e VC1Leste ligados!" << std::endl;
		} else if(VN1Sul.getStatusSemaforo() && VN2Sul.getStatusSemaforo()){
			VN1Sul.desligarSemaforo();
			VN2Sul.desligarSemaforo();
			VC1Oeste.ligarSemaforo();
			VL1Oeste.ligarSemaforo();
			//std::cout << "VN1Sul e VN2Sul ligados!" << std::endl;
		} else if(VC1Oeste.getStatusSemaforo() && VL1Oeste.getStatusSemaforo()){
			VC1Oeste.desligarSemaforo();
			VL1Oeste.desligarSemaforo();
			VS1Norte.ligarSemaforo();
			VS2Norte.ligarSemaforo();
			//std::cout << "VC1Oeste e VL1Oeste ligados!" << std::endl;
		} else if(VS1Norte.getStatusSemaforo() && VS2Norte.getStatusSemaforo()){
			VS1Norte.desligarSemaforo();
			VS2Norte.desligarSemaforo();
			VO1Leste.ligarSemaforo();
			VC1Leste.ligarSemaforo();
			//std::cout << "VS1Norte e VS2Norte ligados!" << std::endl;
		}
	}
}

// Controlar o fluxo de inserções de novos carros em cada uma das pistas Fonte
void Sistema::loopInsercoes(Pista &VO1Leste, Pista &VN1Sul, Pista &VS1Norte, Pista &VN2Sul, Pista &VS2Norte, Pista &VL1Oeste, int i) {

	// Verificar pelas frequencias p/ decidir se é hora ou não da pista gerar um novo carro beseado na sua frequencia calculada.
    if(i % VO1Leste.getFrequencia() == 0) {
		Veiculo* veiculo = new Veiculo();
		VO1Leste.receberCarro((*veiculo));
	 }
	 //Transferir carro da Pista X p/ a sua próxima pista Y.
	 VO1Leste.transferirCarro(VO1Leste.getStatusSemaforo());

	 if(i % VN1Sul.getFrequencia() == 0) {
		Veiculo* veiculo = new Veiculo();
		VN1Sul.receberCarro(*veiculo);
	 }
	 VN1Sul.transferirCarro(VN1Sul.getStatusSemaforo());

	 if(i % VS1Norte.getFrequencia() == 0) {
		Veiculo* veiculo = new Veiculo();
		VS1Norte.receberCarro(*veiculo);
	 }
	 VS1Norte.transferirCarro(VS1Norte.getStatusSemaforo());

	 if(i % VN2Sul.getFrequencia() == 0) {
		Veiculo* veiculo = new Veiculo();
		VN2Sul.receberCarro(*veiculo);		
	 }
	 VN2Sul.transferirCarro(VS1Norte.getStatusSemaforo());

	 if(i % VS2Norte.getFrequencia() == 0) {
		Veiculo* veiculo = new Veiculo();
		VS2Norte.receberCarro(*veiculo);
	 }
	 VS2Norte.transferirCarro(VS2Norte.getStatusSemaforo());

	 if(i % VL1Oeste.getFrequencia() == 0) {
		Veiculo* veiculo = new Veiculo();
		VL1Oeste.receberCarro(*veiculo);
	 }
	 VL1Oeste.transferirCarro(VL1Oeste.getStatusSemaforo());
}

// Controlar o fluxo de remoção dos carros das pistas Sumidouro
void Sistema::loopRemocoes(Pista &VO1Oeste, Pista &VN1Norte, Pista &VS1Sul, Pista &VN2Norte, Pista &VS2Sul, Pista &VL1Leste) {

	if(VO1Oeste.quantidadeDeCarros() > 0) {
		VO1Oeste.retirarCarro();
	 }
	 if(VN1Norte.quantidadeDeCarros() > 0) {
		VN1Norte.retirarCarro();
	 }
	 if(VS1Sul.quantidadeDeCarros() > 0) {
		VS1Sul.retirarCarro();
	 }
	 if(VN2Norte.quantidadeDeCarros() > 0) {
		VN2Norte.retirarCarro();
	 }
	 if(VS2Sul.quantidadeDeCarros() > 0) {
		VS2Sul.retirarCarro();
	 }
	 if(VL1Leste.quantidadeDeCarros() > 0) {
		VL1Leste.retirarCarro();
	 }
}

// Controlar o fluxo das transferencias de carros das Pistas Centro
void Sistema::loopTransferecias(Pista &VC1Oeste, Pista &VC1Leste, int i)
{
    if(VC1Oeste.quantidadeDeCarros() > 0) {
		VC1Oeste.transferirCarro(VC1Oeste.getStatusSemaforo());
	 }
	 if(VC1Leste.quantidadeDeCarros() > 0) {
		VC1Leste.transferirCarro(VC1Leste.getStatusSemaforo());
	 }
}

// Gerar número aleatório baseado numa range passada por parâmetro
int Sistema::calcularNumeroAleatorio(int pMin, int pMax) {
	std::random_device rd;  // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(pMin, pMax); // Faixa de pMin até pMax
	double numeroAleatorio = dis(gen); // Retorna valor,, aleatório gerado
	return (int)numeroAleatorio;
}

/*
void Sistema::adicionarAlarme(const Alarme& pAlarme)
{
	this->eventos_.push_back(pAlarme);
}
*/

/*
void Sistema::calcularInsercoes(int pTempoDeExecucao, Pista &pPista1, Pista &VN1Sul, Pista &VS1Norte, Pista &VN2Sul, Pista &VS2Norte, Pista &VL1Oeste)
{
	for (int i = 1; i <= pTempoDeExecucao; i++) {
		pPista1.incluirCarroAlarme(i, (*this));
		VN1Sul.incluirCarroAlarme(i, (*this));
		VS1Norte.incluirCarroAlarme(i, (*this));
		VN2Sul.incluirCarroAlarme(i, (*this));
		VS2Norte.incluirCarroAlarme(i, (*this));
		VL1Oeste.incluirCarroAlarme(i, (*this));
	}
}*/
