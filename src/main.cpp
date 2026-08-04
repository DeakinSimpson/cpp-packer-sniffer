/*
* Author: Deakin Simpson
* Created: 06/08/2026
*/

#include <iostream>
#include <pcap.h>
#include <fstream>
#include <string>
#include <vector>

const std::string FILE_LOCATION = "test/pcap/test-data.pcap";
static void ReadAllBytes(std::string filename, std::vector<char>& results);

int main()
{
    std::cout << "Hello World!" << std::endl;

    // TODO: open file into memory, then later implement more efficient method
    // read all bytes
    std::vector<char> bytes;
    ReadAllBytes(FILE_LOCATION, bytes);

    std::cout << "first byte: " << bytes[0] << std::endl;

    // reader pcap header

    // ts seconds
    // ts microseconds

    // get capture packet length

    // original packet length

}

// a char is always 1 byte so we use char instead of BTYE
static void ReadAllBytes(std::string filename, std::vector<char>& results)
{
    // open the file
    std::ifstream ifs(filename, std::ios::binary|std::ios::ate);

    // get the end position of the file
    std::ifstream::pos_type pos = ifs.tellg();

    // if the files end position is 0, close
    if (pos == 0)
    {
        // set results to empty char vector
        results = std::vector<char>{};
        return;
    }

    // seeks the beginning of the file
    ifs.seekg(0, std::ios::beg);

    // resize results to be the size of the file
    results.resize(pos);

    // read from the beging to the end
    ifs.read(&results[0], pos);
}