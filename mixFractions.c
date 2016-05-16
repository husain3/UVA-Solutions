#include <stdio.h>




int main()
{
	int inputNumbers[100000];
	int firstNumber = -1;
	int  secondNumber = -1;



	int i =0;
	while (firstNumber != 0 && secondNumber != 0)
	{
		
		scanf("%d %d", &firstNumber, &secondNumber);
		inputNumbers[i] = firstNumber;
		inputNumbers[i+1] = secondNumber;


		i = i+2;

	}

	i = 0;
	int firstRead, secondRead, mixed, divideClean, remainder;;
	while(inputNumbers[i] != 0 && inputNumbers[i+1] != 0)
	{
		firstRead = inputNumbers[i];
		secondRead = inputNumbers[i+1];
		//while((firstRead / secondRead) != 0)
		//{
			
		mixed = firstRead/secondRead;
		divideClean = mixed * secondRead;
		firstRead = firstRead - divideClean;

		
		printf("%d %d / %d\n", mixed, firstRead, secondRead);
		


		//}

		i = i +2;


	}



}
