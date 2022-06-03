#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


 float ran1(long *);
 long rnum; /* global variable for random number generator */

 int main(void)
{
        int i,k,sum=0,numtests=1000;
        int test[1001],histogram[500]={0};
        float r,alpha;
        int t,dt,tf,n,n0;
        char name[40];

        rnum=-time(NULL);
        ran1(&rnum); /* seed generator */


    printf("Enter the number of nuclei and press enter: \n");
    scanf("%d", &n);
    printf("Enter decay rate: \n");
    scanf("%f", &alpha);
    printf("Enter the time step : \n");
    scanf("%d", &dt);
    printf("Enter total time \n");
    scanf("%d",&tf);
   printf("Enter the name of the data file: ");
    scanf("%40s",name);

     FILE *data;

        if ((data=fopen(name,"w"))==NULL) {
                            printf("Can't open file %s.\n",name);
                            exit(1); // Exits program
                            }

    for(i=1;i<=numtests;i++){
        /*printf("Test %d \n",i);*/
          test[i]=0;
        for (t=dt;t<=tf;t+=dt) {
                n0=n;

                for (k=1;k<=n0;k++){

                    if (ran1(&rnum)<alpha*dt) {
                            n--;
                        test[i]++;
                        sum += test[i];
                          histogram[test[i]]++;
                        }
                }
        }
     /*printf("%d \n",test[i]);
            printf("\n");

            fprintf(data, "%d  %d\n",i,test[i]);*/
    }
        printf("Decays   Count :\n");
        for(i=1;i<=499;i++){
            printf("%d  %d \n",i,histogram[i]);
            fprintf(data,"%d , %d\n",i,histogram[i]);

        }
        printf("The total decays were %d ",sum);
        fprintf(data,"The total decays were %d ",sum);

        if (fclose(data)) printf("Error in closing data file.\n");
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

