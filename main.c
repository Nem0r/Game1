#include <stdio.h>

//迷路行数
#define MAZE_ROW 5
//迷路列数
#define MAZE_COLUMN 5

//プレイヤー
typedef struct {
	//プレイヤー位置（行）
	int row;
	//プレイヤー位置（列）
	int column;
} MazePlayer;

//迷路1ブロック
//ブロックの種類　道、壁、スタート、ゴール
enum MazeKind { PATH, WALL, START, GOAL };
//ブロックが判定してるかどうか
enum MazeFlag { FALSE, TRUE };


typedef struct{
	//ブロックの種類　道、壁、スタート、ゴール
	enum MazeKind kind;
	//ブロックが判定してるかどうか
	enum MazeFlag flag;
} MazeBlock;

//プレイヤー初期化
int MazePlayerInit(int* playerRow, int* playerColumn, MazeBlock maze[MAZE_ROW][MAZE_COLUMN]) {
	int i, j;
	//行
	for (i = 0; i < MAZE_ROW; i++) {
		//列
		for (j = 0; j < MAZE_COLUMN; j++) {
			//スタート地点ならばプレイヤーの位置を設定
			if (maze[i][j].kind == START) {
				*playerRow = i;
				*playerColumn = j;
				//関数終了　プレイヤー設定済みの場合、残処理は不要
				return 0;
			}
		}
	}

	//スタート地点がない場合、プレイヤーを設定せずに戻る
	printf("スタート地点がありません\n");
	return -1;
}

//迷路表示
void MazeDraw(int playerRow, int playerColumn, MazeBlock maze[MAZE_ROW][MAZE_COLUMN]) {
	int i, j;

	//迷路行
	for(i = 0; i < MAZE_ROW; i++) {
		//迷路列
		for(j = 0; j < MAZE_COLUMN; j++) {
			//プレイヤー位置
			if(i == playerRow && j == playerColumn) {
				printf("P");
			}
			//ブロックが判明してない場合
			else if(maze[i][j].flag == FALSE) {
				printf("?");
			}
			else {
				switch(maze[i][j].kind) {
				case WALL :
					//壁
					printf("□"); break;
					//ゴール
				case GOAL:
					printf("G"); break;
					//その他（道、スタート）
				default:
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}



int main(void){

	//プレイヤー
	MazePlayer player;

	//迷路
	MazeBlock maze[MAZE_ROW][MAZE_COLUMN] = {
		{ {START,TRUE},{PATH,FALSE},{PATH,FALSE},{PATH,FALSE},{PATH,FALSE}},
		{ {WALL,FALSE},{WALL,FALSE},{PATH,FALSE},{WALL,FALSE},{WALL,FALSE}},
		{ {WALL,FALSE},{PATH,FALSE},{PATH,FALSE},{PATH,FALSE},{PATH,FALSE}},
		{ {PATH,FALSE},{PATH,FALSE},{WALL,FALSE},{WALL,FALSE},{WALL,FALSE}},
		{ {WALL,FALSE},{PATH,FALSE},{PATH,FALSE},{PATH,FALSE},{GOAL,TRUE }},
	};

	//プレイヤー初期化
	if (MazePlayerInit(&player.row, &player.column, maze) == -1) {
		//関数MazePlayerInitが-1を返した場合、迷路表示を行わない
		return 0;
	}

	//迷路表示
	MazeDraw(player.row, player.column, maze);

	return 0;
}