#pragma once


/* ���[�U�����l����͂���� */
#define USER_INPUT_NUMBER_COUNT (10)


typedef struct _number_t
{
	int number;
	struct _number_t *next;
} number_t;

