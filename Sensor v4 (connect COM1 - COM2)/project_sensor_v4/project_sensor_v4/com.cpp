#include "com.h"

int COM::com1()
{
    LPCTSTR sPortName = L"COM1";

    hSerial = ::CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    //////////////////////////////////////////////////////
    if (hSerial == INVALID_HANDLE_VALUE)
    {
        if (GetLastError() == ERROR_FILE_NOT_FOUND)
        {
            std::cout << "serial port does not exist.\n";
        }
        std::cout << "some other error occurred.\n";
    }
    ///////////////////////////////////////////////////////
    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams))
    {
        std::cout << "getting state error\n";
    }

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams))
    {
        std::cout << "error setting serial port state\n";
    }

    char data[] = "Hello from C++";  // 
    DWORD dwSize = sizeof(data);   // 
    DWORD dwBytesWritten;    // 

    BOOL iRet = WriteFile(hSerial, data, dwSize, &dwBytesWritten, NULL);

    std::cout << dwSize << " Bytes in string. " << dwBytesWritten << " Bytes sended. " << std::endl;

    while (1)
    {
        ReadCOM();
    }
    return 0;
}

void COM::ReadCOM(void)
{
    DWORD iSize;

    while (true)
    {
        ReadFile(hSerial, &sReceivedChar, 1, &iSize, 0);  // ïîëó÷àåì 1 áàéò

        if (iSize > 0)   // åñëè ÷òî-òî ïðèíÿòî, âûâîäèì
            std::cout << sReceivedChar;
    }
}

int COM::scan()
{
    return com1();
}