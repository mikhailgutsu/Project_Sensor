#pragma once
#include <iostream>
#include <windows.h>
#include <ctime>
#include <chrono>
#include <windows.h>
#include "tchar.h"

//Обработчик COM порта
HANDLE hSerial;


class COM
{
private:
    char sReceivedChar;
    int  com1();
    void ReadCOM(void);
public:
    int scan();
};