/*#ifndef MILIVOLTY_H
#define MILIVOLTY_H

#include "oscyloskop.h"
class Milivolty
{
private:
	int m_milivolty;
public:
	Milivolty(int milivolty = 0)
	{
		m_milivolty = milivolty;
	}
	operator Oscyloskop()
	{
		return Oscyloskop (m_milivolty * 100);
	}

};
#endif*/
