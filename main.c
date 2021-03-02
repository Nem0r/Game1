#include <stdio.h>

//���H�s��
#define MAZE_ROW 5
//���H��
#define MAZE_COLUMN 5

//�v���C���[
typedef struct {
	//�v���C���[�ʒu�i�s�j
	int row;
	//�v���C���[�ʒu�i��j
	int column;
} MazePlayer;

//���H1�u���b�N
//�u���b�N�̎�ށ@���A�ǁA�X�^�[�g�A�S�[��
enum MazeKind { PATH, WALL, START, GOAL };
//�u���b�N�����肵�Ă邩�ǂ���
enum MazeFlag { FALSE, TRUE };


typedef struct{
	//�u���b�N�̎�ށ@���A�ǁA�X�^�[�g�A�S�[��
	enum MazeKind kind;
	//�u���b�N�����肵�Ă邩�ǂ���
	enum MazeFlag flag;
} MazeBlock;

//�v���C���[������
int MazePlayerInit(int* playerRow, int* playerColumn, MazeBlock maze[MAZE_ROW][MAZE_COLUMN]) {
	int i, j;
	//�s
	for (i = 0; i < MAZE_ROW; i++) {
		//��
		for (j = 0; j < MAZE_COLUMN; j++) {
			//�X�^�[�g�n�_�Ȃ�΃v���C���[�̈ʒu��ݒ�
			if (maze[i][j].kind == START) {
				*playerRow = i;
				*playerColumn = j;
				//�֐��I���@�v���C���[�ݒ�ς݂̏ꍇ�A�c�����͕s�v
				return 0;
			}
		}
	}

	//�X�^�[�g�n�_���Ȃ��ꍇ�A�v���C���[��ݒ肹���ɖ߂�
	printf("�X�^�[�g�n�_������܂���\n");
	return -1;
}

//���H�\��
void MazeDraw(int playerRow, int playerColumn, MazeBlock maze[MAZE_ROW][MAZE_COLUMN]) {
	int i, j;

	//���H�s
	for(i = 0; i < MAZE_ROW; i++) {
		//���H��
		for(j = 0; j < MAZE_COLUMN; j++) {
			//�v���C���[�ʒu
			if(i == playerRow && j == playerColumn) {
				printf("P");
			}
			//�u���b�N���������ĂȂ��ꍇ
			else if(maze[i][j].flag == FALSE) {
				printf("?");
			}
			else {
				switch(maze[i][j].kind) {
				case WALL :
					//��
					printf("��"); break;
					//�S�[��
				case GOAL:
					printf("G"); break;
					//���̑��i���A�X�^�[�g�j
				default:
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}



int main(void){

	//�v���C���[
	MazePlayer player;

	//���H
	MazeBlock maze[MAZE_ROW][MAZE_COLUMN] = {
		{ {START,TRUE},{PATH,FALSE},{PATH,FALSE},{PATH,FALSE},{PATH,FALSE}},
		{ {WALL,FALSE},{WALL,FALSE},{PATH,FALSE},{WALL,FALSE},{WALL,FALSE}},
		{ {WALL,FALSE},{PATH,FALSE},{PATH,FALSE},{PATH,FALSE},{PATH,FALSE}},
		{ {PATH,FALSE},{PATH,FALSE},{WALL,FALSE},{WALL,FALSE},{WALL,FALSE}},
		{ {WALL,FALSE},{PATH,FALSE},{PATH,FALSE},{PATH,FALSE},{GOAL,TRUE }},
	};

	//�v���C���[������
	if (MazePlayerInit(&player.row, &player.column, maze) == -1) {
		//�֐�MazePlayerInit��-1��Ԃ����ꍇ�A���H�\�����s��Ȃ�
		return 0;
	}

	//���H�\��
	MazeDraw(player.row, player.column, maze);

	return 0;
}