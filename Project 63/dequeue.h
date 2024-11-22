#pragma once
#include<iostream>
#include <initializer_list>

namespace rut
{
	template <typename T> class dequeueue;

	/*
	*@brief �������� "<<" ��� ������ ���
	*@tparam T ��� �������� ������ ��� ������ ����
	*@param output ����� ������
	*@param deque ���
	*@return ��������� ����� ������
	*/
	template <typename T>
	std::ostream& operator << (std::ostream& output, const rut::dequeueue<T>& deque);

	/*
	*@brief ����� ���
	*@tparam T ��� �������� ������ ��� ������ ����
	*/
	template <typename T>
	class dequeueue
	{
	private:
		/*
		*@brief ��������� ����
		*/
		struct Node
		{
			T data;
			Node* next;
			Node* prev;
			Node(T value) :data(value), next(nullptr), prev(nullptr) {}
		};

		/*
		*@brief ���� ������ ����
		*/
		Node* head;

		/*
		*@brief ���� ������ ����
		*/
		Node* tail;

		/*
		*@brief ������ ����
		*/
		size_t size;

	public:

		/*
		*@brief �������������� ������ ���� ::Deque<T>
		*/
		dequeueue();

		/*
		*@brief �������������� ������ ���� ::Deque<T> �� ������
		*@param list ������ �� �������� ���� T
		*/
		dequeueue(std::initializer_list<T> list);

		/*
		*@brief ����������� ����������� ������� ���� ::Deque<T>
		*@param other ������ ���
		*/
		dequeueue(const dequeueue& other);

		/*
		*@brief ����������� ����������� ������� ���� ::Deque<T>
		*@param other ������ ���
		*/
		dequeueue(dequeueue&& other) noexcept;

		/*
		*@brief ����������. ��������� ������� ���� ::Deque<T>
		*/
		~dequeueue();

		/*
		*@brief �������� ������������ ��� ���� ���� ::Deque<T>
		*@param other ������ ���
		*@return ���������� ���, ������ other
		*/
		dequeueue& operator=(const dequeueue& other);

		/*
		*@brief �������� ������������ ������������ ��� ���� ���� ::Deque<T>
		*@param other ������ ���
		*@return ���������� ���, ������ other
		*/
		dequeueue& operator = (dequeueue&& other) noexcept;

		/*
		*@brief ������� �������� ��������� ���� ����
		*/
		void pop_front();

		/*
		*@brief ������� �������� ���������� ���� ����
		*/
		void pop_back();

		/*
		*@brief ������� ���������� ���� ������� ����
		*@param value ��������, ������� ����� ��������� ����� ���� ���� �
		*/
		void push_front(const T value);

		/*
		*@brief ������� ���������� ���� � ����� ����
		*@param value ��������, ������� ����� ��������� ����� ����
		*/
		void push_back(const T value);

		/*
		*@brief ������� ��� ��������� �������� ��������� ���� ����
		*@return �������� ��������� ���� ���� T
		*/
		T front();

		/*
		*@brief ������� ��� ��������� �������� ���������� ���� ����
		*@return �������� ���������� ���� ���� T
		*/
		T back();

		/*
		*@brief ������� �������� �� ������� ���� ���� ::Deque<T>
		*@return true ���� ��� �� �������� �����-���� ���������, ����� false
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
			throw std::out_of_range("����� �� ������� ����");
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
			throw std::out_of_range("����� �� ������� ����");
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
			throw std::out_of_range("����� �� ������� ����");
		}
		return this->head->data;
	}

	template <typename T>
	T dequeueue<T>::back()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("����� �� ������� ����");
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