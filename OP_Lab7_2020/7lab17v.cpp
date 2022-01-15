
#include <iostream>
#include <string.h>
#include <conio.h>
#include "str_unit.h"
#include "testing.h"

/*
В многострочном тексте (char text[20][81]) перевернуть заданное слово. Слово – это непрерывная последовательность букв и/или цифр. 
Разделителями слов могут быть любые другие символы.

Реализовать и использовать функцию переворота заданного слова в строке:

void reverseWords(char str[81], const char word[21]);

Входные данные:
str - исходная строка
word - переворачиваемое слово
Выходные данные:
str - строка с перевернутыми словами

Реализовать и использовать функцию поиска слова в строке:
int searchWord( const char str[81], const char word[21]);

Входные данные:
str – исходная строка
word – искомое слово
Выходные данные:
возвращаемое значение - индекс первого вхождения искомого слова в строку; возвращает -1, если слово не найдено

Формат входных данных. [слово] [M] [1-я строка] [2-я строка] и т.д. M – кол-во строк в тексте, целое число в диапазоне [1, 20].
Формат выходных данных. [1-я строка] [перевод строки] [2-я строка] и т.д.; пустые строки не печатать; если все строки пустые, то напечатайте сообщение «no solution». 
Пустыми строками считать строки, в которых либо нет символов, либо они содержат только «белые» разделители.
*/

int searchWord(const char str[81], const char word[21])
{
	const char* nul = str;
	const char* exit = strstr(str, word);
	int result;

	if (exit == NULL) 
	{
		result = -1;
	}
	else 
	{
		result = exit-str;
	}

	return result;
}

void reverseWords(char str[81], const char word[21])
{
	int mass[20];                                                  //массив, где хранятся индексы первой буквы неподходящих слов
	int len_word = strlen(word);
	char drow[21];
	strcpy(drow, word);
	_strrev(drow);
	int len_attempts = strlen(str) / len_word;                     //примерное количество попыток найти слово и его перевернуть
	char first_char_word = word[0];                                //первая буква слова
	int index_mass = 0;                                            //индекс массива с индексами первых букв неподходящих слов

	for (int d = 0; len_attempts > d; d++)                         //цикл, который ищет вхождение в слово 
	{
	int index = searchWord(str, word);                             

	if (!(index == -1))                                            //оператор, который проверяет, есть ли вообще слово в строке
	{
		if (index == 0)                                            //оператор, проверяющий индекс слова
		{
			if (!(isalnum(str[len_word])))                         //оператор, проверяющий, является ли вхождение целым словом
			{
				for (int i = 0; i < len_word; i++)                 //замена слова на перевернутое
				{
					str[i] = drow[i];
				}
			}
		}
		else
		{
			if ((!(isalnum(str[index - 1]))) && (!(isalnum(str[index + len_word]))))             //проверяет, является ли вхождение целым словом
			{
				for (int i = 0; i < len_word; i++)                 //замена слова на перевернутое
				{
					str[index + i] = drow[i];
				}
			}
			else
			{
				char e = '^';                                      //замена первой буквы неподходящих вхождений,
				str[index] = e;                                    //чтобы программа шла проверять слова дальше 
                mass[index_mass] = index;                          //занесение индексов в массив
	           	index_mass++;
			}
		}
	}
}
	for (int w = 0; w < index_mass; w++)                           //замена первых букв неподходящих слов на родные
	{
		str[mass[w]] = first_char_word;
	}
}

void reverseManyWords(char str[81], const char words[21][81], int N)
{
	for (int q = 0; q<N  ; q++) 	
	{
		int mass[20];                                                  //массив, где хранятся индексы первой буквы неподходящих слов
		int len_word = strlen(words[q]);
		char drow[21];
		strcpy(drow, words[q]);
		_strrev(drow);
		_strupr(drow);
		int len_attempts = strlen(str) / len_word;                      //примерное количество попыток найти слово и его перевернуть
		char first_char_word = words[q][0];                             //первая буква слова
		int index_mass = 0;                                             //индекс массива с индексами первых букв неподходящих слов

		for (int d = 0; len_attempts > d; d++)                          //цикл, который ищет вхождение в слово 
		{
			int index = searchWord(str, words[q]);                      

			if (!(index == -1))                                         //оператор, который проверяет, есть ли вообще слово в строке
			{
				if (index == 0)                                         //оператор, проверяющий индекс слова
				{
					if (!(isalnum(str[len_word])))                      //оператор, проверяющий, является ли вхождение целым словом
					{
						for (int i = 0; i < len_word; i++)              //замена слова на перевернутое
						{
							str[i] = drow[i];
						}
					}
					else
					{
						char e = '^';                                    //замена первой буквы неподходящих вхождений,
						str[index] = e;                                  //чтобы программа шла проверять слова дальше 
						mass[index_mass] = index;                        //занесение индексов в массив
						index_mass++;
					}
				}
				else
				{
					if ((!(isalnum(str[index - 1]))) && (!(isalnum(str[index + len_word]))))             //проверяет, является ли вхождение целым словом
					{
						for (int i = 0; i < len_word; i++)               //замена слова на перевернутое
						{
							str[index + i] = drow[i];
						}
					}
					else
					{
						char e = '^';                                    //замена первой буквы неподходящих вхождений,
						str[index] = e;                                  //чтобы программа шла проверять слова дальше 
						mass[index_mass] = index;                                   //занесение индексов в массив
						index_mass++;
					}
				}
			}

		}

		for (int w = 0; w < index_mass; w++)                              //замена первых букв неподходящих слов на родные
		{
			str[mass[w]] = first_char_word;
		}
	}
}

int main()
{
	char text[21][81], words[21][81];
	int M,N;

    scanf_s("%d", &M);
	scanf_s("%d", &N);
	getchar();

	for (int i = 0; i < N; i++)
	{
		gets_s(words[i]);
	}


	for (int i = 0; i < M; i++)
	{
		gets_s(text[i]);
	}

	reverseManyWords(text[0], words, N);

	for (int i = 0; i < M; i++) 
	{
	    puts(text[i]);
	}
	
	return 0;
}

