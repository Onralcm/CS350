#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int number;
  int preferences = 5;
  int votes[preferences];
  int threshold_value = 10;
  char dishes[5][10] = {"Kebab", "Burger", "Pasta", "Lahmacun", "Salad"};
  int count;
  
  for(int i=0;i<preferences;++i)
    votes[i] = 0;
   
  printf("Number of people:\n");
  scanf("%d", &number);
  
  for(int i=0;i<number;++i)
  {
    printf("%d. person:\n1-Kebab 2-Burger 3-Pasta 4-Lahmacun 5-Salad\n",i+1);
    for(int j=0;j<preferences;++j)
    {
    int vote;
    printf("%d. preference: ",j+1);
    scanf("%d", &vote);
    votes[--vote]+=(preferences-j);
    }
  }
  
  for(int i=0;i<preferences;++i)
  {
     if(votes[i] >= threshold_value)
     {
     	printf("%s: %d votes\n",dishes[i],votes[i]);
     	count++;
     }
  }
  
  if(count == 0)
     printf("You are eating at home/dorm today!\n");
  else
  {
     char shortList[count][10];
     int finalVotes[count];
     int index=0;
     int max;
     char ordered[10];
     
     for(int i=0;i<count;++i)
     	finalVotes[i] = 0;
     
     for(int i=0;i<preferences;++i)
     {
     	if(votes[i] >= threshold_value)
     	   strcpy(shortList[index++], dishes[i]);
     }
     
     for(int i=0;i<number;++i)
     {
     	printf("%d. person:\n",i+1);
     	for(int j=0;j<count;++j)
     	   printf("%d-%s ",j+1,shortList[j]);
     	printf("\n"); 	
	for(int j=0;j<count;++j)
	{
	   int finalVote;
	   printf("%d. preference: ",j+1);
	   scanf("%d", &finalVote);
	   finalVotes[--finalVote]+=(preferences-j);
	}
     }
     
     for(int i=0;i<count;++i)
     {
     	printf("%s: %d votes\n",shortList[i],finalVotes[i]);
     	if(finalVotes[i] > max)
     	{
     	   max = finalVotes[i];
     	   strcpy(ordered, shortList[i]);
     	}
     }
     
     printf("%s will be ordered with %d votes.\n",ordered,max);
  }
  
  return 0;
}
