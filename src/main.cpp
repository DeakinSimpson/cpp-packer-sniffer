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

struct PcapHeader 
{
    uint32_t magicNumber;
    uint16_t majorVersion;
    uint16_t minorVersion;
    uint32_t reserved1;
    uint32_t reserved2;
    uint32_t network;
};

struct Packet 
{
    uint32_t timestampSeconds;
    uint32_t timestampFraction;
    uint32_t capturePacketLength;
    uint32_t originalPacketLength;
};

// a char is always 1 byte so we use char instead of BTYE
static void ReadPcapHeader(std::ifstream* fs, PcapHeader& pcapHeader)
{
    // cast the header of the file to 
    fs->read(reinterpret_cast<char*>(&pcapHeader.magicNumber), sizeof(pcapHeader.magicNumber));
    fs->read(reinterpret_cast<char*>(&pcapHeader.majorVersion), sizeof(pcapHeader.majorVersion));
    fs->read(reinterpret_cast<char*>(&pcapHeader.minorVersion), sizeof(pcapHeader.minorVersion));
    fs->read(reinterpret_cast<char*>(&pcapHeader.reserved1), sizeof(pcapHeader.reserved1));
    fs->read(reinterpret_cast<char*>(&pcapHeader.reserved2), sizeof(pcapHeader.reserved2));
    fs->read(reinterpret_cast<char*>(&pcapHeader.network), sizeof(pcapHeader.network));
}

/*
0 = invalid
1 = microseconds
2 = nanoseconds
*/
static char GetPcapMagicType(const PcapHeader* pcapHeader)
{
    // magic header types
    const uint32_t microSeconds = 2712847316;
    const uint32_t nanoSeconds = 2712812621;

    char val = '0';

    if (pcapHeader->magicNumber == microSeconds) { val = '1'; }
    if (pcapHeader->magicNumber == nanoSeconds) { val = '2'; }

    return val;
}



const std::string FILE_LOCATION = "test/pcap/test-data.pcap";

int main()
{
    std::cout << "Hello World!" << std::endl;

    // TODO: open file into memory, then later implement more efficient method

    // opens the file into memory
    std::ifstream fs;
    fs.open(FILE_LOCATION, std::ifstream::binary);
    if (!fs.good()) { return 1; }

    // reader pcap header
    PcapHeader pcapHeader;

    ReadPcapHeader(&fs, pcapHeader);

    std::cout << pcapHeader.magicNumber << std::endl;
    std::cout << GetPcapMagicType(&pcapHeader);

    // ts seconds
    // ts microseconds
    char timestampType = GetPcapMagicType(&pcapHeader);

    // get capture packet length

    // original packet length

    // cleanup
    fs.clear();

    return 0;
}