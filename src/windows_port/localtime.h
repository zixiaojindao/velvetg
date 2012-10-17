#ifndef LOCALTIME_H
#define LOCALTIME_H

#define MICROSECONDS (1000 * 1000) 

#define timeradd(t1, t2, t3) do { \
(t3)->tv_sec = (t1)->tv_sec + (t2)->tv_sec; \
(t3)->tv_usec = (t1)->tv_usec + (t2)->tv_usec % MICROSECONDS; \
if ((t1)->tv_usec + (t2)->tv_usec > MICROSECONDS) (t3)->tv_sec ++; \
} while (0) 

#define timersub(t1, t2, t3) do { \
(t3)->tv_sec = (t1)->tv_sec - (t2)->tv_sec; \
(t3)->tv_usec = (t1)->tv_usec - (t2)->tv_usec; \
if ((t1)->tv_usec - (t2)->tv_usec < 0) (t3)->tv_usec --, (t3)->tv_usec += MICROSECONDS; \
} while (0) 


//#define timeradd(t1, t2, t3)
//#define timersub(t1, t2, t3)

struct timeval {
	long    tv_sec;         // seconds
	long    tv_usec;        // and microseconds
};


int gettimeofday (struct timeval *tv, void *tz);
#endif