#pragma comment(lib, "PowrProf.lib")

#include <iostream>
#include <Windows.h>
#include <powersetting.h>
#include <powrprof.h>

using namespace std;

int main() {

	GUID *pGuid;
	DWORD dwObtainActivePowerScheme = PowerGetActiveScheme(NULL, &pGuid);
	
	//Returns 0 if successful
	cout << "PowerGet: " << dwObtainActivePowerScheme << endl << endl;
 
	SYSTEM_POWER_STATUS pwrStatus;
	BOOL bPwr = GetSystemPowerStatus(&pwrStatus);
	bool bAC = 0;
	bAC = static_cast<bool>(pwrStatus.ACLineStatus);
	cout << "(0)DC (1)AC: " << bAC << endl << endl;

	ULONG uType = 0;
	int intNormalMonitorBrightness = 0;
	DWORD dwBufferSize = sizeof(intNormalMonitorBrightness);


	cout << "uType = " << uType << endl;
	cout << "NorMal Monitor Brightness = " << intNormalMonitorBrightness << endl;
	cout << "dwBufferSize = " << dwBufferSize << endl << endl;

	DWORD dwPowerReadAC = PowerReadACValue(NULL, pGuid, &GUID_VIDEO_SUBGROUP, &GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS,&uType, (BYTE*) &intNormalMonitorBrightness, &dwBufferSize);

	cout << "PowerRead: " << dwPowerReadAC << endl << endl;

	DWORD dwNewMonitorBrightness = 0;
	cout << "Set New Monitor Brightness: \n";
	cin >> dwNewMonitorBrightness;

	DWORD dwPowerWriteAC = PowerWriteACValueIndex(NULL, pGuid, &GUID_VIDEO_SUBGROUP, &GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS, dwNewMonitorBrightness);

	cout << "PowerWrite: " << dwPowerWriteAC << endl;

	DWORD dwReplaceActivePowerScheme = PowerSetActiveScheme(NULL, pGuid);
	cout << "PowerSet: " << dwReplaceActivePowerScheme << endl;
}