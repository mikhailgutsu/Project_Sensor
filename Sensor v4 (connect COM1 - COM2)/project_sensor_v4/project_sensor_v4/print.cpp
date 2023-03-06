#include "print.h"


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
//-------------------------------------------------------------------------
void Print::srandGraph(int m_temp, int counter)
{
	Graph[m_temp][counter] = "*";
}
//-------------------------------------------------------------------------
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
//-------------------------------------------------------------------------
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
//-------------------------------------------------------------------------
void Print::process()
{
	if (forCounter_i == 0)
	{
		setGraph();
		printGraph();
	}

	if (forCounter_i <= 100 || forCounter_i != 0)
	{
		system("cls");

		srandGraph(temp, counter);
		printGraph();
		forCounter_i++;
	}

	if (forCounter_i > 100)
	{
		system("cls");
		moveGraph();

		srandGraph(temp, --counter);
		printGraph();
		forCounter_i++;
	}
	Sleep(100);
	counter++;
}
//-------------------------------------------------------------------------
void Print::sensor(int m_temp)
{
	temp = m_temp;
	process();
}