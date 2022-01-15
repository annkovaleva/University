#ifndef SCIENCE_CONTAINER_H
#define SCIENCE_CONTAINER_H
#include "Science.h"

#include <QString>
#include <QList>
#include <QVector>

struct structScience
{
    QList <Science> S_struct;
};

class Science_container
{
    QList <Science> science;

public:

    Science_container();

    int count() const;                                                              //возвращает количество записей в базе
    void remove(int id);                                                            //удаляет запись по заданному идентификатору
    void clear();                                                                   //уничтожает все данные
    void record(int id, Science &record) const;                                     //возвращает запись по заданному идентификатору
    int append(Science &record);                                                    /*добавляяет запись в базу, возвращается позиция записи в соответствии с порядком сортировки, метод
                                                                                    генерирует уникальный идентификатор для указанной записи и он записывается в поле Id параметра record*/
    int update(Science &record);                                                    //изменяет запись в базе; возвращается новая позиция записи в соответствии с порядком сортировки
    bool saveInFile(QString filename, int startRecord, int numberRecords) const;    //сохраняет данные в заданный файл, возвращает false, если сохранить данные не удалось
    bool load(QString filename);                                                    /*загрузить данные из заданного файла; при этом предыдущие данные уничтожаются, возвращает false,
                                                                                    если сохранить данные не удалось*/
    bool isModified() const;                                                        //показывает, имеются ли изменения базы после её загрузки/сохранения
    const QVector<Science> records() const;                                         /*возвратить вектор записей, которые должны отображается в браузере с учетом сортировки записей,
                                                                                    где S — структура, соответствующая строке браузера (поля структуры совпадают с колонками барузера,
                                                                                    также структура содержат идентификатор записи)*/
};


#endif // SCIENCE_CONTAINER_H
