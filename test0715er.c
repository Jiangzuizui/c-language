#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void init(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL]) {
	/*for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			showMap[row][col] = '*';
		}
	}*/
	//mem=>memory 内存
	//set 设置,集合
	//memset把一段内存上的每个字节都设置成一个具体的值
	memset(showMap, '*', MAX_ROW * MAX_COL);
	memset(mineMap, '0', MAX_ROW * MAX_COL);
	srand((unsigned int)time(0));
	int mineCount = 0;
	while(mineCount<mineCount){
		int row = rand() & MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] == '1') {
			continue;
		}
		mineMap[row][col] = '1';
		mineCount++;
	}
}

void print(char theMap[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ",theMap[row][col]);
		}
		printf("\n");
	}
}

void update(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL],
	int row,int col) {
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL) {
				continue;
			}
			if (r == row && c == col) {
				continue;
			}
			if (mineMap[r][c] == '1') {
				count++;
			}
		}
	}
	showMap[row][col] = '0' + count;
}

int main() {
	//1.创建地图并初始化
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	init(showMap, mineMap);
	int openCount = 0;
	while(1){
		system("cls");
		//2.打印地图
		print(showMap);
		//printf("===============\n");
		//print(mineMap);
		//3.玩家输入坐标
		int row = 0;
		int col = 0;
		printf("请输入坐标(row col)");
		scanf("%d %d", &row, &col);
		//进行合法性判定
		if (row < 0 || row >= MAX_ROW
			|| col < 0 || col >= MAX_COL) {
			printf("输入有误,请重新输入\n");
			continue;
		}
		if (showMap[row][col] != '*') {
			printf("该位置已翻开,请重新输入\n");
			continue;
		}
		//4.判定是否踩雷
		if (mineMap[row][col] == '1') {
			printf("您踩雷了 游戏结束\n");
			break;
		}
		//5.更新showmap,显示该位置周围有多少雷
		update(showMap, mineMap, row, col);
		//6.进行游戏胜利的判定
		openCount++;
		if (openCount == MAX_ROW * MAX_COL - MINE_COUNT) {
			printf("恭喜你 胜利了\n");
			break;
		}
	}
	
	system("pause");
	return 0;
}