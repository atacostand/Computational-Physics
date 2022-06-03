#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXDATA 100

double x[MAXDATA];
double y[MAXDATA];
double sigma[MAXDATA];


void readfile(double x[], double y[], double sigma[], int * entries)
{
    /* read data into x[] and y[]
    fill sigma[] with 1's
    determine the value of entries */

    char name[40];
    FILE *data;

    *entries=0;

    printf("Enter the name of the data file: ");
    scanf("%40s",name);

    if ((data=fopen(name,"r"))==NULL) {
        printf("Can't open file %s.\n",name);
        exit(1); // Exits program
    }
    // Assume data file contains 2 columns of data with no header
    while (*entries<MAXDATA &&
        fscanf(data,"%lf %lf",&x[*entries],&y[*entries])==2) {
            sigma[*entries]=1;
            (*entries)++;
    }
    if (fclose(data)) printf("Error in closing data file.\n");
    return;
}

void linearfit(double x[], double y[], double sigma[],
                double parameter[], int entries)
    {
        /* given x[], y[], sigma[], and entries
            fill parameter[] as follows:
            parameter[0] = linear coefficient
            parameter[1] = uncertainty in linear coefficient
            parameter[2] = constant coefficient
            parameter[3] = uncertainty in constant coefficient
            parameter[4] = chi-square */

        double s=0, sx=0, sy=0, sxx=0, sxy=0, delta, f;
        int i;

        /* use a loop to calculate the values of s, sx, sy,
            sxx, and sxy here */
        for (i=0;i<entries;i++){

            s=s+1/pow(sigma[i],2);

            sx= sx+ x[i]/pow(sigma[i],2);

            sy= sy+ y[i]/pow(sigma[i],2);

            sxx= sxx+ pow(x[i],2)/pow(sigma[i],2);

            sxy= sxy+ x[i]*y[i]/pow(sigma[i],2);
        }

        delta=s*sxx-sx*sx;

        /* calculate the values of parameter[0] through parameter[3]
            here */
            parameter[0]=((s*sxy)-(sx*sy))/(delta);
            parameter[1]= sqrt(s/delta);
            parameter[2]=((sxx*sy)-(sx*sxy))/(delta);
            parameter[3]= sqrt(sxx/delta);
            parameter[4]=0;

        /* use a loop to calculate the value of parameter[4] here.
        to simplify the logic, use f to hold the current value of
        the fitted function: f=parameter[0]*x[i]+parameter[2]
        you may use pow() to do the squaring if you wish */

        for (i=0;i<entries;i++){
        f=parameter[0]*x[i]+parameter[2];
        parameter[4]= parameter[4]+pow((y[i]-f*x[i]),2)/pow((sigma[i]),2);
        }
        return;
}

int main()
{
    int i,index;
    double fit[4];

    readfile(x,y,sigma,&index);
    linearfit(x,y,sigma,fit,index);

    for(i=0;i<5;i++){
    printf("paramater[%d] is : %lf \n",i,fit[i]);
    }
    return;
}
