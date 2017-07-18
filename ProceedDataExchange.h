#include <windows.h>
#include <iostream>
#include <tchar.h>
#ifndef __PROCEED_DATA_EXCHANGE_H   
#define __PROCEED_DATA_EXCHANGE_H

#define NEWDATA 1
#define EXISTDATA 0
#define NOEXISTDATA -1

#define ASKFORWRITEFAIL -2
#define ASKFORREADFAIL -3

using namespace std;
typedef struct
{
	long int dataOffset[10];
	long int dataID[10];
	long int arrayLen;
} DataT;
class ProceedDataExchange
{
private:
	HANDLE hMapFile;				//map handle(data map)
	HANDLE hMapFileWRLock;		//(lock map)

	HANDLE hMutexWRLock;			//(mutex handle)
	HANDLE hEventWRLock;			//(event handle)

	HANDLE lockStart;				//Memory Start handle
	HANDLE hMutexWRLockStart;	//Lock Start handle

	LPCTSTR memoryPBuf;			//memory pointer
	LPCTSTR memoryPBufWRLock;	//lock memory pointer
	DataT dataInform;

	int askWriteLock(int);
	void unLockWriteLock(void);
	int askReadLock(int);
	void unLockReadLock(void);
public:
	ProceedDataExchange(TCHAR memoryName[], long int memorySize);
	~ProceedDataExchange();
	int writePackage(void *PData,long int dataSize,long int dataID,int blockFlag);//write data package
	int readPackage(void *PData, long int dataSize, long int dataID,int blockFlag);//read data package
};

#endif	
