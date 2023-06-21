//
// Created by Dardan Matias Berisha on 21/06/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
#define ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
#include <string>
#include <sstream>
#include <vector>

struct time{
    int hour, minute, second;

    std::string toString(){
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

    bool operator<(struct time &other) const{
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
    int getDurationSeconds(){
        int sum = 0;
        sum += (end.hour - start.hour)*3600;
        sum += (end.minute - start.minute)*60;
        sum += end.second - start.second;
        return sum;
    }
};

class ActivityLog {
public:
    void addActivity(const struct activity &a);
    std::vector<activity> getActivities();
    bool deleteActivity(struct activity &a);

private:
    std::vector<activity> activities;
};


#endif //ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
