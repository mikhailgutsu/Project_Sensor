#include <iostream>
#include <windows.h>
#include <ctime>

#define Lines 20
#define Columns 120

class Print
{
private:
	std::string Graph[Lines][Columns];

public:
	void setGraph()
	{
		for (int i = 0; i < Lines; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				Graph[i][j] = " ";
			}
		}

		for (int i = 0; i < Lines; i++)
		{
			Graph[i][0] = "|";
		}

		for (int i = 1; i < Columns - 1; i++)
		{
			Graph[19][i] = "-";
		}
	}

	void srandGraph(int m_temp, int counter)
	{
			Graph[m_temp][counter] = "*";
	}

	void printGraph()
	{
		system("cls");
		for (int i = 0; i < Lines; i++)
		{
			for (int j = 0; j < Columns - 1; j++)
			{
				std::cout << Graph[i][j];
			}
			std::cout << std::endl;
		}
	}

	void moveGraph()
	{
		for (int i = 1; i < Lines - 1; i++)
		{
			for (int j = 2; j < Columns - 2; j++)
			{
				Graph[i][j-1] = Graph[i][j];
			}
		}
	}

};

int main()
{
	Print printFunc;
	printFunc.setGraph();
	printFunc.printGraph();
	system("PAUSE");

	srand(time(0));

	int temp = rand() % 10 + 9;
	int counter = 1;

	for (int i = 0;i < 100; i++)
	{
		system("cls");

		printFunc.srandGraph(temp, counter);
		printFunc.printGraph();
		Sleep(100);

		counter++;
		temp = rand() % 10 + 9;
		
	}

	for (int i = 100;; i++)
	{
		system("cls");
		printFunc.moveGraph();
		
		printFunc.srandGraph(temp, --counter);
		printFunc.printGraph();
		Sleep(100);
		 
		temp = rand() % 10 + 9;
		counter++;
	}

	return 0;
}