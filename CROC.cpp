#include "CROC.h"



CROC::CROC()
{
}


CROC::~CROC()
{
}


string CROC::GetStrImageFilename()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return m_strImageFilename;
}


int CROC::GetnFO()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return m_nFO;
}


int CROC::GetnFR()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return m_nFR;
}


int CROC::GetnFC()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return m_nFC;
}


double CROC::GetRecall()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return m_recall;
}


double CROC::GetPrecision()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return m_precision;
}


void CROC::SetStrImageFilename(string strImageFilename)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	m_strImageFilename = strImageFilename;
}


void CROC::SetnFO(int nFO)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	m_nFO = nFO;
}


void CROC::SetnFR(int nFR)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	m_nFR = nFR;
}


void CROC::SetnFC(int nFC)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	m_nFC = nFC;
}


void CROC::SetRecall(double recall)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	m_recall = recall;
}


void CROC::SetPrecision(double precision)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	m_precision = precision;
}
