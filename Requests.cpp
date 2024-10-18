#include "Requests.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>

Requests::Requests(){
    ip_in = generateIP();
    ip_out = generateIP();
    Time = generateTime();
    job_type = generateJobType();
}

string Requests::generateIP(){
    srand(static_cast <unsigned>(time(0)));
    int it = 0;
    string IP;
    int count = 2;
    while(it < 7){
        if(count%2==0){
            IP += std::to_string(rand()%256);
        }
        else {
            IP += ".";
        }
        count+=1;
        it+=1;
    }
    return IP; 
}

int Requests::generateTime(){
    int time = rand() % 101;
    return time; 
}

char Requests::generateJobType() {
    int num;

    num = rand() % 2;

    if(num==0){
        return 'P';
    }
    else {
        return 'S';
    }
}

string Requests::get_ip_in() {
    return ip_in;
}

string Requests::get_ip_out() {
    return ip_out;
}

char Requests::get_job_type(){
    return job_type;
}

int Requests::get_time(){
    return Time;
}

/* For testing 

int main () {
    Requests req;
    std::cout << req.get_ip_in() << std::endl;
    std::cout << req.get_job_type() << std::endl;
}
*/