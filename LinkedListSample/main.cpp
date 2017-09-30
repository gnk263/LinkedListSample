#include<stdio.h>

#include"common.h"
#include"linked_list.h"


/*--------------------------------------------*/

/* ユーザが数値を入力する */
static void InputNumberByUser();

/* キーボード入力された数値を取得する */
static int GetNumberByKeybord();


/*--------------------------------------------*/

int main()
{
	/* 線形リストの初期化 */
	LinkedListInit();

	/* ユーザが数値を入力する */
	InputNumberByUser();

	/* データを削除する */
	LinkedListDeleteData();

	/* 線形リストのデータを表示 */
	LinkedListDisplayAllData();

	return 0;
}


/* ユーザが数値を入力する */
static void InputNumberByUser()
{
	int i;
	int inputNumber;


	printf("数値を入力してください。\n");

	for (i = 0; i < USER_INPUT_NUMBER_COUNT; i++)
	{
		printf("> ");

		/* キーボード入力された数値を取得する */
		inputNumber = GetNumberByKeybord();

		/* 線形リストにデータを追加する */
		LinkedListAddData(inputNumber);
	}
}


/* キーボード入力された数値を取得する */
static int GetNumberByKeybord()
{
	int inputNumber;

	scanf_s("%d", &inputNumber);

	return inputNumber;
}