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

/* ���`���X�g�̏����� */
void LinkedListInit()
{
	head.number = 0;
	head.next = NULL;
}


/* ���`���X�g�Ƀf�[�^��ǉ� */
void LinkedListAddData(int addNumber)
{
	number_t *addData;
	number_t *tailData;

	addData = (number_t*)malloc(sizeof(number_t));

	if (addData == NULL)
	{
		printf("�������̊m�ۂɎ��s���܂����B\n");

		exit(1);
	}


	/* ���`���X�g�̖�����T�� */
	tailData = LinkedListSearchTail();

	/* �ǉ�����f�[�^���쐬���� */
	addData->number = addNumber;
	addData->next = NULL;

	/* ���`���X�g�̖����ɒǉ����� */
	tailData->next = addData;
}


/* ���`���X�g�̃f�[�^���폜(3�̔{���̐������폜����) */
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

/* ���`���X�g�̃f�[�^��\�� */
void LinkedListDisplayAllData()
{
	number_t *currentData;
	number_t *nextData;

	printf("�f�[�^��\�����܂��B\n");


	currentData = &head;

	while (currentData->next != NULL)
	{
		nextData = currentData->next;

		LinkedListDisplayData(nextData);

		currentData = nextData;
	}

}


/*--------------------------------------------*/

/* �폜����f�[�^�����肷�� */
static bool LinkedListIsDeleteData(int number)
{
	return number % 3 == 0;
}


/* ���`���X�g�̖�����T�� */
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


/* �f�[�^��\������ */
static void LinkedListDisplayData(number_t *data)
{
	printf("%d\n", data->number);
}


