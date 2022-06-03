


//This program will perform basic vector operations
#include <stdio.h>
#include <vector>

/* prototypes for vector math functions */
void vec_sum(float a[], float b[], float result[], int n);
float vec_dot(float a[], float b[], int n);
void vec_cross(float a[], float b[], float result[], int n);
float vec_angle(float a[], float b[], int n);

int main () {
float a[3],b[3],c[3],sum=0, maga=0, magb=0; //a, b, and c are arrays that will store the vector information
int i,option;
printf("What is your first vector (x,y,z)? "); //these two lines fill vector/array a
scanf("%f,%f,%f",&a[0],&a[1],&a[2]);
printf("\nWhat is your second vector (x,y,z)? "); //these two lines fill vector/array b
scanf("%f,%f,%f",&b[0],&b[1],&b[2]);
printf("\nWhat would you like to find (enter 1 for sum, 2 for dot product, 3 for cross\nproduct, and 4 for the angle between them)?: ");
scanf("%d",&option);
if(option==1){ //This section finds the sum of a and b
vec_sum(a, b, c, 3);
printf("\nThe sum of your vectors is <%.2f,%.2f,%.2f>\n",c[0],c[1],c[2]);
}
else if(option==2){ //This section finds the dot product of a and b

printf("\nThe dot product of your vectors is %.2f\n",vec_dot(a, b, 3));
}
else if(option==3){ //This section finds the cross product of a and b
vec_cross(a, b, c, 3);
printf("\nThe cross product of your vectors is <%.2f,%.2f,%.2f>\n",c[0],c[1],c[2]);
}
else if(option==4){ //This section finds the angle between a and b

printf("\nThe angle between your vectors is %.2f radians.\n", vec_angle(a,b,3)); //the formula here divides the dot product by the product of the magnitudes
}
else //This section handles invalid cases
printf("\nInvalid input\n");
return 0;
}

void vec_sum(float a[], float b[], float result[], int n)
{
int i;
for(i=0; i
result[i] = a[i] + b[i]; //each element in c is the sum of the corresponding elements in a and b
}

}

float vec_dot(float a[], float b[], int n)
{
float sum = 0;
int i;
for(i=0; i
sum+=a[i]*b[i]; //each element in c is the product of the corresponding elements in a and b
}
return sum;
}

void vec_cross(float a[], float b[], float result[], int n)
{
result[0]=a[1]*b[2]-a[2]*b[1];
result[1]=a[2]*b[0]-a[0]*b[2];
result[2]=a[0]*b[1]-a[1]*b[0];
}

float vec_angle(float a[], float b[], int n)
{
float sum = 0, maga = 0, magb = 0;
int i;
for(i=0; i
sum+=a[i]*b[i]; //finds the dot product of a and b
maga+=a[i]*a[i]; //finds the magnitude of a, squared
magb+=b[i]*b[i]; //finds the magnitude of b, squared
}
return (acosf((sum/(sqrt(maga)*sqrt(magb)))));
}
