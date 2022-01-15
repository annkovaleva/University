#pragma once
//!Максимальное количество строк в функции
int const MAX_NUMBER_ROWS = 20;

//!Максимальное количество символов в строке функции
int const MAX_NUMBER_SYMBOLS = 500;

//!Список допустимых возвращаемых значений
char const returnTypes[10][10] = { "int", "void", "char", "float", "double", "unsigned", "signed", "short", "long"};

/*!Главная функция, которая генерирует прототип
 \ param [in] textFunction - текст функции
 \ param [in] nameFunction - название функции
 \ param [in] numberRows - число строк в тексте функции
 \ param [out] strPrototip - строка с прототипом
 */
int generatePrototip (char textFunction[][MAX_NUMBER_SYMBOLS], int numberRows, char nameFunction[], char strPrototip[]);
/*Возвращает 1, прототип сгенерирован\найден;
  Возвращает 0, прототип не найден */

/*!Функция, которая определяет вид строки 
 \ param [in] textFunction - строка
 \ param [in] nameFunction - название функции
 */
int findEntryName (char textFunction[], char nameFunction[]);
/*Возвращает 1 - прототип;
  Возвращает 0 - заголовок;
  Возвращает -1 - не найдено*/

/*!Функция, которая убирает комментарии из всего текста
 \ param[in] textFunction - текст функции
 \ param[in] numberRows - число строк в тексте функции */
void removeCommentsFromFunctionText(char textFunction[][MAX_NUMBER_SYMBOLS], int numberRows);

/*!Функция, которая вырезает часть строки
 \ param [in]  str - строка, из которой происходит вырезка
 \ param [out] partStr - строка с вырезкой
 \ param [in]  startStr - строка с символами, которые нужно игнорировать при вырезке перед нужной частью
 \ param [in]  finishSymbol - символ, до которого нужно вырезать часть строки
*/
void cutPartStr(char str[], char partStr[], char finishSymbol, char startStr[]);
