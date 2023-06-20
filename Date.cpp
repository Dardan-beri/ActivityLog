//
// Created by Dardan Matias Berisha on 20/06/23.
//

#include <sstream>
#include "Date.h"

Date::Date(int year, int month, int day, int hour, int minute): year(year) {
    if(isMonthCorrect(month) && isDayCorrect(day) && isHourCorrect(hour) && isMinuteCorrect(minute)){
        Date::month = month;
        Date::day = day;
        Date::hour = hour;
        Date::minute = minute;
    }else
        throw DateNumberOutOfRangeException();
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {

    Date::month = month;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    if(!doesDayExist(day))
        throw DateNumberOutOfRangeException();
    Date::day = day;
}

int Date::getHour() const {
    return hour;
}

void Date::setHour(int hour) {
    if(hour < 0 || hour > 23)
        throw DateNumberOutOfRangeException();
    Date::hour = hour;
}

int Date::getMinute() const {
    return minute;
}

void Date::setMinute(int minute) {
    if(minute < 0 || minute > 59)
        throw DateNumberOutOfRangeException();
    Date::minute = minute;
}

bool Date::doesDayExist(int day) const {
    bool result = true;
    if(day < 1){
        result = false;
    }else if(month == 1 || month == 3 ||
        month == 5 || month == 7 ||
        month == 8 || month == 10 ||
        month == 12){
        if(day > 31)
            result = false;

    }else if(month == 2){
        if(year%4 == 0){
            if(day > 29)
                result = false;
        }else{
            if(day > 28)
                result = false;
        }
    }else{
        if(day > 30)
            result = false;
    }
    return result;
}

std::string Date::getDate() const {
    std::stringstream date;
    date << day << "/" << month << "/" << year;
    return date.str();
}

std::string Date::getTime() const {
    std::stringstream time;
    time << hour << ":" << minute;
    return time.str();
}

bool Date::isMonthCorrect(int month) {
    if(month < 1 || month > 12)
        return false;
    return true;
}

bool Date::isDayCorrect(int day) {
    return doesDayExist(day);
}

bool Date::isHourCorrect(int hour) {
    if(hour < 1 || hour > 12)
        return false;
    return true;
}

bool Date::isMinuteCorrect(int minute) {
    if(minute < 0 || minute > 59)
        return false;
    return true;
}