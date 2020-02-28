#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct{

	char NAME[40];
	char SURNAME[40];
	int ID;
	char MAIL[45];

}human;

int id(char * str);
int name(char * str);   /*These function is determine which words is which type.*/
int mail(char * str);
int surname(char * str);
char arranging(human elaman[], char * str ,int person); /*This fuction include every function to arrange and try one by one.*/


int main(){

	int i=0,j=0;
	FILE *filep = fopen("disordered_text.txt","r");
	FILE *filep2 = fopen("ordered_text.txt","w+");
	char temp[60];
	char word[60];

	human elaman[200];
	int x;
	int person=0;
	if(filep == NULL )
	{
		printf("Err!");		
	}

	else{	printf("NAME                ID        SURNAME       @MAIL \n\n" );

		while(!feof(filep))            // In end of file this while loop will be end. 
	    {

			fgets(temp, 60, filep);   /* We will get the character in the row (id,name,surname,mail) from text with disorganised.*/

			i=0;
			while(temp[i]!='\n')   /*if there is no new line this row will going so we can reorganise every row. */
			{
				for(i,j=0; temp[i]!=' ' && temp[i]!='\n'; ++i, ++j) /*we find the sentences in the row*/
				{
					word[j] = temp[i];/*record word to array. */

				}
				if(temp[i]==' ') ++i;    /*goes to other word*/
					
				word[j]='\0';
				arranging(elaman, word, person);  
		 	}

		 	printf("%-10s %12d %12s       %12s  \n",elaman[person].NAME,elaman[person].ID,elaman[person].SURNAME,elaman[person].MAIL );

			fprintf(filep2, "%-10s %12d %12s       %12s  \n",elaman[person].NAME,elaman[person].ID,elaman[person].SURNAME,elaman[person].MAIL );


		 	
		}
	}

	fclose(filep2);
	fclose(filep);
	return 0;
}

int id(char * str)
{	int c=0;
	int tf=-5;		       	/*if function is true tf is 5, in other hand -5*/
	int d;
	d=strlen(str);
	for(c=0;c<d;c++){				
		if(47<str[c] && 58>str[c])          /*In the ascii table 0=48 9=57 */
		tf=5;
	
			    
	}

	return tf;
}


int name(char * str)
{	int c=0;
	int tf=-5; 	         
	int d;
	d=strlen(str);
	if(d>1)
	{
		if((str[0]>='A' && str[0]<='Z') && (str[1]>='a' && str[1]<='z') )
			tf=5;
	}					/* in the text name's first character is capital, second character is minuscule so this condition will help us.*/
	
	
			                    

	return tf;
}

int mail(char * str)
{	int c=0;
	int tf=-5;		         
	int d;
	d=strlen(str);
	for(c=0;c<d;c++){					
		if(str[c]==64)		// 64 == @, to determine mail adress*/
			tf=5;
	
			 
	}

	return tf;
}

int surname(char * str)
{	int c=0;
	int tf=-5;		         
	int d;
	d=strlen(str);
	if(d>1)
	{
		if((str[0]>='A' && str[0]<='Z') && (str[1]>='A' && str[1]<='Z') )
			tf=5;
	}					
	

	return tf;
}

char arranging(human elaman[], char * str, int person){


	if(name(str)==5){
	strcpy(elaman[person].NAME,str);

}

	else if(id(str)==5){
	elaman[person].ID=atoi(str); /* ascii to integer */


	}	

	else if(surname(str)==5){
		strcpy(elaman[person].SURNAME,str);

	}	




else if(mail(str)==5){
		strcpy(elaman[person].MAIL,str);

	}		





}
	


