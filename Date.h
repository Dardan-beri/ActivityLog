//
// Created by Dardan Matias Berisha on 20/06/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_DATE_H
#define ELABORATO_PROGRAMMAZIONE_DATE_H


#include <exception>
#include <string>

class Date {
public:
    Date(int year, int month, int day, int hour, int minute);
    ~Date();

    int getYear() const;
    void setYear(int year);
    int getMonth() const;
    void setMonth(int month);
    int getDay() const;
    void setDay(int day);
    int getHour() const;
    void setHour(int hour);
    int getMinute() const;
    void setMinute(int minute);

    bool isMonthCorrect(int month);
    bool isDayCorrect(int day);
    bool isHourCorrect(int hour);
    bool isMinuteCorrect(int minute);

    std::string getDate() const;
    std::string getTime() const;
    //TODO implementare overload di operatori = < >
    Date& operator=(const Date other);
    bool operator<(const Date other);
    bool operator>(const Date other);

private:
    int year;
    int month;
    int day;
    int hour;
    int minute;

    bool doesDayExist(int day) const;

};

class DateNumberOutOfRangeException : public std::exception{
public:
    char* what(){
        return "Wrong number number used.";
    }
};


#endif //ELABORATO_PROGRAMMAZIONE_DATE_H
