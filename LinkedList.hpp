//  "Copyright [2017] <Getúlio Benincá>"
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>

// BREAK numLinha
// RUN p/ executar o código
// F6 p/ interar cada comando
// F5 p/ entrar dentro do método
// Selecionar variavel e pressionar display p/ visualizar conteúdo

	template<typename T>
	//! Método Insert
	/* Insere um valor numa determinada posição */
	class LinkedList {
	public:
		LinkedList() {
			head = NULL;
			size_ = 0;
		}  // construtor padrão

		   //! Método Insert
		   /* Insere um valor numa determinada posição */
		~LinkedList() { }  // destrutor

		//! Método Insert
		/* Insere um valor numa determinada posição */
		void clear() {
			/*for (int i = size_; size_ > 0; i--) {
			pop_back(i);
			}*/
			size_ = 0;
		}  // limpar lista

		   //! Método Insert
		   /* Insere um valor numa determinada posição */
		void push_back(const T& data) {
			insert(data, size_);
		}

		//! Método Insert
		/* Insere um valor numa determinada posição */
		void push_front(const T& data) {
			T paramData = data;
			Node *novo = new Node(paramData, head);
			if (novo == nullptr) {
				throw std::out_of_range("Lista cheia!");
			}
			else {
				head = novo;
				size_++;
			}
		}  // inserir no início

		   //! Método Insert
		   /* Insere um valor numa determinada posição */
		void insert(const T& data, std::size_t index) {
			Node *novo;
			Node *anterior;
			if (index < 0 || index > size_) {
				throw std::out_of_range("Posicao inválida!");
			}
			else if (index == 0) {
				return push_front(data);
			}
			else {
				novo = new Node(data, NULL);
				if (novo == nullptr) {
					throw std::out_of_range("Lista Cheia!");
				}
				else {
					anterior = head;
					for (int i = 0; i < index - 1; i++) {
						anterior = anterior->next();
					}
					novo->next(anterior->next());
					anterior->next(novo);
					size_++;
				}
			}
		}  // inserir na posição

		   //! Método Insert Sorted, ALTERAR
		   /* Insere um valor numa determinada posição */
		void insert_sorted(const T& data) {
			if (empty()) {
				push_front(data);
			}
			else {}
			T paramData = data;
			Node *novo = new Node(paramData, head);
			if (novo == nullptr) {
				throw std::out_of_range("Lista cheia!");
			}
			else {
				head = novo;
				size_++;
			}
		}  // inserir em ordem

		   //! Método Insert
		   /* Insere um valor numa determinada posição */
		T& at(std::size_t index) {
			T param = index;
			if (param < 0 || param > size_ + 1) {
				throw std::out_of_range("Posicao Inválida!");
			}
			else {
				Node* aux = head;
				int posicao = 0;
				while (posicao < index) {
					posicao++;
					aux = aux->next();
				}
				return aux->data();
			}
		}

		//! Método Insert
		/* Insere um valor numa determinada posição */
		T pop(std::size_t index) {
			Node *saiu;
			Node *aux;
			T dado;
			if (index == 0) {
				return pop_front();
			}
			else if (size_ == 0) {
				throw std::out_of_range("Lista vazia!");
			}
			else if (index < 0 || index > size_ - 1) {
				throw std::out_of_range("Posicao inválida!");
			}
			else {
				aux = head;
				for (int i = 0; i < index - 1; i++) {
					aux = aux->next();
				}
				saiu = aux->next();
				dado = saiu->data();
				aux->next(saiu->next());
				size_--;
				return dado;
			}
		}

		//! Método Insert
		/* Insere um valor numa determinada posição */
		T pop_back() {
			unsigned int posicao = 1;
			Node* aux;
			T valor;
			if (size_ == 0) {
				throw std::out_of_range("Lista vazia!");
			}
			else {
				aux = head;
				while (posicao < size_) {
					aux = aux->next();
					posicao++;
				}
				valor = aux->data();
				size_--;
				return valor;
			}
		}  // retirar do fim

		   //! Método Insert
		   /* Insere um valor numa determinada posição */
		T pop_front() {
			Node *saiu;
			T volta;
			if (empty()) {
				throw std::out_of_range("Lista Vazia!");
			}
			else {
				saiu = head;
				volta = saiu->data();
				head = saiu->next();
				size_--;
				delete saiu;
				return volta;
			}
		}  // retirar do início

		   //! Método Insert
		   /* Insere um valor numa determinada posição */
		void remove(const T& data) {
			pop(find(data));
		}  // remover específico

		   //! Método Insert
		   /* Insere um valor numa determinada posição */
		bool empty() const {
			return (size_ == 0);
		}  // lista vazia

		   //! Método Insert
		   /* Insere um valor numa determinada posição */
		bool contains(const T& data) const {
			T param = data;
			Node* dado;
			dado = head;
			T posicao = 0;
			while (posicao < size_) {
				if (dado->data() == param) {
					return true;
				}
				else {
					dado = dado->next();
					posicao++;
				}
			}
			return false;
		}  // contém

		   //! Método Insert
		   /* Insere um valor numa determinada posição */
		std::size_t find(const T& data) const {
			if (empty()) {
				throw std::out_of_range("Lista vazia");
			}
			else {
				Node* currentNode = head;
				for (int i = 0; i < size_; i++) {
					if (currentNode->data() >= data) {
						return i;
					}
					currentNode = currentNode->next();
				}
			}
			return size_;
		}  // posição do dado

		   //! Método Insert
		   /* Insere um valor numa determinada posição */
		std::size_t size() const { return size_; }  // tamanho da lista

	private:
		//! Método Insert
		/* Insere um valor numa determinada posição */
		class Node {  // Elemento
		public:
			explicit Node(const T& data) :
				data_{ data }
			{}

			Node(const T& data, Node* next) :
				data_{ data },
				next_{ next }
			{}

			T& data() {  // getter: dado
				return data_;
			}

			const T& data() const {  // getter const: dado
				return data_;
			}

			Node* next() {  // getter: próximo
				return next_;
			}

			const Node* next() const {  // getter const: próximo
				return next_;
			}

			void next(Node* node) {  // setter: próximo
				next_ = node;
			}

			void data(T data) {  // setter: data
				data_ = data;
			}

		private:
			T data_;
			Node* next_{ nullptr };
		};

		Node* end() {  // último nodo da lista
			auto it = head;
			for (auto i = 1u; i < size(); ++i) {
				it = it->next();
			}
			return it;
		}

		Node* head{ nullptr };
		std::size_t size_{ 0u };
	};

#endif

