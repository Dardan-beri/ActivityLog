//
// Created by Dardan Matias Berisha on 19/06/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_ACTIVITY_H
#define ELABORATO_PROGRAMMAZIONE_ACTIVITY_H


#include <string>
#include "Date.h"

class Activity {
public:

    Activity(std::string desc, Date start, Date end);
    ~Activity();

    std::string getDescription()const{
        return description;
    }
    Date getStart_time() const{
        return start_time;
    }
    Date getEnd_time() const{
        return end_time;
    }

    void setDescription(std::string desc){
        description = std::move(desc);
    }
    void setStart_time(const Date &start){
        start_time = start;
    }
    void setEnd_time(const Date &end){
        end_time = end;
    }

    int durationInMinutes() const;

private:
    std::string description;
    Date start_time;
    Date end_time;

};


#endif //ELABORATO_PROGRAMMAZIONE_ACTIVITY_H
