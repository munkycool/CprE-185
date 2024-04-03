#include<stdio.h>
#include<math.h>
//=============//
#define PI 3.14
//=============//
//declaring functions

void coneProperties(float height, float radius, float result[]);

//=============//	
int main() {
	//variable declaration
	float height, radius;

	float result[3];

	//Function call to caluculate the cone properties

	
	//ask the user to enter the height and the radius
	printf("Please enter the height:\n");
	scanf("%f",&height);
	printf("Please enter the radius:\n");
	scanf("%f", &radius);

	coneProperties(height, radius, result);
	
	//Generate the output by calling the functions
	printf("The area of the cone is: %f\n",result[0]);
	printf("The area of the base is: %f\n",result[1]);
	printf("The volume of the cone is:%f\n",result[2]);
	
}

void coneProperties (float h, float r, float result[]) {
	result[0] = PI*r*sqrt(h*h+r*r);
	result[1] = PI*r*r;
	result[2] = (1.0/3)*PI*r*r*h;
}

/*
//defining the functions
//================================//
//coneArea function//
double coneArea(float h, float r){
	return PI*r*sqrt(h*h+r*r);
}//===============================//
//baseArea function//
double baseArea(float r){
	return PI*r*r;
}//==============================//
//coneVolume function//
double coneVol(float h, float r){
	return (1.0/3)*PI*r*r*h;
}//==============================//
*/