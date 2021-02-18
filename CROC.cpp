#include "CROC.h"



CROC::CROC()
{
}


CROC::~CROC()
{
}


string CROC::GetStrImageFilename()
{
	// TODO: 여기에 구현 코드 추가.
	return m_strImageFilename;
}


int CROC::GetnFO()
{
	// TODO: 여기에 구현 코드 추가.
	return m_nFO;
}


int CROC::GetnFR()
{
	// TODO: 여기에 구현 코드 추가.
	return m_nFR;
}


int CROC::GetnFC()
{
	// TODO: 여기에 구현 코드 추가.
	return m_nFC;
}


double CROC::GetRecall()
{
	// TODO: 여기에 구현 코드 추가.
	return m_recall;
}


double CROC::GetPrecision()
{
	// TODO: 여기에 구현 코드 추가.
	return m_precision;
}


void CROC::SetStrImageFilename(string strImageFilename)
{
	// TODO: 여기에 구현 코드 추가.
	m_strImageFilename = strImageFilename;
}


void CROC::SetnFO(int nFO)
{
	// TODO: 여기에 구현 코드 추가.
	m_nFO = nFO;
}


void CROC::SetnFR(int nFR)
{
	// TODO: 여기에 구현 코드 추가.
	m_nFR = nFR;
}


void CROC::SetnFC(int nFC)
{
	// TODO: 여기에 구현 코드 추가.
	m_nFC = nFC;
}


void CROC::SetRecall(double recall)
{
	// TODO: 여기에 구현 코드 추가.
	m_recall = recall;
}


void CROC::SetPrecision(double precision)
{
	// TODO: 여기에 구현 코드 추가.
	m_precision = precision;
}
