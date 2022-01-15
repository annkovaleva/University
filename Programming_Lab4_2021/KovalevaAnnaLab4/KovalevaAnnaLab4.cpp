
#include <iostream>
#include "Header.h" 

int main()
{
    int vectorExc1[10] = {3, 5, 4,7,9,1,3};

    OrderArrInAscending(vectorExc1, 7);

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", vectorExc1[i]);
    }

    return 0;
}

void OrderArrInAscending(int vector[1000], int lengtn)
{
    int len1 = lengtn / 2;
    int len2 = lengtn - len1;
    int mergedVector[1000];

    if (lengtn == 2)    //Если в векторе два элемента
    {
        //Поменять их местами, если они неупорядочены
        if (vector[0] > vector[1])
        {
            int copy = vector[0];
            vector[0] = vector[1];
            vector[1] = copy;
        }
    }
    else if (lengtn > 2)  //ИначеЕсли в векторе больше двух элементов
    {
        //Упорядочить первую половину вектора
        OrderArrInAscending(vector, len1);
        //Упорядочить вторую половину вектора
        OrderArrInAscending(&vector[len1], len2);
        //Выполнить слияние половинок вектора, создав новый вектор
        int len = CombineOrderedVectors(vector, lengtn / 2, &vector[len1], lengtn - len1, mergedVector);
        //Скопировать содержимое нового вектора в исходный
        for (int i = 0; i < len ; i++)
        {
            vector[i] = mergedVector[i];
        }
    }


}

int CombineOrderedVectors(int vectorA[1000], int lengthA, int vectorB[1000], int lengthB, int mergedVector[1000])
{
    //...Считать объединенный вектор пустым

    //...Задать первый элемент первого вектора текущим
    int curElement1 = vectorA[0];
    //...Задать первый элемент второго вектора текущим
    int curElement2 = vectorB[0];

    int len1 = 0;                         //Переменная, которая будет превращаться в длину первого вектора
    int len2 = 0;                         //Переменная, которая будет превращаться в длину второго вектора
    int mergedLen = lengthA + lengthB;    //Длина выходного вектора
    int count = 0;                        //Счетчик, отвечающий за индекс вставляемого элемента
    /*
    Если первый вектор не завершился, а второй завершился или (оба вектора
    не завершились и текущий элемент из первого вектора меньше текущего
    элемента из второго)
    */
    while (len1!= lengthA || len2!= lengthB) 
    {

        if (lengthA != len1 && (lengthB == len2 || (lengthB != len2 && lengthA != len1 && (curElement1<curElement2))))
        {        
            //Записать текущий элемент первого вектора в конец объединенного вектора
            mergedVector[count] = curElement1;
            //Перейти к следующему элементу первого вектора
            len1++;
            count++;
            curElement1 = vectorA[len1];
        }
        else
        {
            //Записать текущий элемент второго вектора в конец объединенного вектора
            mergedVector[count] = curElement2;
            len2++;
            count++;
            //Перейти к следующему элементу второго вектора
            curElement2 = vectorB[len2];
        }
    }

    return len1 + len2;
}
