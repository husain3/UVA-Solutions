#include <stdio.h>
#include <cmath>
#include <stdlib.h>



int main()
{
	using namespace std;
	
	int currArrayAlloc = 10;
	int elementDiffAlloc = 10;
	int * currArray;
	int * elementDiff;
	currArray = (int *) malloc(currArrayAlloc);
	elementDiff = (int *) malloc(elementDiffAlloc);
	
	FILE * fp;
	fp = fopen("arrays.txt", "r");
	if(fp != NULL)
	{
		char  num;
		fscanf(fp, "%c", &num);
		while(!feof(fp))
		{	
			int iterator = 0;
			while(num != '\n')
			{	
				if(num != ' ' && num != '-')
				{
					int a = (int) num - '0';
					currArray[iterator] = a;
					iterator++;
				}
		
				fscanf(fp, "%c", &num);	
#if DEBUG
				printf("iterator: %d\n", iterator);		
#endif
				if(iterator == currArrayAlloc)
				{
					currArrayAlloc+=10;
					currArray = (int *) malloc(currArrayAlloc);
				}
			}
		
			if(iterator == 0)
			{
				fscanf(fp, "%c", &num);
				continue;

			}
			int elementDiffSize = 0;
#if DEBUG
			for(int i = 0; i < iterator; i++)
			{
				printf("%d ", currArray[i]);

			}

			printf("\n");	
#endif
			for(int i = 0; i < iterator; i++ )
			{
				int diff = currArray[i] - currArray[i + 1];
				
				elementDiff[i] = abs(diff);
				elementDiffSize = i;
			
			}
			iterator = 0;
#if DEBUG
			for(int i = 0; i < elementDiffSize; i++)
			{
      				printf("%d ", elementDiff[i]);

			}
#endif
			bool isJolly = true;
			for(int j = 0; j < elementDiffSize-1; j++) 
			{
				int number = elementDiff[j];
				
				if(elementDiff[j+1] == number || elementDiff[j+1] == number-1)
				{
#if DEBUG
					printf("elementDiff: %d, number %d\n", elementDiff[j+1], number);
#endif		
				} else {
#if DEBUG
					printf("elementDiff: %d, number %d\n", elementDiff[j+1], number);
#endif	
					isJolly = false;
					break;
				}
			}
			elementDiffSize = 0;
			if(isJolly == true)
			{
				printf("Jolly\n");

			} else {
				printf("Not jolly\n");
			}
			fscanf(fp, "%c", &num);		
		}
	} else {
		//printf("File cannot be opened\n");
		return 0;
	}


}
