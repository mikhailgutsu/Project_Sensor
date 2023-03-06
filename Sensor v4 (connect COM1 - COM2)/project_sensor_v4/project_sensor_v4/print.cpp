//------- HEADER INCLUDE
#include "print.h"

//------- Set XY graph 
void Print::setGraph()
{
	for (int forCounter_i = 0; forCounter_i < Lines; forCounter_i++)
	{
		for (int forCounter_j = 0; forCounter_j < Columns; forCounter_j++)
		{
			Graph[forCounter_i][forCounter_j] = " ";
		}
	}

	for (int forCounter_i = 0; forCounter_i < Lines; forCounter_i++)
	{
		Graph[forCounter_i][0] = "|";
	}

	for (int forCounter_i = 1; forCounter_i < Columns - 1; forCounter_i++)
	{
		Graph[19][forCounter_i] = "-";
	}
}
//------- Set pos to include '*'
void Print::srandGraph(int m_temp, int counter)
{
	Graph[m_temp][counter] = "*";
}
//------- Print updated graph
void Print::printGraph()
{
	system("cls");
	for (int forCounter_i = 0; forCounter_i < Lines; forCounter_i++)
	{
		for (int forCounter_j = 0; forCounter_j < Columns - 1; forCounter_j++)
		{
			std::cout << Graph[forCounter_i][forCounter_j];
		}
		std::cout << std::endl;
	}
}
//------- Move graph 
void Print::moveGraph()
{
	for (int forCounter_i = 1; forCounter_i < Lines - 1; forCounter_i++)
	{
		for (int forCounter_j = 2; forCounter_j < Columns - 2; forCounter_j++)
		{
			Graph[forCounter_i][forCounter_j - 1] = Graph[forCounter_i][forCounter_j];
		}
	}
}
//------- Main funct to write graph
void Print::process()
{
	if (forCounter_i == 0)
	{
		setGraph();									//<		Set Graph
		printGraph();								//<		Print Graph
	}

	if (forCounter_i <= 100 || forCounter_i != 0)
	{
		system("cls");

		srandGraph(temp, counter);					//<		Set temp_var to counter_position
		printGraph();								//<		Print Graph
		forCounter_i++;
	}

	if (forCounter_i > 100)
	{
		system("cls");
		moveGraph();								//<		Move Graph

		srandGraph(temp, --counter);				//<		Set temp_var to --counter_position
		printGraph();								//<		Print Graph
		forCounter_i++;
	}
	Sleep(100);
	counter++;
}
//------- COM
void Print::sensor(int m_temp)
{
	temp = m_temp;
	process();										//<		Start
}