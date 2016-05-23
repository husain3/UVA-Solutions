#include <stdio.h>
#include <unordered_map>

int main()
{
	int numTests;
	int numCharMapping;
	unsigned char charToMap;
	int intToMap;
	char line[10001];
	int numOfLines;

	std::unordered_map<unsigned char, int> paidCharacters;

	fscanf(stdin ,"%d\n", &numTests);

	for(int i = 0; i < numTests; i++)
	{
		fscanf(stdin ,"%d\n", &numCharMapping);
		for(int j = 0; j < numCharMapping; j++)
		{
			fscanf(stdin , "%c %d\n", &charToMap, &intToMap);
			std::pair<unsigned char, int> charAndPrice (charToMap, intToMap);
			paidCharacters.insert(charAndPrice);
			//printf("%c %d\n", charToMap, intToMap);
			
		}
		fscanf(stdin, "%d\n", &numOfLines);
		//printf("%d\n", numOfLines);
		double currentPrice;
		//int charPrice;
		for(int j = 0; j < numOfLines; j++)
		{
			//fgets(line, 10001, stdin);
			unsigned char character;
			int k = 0;
			//printf("%s", line);
			character = '0';
			//printf("%c", character);
			while(character != 10  && character != 255)
			{
				int c = fgetc(stdin);
				character = c;
				//printf("%u", character);
				std::unordered_map<unsigned char, int>::const_iterator got = paidCharacters.find(character);
				if(got != paidCharacters.end())
				{	
					double charPrice = got->second;
					charPrice = charPrice / 100;	
				//	printf("%f\n", charPrice);
					currentPrice += charPrice;
				}
				line[k] = '\0';
				k++;
			}
			
		}
		printf("%.2f$\n", currentPrice);
		currentPrice = 0;
	}

	return 0;
}
