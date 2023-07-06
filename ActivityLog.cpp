//
// Created by Dardan Matias Berisha on 21/06/23.
//

#include "ActivityLog.h"
#include <algorithm>

bool ActivityLog::addActivity(const struct activity &activity) {
    auto it = std::find(activities.begin(), activities.end(), activity);
    if (it == activities.end()) {
        activities.push_back(activity);
        std::sort(activities.begin(), activities.end()); //sorts by start time of activities
        return true;
    }else{
        return false;
    }
}

std::vector<activity> ActivityLog::getActivities() const{
    return activities;
}

bool ActivityLog::deleteActivity(struct activity &activity){
    auto it = std::find(activities.begin(), activities.end(), activity);
    if(it != activities.end()) {
        activities.erase(it);
        return true;
    }
    return false;
}

bool ActivityLog::deleteActivity(std::string &title){
    struct activity a;
    a.title = title;
    auto it = std::find(activities.begin(), activities.end(), a);
    if(it != activities.end()) {
        activities.erase(it);
        return true;
    }
    return false;
}

struct activity ActivityLog::operator[](int pos) const{
    return activities[pos];
}
