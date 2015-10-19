#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>

using namespace std;


class Time
{
public:
	Time();
	Time::Time(int h, int m, int s, clock_t St,int,int);
	Time::Time(int);
	~Time();

	void goTime(clock_t start)
	{
		clock_t stop;
		int i = getSec();
		while (true)
		{
			stop = clock();

			if ((int)((stop - start) / CLOCKS_PER_SEC) != i )
			{
				i++;
				setSec(i);
				clearRow(y+1);
				Time::Print();
			}
			
		}
	}

		int getSec()
		{
			return sec;
		}

		int getMin()
		{
			return Min;
		}

		int getHour()
		{
			return hour;
		}
	void setSec( int s)
	{
		int i = s / 60;
		sec = s - i * 60;
		Min = i;
		if (Min == 60)
		{
			hour += 1;
			Min = 0;
		}
		if (hour == 24)
		{
			gotoxy(x, y + 1);
			cout << "started a new day)";
			hour = 0;
		}
		

	}

	

	int TimeinSec()
	{
		currentTimeSec = (hour * 3600 + Min * 60 + sec);

		return currentTimeSec;
	}

	void setXY(int X, int Y)
	{
		x = X;
		y = Y;
	}
	void Print()
	{
		gotoxy(x, y);
		
		cout << hour << ":" << Min << ":" << sec;
			
		
	}
	void gotoxy(int x, int y)

	{
		COORD coord; // coordinates

		coord.X = x; coord.Y = y; // X and Y coordinates

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // moves to the coordinates

	}


		void clearRow(int row)
		
		{
				// �������� ����� ���� �������
				HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		// �������� ���������� ������ ��� �������
				COORD coord = { 0, row - 1 };
				// �������� ������ �� ������ ������ �������

				CONSOLE_SCREEN_BUFFER_INFO csbi;
			
				GetConsoleScreenBufferInfo(hStdOut, &csbi);
				// ��������� ������ ���������
				
				FillConsoleOutputCharacter(hStdOut, ' ', 80, coord, NULL);
		
				// ���������� ������� �������
			
				SetConsoleCursorPosition(hStdOut, csbi.dwCursorPosition);
			
		}
		

private:
	int currentTimeSec;
	int sec, hour, Min, x, y;
	clock_t start, stop;

};

Time::Time() : hour(0), Min(0), sec(0),x(0),y(0) ,start(clock())
{
}

Time::Time(int h, int m, int s, clock_t St,int X,int Y) 
{
	h<24 ? hour = h : hour = 24;
	if (m<60)
		Min = m;
	else
	{
		int s = m / 60;
		Min = m - s * 60;
		hour += s;
	}
	if (s<60)
		sec = s;
	else
	{
		int i = s / 60;
		sec = s - i * 60;
		Min += i;
	}
	start = St;
	x = X;
	y = Y;


}

Time::Time(int s) : hour(0), Min(0), sec(s), start(0), x(0), y(0)
{

}

Time::~Time()
{
}
