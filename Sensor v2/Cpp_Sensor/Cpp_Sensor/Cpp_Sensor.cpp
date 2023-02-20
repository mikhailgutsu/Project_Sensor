#include <iostream>
#include <windows.h>
#include <ctime>

#define Lines 20
#define Columns 120
#define loop() for(;;)

class Print
{
private:
	std::string Graph[Lines][Columns];
	int counter = 1;
	int temp;
	int i = 0;
	int j = 0;

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
				Graph[i][j - 1] = Graph[i][j];
			}
		}
	}

	void process()
	{
		if (i == 0)
		{
			setGraph();
			printGraph();
		}

		if (i <= 100 || i != 0)
		{
			system("cls");

			srandGraph(temp, counter);
			printGraph();
			i++;
		}

		if (i > 100)
		{
			system("cls");
			moveGraph();

			srandGraph(temp, --counter);
			printGraph();
			i++;
		}
		Sleep(100);
		counter++;
	}
public:

	void sensor(int m_temp)
	{
		temp = m_temp;
		process();
	}
};

int main()
{
	Print obj;
	int m_temp;

	loop()
	{
		std::cout << "Sensor - ";
		std::cin >> m_temp;
		obj.sensor(m_temp);
	}
	

	return 0;
}