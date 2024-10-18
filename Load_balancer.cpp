#include <iostream>
#include "Load_balancer.h"
#include <cstdlib>
#include "Web_servers.h"
#include "Requests.h"

using std::cout, std::endl;

Load_balancer::Load_balancer(int num_servers) : servers_requested(num_servers){
    for(int i = 0; i < num_servers; ++i){
        servers.push_back(Web_servers());
    }
}

void Load_balancer::add_request(Requests request){
    request_queue.push(request);
    allocate_deallocate_servers();
}

void Load_balancer::allocate_deallocate_servers(){
    if(request_queue.size() > servers.size() * 100){
        Web_servers new_server;
        servers.push_back(new_server);
        cout << "High request volume detected. " << endl;
        cout << "Generating new server... " << endl;
        cout << "ID: " << new_server.server_id << endl; 
    }

    if((request_queue.size() < servers.size() * 2 && servers.size() > servers_requested)){
        servers.pop_back();
        cout << "Low request volume detected. " << endl;
        cout << "Removing a server... " << endl;
    }
}

bool Load_balancer::requests_empty(){
    if(request_queue.empty()){
        return true;
    }
    else {
        return false;
    }
}
void Load_balancer::send_request(Web_servers& server){
    if(!requests_empty()){
        Requests request = request_queue.front();
        request_queue.pop();
        server.process_request(request, *this);
    }
    else {
        cout << "All requests processed..." << endl;
    }
    allocate_deallocate_servers();
}

void Load_balancer::balance(int runtime){
    int clock = 0;
    for (int clock = 0; clock < runtime; ++clock){
        if(rand() % 100 < 15){
            Requests request;
            add_request(request);
            cout << "Incoming request detected..." << endl;
        }
        for (auto& server : servers){
            if(!request_queue.empty()){
                send_request(server);
            }
        }
    }
}