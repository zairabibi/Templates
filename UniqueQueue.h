#ifndef SDDS_UNIQUEQUEUE_H__
#define SDDS_UNIQUEQUEUE_H__

#include <iostream>

#include "Queue.h"

namespace sdds
{
	template <class T, unsigned CAPACITY = 100>

	class UniqueQueue : public Queue<T, 100>
	{

	public:

		//overriding Queue::push() 
		bool push(const T& item)
		{
			bool ifExists = false;

			//if the item already exists in the Queue, ifExists is true
			for (unsigned x = 0; x < this->size(); x++)
			{
				if (this->operator[](x) == item)
				{
					ifExists = true;
					break;
				}
			}

			//if the item already exists, no need to add it to the queue
			if (ifExists)
				return false;

			//else push into the queue
			else
				return Queue<T, CAPACITY>::push(item);
		}

	};

	//Specialization

	//for T = double
	template<>
	bool UniqueQueue<double>::push(const double& item)
	{
		bool ifExists = false;

		for (unsigned int x = 0; x < this->size(); x++)
		{
			if (fabs(this->operator[](x) - item) <= 0.005)
			{
				ifExists = true;
				break;
			}
		}

		if (ifExists)
			return false;

		else
			return Queue<double, 100>::push(item);
	}
}

#endif 


