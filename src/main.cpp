/*
* Author: Deakin Simpson
* Created: 06/08/2026
*/

#include <iostream>
#include <pcap.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

const std::string FILE_LOCATION = "test/pcap/test-data.pcap";
static void ReadAllBytes(std::string filename, std::vector<char>& results);
static std::string HexToString(std::vector<char> hex, int const hex_length);

int main()
{
    std::cout << "Hello World!" << std::endl;

    // TODO: open file into memory, then later implement more efficient method
    // read all bytes
    std::vector<char> bytes;
    ReadAllBytes(FILE_LOCATION, bytes);

    std::cout << HexToString(bytes, 4) << std::endl;

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

static std::string HexToString(std::vector<char> hex, int const hex_length)
{
    std::stringstream ss;

    ss << "0x";
        
    for (int i = 1; i < hex_length + 1; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int) static_cast <unsigned char>(hex[hex_length - i]);
    }

    return ss.str();
}