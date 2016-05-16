#include <stdio.h>

int main()
{
	using namespace std;

	int currArray[3000];
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
				fscanf(fp, "%c", &num);
				int a = (int) num;
				currArray[iterator] = a;
				iterator++;
			}
		}
	} else {
		printf("File cannot be opened\n");
	
	}


}
