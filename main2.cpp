#include <vcruntime.h>
#include <windows.h>
#include <iostream>

double getDiskFreeSpacePercentage()
{
	DWORD lpSectorsPerCluster,
		lpBytesPerSector,
		lpNumberOfFreeClusters,
		lpTotalNumberOfClusters;

	if (GetDiskFreeSpace(NULL,
		&lpSectorsPerCluster,
		&lpBytesPerSector,
		&lpNumberOfFreeClusters,
		&lpTotalNumberOfClusters))
	{
		return double(lpNumberOfFreeClusters) * double(lpSectorsPerCluster) * double(lpBytesPerSector);
	}
	else
	{
		return 0;
	}
}

int main(int argc, char *argv[])
{
    using namespace std;

    setlocale(LC_ALL, ".1251");

    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof (statex);

    GlobalMemoryStatusEx (&statex);

    cout << "RAM " << statex.ullTotalPhys / (1024 * 1024) << " MB's\n";

    cout << "HDD " << getDiskFreeSpacePercentage()  / (1024 * 1024)<< " MB's\n";

    return 0;   
}