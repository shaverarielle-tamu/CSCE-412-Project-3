#include <iostream>
#ifndef REQUESTS_H
#define REQUESTS_H
#include <string>
#include <random>

using std::string;
class Requests {
    private:
        string ip_in;
        string ip_out;
        int time;
        char job_type;
    public:
        Requests();
        string get_ip_in();
        string get_ip_out();
        char get_job_type();
};

#endif