#define _CRT_SECURE_NO_WARNINGS
#define SPACE 0
#define WHITE_PIECE 1
#define BLACK_PIECE 2
#define BOARD_SIZE 8
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "InternationaleCheckers.h"
bool isOver = false;//�н���û����
int myPiece;//���õ�ʲô����
char* buffer=(char*)malloc(sizeof(char)*1024);//ָ�����

int BOARD[BOARD_SIZE][BOARD_SIZE] = {
	{SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE},
	{WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE},
	{SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE},
	{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},
	{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},
	{BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE},
	{SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE},
	{BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE},
};//����

//��
typedef struct {
	int x;
	int y;
}Pos;

//ÿ�ν���ָ�����һ�ζ���
typedef struct {
	Pos start;//��ʼ��
	Pos viaPos[64];//�����ĵ�
}Movement;

/*
������������ӱ�׼����stdin����ָ��,��stdout���,ÿ��ָ���ռһ��,���Ҳ��ռһ��
*/



//���ݵ��˵��ƶ���������
//�Լ����ƶ�ˢ�����̿�����move()�е���
void freashBoard(Movement movement);


//�ȴ���ʼ����
//ָ�� START[FIELD]
//FIELD 1 ����,2 ����
//�ظ� OK
void waitForStartCommand() {

}

//��ȡ����,������Ƿ��������������END [FIELD]
//��ʾ��Ϸ������
//ÿ�ν�������ʱ�ȵ������,�����˵Ļ���isOver��Ϊtrue
//�������Ҫ�Լ����
//ֱ�Ӵ�buffer������Ϳ���
//����Ҫ�ȼ��һ��buffer�ǲ��ǿ�ָ���
//��ָ��˵����Ϸ������
void getCommond() {
	fgets(buffer, 1024, stdin);
	char* firstWord = strtok(buffer, " ");
	if (strcmp(firstWord, "END")) {
		isOver == true;
	}
	free(buffer);
	buffer = NULL;
}

//��������ܶԷ��ղ�����ʲô��
Movement waitForMovementCommond();



//����ָ���Ļغ���
void waitForTurnCommond() {
	getCommond();
	if (!buffer) {

	}
}


//���岢��������
Movement move();



//�������л㱨�ҵ��ƶ�
void reportMovement(Movement movement);



int main() {
	waitForStartCommand();
	if (myPiece == BLACK_PIECE) {
		while (!isOver) {
			waitForTurnCommond();
			Movement myMovement=move();
			reportMovement(myMovement);
			Movement enemyMovement = waitForMovementCommond();
			freashBoard(enemyMovement);
		}
	}
	else if (myPiece == WHITE_PIECE) {
		while (!isOver) {
			Movement enemyMovement = waitForMovementCommond();
			freashBoard(enemyMovement);
			waitForTurnCommond();
			Movement myMovement = move();
			reportMovement(myMovement);
		}
	}
	
}

