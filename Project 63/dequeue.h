#pragma once
#include<iostream>
#include <initializer_list>

namespace rut
{
	template <typename T> class dequeueue;

	/*
	*@brief Оператор "<<" для класса дэк
	*@tparam T Тип хранимых данных при помощи дэка
	*@param output Поток вывода
	*@param deque Дэк
	*@return Изменённый поток вывода
	*/
	template <typename T>
	std::ostream& operator << (std::ostream& output, const rut::dequeueue<T>& deque);

	/*
	*@brief Класс дэк
	*@tparam T Тип хранимых данных при помощи дэка
	*/
	template <typename T>
	class dequeueue
	{
	private:
		/*
		*@brief Структура узла
		*/
		struct Node
		{
			T data;
			Node* next;
			Node* prev;
			Node(T value) :data(value), next(nullptr), prev(nullptr) {}
		};

		/*
		*@brief Узел головы дэка
		*/
		Node* head;

		/*
		*@brief Узел хвоста дэка
		*/
		Node* tail;

		/*
		*@brief Размер дэка
		*/
		size_t size;

	public:

		/*
		*@brief Инициализирует объект типа ::Deque<T>
		*/
		dequeueue();

		/*
		*@brief Инициализирует объект типа ::Deque<T> из списка
		*@param list Список из объектов типа T
		*/
		dequeueue(std::initializer_list<T> list);

		/*
		*@brief Конструктор копирования объекта типа ::Deque<T>
		*@param other Другой дэк
		*/
		dequeueue(const dequeueue& other);

		/*
		*@brief Конструктор перемещения объекта типа ::Deque<T>
		*@param other Другой дэк
		*/
		dequeueue(dequeueue&& other) noexcept;

		/*
		*@brief Деструктор. Разрушает объекта типа ::Deque<T>
		*/
		~dequeueue();

		/*
		*@brief Оператор присваивания для дэка типа ::Deque<T>
		*@param other Другой дэк
		*@return Возвращает дэк, равный other
		*/
		dequeueue& operator=(const dequeueue& other);

		/*
		*@brief Оператор присваивания перемещением для дэка типа ::Deque<T>
		*@param other Другой дэк
		*@return Возвращает дэк, равный other
		*/
		dequeueue& operator = (dequeueue&& other) noexcept;

		/*
		*@brief Функция удаления переднего узла дэка
		*/
		void pop_front();

		/*
		*@brief Функция удаления последнего узла дэка
		*/
		void pop_back();

		/*
		*@brief Функция добавления узла спереди дэка
		*@param value Значение, которое будет принимать новый узел типа Т
		*/
		void push_front(const T value);

		/*
		*@brief Функция добавления узла в конце дэка
		*@param value Значение, которое будет принимать новый узел
		*/
		void push_back(const T value);

		/*
		*@brief Функция для получения значения переднего узла дэка
		*@return Значение переднего узла типа T
		*/
		T front();

		/*
		*@brief Функция для получения значения последнего узла дэка
		*@return Значение последнего узла типа T
		*/
		T back();

		/*
		*@brief Функция проверки на пустоту дэка типа ::Deque<T>
		*@return true если дэк не содержит каких-либо элементов, иначе false
		*/
		bool IsEmpty();
	};

	template <typename T>
	dequeueue<T>::dequeueue() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

	template <typename T>
	dequeueue<T>::dequeueue(std::initializer_list<T> list)
	{
		for (auto& x : list)
		{
			push_back(x);
		}
	}

	template <typename T>
	dequeueue<T>::dequeueue(const dequeueue& other)
	{
		Node* temp = other.head;
		while (temp != nullptr)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}

	template <typename T>
	dequeueue<T>::dequeueue(dequeueue&& other) noexcept : head{ other.head }, tail{ other.tail }, size{ other.size }
	{
		other.head = other.tail = nullptr;
		other.size = 0;
	}

	template <typename T>
	dequeueue<T>::~dequeueue()
	{
		while (!(IsEmpty()))
		{
			pop_front();
		}
	}

	template <typename T>
	dequeueue<T>& dequeueue<T>::operator=(const dequeueue& other)
	{
		if (this != &other)
		{
			dequeueue temp(other);
			std::swap(this->head, temp.head);
			std::swap(this->tail, temp.tail);
			std::swap(this->size, temp.size);
		}
		return *this;
	}

	template <typename T>
	dequeueue<T>& dequeueue<T>::operator = (dequeueue&& other) noexcept
	{

		if (this == &other)
		{
			return *this;
		}
		this->head = other.head;
		this->tail = other.tail;
		this->size = other.size;
		other.head = other.tail = nullptr;
		other.size = 0;
		return *this;
	}

	template <typename T>
	void dequeueue<T>::pop_front()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("выход за пределы дэка");
		}
		if (this->head == this->tail)
		{
			this->head = this->tail = nullptr;
		}
		else
		{
			this->head = this->head->next;
			this->head->prev = nullptr;
		}
		--this->size;
	}

	template <typename T>
	void dequeueue<T>::pop_back()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("выход за пределы дэка");
		}
		if (this->head == this->tail)
		{
			this->head = this->tail = nullptr;
		}
		else
		{
			this->tail = this->tail->prev;
			this->tail->next = nullptr;
		}
		--this->size;
	}

	template <typename T>
	void dequeueue<T>::push_front(const T value)
	{
		Node* frontNode = new Node(value);
		if (IsEmpty())
		{
			this->head = this->tail = frontNode;
		}
		else
		{
			this->head->prev = frontNode;
			frontNode->next = this->head;
			this->head = frontNode;
		}
		++this->size;
	}

	template <typename T>
	void dequeueue<T>::push_back(const T value)
	{
		Node* backNode = new Node(value);
		if (IsEmpty())
		{
			this->head = this->tail = backNode;
		}
		else
		{
			this->tail->next = backNode;
			backNode->prev = this->tail;
			this->tail = backNode;
		}
		++this->size;
	}

	template <typename T>
	T dequeueue<T>::front()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("выход за границы дэка");
		}
		return this->head->data;
	}

	template <typename T>
	T dequeueue<T>::back()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("выход за границы дэка");
		}
		return this->tail->data;
	}

	template <typename T>
	bool dequeueue<T>::IsEmpty()
	{
		return this->size == 0;
	}

	template <typename T>
	std::ostream& operator << (std::ostream& output, const dequeueue<T>& deque)
	{
		dequeueue temp = deque;
		while (!(temp.IsEmpty()))
		{
			output << temp.front() << std::endl;
			temp.pop_front();
		}
		return output;
	}
}