#pragma once


/* ƒ†[ƒU‚ª”’l‚ğ“ü—Í‚·‚é‰ñ” */
#define USER_INPUT_NUMBER_COUNT (10)


typedef struct _number_t
{
	int number;
	struct _number_t *next;
} number_t;

