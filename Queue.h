#ifndef SDDS_QUEUE_H__
#define SDDS_QUEUE_H__

#include <iostream>

#include "Dictionary.h"

namespace sdds
{
	template <class T, unsigned int CAPACITY>


	class Queue
	{
		T m_queue[CAPACITY]; //a statistically allocated array
		unsigned int m_count{ 0 }; //count of the current number of object stored in the queue

		static T m_dummy; //class member

	public:

		virtual bool push(const T& item)
		{
			if (m_count >= CAPACITY)
				return false;

			m_queue[m_count] = item;
			m_count++;

			return true;
		}

		T pop()
		{
			T temp = m_queue[0];

			for (unsigned int i = 1; i < m_count; i++)
				m_queue[i - 1] = m_queue[i];

			m_count--;

			return temp;
		}

		//a query that returns the current number of elements in the queue
		unsigned int size()
		{
			return m_count;
		}

		//a query that receives as the parameter an output stream and inserts into the stream all items from the collection
		void display(std::ostream& ostr = std::cout)
		{
			ostr << "----------------------\n| ";
			ostr << "Dictionary Content |\n----------------------" << std::endl;

			for (unsigned int i = 0; i < m_count; i++)
				ostr << m_queue[i] << std::endl;

			ostr << "----------------------\n";
		}

		//a query that returns a copy of the element stored in the collection at the specified index
		T operator[](unsigned int index)
		{
			if (index >= 0 && index < m_count) //valid index
				return m_queue[index];

			return m_dummy;
		}

		//empty body destructor
		virtual ~Queue() {}

	};


	template<class T, unsigned int CAPACITY>
	T Queue<T, CAPACITY>::m_dummy{};

	template<>
	Dictionary Queue<Dictionary, 100u>::m_dummy{ "Empty Term", "Empty Substitute"};

	//u = unsigned int
}

#endif 


