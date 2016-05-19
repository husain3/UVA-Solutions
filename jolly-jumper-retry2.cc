#include <stdio.h>
#include <cstdlib>
#include <vector>
int main()
{
	int currentNum;
	int prevNum;
	int numOfNumbers;
	int prevDiff;
	int currentDiff;
	std::vector<bool> jollyChecker;
	
	while(scanf("%d", &numOfNumbers))
	{
		scanf("%d", &prevNum);
		scanf("%d", &currentNum);
		currentDiff = abs(currentNum - prevNum);
		prevNum = currentNum;
		prevDiff = currentDiff;
		int iterator = 2;
		//printf("Iterator: %d, numOfNumbers: %d: ", iterator, numOfNumbers);
		while(iterator < numOfNumbers)
		{
			scanf("%d", &currentNum);
			currentDiff = abs(currentNum - prevNum);
			if(currentDiff == prevDiff - 1 || currentDiff == prevDiff)
			{
				jollyChecker.push_back(true);

			} else {
				//printf("%d ", prevDiff);
				//printf("%d ", currentDiff);
				jollyChecker.clear();
				iterator = 0;
				printf("Not jolly\n");
				break;
			}
			prevNum = currentNum;
			prevDiff = currentDiff;		
			iterator++;
		}
		if(iterator == numOfNumbers)
		{
			jollyChecker.clear();
			iterator = 0;
			printf("Jolly\n");
			
		}
		iterator = 0;

	}

	return 0;
}
