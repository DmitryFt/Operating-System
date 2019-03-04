#include <QCoreApplication>
#include <windows.h>
#include <iostream>

extern "C" __declspec(dllimport)
BOOL __stdcall GetPhysicallyInstalledSystemMemory(PULONGLONG);

int main()
{
    ULONGLONG TotalMemoryInKilobytes;
    GetPhysicallyInstalledSystemMemory(&TotalMemoryInKilobytes);
    std::cout <<"RAM: "<< TotalMemoryInKilobytes/1024 << " MB" << std::endl;
    return 0;
}
