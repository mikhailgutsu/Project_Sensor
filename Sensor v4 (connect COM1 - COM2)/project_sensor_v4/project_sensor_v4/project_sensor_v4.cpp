//------- HEADER INCLUDE
#include "print.h"										
#include "com.h"										

//------- MAIN
int main()
{
	Print obj;											
	COM comScan;	

	//--- TempVar for COM PORT 
	int m_temp;											

	loop()												
	{
		m_temp = comScan.scan();						
		obj.sensor(m_temp);								
	}

	return 0;
}
//-------- END