#pragma once


/* ユーザが数値を入力する回数 */
#define USER_INPUT_NUMBER_COUNT (10)


typedef struct _number_t
{
	int number;
	struct _number_t *next;
} number_t;

