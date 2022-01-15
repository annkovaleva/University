#ifndef SCIENCE_H
#define SCIENCE_H
#include <QString>

enum Area {Electronics, Chemistry, Physics, Biology, Math};

class Science
{
public:
    Science();

    Area getArea() const;
    QString getName() const;
    int getYear() const;
    int getId() const;

    void setArea(const Area& science);
    void setName(const QString& Name);
    void setYear(const int& Year);
    void setId(const int& Id);

    void operator=(const Science & other);
    bool operator==(const Science & other) const;
    bool operator!=(const Science & other) const;
    bool operator<(const Science & other) const;
    bool operator<=(const Science & other) const;
    bool operator>(const Science & other) const;
    bool operator>=(const Science & other) const;

//private:
    Area science;
    QString Name;
    int Year;
    int Id;
};

#endif // SCIENCE_H
