#include <iostream>
#ifndef REQUESTS_H
#define REQUESTS_H
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

using std::string;
class Requests {
    private:
        string ip_in;
        string ip_out;
        int Time;
        char job_type;

        // Functions to generate data
        int generateTime();
        char generateJobType();
        string generateIP();
    public:
        Requests();
        string get_ip_in();
        string get_ip_out();
        char get_job_type();
};

#endif