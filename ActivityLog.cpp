//
// Created by Dardan Matias Berisha on 21/06/23.
//

#include "ActivityLog.h"
#include <algorithm>

void ActivityLog::addActivity(const struct activity &a) {
    activities.push_back(a);
}

std::vector<activity> ActivityLog::getActivities(){
    return activities;
}

bool ActivityLog::deleteActivity(struct activity &a){

}
