#include <stdio.h>

//C code to implement binary search using iterative function

int binarySearch(int ptr[], int low, int high, int x){
	while(low<=high){	
		int mid = (low + high)/2;//find mid value
				
		if(ptr[mid]==x)//check if mid value is the search number
			return mid;		
		
		if(ptr[mid]<x) //check if the search number higher than the mid value
			low = mid + 1;		
		
		else 
			high = mid - 1;//search number lower than the mid value
	}
	return -1; 
}
int main(){
	int n = 7; //no of elements
	int x; 
	int arr[7]= {4, 7, 16, 20, 37, 38, 43}; //sorted array	
	printf("Enter a number to search:");
	scanf("%d",&x);
	
	int sResult = binarySearch(arr, 0, n-1, x);
	
	if(sResult == -1)
		printf("Element is not present in the array\n");	
	else 
		printf("Element found in the array: arr[%d]=%d\n", sResult, arr[sResult]);
}
