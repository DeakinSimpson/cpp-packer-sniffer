/*
* Author: Deakin Simpson
* Created: 06/08/2026
*/

#include <iostream>
#include <pcap.h>
#include <fstream>
#include <string>

const std::string FILE_LOCATION = "test/pcap/test-data.pcap";

int main()
{
    std::cout << "Hello World!" << std::endl;




    // TODO: open file into memory, then later implement more efficient method
    // open file
    std::ifstream file(FILE_LOCATION);

    // check if file opened succefully
    if (!file.is_open())
    {
        std::cout << "Could not open file at: " << FILE_LOCATION << std::endl;
        return 1;
    }

    std::cout << "read: "<< file.get() << std::endl;




    // reader pcap header

    // ts seconds
    // ts microseconds

    // get capture packet length

    // original packet length

}