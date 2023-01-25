// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
NOTE TO READERS:
    1. I have tried to keep variable names as descriptive as possible.
    2. I have tried to summarize the code logic in the comments.
    3. P2**... indicates code additions to p1 of lab1.
*/

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 24th January'2023
*/

#include "TimedTask.h"

sdds::TimedTask::TimedTask() = default; // default constructor of class 'TimedTask'
sdds::TimedTask::Task::Task() = default; // default constructor of struct 'Task'

void sdds::TimedTask::startClock()
{
    _t_start = steady_clock::now(); // stores time_point at instance of function call.
}

void sdds::TimedTask::stopClock()
{
    _t_end = steady_clock::now(); // stores time_point at instance of function call.
}

void sdds::TimedTask::addTask(const string task_name)
{
    static int counter = 0; // counter will be initialised only once.

    if ((_n_records == counter) && (_n_records < 10)) // safety: (_n_records == counter) To prevent _n_records from getting changed anywhere else.
    {
        _task_obj[_n_records] = Task(task_name, "nanoseconds", duration_cast<duration<long long, std::nano>>(_t_end - _t_start)); // store event objects.

        ++_n_records; // counter and _n_records must have same value to store event objects.
        ++counter;
    }
}
