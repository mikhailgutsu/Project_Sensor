#pragma once
#include <iostream>
#include <windows.h>
#include <ctime>
#include <chrono>

#define Lines 20
#define Columns 120
#define loop() for(;;)

class Print
{
private:
	std::string Graph[Lines][Columns];						//<
	int counter = 1;										//<
	int temp;												//<
	int forCounter_i = 0;									//<
	int forCounter_j = 0;									//<

	void setGraph();										//< 
	void srandGraph(int m_temp, int counter);				//<
	void printGraph();										//<
	void moveGraph();										//<
	void process();											//<

public:
	void sensor(int m_temp);								//<
};
