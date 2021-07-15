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
	//mem=>memory �ڴ�
	//set ����,����
	//memset��һ���ڴ��ϵ�ÿ���ֽڶ����ó�һ�������ֵ
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
	//1.������ͼ����ʼ��
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	init(showMap, mineMap);
	int openCount = 0;
	while(1){
		system("cls");
		//2.��ӡ��ͼ
		print(showMap);
		//printf("===============\n");
		//print(mineMap);
		//3.�����������
		int row = 0;
		int col = 0;
		printf("����������(row col)");
		scanf("%d %d", &row, &col);
		//���кϷ����ж�
		if (row < 0 || row >= MAX_ROW
			|| col < 0 || col >= MAX_COL) {
			printf("��������,����������\n");
			continue;
		}
		if (showMap[row][col] != '*') {
			printf("��λ���ѷ���,����������\n");
			continue;
		}
		//4.�ж��Ƿ����
		if (mineMap[row][col] == '1') {
			printf("�������� ��Ϸ����\n");
			break;
		}
		//5.����showmap,��ʾ��λ����Χ�ж�����
		update(showMap, mineMap, row, col);
		//6.������Ϸʤ�����ж�
		openCount++;
		if (openCount == MAX_ROW * MAX_COL - MINE_COUNT) {
			printf("��ϲ�� ʤ����\n");
			break;
		}
	}
	
	system("pause");
	return 0;
}