#include<stdio.h>

#include"common.h"
#include"linked_list.h"


/*--------------------------------------------*/

/* ���[�U�����l����͂��� */
static void InputNumberByUser(int *inputNumber, int inputNumberSize);

/* �L�[�{�[�h���͂��ꂽ���l���擾���� */
static int GetNumberByKeybord();

/* ���[�U�����͂������l��o�^���� */
static void RegistNumber(int *registNumber, int registNumberSize);


/*--------------------------------------------*/

int main()
{
	int inputNumber[USER_INPUT_NUMBER_COUNT];

	/* ���`���X�g�̏����� */
	LinkedListInit();

	/* ���[�U�����l����͂��� */
	InputNumberByUser(inputNumber, USER_INPUT_NUMBER_COUNT);

	/* ���[�U�����͂������l��o�^���� */
	RegistNumber(inputNumber, USER_INPUT_NUMBER_COUNT);

	/* �f�[�^���폜���� */
	LinkedListDeleteData();

	/* ���`���X�g�̃f�[�^��\�� */
	LinkedListDisplayAllData();

	return 0;
}


/* ���[�U�����l����͂��� */
static void InputNumberByUser(int *inputNumber, int inputNumberSize)
{
	int i;

	
	if (inputNumber == NULL || inputNumberSize <= 0)
	{
		return;
	}


	printf("���l����͂��Ă��������B\n");

	for (i = 0; i < inputNumberSize; i++)
	{
		printf("> ");

		/* �L�[�{�[�h���͂��ꂽ���l���擾���� */
		inputNumber[i] = GetNumberByKeybord();
	}
}


/* �L�[�{�[�h���͂��ꂽ���l���擾���� */
static int GetNumberByKeybord()
{
	int inputNumber;

	scanf_s("%d", &inputNumber);

	return inputNumber;
}


/* ���[�U�����͂������l��o�^���� */
static void RegistNumber(int *registNumber, int registNumberSize)
{
	int i;


	if (registNumber == NULL || registNumberSize <= 0)
	{
		return;
	}


	for (i = 0; i < registNumberSize; i++)
	{
		/* ���`���X�g�Ƀf�[�^��ǉ� */
		LinkedListAddData(registNumber[i]);
	}
}

