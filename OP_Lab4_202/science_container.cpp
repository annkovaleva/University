#include "science_container.h"
#include "Science.h"
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

Science_container::Science_container()
{

}

int Science_container::count() const
{
    return science.size();
}

void Science_container::remove(int id)
{
    QList<Science>::Iterator iter;

    for(iter = science.begin(); iter!=science.end(); iter++)
    {
        if((*iter).getId() == id)
        {
             science.erase(iter);
             return;
        }
    }
}

void Science_container::clear()
{
     science.clear();
}

void Science_container::record(int id, Science &record) const
{
     record = science.operator[](id);
}

int Science_container::append(Science &record)
{
     QList<Science>::Iterator iter;
     int indexIn = 0;

     for(iter = science.begin(); iter!=science.end(); iter++)
     {
         if(*iter < record)
         {
             indexIn++;
         }
         else if(*iter == record)
         {
             indexIn++;
             break;
         }
     }

     science.insert(indexIn, record);

     return indexIn;

}

int Science_container::update(Science &record)
{
    remove(record.getId());

    int ID = append(record);

    return ID;

}

bool Science_container::saveInFile(QString filename, int startRecord, int numberRecords) const
{

    Science scienceCur;

    if(!filename.isEmpty())
    {
        QFile textFile(filename);
        bool open = textFile.open(QIODevice::WriteOnly);

        if(open == true)
        {
            QDataStream stream(&textFile);
            stream << numberRecords;

            for(int i = startRecord; i<startRecord+numberRecords; i++)
            {
                record(i, scienceCur);                
                stream << scienceCur.getId() << scienceCur.getArea() << scienceCur.getName() << scienceCur.getYear();
            }

        }
        textFile.close();

        return true;
    }
    else
    {
        return false;
    }
}


const QVector<Science> Science_container::records() const
{
    QVector <Science> vectorScience;

    for(int i=0; i<count(); i++)
    {
        vectorScience << science[i];
    }
    return vectorScience;
}


bool Science_container::load(QString filename)
{
    science.clear();

    Science scienceCur;

    if(!filename.isEmpty())
    {
        QFile textFile(filename);
        bool open = textFile.open(QIODevice::ReadOnly);

        if(open == true)
        {
            int size;
            QDataStream pOtOk(&textFile);
            pOtOk >> size;
            for(int i = 0; i<size; i++)
            {
                pOtOk >> scienceCur.Id;
                int area;
                pOtOk >> area;
                scienceCur.science = (Area)area;
                pOtOk >> scienceCur.Name >> scienceCur.Year;
                int index = append(scienceCur);
            }
        }
        else
        {
            return false;
        }
        textFile.close();
    }
    else
    {
        return false;
    }
    return true;
}















