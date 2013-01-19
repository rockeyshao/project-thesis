//============================================================================
// Name        : xJus-epos.cpp
// Author      : Hayk Martirosyan
// Description : Usage of the EPOS2 API over C++
//============================================================================

#include "xJus-epos.h"
#include "Definitions.h"
#include <iostream>
using namespace std;

// Protocol information
char deviceName[] = "EPOS2";
char protocolStackName[] = "EPOS2_USB";
char interfaceName[] = "USB";
char portName[] = "USB3";

// Protocol stack settings
const unsigned long BAUDRATE = 1000000;
const unsigned long TIMEOUT  = 500;

// Variables that hold error states
unsigned long errorCode;
const unsigned short ERROR_INFO_LENGTH = 100;
char errorInfo[ERROR_INFO_LENGTH];

// Handle of the connected device
void* device;

int main() {

	cout << "Attempting connection to " << deviceName;
	cout << " at " << portName << "..." << endl;
	device = VCS_OpenDevice(deviceName, protocolStackName, interfaceName, portName, &errorCode);
	printError();
	cout << "Connected Device" << ": " << device << endl;

	cout << "Attempting to set protocol stack settings with ";
	cout << "baudrate " << BAUDRATE << " and timeout " << TIMEOUT << "..." << endl;
	VCS_SetProtocolStackSettings(device, BAUDRATE, TIMEOUT, &errorCode);
	printError();

	//cout << "Closing connection to device..." << endl;
	//VCS_CloseDevice(device, &errorCode);
	//printError();

	return 0;
}

void printError() {
	VCS_GetErrorInfo(errorCode, errorInfo, ERROR_INFO_LENGTH);
	cout << "Error info: " << errorInfo << endl;
}
