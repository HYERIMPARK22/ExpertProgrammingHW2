#include <string>
#include <iostream>
#include <fstream>
#include "CROC.h"
#include <iomanip>
using namespace std;
const int NMAXARRAY = 100;
const int NMAXMETHOD = 5;
const int WIDTH = 10;

void ReadEvalFileToArray(string strEvaldata, int &nImage, int &nMethod,
	CROC pnROC[]);
void ComputeRecallAndPrecision(const int &nImage, const int &nMethod,
	CROC pnROC[]);
void 	ComputeAverageOfRecallAndPrecision(const int &nImage, const int &nMethod,
	CROC pnROC[]);

int main()
{
	//string pstrFilename[NMAXARRAY];
	//int pnFO[NMAXARRAY], pnFR[NMAXARRAY], pnFC[NMAXARRAY];
	//double pPrecision[NMAXARRAY], pRecall[NMAXARRAY];
	//double pAvgprecision[NMAXMETHOD], pAvgrecall[NMAXMETHOD];
	CROC pnROC[100];
	int nImage, nMethod;
	string strEvaldata;
	strEvaldata = "HW2-2.txt";

	//1
	ReadEvalFileToArray(strEvaldata, nImage, nMethod,
		pnROC);
	//2
	ComputeRecallAndPrecision(nImage, nMethod,
		pnROC);
	//3
	ComputeAverageOfRecallAndPrecision(nImage, nMethod,
		pnROC);
	//Prob4();

}

void ReadEvalFileToArray(string strEvaldata, int &nImage, int &nMethod,
	CROC pnROC[])
{
	// 파일 읽기
	// array에 넣기
	ifstream myReadFile;
	int nItem = 0;
	string strFilename;
	int nFO, nFR, nFC;
	myReadFile.open(strEvaldata);
	myReadFile >> nImage >> nMethod;
	cout << "[File Read]\n";
	cout << "image number is " << nImage << " method number is " << nMethod << endl;
	for (int nIndex = 0; nIndex < nImage; nIndex++)
	{
		for (int nCount = 0; nCount < nMethod; nCount++)
		{
			myReadFile >> strFilename >> nFO >> nFR >> nFC;
			pnROC[nItem].SetStrImageFilename(strFilename);
			pnROC[nItem].SetnFO(nFO);
			pnROC[nItem].SetnFR(nFR);
			pnROC[nItem].SetnFC(nFC);
			cout << pnROC[nItem].GetStrImageFilename() << setw(WIDTH) << setfill(' ') << pnROC[nItem].GetnFO() << setw(WIDTH) << setfill(' ') << pnROC[nItem].GetnFR() << setw(WIDTH) << setfill(' ') << pnROC[nItem].GetnFC() << endl;
			nItem++;
		}
	}
	myReadFile.close();
}

void ComputeRecallAndPrecision(const int &nImage, const int &nMethod,
	CROC pnROC[])
{
	int nItem = 0;
	double recall, precision;
	int nFO, nFR, nFC;
	cout << "\n\n[File Name, recall, precision]\n";
	for (int nIndex = 0; nIndex < nImage; nIndex++)
	{
		for (int nCount = 0; nCount < nMethod; nCount++)
		{
			nFO = pnROC[nItem].GetnFO();
			nFR = pnROC[nItem].GetnFR();
			nFC = pnROC[nItem].GetnFC();

			recall = (double)nFC / nFO;
			pnROC[nItem].SetRecall(recall);		//recall

			precision = (double) nFC / nFR;	//precision
			pnROC[nItem].SetPrecision(precision);

			cout << "<" << nCount + 1 << "번 방법>\n";
			cout << setw(WIDTH) << setfill(' ') << pnROC[nItem].GetStrImageFilename() << setw(WIDTH) << setfill(' ') << pnROC[nItem].GetRecall() << setw(WIDTH) << setfill(' ') << pnROC[nItem].GetPrecision() << endl;
			nItem++;
		}
	}
}

//입력 : pPrecision, pRecall, nImage, nMethod
//출력 : pAvgprecision[nMethod], pAvgrecall[nMethod]
void 	ComputeAverageOfRecallAndPrecision(const int &nImage, const int &nMethod,
	CROC pnROC[])
{
	//int nItem = 0;
	//double recallSum[NMAXMETHOD];
	//double precisionSum[NMAXMETHOD];
	//double recall, precision;
	////0으로 초기화
	//for (int nCount = 0; nCount < nMethod; nCount++)
	//{
	//	precisionSum[nCount] = 0;
	//	recallSum[nCount] = 0;
	//}

	//for (int nIndex = 0; nIndex < nImage; nIndex++)
	//{
	//	for (int nCount = 0; nCount < nMethod; nCount++)
	//	{
	//		precision = pnROC[nItem].GetPrecision();
	//		precisionSum[nMethod] += precision;

	//		recall = pnROC[nItem].GetRecall();
	//		recallSum[nMethod] += recall;
	//		nItem++;
	//	}
	//}

	//for (int nCount = 0; nCount < nMethod; nCount++)
	//{
	//	precisionSum[nCount] /= nImage;
	//	recallSum[nCount] /= nImage;
	//}

	//for (int nCount = 0; nCount < nMethod; nCount++)
	//{
	//	cout << precisionSum[nCount] << "  " << recallSum[nCount] << endl;
	//}
	
	double pAvgprecision[NMAXMETHOD], pAvgrecall[NMAXMETHOD];
	int nItem = 0;
	//0으로 초기화
	for (int nCount = 0; nCount < nMethod; nCount++)
	{
		pAvgrecall[nCount] = 0;
		pAvgprecision[nCount] = 0;
	}

	for (int nIndex = 0; nIndex < nImage; nIndex++)
	{
		for (int nCount = 0; nCount < nMethod; nCount++)
		{
			pAvgrecall[nCount] = pAvgrecall[nCount] + pnROC[nItem].GetRecall();
			pAvgprecision[nCount] = pAvgprecision[nCount] + pnROC[nItem].GetPrecision();
			nItem++;
		}
	}

	for (int nCount = 0; nCount < nMethod; nCount++)
	{
		pAvgrecall[nCount] /= nImage;
		pAvgprecision[nCount] /= nImage;
	}

	for (int nCount = 0; nCount < nMethod; nCount++)
	{
		cout << "\n<" << nCount + 1 << "번 방법>\n";
		cout << "recall : "<< pAvgrecall[nCount];
		cout << "     precision : " << pAvgprecision[nCount] << endl;
	}

}

