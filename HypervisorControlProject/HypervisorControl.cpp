// HypervisorControlProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Hypervisor_Windows_1.7.0/include/brhypsrv.h"


int main(int argc, char* argv[], char* envp[])
{

    if (brhypsrvIsHypervisorRunning())
    {
        std::cout << "Hypervisor is running!\n";

        if (argc > 1)
        {
            if (strcmp(argv[1], "reboot") == 0)
            {
                brhypsrvSystemReboot();
            }
            else if (strcmp(argv[1], "shutdown") == 0)
            {
                brhypsrvSystemShutdown();
            }
            else
            {
                std::cout << "\nUse reboot or shutdown to perform an action\n";
            }
        }
        else
        {
            std::cout << "\nUse reboot or shutdown to perform an action\n";
        }
    }
    else
    {
        std::cout << "Hypervisor is NOT ACTIVE!\n";
    }

}
