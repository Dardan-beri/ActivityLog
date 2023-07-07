//
// Created by Dardan Matias Berisha on 21/06/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
#define ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
#include <string>
#include <sstream>
#include <vector>

struct time{
    int hour, minute, second = 0;

    std::string toString() const{
        std::stringstream s;
        std::string str_hour = std::to_string(this->hour);
        std::string str_minute = std::to_string(this->minute);
        std::string str_second = std::to_string(this->second);
        if(str_hour.length() == 1)
            str_hour = "0" + str_hour;
        if(str_minute.length() == 1)
            str_minute = "0" + str_minute;
        if(str_second.length() == 1)
            str_second = "0" + str_second;

        s << str_hour << ":" << str_minute << ":" << str_second;
        return s.str();
    }

    bool operator==(struct time &other) const{
        return (hour == other.hour && minute == other.minute && second == other.second);
    }

    bool operator!=(struct time &other) const{
        return !(*this == other);
    }

    bool operator<(const struct time &other) const{
        bool result = false;
        if(hour < other.hour){
            result = true;
        }else if(hour == other.hour){
            if(minute < other.minute){
                result = true;
            }else if(minute == other.minute){
                if(second < other.second){
                    result = true;
                }
            }
        }
        return result;
    }
};

struct activity{
    std::string description, title;
    struct time start, end;
    bool operator==(const struct activity &other) const{
        return title == other.title;
    }

    bool operator!=(const struct activity &other) const{
        return title != other.title;
    }

    bool operator<(const struct activity &other) const{
        return start < other.start;
    }

    std::string toString() const{
        std::stringstream s;
        s << "Title: " << title << std::endl << "Description: " << description << std::endl
          << "Start: " << start.toString() << std::endl << "End: " << end.toString() << std::endl;
        return s.str();
    }
};

class ActivityLog{
public:
    bool addActivity(const struct activity &a);
    std::vector<activity> getActivities() const;
    bool deleteActivity(struct activity &a);
    bool deleteActivity(std::string &title);
    struct activity operator[](int pos) const;

private:
    std::vector<activity> activities;
};


#endif //ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
