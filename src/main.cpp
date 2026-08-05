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

struct PcapHeader {
    uint32_t magicNumbers;
    uint16_t majorVersion;
    uint16_t minorVersion;
    uint32_t reserved1;
    uint32_t reserved2;
    uint32_t network;
};

// a char is always 1 byte so we use char instead of BTYE
static void ReadPcapHeader(const std::string& filename, PcapHeader& pcapHeader)
{
    // open the file
    std::ifstream fs;
    fs.open(filename, std::ifstream::binary);
    if (!fs.good()) { return; }

    fs.read(reinterpret_cast<char*>(&pcapHeader.magicNumbers), sizeof(pcapHeader.magicNumbers));
    fs.read(reinterpret_cast<char*>(&pcapHeader.majorVersion), sizeof(pcapHeader.majorVersion));
    fs.read(reinterpret_cast<char*>(&pcapHeader.minorVersion), sizeof(pcapHeader.minorVersion));
    fs.read(reinterpret_cast<char*>(&pcapHeader.reserved1), sizeof(pcapHeader.reserved1));
    fs.read(reinterpret_cast<char*>(&pcapHeader.reserved2), sizeof(pcapHeader.reserved2));
    fs.read(reinterpret_cast<char*>(&pcapHeader.network), sizeof(pcapHeader.network));

    fs.close();
}

const std::string FILE_LOCATION = "test/pcap/test-data.pcap";

int main()
{
    std::cout << "Hello World!" << std::endl;

    // TODO: open file into memory, then later implement more efficient method
    // read all bytes
    PcapHeader pcapHeader;

    ReadPcapHeader(FILE_LOCATION, pcapHeader);

    std::cout << pcapHeader.magicNumbers << std::endl;
    // reader pcap header


    // ts seconds
    // ts microseconds

    // get capture packet length

    // original packet length

}