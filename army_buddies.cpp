//
//  army_buddies.cpp
//  
//
//  Created by Arshad Husain on 2016-06-07.
//
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int number; 
	node *prev;
	node *next;   
};

struct lossPairs
{
    int leftMost;
    int rightMost;
    
};


node *start=NULL, *temp1, *temp2, *temp3;

void addNode(int numOfSoldiers);
void deleteNode(int leftMost, int rightMost);
int main()
{
	int numOfSoldiers, numOfLossReports, leftMost, rightMost;
	fscanf(stdin, "%d %d", &numOfSoldiers, &numOfLossReports);
	


	while(numOfSoldiers != 0 && numOfLossReports != 0)
	{
        //ADD FOR LOOP FOR ALLOCATION
        /*for(int i = 0; i < numOfSoldiers; i++)
        {
            addNode(i+1);
        }*/

        addNode(numOfSoldiers);
        
        /*temp3=start;
        if(temp3 != NULL) {
            while(temp3->next != NULL) {
                    printf("%d, ", temp3->number);
                    temp3 = temp3->next;
            }
            printf("%d\n", temp3->number);
        }*/
        
        lossPairs *lossPairsArray = (lossPairs *) malloc(numOfLossReports * sizeof(lossPairs));

        for(int i = 0; i < numOfLossReports; i++)
        {
            fscanf(stdin, "%d %d", &leftMost, &rightMost);
            lossPairsArray[i].leftMost = leftMost;
            lossPairsArray[i].rightMost = rightMost;
        
        }
		
        for(int i = 0; i < numOfLossReports; i++)
        {
            deleteNode(lossPairsArray[i].leftMost, lossPairsArray[i].rightMost);



        }
        //DEALLOCATE LINKED LIST

        free(lossPairsArray);
        printf("-\n");
        start = NULL;
		fscanf(stdin, "%d %d", &numOfSoldiers, &numOfLossReports);
	}



}

void addNode(int numOfSoldiers)
{
    temp1=new node;
    if(start==NULL)
    {
        //printf("inside addNode IF\n");
        temp1->number = 1;
        temp1->prev= NULL;
        temp1->next=NULL;
        start=temp1;
    }
    
    
    /*else
    {
        //printf("inside addNode ELSE\n");
        temp2=start;
        temp1->number= numberAssign;
        while(temp2->next != NULL)
            temp2=temp2->next;
        temp2->next=temp1;
        temp1->prev=temp2;
        temp1->next=NULL;

    }*/
    int i = 2;
    temp2 = start;
    while(i <= numOfSoldiers) //given number in fuction call
    {
        temp1 = new node;
        temp1->number = i;
        if(temp2->next == NULL)
        {
            temp2->next= temp1;
            temp1->prev = temp2;
            temp1->next = NULL;
        }
        temp2= temp2->next;
        i++;
        
    }
    
    
    
    
}

void deleteNode(int leftMost, int rightMost)
{
    temp1 = start;
    node *leftMostPointer, *rightMostPointer;
    leftMostPointer = new node;
    rightMostPointer = new node;
    int newLeftMost, newRightMost;
    int i = 1;
    while(temp1 != NULL)
    {
        
        /*
         INSTEAD, JUST DEALLOCATE NODES AND KEEP TRACK USING THE NUMBER IN THE NODES
        */
        
        //printf("temp1Pointer: %p\n", temp1);
        
        if(temp1->number == leftMost)
        {
            leftMostPointer = temp1;
            //printf("leftPointer: %p\n", leftMostPointer);
        }
        
        if(temp1->number == rightMost)
        {
            rightMostPointer = temp1;
            //printf("rightPointer: %p\n", rightMostPointer);
        }

        temp1=temp1->next;
        i++;
    }
    


    
    if (leftMostPointer->prev == NULL && rightMostPointer->next == NULL)
    {
        start = NULL;
        printf("* *\n");
        
    } else if (leftMostPointer->prev == NULL && rightMostPointer->next != NULL) {
        rightMostPointer = rightMostPointer->next;
        rightMostPointer->prev = NULL;
        
        start = rightMostPointer;
        
        printf("* %d\n", rightMostPointer->number);
        
    } else if (leftMostPointer->prev != NULL && rightMostPointer->next == NULL) {
        leftMostPointer = leftMostPointer->prev;
        leftMostPointer->next = NULL;
        
        start = leftMostPointer;
        
        printf("%d *\n", leftMostPointer->number);
    
    } else if (leftMostPointer->prev != NULL && rightMostPointer->next != NULL) {
        leftMostPointer = leftMostPointer->prev;
        rightMostPointer = rightMostPointer->next;
        
        leftMostPointer->next = rightMostPointer;
        rightMostPointer->prev = leftMostPointer;
        
        start = leftMostPointer;
        
        printf("%d %d\n", leftMostPointer->number, rightMostPointer->number);
    }
    

    
    
    
}
