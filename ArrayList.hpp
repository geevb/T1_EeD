// Copyright [2017] <Getulio Beninca>
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>  // C++ Exceptions

namespace structures {

	template<typename T>

	//! Classe Array Lista
	/* Defini��o da Classe Array List */
	class ArrayList {
	public:
		//! Construtor
		/* Utilizando vari�vel hard coded */
		ArrayList() {
			max_size_ = DEFAULT_MAX;
			contents = new T[max_size_];
			size_ = -1;
		}

		//! Construtor
		/* Utilizando par�metro */
		explicit ArrayList(std::size_t max_size) {
			max_size_ = max_size;
			contents = new T[max_size_];
			size_ = -1;
		}

		//! Destrutor
		/* Desaloca mem�ria */
		~ArrayList() {
			delete[] contents;
		}

		//! Limpa Fila
		/* Retorna o valor de tamanho para -1 */
		void clear() {
			size_ = -1;
		}

		//! M�todo Push back
		/* Insere no final da fila */
		void push_back(const T& data) {
			insert(data, size_ + 1);
		}

		//! M�todo Push Front
		/* Insere no in�cio da fila */
		void push_front(const T& data) {
			insert(data, 0);
		}

		//! M�todo Insert
		/* Insere um valor numa determinada posi��o */
		void insert(const T& data, std::size_t index) {
			T posicao;
			if (full()) {
				throw std::out_of_range("Lista Cheia!");
			}
			else if ((index > size_ + 1) || (index < 0)) {
				throw std::out_of_range("Posi��o Inv�lida!");
			}
			else {
				size_ += 1;
				posicao = size_;
				while (posicao > index) {
					contents[posicao] = contents[posicao - 1];
					--posicao;
				}
				contents[index] = data;
			}
		}

		//! M�todo Insert Sorted
		/* Insere um valor em ordem */
		void insert_sorted(const T& data) { }

		//! M�todo Pop
		/* Retira um elemento da posi��o */
		T pop(std::size_t index) {
			T posicao = index;
			T num = 0;
			if (empty()) {
				throw std::out_of_range("Lista Vazia");
			}
			else if ((index > size_) || (index < 0)) {
				throw std::out_of_range("Posicao Inv�lida");
			}
			else {
				num = contents[index];
				while (posicao <= size_) {
					contents[posicao] = contents[posicao + 1];
					posicao++;
				}
				size_ -= 1;
				return num;
			}
		}

		//! M�todo Pop back
		/* Retira elemento do fim da fila */
		T pop_back() {
			if (empty()) {
				throw std::out_of_range("Lista Vazia");
			}
			else {
				size_ -= 1;
			}
			return contents[size_ + 1];
		}

		//! M�todo Pop front
		/* Retira elemento do in�cio fila */
		T pop_front() {
			T num = 0;
			T posicao = 0;
			if (empty()) {
				throw std::out_of_range("Lista est� vazia!");
			}
			else {
				num = contents[0];
				while (posicao <= size_) {
					contents[posicao] = contents[posicao + 1];
					posicao++;
				}
			}
			size_ -= 1;
			return num;
		}

		//! M�todo Remove
		/* Retira um determinado elemento da fila */
		void remove(const T& data) {
			T posicao = 0;
			if (empty()) {
				throw std::out_of_range("Lista Vazia");
			}
			else {
				while (posicao <= size_) {
					if (contents[posicao] == data) {
						T posicaoAux = posicao;
						while (posicaoAux <= size_) {
							contents[posicao] = contents[posicao + 1];
							posicaoAux++;
						}
					}
					else {
						posicao++;
					}
				}
				size_ -= 1;
			}
		}

		//! M�todo Full
		/* Verifica se a Lista est� cheia */
		bool full() const {
			return (size_ == max_size_ - 1);
		}

		//! M�todo Empty
		/* Verifica se a lista est� vazia */
		bool empty() const {
			return (size_ == -1);
		}

		//! M�todo Contains
		/* Verifica se a lista cont�m determinado elemento */
		bool contains(const T& data) const {
			T posicao = 0;
			while (posicao <= size_) {
				if (contents[posicao] == data) {
					return true;
				}
				else { posicao++; }
			}
			return false;
		}

		//! M�todo Find
		/* Retorna a posi��o de determinado elemento */
		std::size_t find(const T& data) const {
			T posicao = 0;
			while (posicao <= size_) {
				if (contents[posicao] == data) {
					break;
				}
				else {
					posicao++;
				}
			}
			return posicao;
		}

		//! M�todo Size
		/* Mostra o tamanho atual da Lista */
		std::size_t size() const {
			return size_ + 1;
		}

		//! M�todo Max
		/* Mostra o tamanho total da lista */
		std::size_t max_size() const {
			return max_size_;
		}

		//! M�todo At
		/* Retorna o valor contido na posicao espec�fica da lista */
		T& at(std::size_t index) {
			if ((index >= 0) && (index <= size_)) {
				return contents[index];
			}
			else {
				throw std::out_of_range("Posicao inv�lida!");
			}
		}

		//! M�todo Operator
		/* Efetua a sobrecarga do operador [] */
		T& operator[](std::size_t index) { return contents[index]; }

		//! M�todo At
		/* Retorna o valor contido na posicao espec�fica da lista */
		const T& at(std::size_t index) const {
			if ((index >= 0) && (index <= size_)) {
				return contents[index];
			}
			else {
				throw std::out_of_range("Posicao inv�lida!");
			}
		}

		//! M�todo Operator
		/* Efetua a sobrecarga do operador [] */
		const T& operator[](std::size_t index) const { return contents[index]; }

	private:
		T* contents;
		std::size_t size_;
		std::size_t max_size_;

		static const auto DEFAULT_MAX = 10u;
	};

}  // namespace structures

#endif
