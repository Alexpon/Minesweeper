#include<ctime>
class Time{
	public:
		void InitialTime();
		void NowTime();
		void Calculate();
		int getHour();
		int getMinute();
		int getSecond();

	private:	
		int start, now;
		int hour, minute, second;

};
