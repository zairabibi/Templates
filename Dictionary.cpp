#include <string>
#include "Dictionary.h"

namespace sdds
{
	Dictionary::Dictionary()
	{
		m_term = "";
		m_definition = "";
	}

	void Dictionary::display(std::ostream& out) const
	{
		out << std::setw(20) << std::right << m_term << ": " << m_definition;
	}

	bool Dictionary::operator==(const Dictionary& p)
	{
		return getTerm() == p.getTerm();
	}

	std::ostream& operator <<(std::ostream& out, const Dictionary& d)
	{
		d.display(out);
		return out;
	}
}