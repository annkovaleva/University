#pragma once
//!������������ ���������� ����� � �������
int const MAX_NUMBER_ROWS = 20;

//!������������ ���������� �������� � ������ �������
int const MAX_NUMBER_SYMBOLS = 500;

//!������ ���������� ������������ ��������
char const returnTypes[10][10] = { "int", "void", "char", "float", "double", "unsigned", "signed", "short", "long"};

/*!������� �������, ������� ���������� ��������
 \ param [in] textFunction - ����� �������
 \ param [in] nameFunction - �������� �������
 \ param [in] numberRows - ����� ����� � ������ �������
 \ param [out] strPrototip - ������ � ����������
 */
int generatePrototip (char textFunction[][MAX_NUMBER_SYMBOLS], int numberRows, char nameFunction[], char strPrototip[]);
/*���������� 1, �������� ������������\������;
  ���������� 0, �������� �� ������ */

/*!�������, ������� ���������� ��� ������ 
 \ param [in] textFunction - ������
 \ param [in] nameFunction - �������� �������
 */
int findEntryName (char textFunction[], char nameFunction[]);
/*���������� 1 - ��������;
  ���������� 0 - ���������;
  ���������� -1 - �� �������*/

/*!�������, ������� ������� ����������� �� ����� ������
 \ param[in] textFunction - ����� �������
 \ param[in] numberRows - ����� ����� � ������ ������� */
void removeCommentsFromFunctionText(char textFunction[][MAX_NUMBER_SYMBOLS], int numberRows);

/*!�������, ������� �������� ����� ������
 \ param [in]  str - ������, �� ������� ���������� �������
 \ param [out] partStr - ������ � ��������
 \ param [in]  startStr - ������ � ���������, ������� ����� ������������ ��� ������� ����� ������ ������
 \ param [in]  finishSymbol - ������, �� �������� ����� �������� ����� ������
*/
void cutPartStr(char str[], char partStr[], char finishSymbol, char startStr[]);
