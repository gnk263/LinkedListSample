#include<stdio.h>

#include"common.h"
#include"linked_list.h"


/*--------------------------------------------*/

/* ���[�U�����l����͂��� */
static void InputNumberByUser();

/* �L�[�{�[�h���͂��ꂽ���l���擾���� */
static int GetNumberByKeybord();


/*--------------------------------------------*/

int main()
{
	/* ���`���X�g�̏����� */
	LinkedListInit();

	/* ���[�U�����l����͂��� */
	InputNumberByUser();

	/* �f�[�^���폜���� */
	LinkedListDeleteData();

	/* ���`���X�g�̃f�[�^��\�� */
	LinkedListDisplayAllData();

	return 0;
}


/* ���[�U�����l����͂��� */
static void InputNumberByUser()
{
	int i;
	int inputNumber;


	printf("���l����͂��Ă��������B\n");

	for (i = 0; i < USER_INPUT_NUMBER_COUNT; i++)
	{
		printf("> ");

		/* �L�[�{�[�h���͂��ꂽ���l���擾���� */
		inputNumber = GetNumberByKeybord();

		/* ���`���X�g�Ƀf�[�^��ǉ����� */
		LinkedListAddData(inputNumber);
	}
}


/* �L�[�{�[�h���͂��ꂽ���l���擾���� */
static int GetNumberByKeybord()
{
	int inputNumber;

	scanf_s("%d", &inputNumber);

	return inputNumber;
}