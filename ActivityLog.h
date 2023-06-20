//
// Created by Dardan Matias Berisha on 19/06/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
#define ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
#include <vector>
#include "Activity.h"

class ActivityLog {
public:
    ActivityLog();
    ~ActivityLog();

    void addActivity(const Activity &a);
    Activity removeActivity(const Activity &a);
    void deleteActivity(Activity &a);

private:
    std::vector<Activity> activities;
};


#endif //ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
