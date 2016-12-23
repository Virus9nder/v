#pragma once

extern "C" __declspec(dllexport) void Virus();
extern "C" __declspec(dllexport) void Prosto();

extern "C" class __declspec(dllexport) MyDll
{
public:
	MyDll();
	void printInfo();
};



