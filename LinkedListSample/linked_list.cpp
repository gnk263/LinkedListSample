#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include"common.h"

/*--------------------------------------------*/

static number_t head;


/*--------------------------------------------*/

static number_t* LinkedListSearchTail();
static bool LinkedListIsDeleteData(int number);
static void LinkedListDisplayData(number_t *data);


/*--------------------------------------------*/

/* 線形リストの初期化 */
void LinkedListInit()
{
	head.number = 0;
	head.next = NULL;
}


/* 線形リストにデータを追加 */
void LinkedListAddData(int addNumber)
{
	number_t *addData;
	number_t *tailData;

	addData = (number_t*)malloc(sizeof(number_t));

	if (addData == NULL)
	{
		printf("メモリの確保に失敗しました。\n");

		exit(1);
	}


	/* 線形リストの末尾を探す */
	tailData = LinkedListSearchTail();

	/* 追加するデータを作成する */
	addData->number = addNumber;
	addData->next = NULL;

	/* 線形リストの末尾に追加する */
	tailData->next = addData;
}


/* 線形リストのデータを削除(3の倍数の整数を削除する) */
void LinkedListDeleteData()
{
	number_t *currentData;
	number_t *nextData;

	currentData = &head;


	while (currentData->next != NULL)
	{
		nextData = currentData->next;

		if (LinkedListIsDeleteData(nextData->number))
		{
			currentData->next = nextData->next;

			free(nextData);
		}
		else
		{
			currentData = nextData;
		}
	}
}

/* 線形リストのデータを表示 */
void LinkedListDisplayAllData()
{
	number_t *currentData;
	number_t *nextData;

	printf("データを表示します。\n");


	currentData = &head;

	while (currentData->next != NULL)
	{
		nextData = currentData->next;

		LinkedListDisplayData(nextData);

		currentData = nextData;
	}

}


/*--------------------------------------------*/

/* 削除するデータか判定する */
static bool LinkedListIsDeleteData(int number)
{
	return number % 3 == 0;
}


/* 線形リストの末尾を探す */
static number_t* LinkedListSearchTail()
{
	number_t *currentData;

	currentData = &head;

	while (currentData->next != NULL)
	{
		currentData = currentData->next;
	}

	return currentData;
}


/* データを表示する */
static void LinkedListDisplayData(number_t *data)
{
	printf("%d\n", data->number);
}


