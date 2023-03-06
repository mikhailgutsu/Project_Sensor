//------- USER Includes
#include "com.h"

/*********************************************************
             Communication from COM1 -> Com2
*********************************************************/
int COM::com1()
{
    //------------ Open L"COM PORT 1"
    LPCTSTR sPortName = L"COM1";

    //------------ Create hSerial_File
    hSerial = ::CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    //------------ CheckLoop
    if (hSerial == INVALID_HANDLE_VALUE)
    {
        if (GetLastError() == ERROR_FILE_NOT_FOUND)                       //< IF Serial Port is close
        {
            std::cout << "serial port does not exist.\n";
        }
        std::cout << "some other error occurred.\n";
    }
    //------------ End ChackLoop

    //------------ Clear Params and = with 0
    DCB dcbSerialParams = { 0 };

    //------------ Lenght = sizeof params
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    //------------ If params is empty 
    if (!GetCommState(hSerial, &dcbSerialParams))
    {
        std::cout << "getting state error\n";
    }

    //------------ Setings
    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    //------------ If params is empty 
    if (!SetCommState(hSerial, &dcbSerialParams))
    {
        std::cout << "error setting serial port state\n";
    }

    //------------ INIT
    char data[] = "Hello from C++";  
    DWORD dwSize = sizeof(data);   
    DWORD dwBytesWritten;     

    //------------ Write file
    BOOL iRet = WriteFile(hSerial, data, dwSize, &dwBytesWritten, NULL);

    //------------ COUT
    std::cout << dwSize << " Bytes in string. " << dwBytesWritten << " Bytes sended. " << std::endl;

    //------------ Loop
    while (1)
    {
        ReadCOM();
    }
    return 0;
}

/****************************************************************
                Read data from COM PORT
****************************************************************/
void COM::ReadCOM(void)
{
    //------------- Open
    DWORD iSize;

    while (true)
    {
        //-------- Reading file from char_chr
        ReadFile(hSerial, &sReceivedChar, 1, &iSize, 0); 

        if (iSize > 0)   //< If isn't empty
            std::cout << sReceivedChar;
    }
}

//----------- START
int COM::scan()
{
    return com1();
}