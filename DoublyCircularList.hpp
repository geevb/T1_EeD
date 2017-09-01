#pragma once
//  Copyright [2017] Getúlio Benincá

#include <cstdint>
#include <stdexcept>

//! Class Lista Circular Duplamente Encadeada
template<typename T>
class DoublyCircularList {
public:
	DoublyCircularList() {
		size_ = 0;
		head = nullptr;
	}

	~DoublyCircularList() {}

	//! Método Limpa Lista
	void clear() {
		size_ = 0;
	}

	//! Método Insere no fim
	void push_back(const T& data) {
		insert(data, size_);
	}

	//! Método Insere no início
	void push_front(const T& data) {
		insert(data, 0);
	}

	//! Método Insere na posição
	void insert(const T& data, std::size_t index) {
		if (valid_position(index)) { throw std::out_of_range("Pos.Invld!"); }
		unsigned int param = index;
		Node* aux = head;
		Node* fim = head;
		Node* elemento = new Node(data, nullptr, nullptr);
		if (elemento == nullptr) { throw std::out_of_range("Lista Cheia!"); }
		if (index == 0) {
			for (unsigned int i = 0; i < param - 1; ++i) {
				fim = fim->next();
			}
			elemento->next(head);
			elemento->prev(fim);
			head = elemento;
			size_++;
		}
		else {
			for (unsigned int i = 0; i < index - 1; ++i) {
				aux = aux->next();
			}
			if (index == size_) {
				aux->next(elemento);
				elemento->prev(aux);
				elemento->next(head);
				size_++;
			}
			else {
				elemento->next(aux->next());
				aux->next(elemento);
				elemento->prev(aux);
				aux = aux->next();
				aux->prev(elemento);
				size_++;
			}
		}
	}

	//! Método Insere em ordem
	void insert_sorted(const T& data) {}

	//! Método Verifica posição válida
	bool valid_position(std::size_t index) {
		return (index < 0 || index > size_);
	}

	//! Método Retira da posição
	T pop(std::size_t index) {
		unsigned int param = index;
		if (empty()) { throw std::out_of_range("Lista vazia!"); }
		if (valid_position(param)) { throw std::out_of_range("Pos.Invld!"); }
		T dado;
		Node* aux = head;
		Node* fim = head;
		for (unsigned int i = 0; i < param - 1; ++i) {
			aux = aux->next();
		}
		if (param == 0) {
			for (unsigned int i = 0; i < size_ - 1; ++i) {
				fim = fim->next();
			}
			dado = aux->data();
			head = aux->next();
			fim->next(head);
			size_--;
			return dado;
		}
		else if (param == size_) {
			dado = aux->data();
			fim->prev(aux);
			aux->next(head);
			size_--;
			return dado;
		}
		else {
			dado = aux->data();
			Node* anterior = aux->prev();
			Node* proximo = aux->next();
			anterior->next(proximo);
			proximo->prev(anterior);
			size_--;
			return dado;
		}
	}

	//! Método Retira do fim
	T pop_back() {
		return pop(size_);
	}

	//! Método Retira do Início
	T pop_front() {
		return pop(0);
	}

	//! Método Retira elemento
	void remove(const T& data) {
		pop(find(data + 1));
	}

	//! Método Lista Vazia
	bool empty() const {
		return (size_ == 0);
	}

	//! Método Contém
	bool contains(const T& data) const {
		if (empty()) { throw std::out_of_range("Lista vazia!"); }
		Node* aux = head;
		for (int i = 0; i < size_; ++i) {
			if (aux->data() == data) {
				return true;
			}
			aux = aux->next();
		}
		return false;
	}

	//! Método Na posição
	T& at(std::size_t index) {
		int param = index;
		if (valid_position(param)) { throw std::out_of_range("Pos.Invld!"); }
		if (empty()) { throw std::out_of_range("Lista vazia!"); }
		Node* aux = head;
		for (int i = 0; i < param; ++i) {
			aux = aux->next();
		}
		return aux->data();
	}

	//! Método na posição
	const T& at(std::size_t index) const {
		int param = index;
		if (valid_position(param)) { throw std::out_of_range("Pos.Invld!"); }
		if (empty()) { throw std::out_of_range("Lista vazia!"); }
		Node* aux = head;
		for (int i = 0; i < param; ++i) {
			aux = aux->next();
		}
		return aux->data();
	}

	//! Método Encontrar elemento
	std::size_t find(const T& data) const {
		if (empty()) {
			throw std::out_of_range("Lista vazia!");
		}
		else {
			Node* aux = head;
			for (int i = 0; i < size_; i++) {
				if (aux->data() == data) {
					return i;
				}
				else {
					aux = aux->next();
				}
			}
			return size_;
		}
	}

	//! Método Tamanho da lista
	std::size_t size() const { return size_; }

private:
	class Node {
	public:
		explicit Node(const T& data) :data_{ data } {}
		Node(const T& data, Node* next) :data_{ data }, next_{ next } {}
		Node(const T& data, Node* prev, Node* next) :data_{ data },
			prev_{ prev },
			next_{ next }
		{}

		T& data() { return data_; }
		const T& data() const { return data_; }

		Node* prev() { return prev_; }
		const Node* prev() const { return prev_; }

		void prev(Node* node) { prev_ = node; }

		Node* next() { return next_; }
		const Node* next() const { return next_; }

		void next(Node* node) { next_ = node; }

	private:
		T data_;
		Node* prev_;
		Node* next_;
	};

	Node* head;
	std::size_t size_;
};


