#pragma once
#include <string>
using namespace std;

class CROC
{
public:
	CROC();
	~CROC();

private:
	string m_strImageFilename;
	int m_nFO;
	int m_nFR;
	int m_nFC;
	double m_recall;
	double m_precision;

public:
	string GetStrImageFilename();
	int GetnFO();
	int GetnFR();
	int GetnFC();
	double GetRecall();
	double GetPrecision();

	void SetStrImageFilename(string strImageFilename);
	void SetnFO(int nFO);
	void SetnFR(int nFR);
	void SetnFC(int nFC);
	void SetRecall(double recall);
	void SetPrecision(double precision);
};

