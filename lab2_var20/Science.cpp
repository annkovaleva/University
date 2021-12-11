#include "Science.h"
#include "ui_mainwindow.h"
#include <QString>

Science::Science()
{

}

Area Science::getArea() const
{
    return this->science;
}

QString Science::getName() const
{
    return this->Name;
}

int Science::getYear() const
{
    return this->Year;
}



void Science::setArea(const Area& science)
{
    this->science = science;
}

void Science::setName(const QString& Name)
{
    this->Name = Name;
}

void Science::setYear(const int& Year)
{
    this->Year = Year;
}



void Science::operator=(const Science &other)
{
    this->setArea(other.science);
    this->setYear(other.Year);
    this->setName(other.Name);
}

bool Science::operator==(const Science &other) const
{
    if(this->science == other.science && this->Year == other.Year && this->Name == other.Name)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool Science::operator!=(const Science &other) const
{
    if(this->science == other.science)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Science::operator<(const Science &other) const
{
    if(science < other.science)
    {
        return true;
    }
    else if(science == other.science)
    {
        if(Year < other.Year)
        {
            return true;
        }
        else if(Year == other.Year)
        {
            if(Name < other.Name)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}

bool Science::operator<=(const Science &other) const
{
    if(science < other.science)
    {
        return true;
    }
    else if(science == other.science)
    {
        if(Year < other.Year)
        {
            return true;
        }
        else if(Year == other.Year)
        {
            if(Name < other.Name)
            {
                return true;
            }
            else if(Name == other.Name)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Science::operator>(const Science &other) const
{
    if(science > other.science)
    {
        return true;
    }
    else if(science == other.science)
    {
        if(Year > other.Year)
        {
            return true;
        }
        else if(Year == other.Year)
        {
            if(Name > other.Name)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Science::operator>=(const Science &other) const
{
    if(science > other.science)
    {
        return true;
    }
    else if(science == other.science)
    {
        if(Year > other.Year)
        {
            return true;
        }
        else if(Year == other.Year)
        {
            if(Name > other.Name)
            {
                return true;
            }
            else if(Name == other.Name)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}




















































