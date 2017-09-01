#pragma once
#ifndef PISTA_H
#define PISTA_H

#include "Veiculo.h"
#include "Alarme.h"
#include "Sistema.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <list>

class Sistema;
class Pista {
	 public:
		// Construtor Padrão
		Pista() {}

		// Construtor Pista Fonte
		Pista(const char* pNomeDaPista, int pNumero0a1, int pFrequencia1, int pFrequencia2, int pVelocidade, int pTamanho, bool pSemaforoLigado) :velocidade_da_via_{ pVelocidade },
		tamanho_da_via_{ pTamanho }, semaforoLigado_{ pSemaforoLigado } {
			frequencia_ = (*this).calcularFrequencia(pNumero0a1, pFrequencia1, pFrequencia2);
			nome_da_pista_ = pNomeDaPista;
			tamanho_ocupado_ = 0;
			carrosEntraram_ = 0;
			carrosSairam_ = 0;
		}

		// Contrutor Pista Sumidouro
		Pista(const char* pNomeDaPista, int pVelocidade, int pTamanho) :nome_da_pista_{ pNomeDaPista }, velocidade_da_via_{ pVelocidade }, tamanho_da_via_{ pTamanho } {
			nome_da_pista_ = pNomeDaPista;
			tamanho_ocupado_ = 0;
			carrosEntraram_ = 0;
			carrosSairam_ = 0;
		}

		// Construtor Pista Centro
		Pista(const char* pNomeDaPista, int pVelocidade, int pTamanho, bool pSemaforoLigado):nome_da_pista_{ pNomeDaPista }, velocidade_da_via_{ pVelocidade },
		tamanho_da_via_{ pTamanho }, semaforoLigado_ {pSemaforoLigado} {
			nome_da_pista_ = pNomeDaPista;
			tamanho_ocupado_ = 0;
			carrosEntraram_ = 0;
			carrosSairam_ = 0;			
		}

		// Destrutor
		~Pista() {}

		// Getters
		int getFrequencia();
		int getVelocidade();
		int getTamanhoDaVia();
		int getTamanhoOcupado();
		int getCarrosEntraram();
		int getCarrosSairam();
		std::string getNomeDaPista();

		Pista& getPistaEsquerda();
		Pista& getPistaDireita();
		Pista& getPistaFrente();
		Pista& getProximaPista();
		Pista& calcularProximaPista();		

		int getProbEsq();
		int getProbDir();
		int getProbFrente();

		/*********************/

		void setProximaPista(Pista &pProximaPista);
		void definirDirecoes(Pista &pF, Pista &pE, Pista &pD, int probF, int probE, int probD);

		void receberCarro(Veiculo& carro);
		void transferirCarro(bool pSemaforoAberto);
		void retirarCarro();
		void inserirTamanhoDoCarro(int pTamanhoDoCarro);
		void removerTamanhoDoCarro(int pTamanhoDoCarro);
		bool verificarSeCabe(Veiculo& carro);		

		void incrementarCarrosEntraram();
		void incrementarCarrosSairam();

		int calcularFrequencia(int pNumero0a1, int pfrequencia1, int pfrequencia2);
		int quantidadeDeCarros();

		bool getStatusSemaforo();
		void setStatusSemaforo(bool pStatus);
		void desligarSemaforo();
		void ligarSemaforo();

		//bool incluirCarroAlarme(int pTempo, Sistema &pSistema);
		//bool removerCarroAlarme(int pTempo, Sistema &pSistema);

	 private:
		Pista* frente_;
		Pista* esquerda_;
		Pista* direita_;
		Pista* proxima_pista_;

		std::list<Veiculo> carros_;

		int carrosEntraram_ = 0;
		int carrosSairam_ = 0;

		int frequencia_;
		int velocidade_da_via_;
		int tamanho_da_via_;
		int tamanho_ocupado_ = 0;
		int probEsq_;
		int probFrente_;
		int probDir_;

		std::string nome_da_pista_;
		bool semaforoLigado_;
	};
#endif // !PISTA_H
