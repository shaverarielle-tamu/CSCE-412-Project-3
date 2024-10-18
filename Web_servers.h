#ifndef WEBSERVERS_H
#define WEBSERVERS_H
#include "Requests.h"
#include "Load_balancer.h"

class Web_servers {
    
    public:
        int server_id;
        Web_servers() {
            server_id = generateID();
        }
        bool processing_request();
        void process_request(Requests& request, Load_balancer& lb);
        void ask_for_request(Load_balancer& lb);
        int generateID();
};

#endif