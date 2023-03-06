//------- HEADER INCLUDE
#pragma once
#include <iostream>
#include <windows.h>
#include <ctime>
#include <chrono>
#include <windows.h>
#include "tchar.h"

//------- COM class
class COM
{
//-------- Protected zone
private:
    //-------- Open hSerial Port
    HANDLE hSerial;

    //-------- Methods
    char sReceivedChar;
    int  com1();
    void ReadCOM(void);

 //-------- Public zone
public:
    int scan(); //<     Start
};