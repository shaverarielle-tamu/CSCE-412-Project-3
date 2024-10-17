#include <iostream>
#include "Web_servers.h"
#include "Load_balancer.h"

using std::cout, std::endl;
Web_servers::Web_servers() {}

void Web_servers::processRequest(Requests& request, Load_balancer& lb){
    cout << "Processing request: " << endl;
    
}