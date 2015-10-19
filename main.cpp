#include <iostream>
#include "Class_Time.h"

using namespace std;

int main()
{
	Time t(0, 0, 0, clock(), 10, 10);
	
	
	
	t.gotoxy(10, 10);

	t.goTime(t.getStart());
	return 0;
}