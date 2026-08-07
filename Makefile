CXX = g++ # use g++
CXXFLAGS = -Wall -std=c++17	# make flags
TARGET = main.exe	# target file name

# npcap flags
NPCAP_SDK = C:\npcap-sdk-1.16
CXXFLAGS += -I$(NPCAP_SDK)/Include
LDFLAGS  += -L$(NPCAP_SDK)/Lib/x64
LDLIBS   += -lwpcap -lPacket -lws2_32

# set the source of all cpp files as the src directory
SRC = $(wildcard src/*.cpp)

# all objects are built from src/ and place in build/
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))

# shows how tou build each object file
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)
# ^ g++ main.o -o main.exe

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# on build make the build directory
build:
	mkdir build

.PHONY: clean
clean:
	if exist build rmdir /s /q build
	if exist $(TARGET) del $(TARGET)