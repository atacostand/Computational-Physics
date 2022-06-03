/* The following program determines the probability of each number appearing on a 6-sided die by
rolling one a large number of times. However, there are parts missing. Complete it and verify it
works.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* insert roll() function prototype here */
int rnd(int);
int roll;
int n;
int main(void)
{
    int histogram[11] = { 0 };
    int i,k,times;
    float dice,sides;

    srand((unsigned)time(NULL)); /* seed random number generator */

    /* initialize all elements of histogram to 0 here */

    printf("This program will roll a die and return the measured\n");
    printf("probability of each number appearing.\n");
    printf("How many dice do you have?:\n");
    scanf("%f",&dice);
    printf("How many sides are on the dice?: \n");
    scanf("%f",&sides);
     printf("How many times should I roll the die? ");
    scanf("%d",&times);
    printf("Your numbers are: \n");
    /* insert the commands to roll the die using the function roll()
        the appropriate number of times here. Perform the loop over
        i in main. roll() should only update the histogram */

    for (i=0;i<=times;i++){
        roll=(float)rnd(i);
        histogram[roll]++;
        printf("%d \n",roll+2);

    }

    printf("The probability of each number appearing is: \n");
    printf("Number Probability\n");
    /* insert the commands for printing the fraction of times each
    number appeared here */

    for(k=0;k<11;k++){
        int index=k+2.0;
        printf("%i appears %d/%d times.\n",index,histogram[k],times);
    }
    return 0;
}

/* insert the appropriate function for roll() here. Use the function
rnd() to generate the random numbers */

int rnd(int n) // Random number 0..n-1 using high bits of rand()
{
    n=11;
    return (int)((float)n*rand()/(RAND_MAX+1.0));
}

