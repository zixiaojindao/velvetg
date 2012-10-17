#include <time.h>
#include "localtime.h"
/*#include <Windows.h>
int	gettimeofday (struct timeval *tv, struct timezone *tz) 
{ 
	FILETIME ft; 
	LARGE_INTEGER li; 
	__int64 t; 
	static int tzflag; 

	if (tv) 
	{ 
		GetSystemTimeAsFileTime (&ft); 
		li.LowPart = ft.dwLowDateTime; 
		li.HighPart = ft.dwHighDateTime; 
		t = li.QuadPart; // In 100-nanosecond intervals 
		t -= EPOCHFILETIME; // Offset to the Epoch time
		t /= 10; // In microseconds 
		tv->tv_sec = (long) (t / 1000000); 
		tv->tv_usec = (long) (t % 1000000); 
	} 

	if (tz) 
	{ 
		if (!tzflag) 
		{ 
			_tzset (); 
			tzflag++; 
		} 
		tz->tz_minuteswest = _timezone / 60; 
		tz->tz_dsttime = _daylight; 
	} 

	return 0; 
}*/

/*int
gettimeofday(struct timeval *tp, void *tzp)
{
    time_t clock;
    struct tm tm;
    SYSTEMTIME wtm;
    GetLocalTime(&wtm);
    tm.tm_year     = wtm.wYear - 1900;
    tm.tm_mon     = wtm.wMonth - 1;
    tm.tm_mday     = wtm.wDay;
    tm.tm_hour     = wtm.wHour;
    tm.tm_min     = wtm.wMinute;
    tm.tm_sec     = wtm.wSecond;
    tm. tm_isdst    = -1;
    clock = mktime(&tm);
    tp->tv_sec = clock;
    tp->tv_usec = wtm.wMilliseconds * 1000;
    return (0);
}*/

int gettimeofday(struct timeval *tp, void *tzp)
{
	time_t rawtime;
	struct tm *timeinfo;
	va_list args;

	time(&rawtime);
	timeinfo = localtime (&rawtime);
	tp->tv_sec = mktime(timeinfo);
	tp->tv_usec = 0;
	return 0;
}
