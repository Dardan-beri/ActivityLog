//
// Created by Dardan Matias Berisha on 19/06/23.
//

#include "Activity.h"
using namespace std;

Activity::Activity(string desc, Date start, Date end): description(desc), start_time(start), end_time(end){}

int Activity::durationInMinutes() const {
    //TODO calcola la durata
}