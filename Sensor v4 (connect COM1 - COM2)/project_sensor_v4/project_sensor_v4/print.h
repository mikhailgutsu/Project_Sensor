//------- HEADER INCLUDE
#pragma once
#include <iostream>
#include <windows.h>
#include <ctime>
#include <chrono>

//------- USER DEFINES
#define Lines 20											//<		Lines OY axe
#define Columns 120											//<		Columns OX axe
#define loop() for(;;)

//------- Print class
class Print
{
private:
	std::string Graph[Lines][Columns];						//<		Predefinition of our graph[20][120]

	int counter = 1;										//<		Firts Pos of counter (for '*')
	int temp;												//<		Temp variable 

	//---------- Temp vars for alghorithm
	int forCounter_i = 0;									
	int forCounter_j = 0;									

	//---------- Predef of methods
	void setGraph();										//<		Set graph
	void srandGraph(int m_temp, int counter);				//<		Set '*'
	void printGraph();										//<		Print
	void moveGraph();										//<		Move graph after <counter> pos
	void process();											//<		Start methods

public:
	//---------- Start Menu
	void sensor(int m_temp);								
};
