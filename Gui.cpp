#include "Gui.h"

// ASCII Art de apresentação inicial
void Gui::apresentacao(){
std::cout << "  _______         __  __ _                                                            #" << std::endl;
std::cout << " |__   __|       / _|/ _(_)                                                           #" << std::endl;
std::cout << "    | |____,__ _| |_| |_ _  ___                                                       #" << std::endl;
std::cout << "    | |  __/ _  |  _|  _| |/ __|                                                      #" << std::endl;
std::cout << "    | | | | (_| | | | | | | (__                                                       #" << std::endl;
std::cout << "    |_|_|  \\__,_|_| |_| |_|\\___|                                                      #" << std::endl;
std::cout << "   _____ _                 _       _                                                  #" << std::endl;
std::cout << "  / ____(_)               | |     | |                                                 #" << std::endl;
std::cout << " | (___  _ _ __ ___  _   _| | __ _| |_ ___  _ __                                      #" << std::endl;
std::cout << "  \\___ \\| | \'_ ` _ \\| | | | |/ _` | __/ _ \\| '__|                                     #" << std::endl;
std::cout << "  ____) | | | | | | | |_| | | (_| | | |(_) | |                                        #" << std::endl;
std::cout << " |_____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|                                        #" << std::endl;
std::cout << "                                                                                      #" << std::endl;
std::cout << "                                                         ________________________     #" << std::endl;
std::cout << "                    /\\      _____          _____       |   |     |     |    | |  \\    #" << std::endl;
std::cout << "     ,-----,       /  \\____/__|__\\_     __/__|__\\___   |___|_____|_____|____|_|___\\   #" << std::endl;
std::cout << "  ,--'---:---`--, /  |  _     |    `|  |     |      `| |                    | |    \\  #" << std::endl;
std::cout << " ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--' #" << std::endl; 
std::cout << "````````````````````````````````````````````````````````````````````````````````````` #" << std::endl;
std::cout << "#######################################################################################" << std::endl;
}

// Tabela de resultados obtidos após a execução da simuação
void Gui::mostrarInformacoesFinais (Pista &pVO1Leste, Pista &pVN1Sul, Pista &pVS1Norte, Pista &pVN2Sul, Pista &pVS2Norte,
	Pista &pVL1Oeste, Pista &pVO1Oeste, Pista &pVN1Norte, Pista &pVS1Sul, Pista &pVN2Norte,
	Pista &pVS2Sul, Pista &pVL1Leste, Pista &pVC1Oeste, Pista &pVC1Leste) {
	std::cout << "\n\n\n\n          >RESULTADOS< \n";
	std::cout << "~~~~~~~~~~Pistas Fonte~~~~~~~~~~~~~~ \n";
	std::cout << "VO1Leste -> Entraram: " << pVO1Leste.getCarrosEntraram() << " | " << "Sairam: " << pVO1Leste.getCarrosSairam() << " \n";
	std::cout << "VN1Sul   -> Entraram: " << pVN1Sul.getCarrosEntraram() << " | " << "Sairam: " << pVN1Sul.getCarrosSairam() << " \n";
	std::cout << "VS1Norte -> Entraram: " << pVS1Norte.getCarrosEntraram() << " | " << "Sairam: " << pVS1Norte.getCarrosSairam() << " \n";
	std::cout << "VN2Sul   -> Entraram: " << pVN2Sul.getCarrosEntraram() << " | " << "Sairam: " << pVN2Sul.getCarrosSairam() << " \n";
	std::cout << "VS2Norte -> Entraram: " << pVS2Norte.getCarrosEntraram() << " | " << "Sairam: " << pVS2Norte.getCarrosSairam() << " \n";
	std::cout << "VL1Oeste -> Entraram: " << pVL1Oeste.getCarrosEntraram() << " | " << "Sairam: " << pVL1Oeste.getCarrosSairam() << " \n";
	std::cout << "------------------------------------ \n \n";
	std::cout << "~~~~~~~~~~Pistas Centro~~~~~~~~~~~~~ \n";
	std::cout << "VC1Oeste -> Entraram: " << pVC1Oeste.getCarrosEntraram() << " | " << "Sairam: " << pVC1Oeste.getCarrosSairam() << " \n";
	std::cout << "VC1Leste -> Entraram: " << pVC1Leste.getCarrosEntraram() << " | " << "Sairam: " << pVC1Leste.getCarrosSairam() << " \n";
	std::cout << "------------------------------------ \n \n";
	std::cout << "~~~~~~~~~~Pistas Sumidouro~~~~~~~~~~ \n";
	std::cout << "VO1Oeste -> Entraram: " << pVO1Oeste.getCarrosEntraram() << " | " << "Sairam: " << pVO1Oeste.getCarrosSairam() << " \n";
	std::cout << "VN1Norte -> Entraram: " << pVN1Norte.getCarrosEntraram() << " | " << "Sairam: " << pVN1Norte.getCarrosSairam() << " \n";
	std::cout << "VS1Sul   -> Entraram: " << pVS1Sul.getCarrosEntraram() << " | " << "Sairam: " << pVS1Sul.getCarrosSairam() << " \n";
	std::cout << "VN2Norte -> Entraram: " << pVN2Norte.getCarrosEntraram() << " | " << "Sairam: " << pVN2Norte.getCarrosSairam() << " \n";
	std::cout << "VS2Sul   -> Entraram: " << pVS2Sul.getCarrosEntraram() << " | " << "Sairam: " << pVS2Sul.getCarrosSairam() << " \n";
	std::cout << "VL1Leste -> Entraram: " << pVL1Leste.getCarrosEntraram() << " | " << "Sairam: " << pVL1Leste.getCarrosSairam() << " \n";
	std::cout << "------------------------------------ \n\n";
	std::cout << "\n\n\n";
}

int Gui::perguntarTempoExecucaoTotal() {
	std::cout << "\nQuanto tempo(em segundos) deseja rodar a simulacao? " << std::endl;
	std::cout << "R: ";
	double i;
	std::cin >> i;
	return (int)i;
}

int Gui::perguntarTempoTrocaSemaforo() {
	std::cout << "\nQuanto tempo(em segundos) para alternar os semaforos? " << std::endl;
	std::cout << "R: ";
	double i;
	std::cin >> i;
	return (int)i;
}
