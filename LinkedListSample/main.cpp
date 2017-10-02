#include<stdio.h>

#include"common.h"
#include"linked_list.h"


/*--------------------------------------------*/

/* ユーザが数値を入力する */
static void InputNumberByUser(int *inputNumber, int inputNumberSize);

/* キーボード入力された数値を取得する */
static int GetNumberByKeybord();

/* ユーザが入力した数値を登録する */
static void RegistNumber(int *registNumber, int registNumberSize);


/*--------------------------------------------*/

int main()
{
	int inputNumber[USER_INPUT_NUMBER_COUNT];

	/* 線形リストの初期化 */
	LinkedListInit();

	/* ユーザが数値を入力する */
	InputNumberByUser(inputNumber, USER_INPUT_NUMBER_COUNT);

	/* ユーザが入力した数値を登録する */
	RegistNumber(inputNumber, USER_INPUT_NUMBER_COUNT);

	/* データを削除する */
	LinkedListDeleteData();

	/* 線形リストのデータを表示 */
	LinkedListDisplayAllData();

	return 0;
}


/* ユーザが数値を入力する */
static void InputNumberByUser(int *inputNumber, int inputNumberSize)
{
	int i;

	
	if (inputNumber == NULL || inputNumberSize <= 0)
	{
		return;
	}


	printf("数値を入力してください。\n");

	for (i = 0; i < inputNumberSize; i++)
	{
		printf("> ");

		/* キーボード入力された数値を取得する */
		inputNumber[i] = GetNumberByKeybord();
	}
}


/* キーボード入力された数値を取得する */
static int GetNumberByKeybord()
{
	int inputNumber;

	scanf_s("%d", &inputNumber);

	return inputNumber;
}


/* ユーザが入力した数値を登録する */
static void RegistNumber(int *registNumber, int registNumberSize)
{
	int i;


	if (registNumber == NULL || registNumberSize <= 0)
	{
		return;
	}


	for (i = 0; i < registNumberSize; i++)
	{
		/* 線形リストにデータを追加 */
		LinkedListAddData(registNumber[i]);
	}
}

