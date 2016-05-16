#include <stdio.h>
#include <cmath>

int main()
{
	using namespace std;

	int currArray[3000];
	int elementDiff[3000];
	FILE * fp;
	fp = fopen("arrays.txt", "r");
	if(fp != NULL)
	{
		char  num;
		fscanf(fp, "%c", &num);
		int iterator = 0;
		while(!feof(fp))
		{	
			while(num != '\n')
			{	
				if(num != ' ')
				{
					int a = (int) num - '0';
					currArray[iterator] = a;
					iterator++;
				}
				fscanf(fp, "%c", &num);
			}
			int elementDiffSize = 0;
			for(int i = 0; i < iterator; i++)
			{
				//printf("%d ", currArray[i]);

			}
		//	printf("\n");	
			for(int i = 0; i < iterator; i++ )
			{
				int diff = currArray[i] - currArray[i + 1];
				
				elementDiff[i] = abs(diff);
				elementDiffSize = i;
			
			}
			iterator = 0;
			for(int i = 0; i < elementDiffSize; i++)
			{
      				//printf("%d ", elementDiff[i]);

			}	
			bool isJolly = true;
			for(int j = 0; j < elementDiffSize-1; j++) 
			{
				int number = elementDiff[j];
				
				if(elementDiff[j+1] == number || elementDiff[j+1] == number-1)
				{

				} else {
					isJolly = false;
					break;
				}
			}
			elementDiffSize = 0;
			if(isJolly == true)
			{
				printf("Jolly\n");

			} else {
				printf("Not Jelly\n");
			}
			fscanf(fp, "%c", &num);		
		}
	} else {
		//printf("File cannot be opened\n");
		return 0;
	}


}
