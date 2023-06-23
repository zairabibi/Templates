#ifndef SDDS_QDICTIONARY_H
#define SDDS_QDICTIONARY_H

#include <iostream>
#include <iomanip>

namespace sdds
{

	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};
	public:
		const std::string& getTerm() const { return m_term; }
		const std::string& getDefinition() const { return m_definition; }
		Dictionary(const std::string& term, const std::string& definition) 
		{
			m_term = term;
			m_definition = definition;
		}

		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.

		Dictionary(); //default constructor to initialize a Dictionary
		void display(std::ostream&) const; //to display a Dictionary in the required format
		bool operator==(const Dictionary&); //== operator overloaded to compare the keys of two DIctionaries
	};

	std::ostream& operator<<(std::ostream&, const Dictionary&); // insertion operator to insert a Dictionary object into the stream

}
#endif // !DICTIONARY_H
