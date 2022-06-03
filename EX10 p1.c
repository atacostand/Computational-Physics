#include <stdio.h>
#include <stdlib.h>
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
int main()
{
    int i,index;
    readfile(x,y,sigma,&index);

    printf("X[], Y[],\n");

    for (i=0;i<index;i++){
        printf("%lf ,%lf \n", x[i], y[i]);
    }
    return 0;
}
