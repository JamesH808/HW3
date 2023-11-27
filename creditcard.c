/* creditcard.c: paying off credit card debt */

/* author: James Holt                        */

/* modifications:                            */
/* 2/28/2023 EA initial version              */

#include <stdio.h>

/* Main Function */

int main(void)
{
        /* variable definitions */

  double limit, balance, monthly, newBalance, interest, monthTotal;
	float a;
	int month=0;

        /* input section */

        printf("Enter the credit limit            : ");
        scanf("%lf", &limit);
        printf("\n");

        printf("Enter the balance on the card     : ");
        scanf("%lf", &balance);
        printf("\n");

        printf("Enter the APR                     : ");
        scanf("%f", &a);
        printf("\n");

        printf("Enter the monthly payment         : ");
        scanf("%lf", &monthly);
        printf("\n");

	
	printf("   Month        Balance            Interest         Payment           New Balance  \n");

	while (newBalance >= 0 )
	  {
	    month += 1;
	    
	    /* computation section */

	    interest = balance * (a / 100) / 12;
	    if (balance < monthly)
	      {
		monthly = balance + interest;
	      }
	    monthTotal += monthly;
	    newBalance = balance + interest - monthly;
	    
	    /* output section */ 
	    printf("   %2d           %8.2lf         %8.2lf           %-8.2lf           %-8.2lf           \n", month, balance, interest, monthly, newBalance);
	    
	   

	    balance = newBalance;
	    if (newBalance == 0)
	      {break;}
	    
	  }

	printf("It will take $%.2lf over %d month to pay off this debt.\n", monthTotal, month);
	
       
	

	return 0;
}
