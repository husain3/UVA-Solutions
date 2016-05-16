#include <iostream>

int main()
{
	using namespace std;

	int currArray[3000];
	FILE * fp;
	fp = fopen("r", "arrays.txt");
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
				currArray[iterator] = (int) num;
				iterator++;
			}
		}
	} else {
		printf("File cannot be opened\n");
	
	}


}
