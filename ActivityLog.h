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
        s << hour << ":" << minute << ":" << second;
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
    struct time start,end;
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
    std::vector<activity> getActivities();
    bool deleteActivity(struct activity &a);
    bool deleteActivity(std::string &title);

private:
    std::vector<activity> activities;
};


#endif //ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
