#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Header.h"

int main()
{
	//Имя функции, для которой нужно сгенерировать прототип
	char nameFunction[MAX_NUMBER_SYMBOLS];

	//Количество строк в функции
	int numberRows;

	//Текст функции
	char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS];

	//Строка, где хранится прототип
	char strPrototip[MAX_NUMBER_SYMBOLS];

	//Ввести данные...

	//Ввести название функции
	gets_s(nameFunction);

	//Ввести количество строк
	scanf_s("%d", &numberRows);

	if (numberRows<21 && numberRows>0)
	{
		//Ввести текст функции
		getchar();
		for (int i = 0; i < numberRows; i++)
		{
			gets_s(textFunction[i]);
		}
	
		//Сгенерировать прототип
		int hitIndex = generatePrototip(textFunction, numberRows, nameFunction, strPrototip);

			//Вывести данные
			if (hitIndex == 1)
			{
				puts(strPrototip);
			}

			else
			{
				puts("no solution");
			}
	}
	else
	{
		puts("invalid input data");
	}

	return 0;
}

int generatePrototip(char textFunction[][MAX_NUMBER_SYMBOLS], int numberRows, char nameFunction[], char strPrototip[])
{
	//Убрать комментарии из текста
	removeCommentsFromFunctionText;

	int indexForFindEntryName = -1;
	int header = 0;
	char desiredWhiteSpacers[5] = " \t";

    //Сгенерировать прототип, пройдясь по всему тексту...
	for (int i = 0; i < numberRows; i++)
	{
		//Определить, является ли строчка прототипом или заголовком
		indexForFindEntryName = findEntryName(textFunction[i], nameFunction);

		//Если найден прототип, то обрезаем лишние пробелы и помещаем его в результирующий массив
		if (indexForFindEntryName == 1)
		{
			cutPartStr(textFunction[i], strPrototip, ';', desiredWhiteSpacers);
			return 1;
		}

		//Иначе если найден заголовок, то обрезаем лишние пробелы и помещаем его в результирующий массив
		else if (indexForFindEntryName == 0)
		{
			cutPartStr(textFunction[i], strPrototip, ')', desiredWhiteSpacers);
			strcat(strPrototip, ";");
			header = 1;
		}
	}

	//Если истинный прототип в тексте не найден, возвращаем сгенерированный прототип
	if (header == 1)
	{
		return 1;
	}
	//Иначе ничего не возвращаем
	else
	{
		return 0;
	}
}
	
int findEntryName(char textFunction[], char nameFunction[])
{
	//Проверка на наличие имени функции в строке...
	if ((strstr(textFunction, nameFunction) != 0) && (strstr(textFunction, "=") == 0))
	{
		char* pointerFirstWord;
		char wordBreakingStr[MAX_NUMBER_SYMBOLS];
		char strSearchSpecialChars[MAX_NUMBER_SYMBOLS];
		strcpy(wordBreakingStr, textFunction);
		strcpy(strSearchSpecialChars, textFunction);
		pointerFirstWord = strtok(wordBreakingStr, " \t");

		//Наличие базовых типов возвращаемого значения...
		for (int i = 0; i < 5; i++)
		{
			bool indexFirstSpecialWord = strcmp(pointerFirstWord, returnTypes[i]);

			//Проверка формата строки...
			if (!indexFirstSpecialWord)
			{
				char* pointerNameFunction = strtok(NULL, " (\t");

				//Если в строке есть имя функции...
				if (strcmp(pointerNameFunction, nameFunction) == 0)
				{
					//Если в строке есть открывающая и закрывающая круглые скобки...
					if (strstr(strSearchSpecialChars, "(") && strstr(strSearchSpecialChars, ")"))
					{
						//Если в строке присутствует точка с запятой...
						if (strstr(strSearchSpecialChars, ";"))
						{
							return 1;
						}

						return 0;
					}
				}
			}
		}

		//Наличие модификаторов для базовых типов...
		for (int i = 5; i < 9; i++)
		{
			bool indexFirstSpecialWord = strcmp(pointerFirstWord, returnTypes[i]);

			//Проверка формата строки...
			if (!indexFirstSpecialWord)
			{
				char* pointerSecondWord = strtok(NULL, " (\t");
				char* pointerThirdWord = strtok(NULL, " (\t");
				char* pointerFourthWord = strtok(NULL, " (\t");

				//Если в строке есть имя функции...
				if (strcmp(pointerSecondWord, nameFunction) == 0 || strcmp(pointerThirdWord, nameFunction) == 0 || strcmp(pointerFourthWord, nameFunction) == 0)
				{
					//Если в строке есть открывающая и закрывающая круглые скобки...
					if (strstr(strSearchSpecialChars, "(") && strstr(strSearchSpecialChars, ")"))
					{
						//Если в строке присутствует точка с запятой...
						if (strstr(strSearchSpecialChars, ";"))
						{
							return 1;
						}
						return 0;
					}
				}
			}
		}
		return -1;
	}
	//Иначе не найдено 
	else
	{
		return -1;
	}
}

void removeCommentsFromFunctionText(char textFunction[][MAX_NUMBER_SYMBOLS], int numberRows)        //Текст функции слишком тривиальный, чтобы создавать тесты
{
	for (int a = 0; a < numberRows; a++)
	{
		strtok(textFunction[a], "//");
	}
}

void cutPartStr(char str[], char partStr[], char finishSymbol, char startStr[])
{
	//Находим указатель на последний символ части строки
	char* finishPrototip = strrchr(str, finishSymbol);

	//Находим указатель на первый символ части строки
	int indexStart = strspn(str, startStr);
	char* startPrototip = &str[indexStart];

	//Помещаем часть строки в результирующий массив
	int lengthPrototip = finishPrototip - startPrototip + 1;
	memcpy(partStr, startPrototip, lengthPrototip);
	partStr[lengthPrototip] = NULL;
}