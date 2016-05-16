#include <stdio.h>




int main()
{
	//int inputNumbers[100000];
	int inputNumber = -1;
	//int  secondNumber = -1;



	int i =0;
//	while (firstNumber != 0 && secondNumber != 0)
	{
		
		scanf("%d", &inputNumber);
		//inputNumbers[i] = firstNumber;
		//inputNumbers[i+1] = secondNumber;
		int j =0;
		int tempInput;
		while(tempInput != 0)
		{
			tempInput = inputNumber / 10;
			j++;

		}
		printf("%d ", j);
		//i = i+2;

	}

/*	i = 0;
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


	}*/



}
