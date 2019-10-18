/*
 *  New Timer
 *  Author: Ian Lantzy
 */

#include <chrono>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

typedef chrono::high_resolution_clock ClockT;
typedef chrono::nanoseconds TimeT;
typedef chrono::time_point<ClockT,TimeT> TimePointT;

inline void calc_time(TimePointT * start, TimePointT * stop, TimeT * t) {
  *t = chrono::duration_cast<TimeT>(*stop-*start);
}

int main(int argc, char const *argv[]) {
  int status;
  pid_t pid;
  TimeT duration;

  TimePointT start = ClockT::now();
  if ((pid = fork()) > 0) {
    waitpid(pid, &status, 0);
  }
  else if (pid == 0) {
    execvp(argv[1], (char * const *)&argv[1]);
    exit(0);
  }
  else exit(1);
  TimePointT stop = ClockT::now();

  calc_time(&start, &stop, &duration);
  if (pid > 0) {
    cout << duration.count() << " ns" << endl;
  }
  else if (pid < 0) {
    cout << "ERROR: Failed to start child process!" << endl;
  }
  return 0;
}
