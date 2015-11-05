/*
 *  New Timer
 *  Author: Ian Lantzy
 */

#include <chrono>
#include <iostream>

using namespace std;

typedef chrono::high_resolution_clock ClockT;
typedef chrono::nanoseconds TimeT;
typedef chrono::time_point<ClockT,TimeT> TimePointT;

inline void calc_time(TimePointT * start, TimePointT * stop, TimeT * t) {
  *t = chrono::duration_cast<TimeT>(*stop-*start);
}

int main(int argc, char const *argv[]) {
  TimeT duration;
  TimePointT start = ClockT::now();
  // Execution to be timed here
  TimePointT stop = ClockT::now();
  calc_time(&start, &stop, &duration);
  return 0;
}
