#include "Printing.h"
#include "com.h"

int main()
{
	Print obj;
	COM comScan;
	int m_temp;

	loop()
	{
		m_temp = comScan.scan();
		obj.sensor(m_temp);
	}

	return 0;
}