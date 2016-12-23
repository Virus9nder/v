#pragma once

extern "C" __declspec(dllexport) int Virus();
extern "C" __declspec(dllexport) int  Prosto();

extern "C" class __declspec(dllexport) MyDll
{
public:
	MyDll();
	int printInfo();
};



