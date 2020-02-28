/* THIS PROGRAM SORTS ARRAY DEMONSTRATION PURPOSES */
/* GTU RULEZ */
#include<stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0


int PrintSelection(int selection){
 printf("Selected Menu item is:");
 printf("%d\n",selection);
 return 1;

}

int DisplayMenu(){
 int selection;
 printf("\e[2J"); // clears screen

 printf("%s","\e[5;31;47mWELCOME TO ADDING PROGRAM\e[0m\n");
 printf("%s","(1) Add two numbers\n");
 printf("%s","(2) Sort an array\n");
 printf("%s","(3) Subtract two numbers\n");
 printf("%s","(4) Divide numbers\n");
 printf("%s","(5) Summarize numbers with words\n");
 printf("%s","(6) Exponent two numbers x to the y\n");
 printf("%s","(0) quit\n");
 printf("Selection:");
 scanf("%d",&selection);
 PrintSelection(selection);
 return selection;
}

int main(){
float number1, number2, sum;
float Result;
char wanttoexit = FALSE;
char c;
int choice;
int i,j;
int myArray[100];
int max;
int pivot;
int temp;

// main loop
while(wanttoexit == FALSE){

	// display menu and get result
	choice = DisplayMenu();


	if(choice == 1){
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%f",&number1);
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%f",&number2);
		sum = number1 + number2;
		printf("The result is: ");
		printf("%.1f\n",sum);
		c=getchar();
		c=getchar();
	}
	if(choice == 2){
		printf("%s","Enter numbers for array and -1 for end\n");
		for(i=0;i<100;i++){
			scanf("%d",&choice);
			if(choice == -1) break;
			myArray[i] = choice;
			max = i ;
		}
		printf("Numbers are entered.. \n");
		printf("Now sorting.. ");
	    for(i=0;i<=max;i++){
	       for(j=0;j<max; j++){
	           if(myArray[j] > myArray[j+1]){
	           		temp = myArray[j];
	           		myArray[j]= myArray[j+1];
	           		myArray[j+1]=temp;
	           }
		    }

		}
		printf("finished..\n ");
	    for(i=0;i<=max;i++){
	      printf("%d  ",myArray[i]);
	    }
	      printf("are the numbers.\n");


		c=getchar();
		c=getchar();
	}
	if(choice == 3){
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%f",&number1);
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%f",&number2);
		Result = number1 - number2;
		printf("The result is: ");
		printf("%.3f\n",Result);
		c=getchar();
		c=getchar();
	}
  if(choice == 4){
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%f",&number1);
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%f",&number2);
		Result = number1 / number2;
		printf("The result is: ");
		printf("%.2f\n",Result);
		c=getchar();
		c=getchar();
	}
  if(choice == 5){
	int  a,b,c,d,e;
	int kalan;
	int girilen;
	float sonuc=1;
	printf("Enter value to summarize : \n");
	scanf("%d",&girilen);

	a=girilen/100000;
	kalan=girilen%100000;
	b=kalan/10000;
	kalan=kalan%10000;
	c=kalan/1000;
	kalan=kalan%1000;
	d=kalan/100;
	kalan=kalan%100;
	e=kalan/10;
	kalan=kalan%10;

	if(a>0){printf("Your value is so high to Summerize.\n");}
	else if(a==0&&b!=0){printf("Your entered value is:%d\n%dx10000  %dx1000  %dx100 %dx10 %dx1\n ",girilen,b,c,d,e,kalan);}
	else if(a==0&&b==0&&c!=0){printf("Your entered value is:%d\n%dx1000  %dx100 %dx10 %dx1\n ",girilen,c,d,e,kalan);}
	else if(a==0&&b==0&&c==0&&d!=0){printf("Your entered value is:%d\n%dx100 %dx10 %dx1\n ",girilen,d,e,kalan);}
	else if(a==0&&b==0&&c==0&&d==0&&e!=0){printf("Your entered value is:%d\n%dx10 %dx1\n ",girilen,e,kalan);}
	else if(a==0&&b==0&&c==0&&d==0&&e==0&&kalan!=0){printf("Your entered value is:%d\n%dx1\n ",girilen,kalan);}

  c=getchar();
  c=getchar();
                  }

  if(choice == 6){
  float  us, alt;
	int i;
	float sonuc=1;
	printf("Enter the base number: \n");
	scanf("%f",&alt);
	printf("Enter the exponent number: \n");
	scanf("%f",&us);

	if(us==0 && alt==0){ printf("Exponent=0 and base=0 \nUnfortunatelly your result is undefined.\n");
	                   }
		else if (us>=0){for(i=1;i<=us;i++){
		sonuc *= alt;
		                                  }
	printf("Your result: %.2f\n",sonuc);
                   }
	else if (us<0){for(i=-1;i>=us;i--){
		sonuc /= alt;
		                                }
	printf("Your result: %.5f\n",sonuc);
                }
  c=getchar();
  c=getchar();

        	      }
	if(choice == 0){
		wanttoexit = TRUE;
		printf("exiting...");
	}
} // end of while

}




