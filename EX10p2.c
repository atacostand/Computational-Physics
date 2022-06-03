#include <stdio.h>
#include <math.h>

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

            sx= sx+ x[i]/pow(sigma[i],2);.

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
        parameter[4]= parameter[4]+ (pow(y[i]-f*x[i],2)/pow(sigma[i],2));

        }
        return;
}
int main(void)
{
    int i;
    int index=10;
    double fit[4];
    double x[10]= {1,2,3,4,5,6,7,8,9,10};
    double y[10]= {2,4,6,8,3,4,1,8,6,11};
    double sigma[10]= {1,1,1,1,1,1,1,1,1,1};

    linearfit(x,y,sigma,fit,index);

   printf("Your linear coefficient is %lf with uncertainty %lf \n",fit[0],fit[1]);
   printf("Your constant coefficient is %lf with uncertainty %lf \n",fit[2],fit[3]);
   printf("Your Chi-square value is %lf \n",fit[4]);
    return 0;
}
