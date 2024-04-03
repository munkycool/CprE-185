#include<stdio.h>

//function declaration
	void scanArray(int a[][3],int n1,int n2);
	void printArray(int a[][3],int n1,int n2);
void main(){
	int n1 = 2;//number of rows
	int n2 = 3;//number of columns
	
	int a[n1][n2];//array declaration
	printf("\nEnter array elements: \n");
	scanArray(a,n1,n2);//update array info
	
	printf("\nPrinting current array------\n");
	printArray(a,n1,n2);//print array
	
	printf("\nUpdating array elements: \n");
	scanArray(a,n1,n2);//update array info
	
	printf("\nPrinting updated array------\n");
	printArray(a,n1,n2);//print array
	
}
//function definition to scan array
void scanArray(int a[][3],int n1,int n2){
	for(int i =0; i<n1; i++){
		for(int j =0; j<n2; j++){
			printf("\nEnter element[%d][%d]: ",i,j);
			scanf("%d", &a[i][j]);
		}
	}
}

//function definition to print array
void printArray(int a[][3],int n1,int n2){
	for(int i =0; i<n1; i++){
		for(int j =0; j<n2; j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
}
