#include<fstream>
#include"SetMap.h"

using namespace std;

First::First():count(0){ 
	for(i=0; i<100; i++){
		for(j=0; j<100; j++){
			boomMap[i][j] = '.';
		}
	}
}

void First::SelectLevel(int choose)
{
	switch(choose){
		case 1 :
			sizeRow = 9;
			sizeCol = 9;
			boomNum = 10;
			SetMap(sizeCol, sizeRow, boomNum);
			break;

		case 2 :
			sizeRow = 16;
			sizeCol = 16;
			boomNum = 40;
			SetMap(sizeCol, sizeRow, boomNum);
			break;

		case 3 :
			sizeRow = 16;
			sizeCol = 30;
			boomNum = 99;
			SetMap(sizeCol, sizeRow, boomNum);
			break;
	}


}


void First::SetMap(int col, int row, int boom)
{
	srand( time( NULL ) );
	ofstream outputMap("Mine.txt", ios::out);
	while(count<boom){
		BoomRow = rand() % (row-1);
		BoomCol = rand() % (col-1);

		if(boomMap[BoomRow+1][BoomCol+1] != 'B'){
			boomMap[BoomRow+1][BoomCol+1]= 'B';
			count ++;
		}
	}

	for(i=1 ; i<=row; i++){
		for(j=1; j<=col; j++){
			if(boomMap[i][j]!='B'){
				num ='0';
				while(boomMap[i+1][j]=='B'){num++;break;}
				while(boomMap[i+1][j+1]=='B'){num++;break;}
				while(boomMap[i+1][j-1]=='B'){num++;break;}
				while(boomMap[i-1][j]=='B'){num++;break;}
				while(boomMap[i-1][j+1]=='B'){num++;break;}
				while(boomMap[i-1][j-1]=='B'){num++;break;}
				while(boomMap[i][j-1]=='B'){num++;break;}
				while(boomMap[i][j+1]=='B'){num++;break;}
				if(num == '0') num = '.';
				boomMap[i][j] = num;

			}
			outputMap << boomMap[i][j];
		}
		outputMap << endl;
	}
}

char First::get(int y, int x){
	return boomMap[y][x];
}
