#include<stdio.h>
//Hog progam counting in blocks of millions
int main()
{
	int i = 0;
	int nmillions;
	
	for(;;)
	{
		if((i%1000000)==0)
		{
			nmillions = i /1000000;
			printf("Now at %d million \n", nmillions);
  		}
		i++;
	}
}