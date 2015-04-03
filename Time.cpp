#include<ctime>
#include"Time.h"
using namespace std;
	
		void Time::InitialTime()
		{
			start = time(NULL);
			now = start;
			Calculate();
		}
		void Time::NowTime()
		{
			now = time(NULL);
			Calculate();
		}
		void Time::Calculate()
		{
			hour = (int)((now-start)/3600);
			minute = (int)((now-start)/60%60);
			second = (int)((now-start)%60);
		}
		int Time::getHour()
		{
			return hour;
		}
		int Time::getMinute()
		{
			return minute;
		}
		int Time::getSecond()
		{
			return second;
		}
