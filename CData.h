#ifndef CDATA_H
#define CDATA_H
#include"CUser.h"
#include<fstream>
#include<map>
#include<list>
#include<iostream>
using namespace std;
#include "CUser.h"
#include"CAdmin.h"
#include"CDoctor.h"
#include "CKeshi.h"
#include"CJiuzhen.h"

class CData
{
public:
	CData();
	~CData();
	static void WriteUserFile();
	static void ReadUserFile();

	static void WriteDoctorFile();
	static void ReadDoctorFile();

	static void WriteAdminFile();
	static void ReadAdminFile();

	static void WriteKeshiFile();
	static void ReaKeshiFile();

	static void WriteJiuzhenFile();
	static void ReadJiuzhenFile();
};

#endif