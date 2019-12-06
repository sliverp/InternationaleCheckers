#define _CRT_SECURE_NO_WARNINGS
#define SPACE 0
#define WHITE_PIECE 1
#define BLACK_PIECE 2
#define BOARD_SIZE 8
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "InternationaleCheckers.h"
bool isOver = false;//判结束没结束
int myPiece;//我拿的什么棋子
char* buffer=(char*)malloc(sizeof(char)*1024);//指令缓冲区

int BOARD[BOARD_SIZE][BOARD_SIZE] = {
	{SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE},
	{WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE},
	{SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE,SPACE,WHITE_PIECE},
	{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},
	{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},
	{BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE},
	{SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE},
	{BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE,BLACK_PIECE,SPACE},
};//棋盘

//点
typedef struct {
	int x;
	int y;
}Pos;

//每次接受指令产生一次动作
typedef struct {
	Pos start;//起始点
	Pos viaPos[64];//经过的点
}Movement;

/*
所有输入输出从标准输入stdin接受指令,从stdout输出,每个指令独占一行,输出也独占一行
*/



//根据敌人的移动属性棋盘
//自己的移动刷新棋盘可以在move()中调用
void freashBoard(Movement movement);


//等待开始命令
//指令 START[FIELD]
//FIELD 1 黑棋,2 白旗
//回复 OK
void waitForStartCommand() {

}

//获取命令,并检测是否命令行输入的是END [FIELD]
//表示游戏结束了
//每次接受命令时先调用这个,结束了的话将isOver置为true
//别的命令要自己检测
//直接从buffer里面读就可以
//但是要先检测一下buffer是不是空指针的
//空指针说明游戏结束了
void getCommond() {
	fgets(buffer, 1024, stdin);
	char* firstWord = strtok(buffer, " ");
	if (strcmp(firstWord, "END")) {
		isOver == true;
	}
	free(buffer);
	buffer = NULL;
}

//从输入接受对方刚才走了什么子
Movement waitForMovementCommond();



//接受指令到你的回合了
void waitForTurnCommond() {
	getCommond();
	if (!buffer) {

	}
}


//走棋并更新棋盘
Movement move();



//向命令行汇报我的移动
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

