/* blackjack.c: blackjack simulation         */

/* author: James Holt                        */

/* modifications:                            */
/* 2/28/2023 EA initial version              */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

        /* Main Function */

int main(void)
{
        srand( time(NULL));
  
        /* variable definitions */

        int card, choice, sum=0, dealersum=0;
        

        /* User's turn */

	printf("************************************\n");
        printf("** Welcome to CENG 231 BlackJack! **\n");
        printf("************************************\n");

	/* computation */
	card = rand() % 13 + 1;
	if(card == 11 || card == 12 || card == 13)
	  {
	    card = 10;
	  }
	printf("Your first card is: %d \n", card);
	if(card == 1)
	  {
	    /* input */
	    printf("You drew an ace, do you want it to count as a 1 or 11? \n");
	    scanf("%d", &choice);
	    if(choice == 1)
	      {
		card = 1;
	      }
	    if(choice == 11)
	      {
		card = 11;
	      }
	  }
	sum += card;

        /* Output */
	while(sum <= 21)
	  {
	    printf("Do you want another card?\n");
	    printf("Type 1 for Yes, 0 for No: ");
	    scanf("%d", &choice);
	    if(choice == 1)
	      {
		card = rand() % 13 + 1;
		printf("Your next card is: %d \n", card);
		if(card == 11 || card == 12 || card == 13)
		  {
		    card = 10;
		  }
		if(card == 1)
		  {
		    printf("You drew an ace, do you want it to count as a 1 or 11? \n");
		    scanf("%d", &choice);
		    if(choice == 1)
		      {
			card = 1;
		      }
		    if(choice == 11)
		      {
			card = 11;
		      }
		  }
		sum += card;
		
		printf("Your combined value is: %d\n", sum);
	       }
	     if(sum > 21)
	       {
		printf("Sorry. You lose!\n");
		return 0;
	       }
	     if(choice == 0)
	       {
		 break;
	       }
	    }

	/* dealer's turn */
	while(dealersum < 21)
	  {
	    printf("Dealer draws another card\n");
	    card = rand() % 13 + 1;
	    if(card == 11 || card == 12 || card == 13)
                 {
                   card = 10;
                 }
	    printf("Dealer's card is %d\n", card);
	    dealersum += card;
	    printf("Dealer's value is %d, you have %d\n", dealersum, sum);
	    if(dealersum >= sum && dealersum <= 21)
	      {
		printf("Dealer wins. You lose!\n");
		break;
	      }
	    if(dealersum > 21)
	      {
		printf("Dealer loses. You win!\n");
		break;
	      }
	  }
	

       
        return 0;
}
