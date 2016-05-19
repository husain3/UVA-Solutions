#include <stdio.h>
#include <cstdlib>




int main()
{

	int numOfNumbers;
	int numInSequence;
	int numberArray[3000];
	int elementDiff[3000];
	
	for(;;)
	{
		scanf("%d", &numOfNumbers);
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
			elementDiff[i] = abs(diff);
			elementDiffSize = i;
		}
		bool isJolly = true;
		for(int j = 0; j < elementDiffSize; j++)
		{
			int number = elementDiff[j];
			//printf("%d ", number);
			if(elementDiff[j+1] != number - 1)
			{
				isJolly = false;
				break;
			}

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
