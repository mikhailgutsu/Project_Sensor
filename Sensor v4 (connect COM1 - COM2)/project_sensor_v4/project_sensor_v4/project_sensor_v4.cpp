//--------------------------
#include "print.h"										//<		Include print.h file
#include "com.h"										//<		Include com.h file

//--------------------------
int main()
{
	Print obj;											//<		Create obj from Print Class
	COM comScan;										//<		Create obj from COM Class
	int m_temp;											//<		Temporary variable for COM data

	loop()												//<		Defined Loop for(;;)
	{
		m_temp = comScan.scan();						//<		Insert data from COM Port to temp var
		obj.sensor(m_temp);								//<		Print on XY axe
	}

	return 0;
}
//--------------------------