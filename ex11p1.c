#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float ran1(long *);
long rnum; /* global variable for random number generator */
int main(void)
{
int i, numtests=1000;
int test[10];
float r;
rnum=-time(NULL);
ran1(&rnum); /* seed generator */
for (i=0;i<10;i++) test[i]=0;
for (i=1;i<=numtests;i++) {
r=ran1(&rnum);
test[(int)(10*r)]++;
}
for (i=0;i<10;i++) printf("%g\n",(float)test[i]/numtests);
return 0;
}
 /* generator from Numerical Recipes */
 /* returns a float uniformly distributed between 0 and 1 */

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
float ran1(long *idum)
{
int j;
long k;
static long iy=0;
static long iv[NTAB];
float temp;

if (*idum<=0 || !iy) {
   if (-(*idum)<1) *idum=1;
   else *idum= -(*idum);
   for (j=NTAB+7;j>=0;j--) {
        k=(*idum)/IQ;
        *idum=IA*(*idum-k*IQ)-IR*k;
        if (*idum<0) *idum+=IM;
        if (j<NTAB) iv[j]= *idum;
        }
        iy=iv[0];
    }
    k=(*idum)/IQ;
    *idum=IA*(*idum-k*IQ)-IR*k;
    if (*idum<0) *idum+=IM;
    j=iy/NDIV;
    iy=iv[j];  iv[j]= *idum;
    if ((temp=AM*iy)>RNMX) return RNMX;
    else return temp;
}
