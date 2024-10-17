#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "Web_servers.h"
#include "Requests.h"
#include <vector>
#include <queue>

using std::queue, std::vector;

class Load_balancer{
    private:
        queue<Requests> request_queue;
        vector<Web_servers> servers; 
    public:
        Load_balancer(int num_servers);
        void add_request(Requests request);
        void allocate_deallocate_servers();
        void manage_requests();
        void run_load_balancer(int runtime);
};