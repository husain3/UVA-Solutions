#include <stdio.h>
#include <cstdlib>




int main()
{

	int numOfNumbers;
	int numInSequence;
	int * numberArray;
	int * elementDiff;
	
	while(scanf("%d", &numOfNumbers))

	{
		numberArray = (int *) calloc(sizeof(int), 3000);
		elementDiff = (int *) calloc(sizeof(int), 3000);	
		
		int iterator = 0;
		while(iterator < numOfNumbers)
		{
			scanf("%d", &numInSequence);
			
			numberArray[iterator] = numInSequence;
			//numOfNumbers--;
			iterator++;
		}
		iterator = 0;
		int elementDiffSize = 0;
		for(int i = 0; i < numOfNumbers -1; i++)
		{
			//printf("%d ", numberArray[i]);
			int diff = numberArray[i] - numberArray[i + 1];	
			elementDiff[abs(diff)] = 1;
			elementDiffSize = i;
		}
		bool isJolly = true;
		//printf("elementDiffSize %d\n", elementDiffSize);
		for(int j = 1; j <= elementDiffSize; j++)
		{
			int number = elementDiff[j];
			//printf("%d ", number);
			/*if(elementDiff[j+1] != number - 1)
			{
				isJolly = false;
				break;
			}*/
		//	printf("%d ", elementDiff[j]);	
			if(elementDiff[j] == 0)
			{
				isJolly = false;
				break;

			}
			elementDiff[j] = 0;
		}
		if(isJolly == true)
		{
			printf("Jolly\n");

		} else {
			printf("Not jolly\n");
		}
		//printf("\n");
	}



}
