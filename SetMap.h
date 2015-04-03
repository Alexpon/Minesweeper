#include<fstream>
#include<cstdlib>
using namespace std;

class First
{
	public:
		First();
		void SelectLevel(int);
		void SetMap(int, int, int);
		char get(int, int);

	private:  int sizeRow, sizeCol, boomNum;
		  int i, j, count;
		  int BoomRow, BoomCol;
		  char boomMap[100][100], num;

};
