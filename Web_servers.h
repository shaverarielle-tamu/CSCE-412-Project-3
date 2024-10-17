#ifndef WEBSERVERS_H
#define WEBSERVERS_H
#include "Requests.h"
#include "Load_balancer.h"

class Web_servers {
    
    public:
        Web_servers();
        bool processing_request();
        void processRequest(Requests& request, Load_balancer& lb);
        void ask_for_request(Load_balancer& lb);
};

#endif