//
// Created by Dardan Matias Berisha on 21/06/23.
//

#include "ActivityLog.h"
#include <algorithm>

void ActivityLog::addActivity(const struct activity &a) {
    activities.push_back(a);
    std::sort(activities.begin(), activities.end()); //sorts by start time of activities
}

std::vector<activity> ActivityLog::getActivities(){
    return activities;
}

void ActivityLog::deleteActivity(struct activity &a){
    auto it = std::find(activities.begin(), activities.end(), a);
    activities.erase(it);
}
