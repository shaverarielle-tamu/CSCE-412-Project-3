#include <iostream>
#include "Web_servers.h"
#include "Load_balancer.h"
#include "Requests.h"

using std::cout, std::endl;
Web_servers::Web_servers() {}

void Web_servers::process_request(Requests& request, Load_balancer& lb){
    cout << "Server " << server_id << "received request from " << request.get_ip_in() << " to " << request.get_ip_out() << endl;
    cout << "Job: " << request.get_job_type() << endl;
    cout << "Processing for " << request.get_time() << " clock cycles" << endl;
    for(int i = 0; i < request.get_time(); ++i){
        cout << ".";
    }
    cout << endl;
    cout << "Server " << server_id << "has processed the request." << endl;

    if(!lb.requests_empty()){
        ask_for_request(lb);
    }
    else {
        cout << "No more requests from server " << server_id << " ..." << endl;
    }

}

int Web_servers::generateID(){
    return rand() % 900000 + 100000;
}

void ask_for_request(Load_balancer& lb){
    cout << "Waiting for next request..." << endl;
    lb.send_request(*this);
}