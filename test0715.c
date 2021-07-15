#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROW 3
#define MAX_COL 3

void init(char chess[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col <MAX_COL; col++) {
			chess[row][col] = ' ';

		}
	}
	srand((unsigned int)time(0));
}

void print(char chess[MAX_ROW][MAX_COL]) {
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("|");
		for (int col = 0; col < MAX_COL; col++) {
			printf(" %c |", chess[row][col]);
		}
		printf("\n+---+---+---+\n");
	}
}

void playMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("�������...\n");
	while (1) {
		printf("����������(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			//���Ϸ� ��������
			printf("�����������Ƿ� ����������\n");
			continue;
		}
		if (chessBoard[row][col] != ' ') {
			printf("��λ������ ����������\n");
			continue;
		}
		chessBoard[row][col] = 'x';
		break;
	}
}


void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' ') {
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}
}

//����1���� ����0û��
int isFull(char chessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char isGameOver(char chessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0]!=' '
			&&chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '
		&& chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[0][2] == chessBoard[2][0]) {
		return chessBoard[0][2];
	}
	if (isFull(chessBoard)) {
		return 'q';
	}
	return ' ';
}


int main() {
	char chessBoard[MAX_ROW][MAX_COL];
	//1.�����̽��г�ʼ��
	init(chessBoard);
	char winner = ' ';
	while (1) {
		system("cls");
		//2.��ӡ����
		print(chessBoard);
		//3.�������
		playMove(chessBoard);
		//4.�ж�ʤ��
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			break;
		}
		//5.��������
		computerMove(chessBoard);
		//6.�ж�ʤ��
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			break;
		}
	}
	print(chessBoard);
	if (winner == 'x') {
		printf("��ϲ���ʤ��\n");
	}
	else if (winner == 'o') {
		printf("������\n");
	}
	else {
		printf("ƽ��\n");
	}


	system("pause");
	return 0;
}