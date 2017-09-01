#include "Pista.h"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "Gui.h"
#include "Semaforo.h"
#include "Veiculo.h"
#include "Alarme.h"
#include "Sistema.h"
#include "Relogio.h"

Gui gui;
Sistema sistema;

int main() {

	// Construindo Pistas fonte com: Nome da Pista, Numero de 0 a 1, Frequencia de entrada de carros, Velocidade, Tamanho e Status do Semáforo 
	Pista* VO1Leste = new Pista("VO1Leste", sistema.calcularNumeroAleatorio(0, 1), 10, 2, 80, 400, true);
	Pista* VN1Sul = new Pista("VN1Sul", sistema.calcularNumeroAleatorio(0, 1), 20, 5, 60, 500, false);
	Pista* VS1Norte = new Pista("VS1Norte", sistema.calcularNumeroAleatorio(0, 1), 30, 7, 60, 500, false);
	Pista* VN2Sul = new Pista("VN2Sul", sistema.calcularNumeroAleatorio(0, 1), 20, 5, 40, 500, false);
	Pista* VS2Norte = new Pista("VS2Norte", sistema.calcularNumeroAleatorio(0, 1), 60, 15, 40, 500, false);
	Pista* VL1Oeste = new Pista("VL1Oeste", sistema.calcularNumeroAleatorio(0, 1), 10, 2, 30, 400, false);

	// Construindo Pistas Sumidouro com Velocidade e Tamanho
	Pista* VO1Oeste = new Pista("VO1Oeste", 80, 2000);
	Pista* VN1Norte = new Pista("VN1Norte", 60, 500);
	Pista* VS1Sul = new Pista("VS1Sul", 60, 500);
	Pista* VN2Norte = new Pista("VN2Norte", 40, 500);
	Pista* VS2Sul = new Pista("VS2Sul", 40, 500);
	Pista* VL1Leste = new Pista("VL1Leste", 30, 400);

	// Construindo pistas Centro com Nome da pista, Velocidade, Tamanho e Status do Semáforo
	Pista* VC1Oeste = new Pista("VC1Oeste", 60, 300, false);
	Pista* VC1Leste = new Pista("VC1Leste", 60, 300, true);

	// Setar Direções das Pistas adjacentes
	(*VO1Leste).definirDirecoes((*VC1Leste), (*VN1Norte), (*VS1Sul), 8, 1, 1);
	(*VN1Sul).definirDirecoes((*VS1Sul), (*VC1Oeste), (*VO1Oeste), 1, 8, 1);
	(*VS1Norte).definirDirecoes((*VN1Norte), (*VO1Oeste), (*VC1Leste), 1, 1, 8);
	(*VN2Sul).definirDirecoes((*VS2Sul), (*VL1Leste), (*VC1Oeste), 3, 4, 3);
	(*VS2Norte).definirDirecoes((*VN2Norte), (*VC1Oeste), (*VL1Leste), 3, 3, 4);
	(*VL1Oeste).definirDirecoes((*VC1Oeste), (*VS2Sul), (*VN2Norte), 3, 3, 4);
	(*VC1Oeste).definirDirecoes((*VO1Oeste), (*VS1Sul), (*VN1Norte), 4, 3, 3);
	(*VC1Leste).definirDirecoes((*VL1Leste), (*VN2Norte), (*VS2Sul), 4, 3, 3);


	gui.apresentacao();
	int tempoTrocaSemaforo = gui.perguntarTempoTrocaSemaforo();
	int tempoExecucaoTotal = gui.perguntarTempoExecucaoTotal();

	sistema.loopDeEventos(tempoExecucaoTotal, tempoTrocaSemaforo, (*VO1Leste), (*VN1Sul), (*VS1Norte), (*VN2Sul), (*VS2Norte), (*VL1Oeste), (*VO1Oeste), (*VN1Norte), (*VS1Sul), (*VN2Norte), (*VS2Sul), (*VL1Leste), (*VC1Oeste), (*VC1Leste));

	gui.mostrarInformacoesFinais((*VO1Leste), (*VN1Sul), (*VS1Norte), (*VN2Sul), (*VS2Norte), (*VL1Oeste), (*VO1Oeste), (*VN1Norte),
		(*VS1Sul), (*VN2Norte), (*VS2Sul), (*VL1Leste), (*VC1Oeste), (*VC1Leste));

	double i;
	std::cin >> i;
	return 0;
}

