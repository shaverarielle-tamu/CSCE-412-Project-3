#include "Web_servers.h"
#include "Load_balancer.h"
#include "Requests.h"
#include <iostream>

using namespace std; 

int main() {
    int num_servers;
    int runtime;
    cout << "Enter number of servers ";
    cin >> num_servers;
    cout << "Enter load balancer runtime";
    cin >> runtime;

    Load_balancer lb(num_servers);

    for (int i = 0; i < num_servers * 100; ++i) {
        Requests request;
        lb.add_request(request);
    }

    lb.balance(runtime);

    cout << "Process complete..." << endl;
    cout << "Runtime was " << runtime << "clock cycles" << endl;
}