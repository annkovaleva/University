set program=12_Kovaleva_AA.exe

echo. > results.txt
echo 01 - типовой тест >> results.txt
%program% < test01.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 02 - текст функции - одна строчка >> results.txt
%program% < test02.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 03 - текста нет >> results.txt
%program% < test03.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 04 - максимальный размер текста (20) >> results.txt
%program% < test04.txt >> results.txt