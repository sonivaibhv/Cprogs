/* THIS SOFTWARE IS A DATABASE PROJECT WITH ALL THE BASIC CAPABILITIES A
   ////////////////////////////////////////////////////////////////////////
   DATABASE SHOULD HAVE. THIS APPLICATION SOFTWARE IS ABOUT AIRPORT RESERVATION
   ///////////////////////////////////////////////////////////////////////////
   AND IT RECORDS AND MAINTAINS RECORDS ABOUT THE AIRLINES AND THE CUSTOMER.
   ///////////////////////////////////////////////////////////////////////////
   RECORDS FOR AIRLINES AND CUSTOMERS ARE SAVED IN SEPERATE FILES AND CAN
   ////////////////////////////////////////////////////////////////////////
   BE USED TO DELETE OR MODIFY RECORDS IN THEM ........				      */






#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>

struct record {                //          STRUCTURE FOR AIRLINE
	char name[30];
	char type[15];         //	     WITH THEIR ELEMENTS
	char dday[10];
	char dtime[10];
	char aday[10];
	char atime[10];
	char des[30];
	int capa;
} airline;

struct record1 {               //	STRUCTURE FOR CUSTOMERS
	    char name[20];
	    char addr[40];
	    char pnum[15];
	    char dob[15];
	    char nic[15];
	    char pass[15];
	    char nation[20];      //           AND THEIR ELEMENTS
	    char dest[30];
	    char airline[20];
	    char dod[10];
	    char time[10];
} customer;


void printTitle(void);
void showMenu(void);               //      FUNCTIONS
void customerf(void);
void airlinef(void);
void start(void);
void menu(void);                  //       MADE AND USED
void add_airline(void);
void edit_airline();
void delete_airline(void);
void add_customer(void);          //	   IN THE PROGRAMS
void edit_customer(void);
void delete_customer(void);
void end(void);
void view_airline(void);
void view_customer(void);
void option(void);
void option1(void);
void end2(void);
void option2(void);
int Password(void);
void inv(void);
int c=0,d=0;

void main(void)
{
	int Proceed;

	int driver=VGA,mode=VGAHI;   	//detect best driver and mode


	initgraph(&driver,&mode,"c:\\tc\\bgi"); 	//initialize graphics mode

	randomize();


	do
	{
	   Proceed = Password();         //	CHECK THE PASSWORD
	} while ( Proceed!=1);
	cleardevice();
	start();                         //	AND THEM CHECK
	menu();
	getch();                         //	THE VALUE RETURNED...
	closegraph();
}
void start(void)
{                                          //	FUNTION USED FOR MAKING THE
	setcolor(RED);
	setlinestyle(SOLID_LINE,1,3);
	rectangle(0,0,639,479);            // 	RECTANGLE WHICH IS THE BORDER

	setcolor(BLUE);
	setlinestyle(SOLID_LINE,1,2);     //	... COLORS ARE USED IN THEM..
	rectangle(10,10,629,469);
}

void showMenu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		//set text style for the options
		setcolor(WHITE);					//set colour for the fonts
		outtextxy(60,150,"1) AIRLINE INFORMATION");	//setting the position and the font
		outtextxy(60,210,"2) CUSTOMER PROFILE");		//setting the position and the font
		outtextxy(60,270,"3) EXIT");			//setting the position and the font
}

void menu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		//set text style for the options
		setcolor(WHITE);					//set colour for the fonts
		outtextxy(60,150,"1) AIRLINE INFORMATION");	//setting the position and the font
		outtextxy(60,210,"2) CUSTOMER PROFILE");		//setting the position and the font
		outtextxy(60,270,"3) EXIT");			//setting the position and the font

	while (1)          						//loop will folow untill key board hits
   {
	while(!(kbhit()))
	{
		printTitle();
	}

	switch(getch())                					// getting options from the user
	{
		case '1':

			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		//set text style for the options
			setcolor(0);					//set colour for the fonts
			outtextxy(60,150,"1) AIRLINE INFORMATION");	//setting the position and the font
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		//set text style for the options
			setcolor(10);					//set colour for the fonts
			outtextxy(60,150,"1) AIRLINE INFORMATION");	//setting the position and the font
			delay(500);

			airlinef();
			cleardevice();
			start();
			showMenu();
			break;
		case '2':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		//set text style for the options
			setcolor(0);					//set colour for the fonts
			outtextxy(60,210,"2) CUSTOMER PROFILE");	//setting the position and the font
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		//set text style for the options
			setcolor(10);					//set colour for the fonts
			outtextxy(60,210,"2) CUSTOMER PROFILE");	//setting the position and the font
			delay(500);

			customerf();
			cleardevice();
			start();
			showMenu();
			break;
		case '3':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		//set text style for the options
			setcolor(0);					//set colour for the fonts
			outtextxy(60,270,"3) EXIT");			//setting the position and the font
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		//set text style for the options
			setcolor(10);					//set colour for the fonts
			outtextxy(60,270,"3) EXIT");			//setting the position and the font
			delay(500);

			end();
			cleardevice();
			start();
			showMenu();                                //	END FUNCTION IS CALLED AFTER
			break;
		default:
			inv();
	}
    }
}


void printTitle(void)
{
		int temp, temp2;

		temp=(rand()% 15)+1;
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);		//set tect style for the heading
		setcolor(temp);						//set colour for the fonts
		outtextxy(16,40,"WELCOME TO THE AIRPORT RESERVATION");	//setting the position and the font

		temp2=(rand()%15)+1;
		setcolor(temp2);						//set colour for the underline
		line(20,80,621,80);       				//set position for the line

		delay(400);						//blinking the heading

}

void airlinef(void)
{
	d=0,c=0;
	cleardevice();
	start();

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	setcolor(LIGHTBLUE);
	outtextxy(25,40," AIRLINE INFORMATION");
	setcolor(YELLOW);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);

	outtextxy(60,150,"1)ADD AIRLINE INFORMATION");
	outtextxy(60,210,"2)DELETE AIRLINE INFORMATION");
	outtextxy(60,270,"3)VIEW AIRLINE INFORMATION");
	outtextxy(60,330,"4)EDIT AIRLINE INFORMATION");
	outtextxy(60,390,"5)GO BACK TO THE MAIN MENU");
	switch(getch())
	{
		case '1':

			add_airline();
			cleardevice();
			airlinef();
			break;

		case '2':
			delete_airline();
			cleardevice();
			airlinef();
			break;
		case '3':
			view_airline();
			cleardevice();
			airlinef();
			break;

		case '4':
			edit_airline();
			cleardevice();
			airlinef();
			break;

		case '5':
			cleardevice();
			start();
			menu();
			break;

		default :
			inv();
			airlinef();
	 }


}
void customerf(void)
{
	d=0,c=0;
	cleardevice();
	start();
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	setcolor(LIGHTBLUE);
	outtextxy(13,40,"CUSTOMER INFORMATION");
	setcolor(YELLOW);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);

	outtextxy(60,150,"1)ADD CUSTOMER INFORMATION");
	outtextxy(60,210,"2)DELETE CUSTOMER INFORMATION");
	outtextxy(60,270,"3)VIEW CUSTOMER INFORMATION");
	outtextxy(60,330,"4)EDIT CUSTOMER INFORMATION");
	outtextxy(60,390,"5)GO BACK TO THE MAIN MENU");

	switch(getch())
	{
		case '1':
			add_customer();
			cleardevice();
			customerf();
			break;
		case '2':
			delete_customer();
			cleardevice();
			customerf();
			break;
		case '3':
			view_customer();
			cleardevice();
			customerf();
			break;
		case '4':
			edit_customer();
			cleardevice();
			customerf();
			break;
		case '5':
			cleardevice();
			start();
			menu();
			break;
		default :
			inv();
			customerf();
	}

}

void end (void)
{
	cleardevice();

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(60,150,"ARE YOU SURE YOU WANT TO EXIT (Y/N)");

	switch(getch())
	{
		case 'Y':
		case 'y':
				end2();
				exit(0);
				break;
		case 'N':
		case 'n':
				break;
		default :
				inv();
				getch();
				end();
	}
}

void add_airline(void)
{
	FILE *fpoin;
	char temp[30];

	int a=35;
	fpoin=fopen("c:\\airline.txt","a");
	cleardevice();
	start();

	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(35,40,"ADD AIRLINE INFORMATION");

	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(60,100,"ENTER AN AIRLINE NAME");
	gotoxy(a,7);
	gets(temp);
	strcpy(airline.name,strupr(temp));

	outtextxy(60,115,"ENTER A DESTINATION");
	gotoxy(a,8);
	gets(temp);
	strcpy(airline.des,strupr(temp));

	outtextxy(60,130,"ENTER AN AIRCRAFT TYPE");
	gotoxy(a,9);
	gets(temp);
	strcpy(airline.type,strupr(temp));

	outtextxy(60,145 ,"DAY OF DEPARTURE");
	gotoxy(a,10);
	gets(temp);
	strcpy(airline.dday,strupr(temp));

	outtextxy(60,160,"DEPARTURE TIME");
	gotoxy(a,11);
	gets(temp);
	strcpy(airline.dtime,strupr(temp));

	outtextxy(60,175,"ARRIVAL DAY");
	gotoxy(a,12);
	gets(temp);
	strcpy(airline.aday,strupr(temp));


	outtextxy(60,190,"ARRIVAL TIME");
	gotoxy(a,13);
	gets(temp);
	strcpy(airline.atime,strupr(temp));


	outtextxy(60,205,"CAPACITY");
	gotoxy(a,14);
	scanf("%d",&airline.capa);

	fwrite(&airline, sizeof(airline),1, fpoin);


	if((c!=1)&&(d!=1))
	{
	cleardevice();
	start();
	outtextxy(90,290,"RECORD ADDED");
	outtextxy(90,310,"PRESS ANY KEY TO CONTINUE");
	getch();
	}

	fclose(fpoin);
	fflush(stdin);
}

void delete_airline(void)
{
	char *searchname,*desname,temp1[30],temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin,*fpoin1;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE NAME OF THE AIRLINE:");
	gets(temp1);
	searchname=strupr(temp1);
	gotoxy(10,7);
	printf("ENTER THE NAME OF DESTINATION:");
	gets(temp);
	desname=strupr(temp);
	fpoin=fopen("c:\\airline.txt","r");
	while((fread(&airline,sizeof(airline),1,fpoin))!=NULL)
	{

		count1++;
		if((strcmp(searchname,airline.name)==0)&&(strcmp(desname,airline.des)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("AIRLINE NAME");
			gotoxy(26,10);
			puts(airline.name);
			gotoxy(20,11);
			printf("\n\tDESTINATION\t %s \
			 \n\tAIRCRAFT TYPE\t %s       \
			  \n\tDEPARTURE DAY\t %s       \
				\n\tDEPARTURE TIME\t %s     \
				\n\tARRIVAL DAY\t %s        \
				 \n\tARRIVAL TIME\t %s       \
				  \n\tCAPACITY\t %d",airline.des,airline.type,airline.dday,airline.dtime,airline.aday,airline.atime,airline.capa);

			printf("\n\n\n\n\n");
			start();
			count++;
			gotoxy(20,20);
			printf("(D)ELETE OR MOVE (F)URTHER");
			switch(getch())
			{
				case 'D':
				case 'd':
					  k=1;
					  success=1;
					  break;
				case 'F':
				case 'f':
					  break;

					 default  :
					 success=2;
					 inv();
			}

			  if(success==1)
			  break;
		}


	}

       if((success2==1)&&(success==1))
	  {
		rewind(fpoin);
		fpoin1=fopen("c:\\temp.txt","w");

		for(i=1;i<count1;i++)
		{
			fread(&airline,sizeof(airline),1,fpoin);
			fwrite(&airline, sizeof(airline),1,fpoin1);
		}

				  for(j=0;j<=3;j++)
				{
					cleardevice();
					start();
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
					setcolor(WHITE);
					outtextxy(100,150,"RECORD DELETING");
					delay(700);
					setcolor(BLACK);
					outtextxy(100,150,"RECORD DELETING");
					delay(700);
					setcolor(WHITE);

				 }
				cleardevice();
				start();
				setcolor(RED);
				outtextxy(100,170,"RECORD DELETED");
				delay(1500);

			fread(&airline,sizeof(airline),1,fpoin);

			while((fread(&airline,sizeof(airline),1,fpoin))!=NULL)
			fwrite(&airline, sizeof(airline),1,fpoin1);

			start();



			fclose(fpoin1);
			fclose(fpoin);

			remove("c:\\airline.txt");
			rename("c:\\temp.txt","c:\\airline.txt");
			fpoin=fopen("c:\\airline.txt","r");

	  }

		if(success2==0)
	  {
		gotoxy(28,20);
		printf("RECORD NOT FOUND");
		getch();
	  }

	 if((count!=0)&&(k==0))
		{
		  gotoxy(10,22);
		  printf("THERE ARE %d RECORD(S) LEFT",count);
		  getch();
		}

}
void view_airline(void)
{
	cleardevice();
	setcolor(4);
	settextstyle(3,0,5);
	outtextxy(40,100,"PRESS");
	setcolor(11);
	settextstyle(3,0,3);
	outtextxy(70,200,"1 - TO SEARCH BY NAME");
	outtextxy(70,240,"2 - TO SEARCH BY DESTINATION");
	outtextxy(70,280,"3 - TO SEARCH BY BOTH");
	outtextxy(70,320,"4 - TO GO BACK");


	start();
	switch(getch())
	{
		case '1':
			 option1();
			 view_airline();
			 break;
		case '2':
			 option();
			 view_airline();
			 break;
		case '3':
			 option2();
			 view_airline();
			 break;
		case '4':
			 airlinef();
			 break;
		default :
			 inv();
			 view_airline();

	}
	fflush(stdin);
}

void option(void)
{
	FILE *fpoin;

	char *searchname,temp[30];
	int count=0;
	cleardevice();
	start();
	gotoxy(10,5);
	printf("Enter the name of destination to search:");
	gets(temp);
	searchname=strupr(temp);
	fpoin=fopen("c:\\airline.txt","r");

	while((fread(&airline,sizeof(airline),1,fpoin))!=NULL)
	{


		if(strcmp(searchname,airline.des)==0)
		{
			cleardevice();
			start();

			gotoxy(9,10);
			printf("AIRLINE NAME");
			gotoxy(26,10);
			puts(airline.name);
			gotoxy(20,11);
			printf("\n\tDESTINATION\t %s \
			 \n\tAIRCRAFT TYPE\t %s       \
			  \n\tDEPARTURE DAY\t %s       \
				\n\tDEPARTURE TIME\t %s     \
				\n\tARRIVAL DAY\t %s        \
				  \n\tARRIVAL TIME\t %s       \
					\n\tCAPACITY\t %d",airline.des,airline.type,airline.dday,airline.dtime,airline.aday,airline.atime,airline.capa);

			printf("\n\n\n\n\n");
			start();
			count++;
			getch();

		}
	 }
	printf("\n\n\t\t\tTHERE ARE %d RECORD(S)",count);
	start();
	getch();

}

void option1(void)
{
	FILE *fpoin;

	char *searchname,temp[30];
	int count=0;
	cleardevice();
	start();
	gotoxy(10,5);
	printf("Enter the name of airline to search:");
	gets(temp);
	searchname=strupr(temp);
	fpoin=fopen("c:\\airline.txt","r");

	while((fread(&airline,sizeof(airline),1,fpoin))!=NULL)
	{


		if(strcmp(searchname,airline.name)==0)
		{
			cleardevice();
			start();

			gotoxy(9,10);
			printf("AIRLINE NAME");
			gotoxy(26,10);
			puts(airline.name);
			gotoxy(20,11);
			printf("\n\tDESTINATION\t %s \
			 \n\tAIRCRAFT TYPE\t %s       \
			  \n\tDEPARTURE DAY\t %s       \
				\n\tDEPARTURE TIME\t %s     \
				 \n\tARRIVAL DAY\t %s        \
				  \n\tARRIVAL TIME\t %s       \
					\n\tCAPACITY\t %d",airline.des,airline.type,airline.dday,airline.dtime,airline.aday,airline.atime,airline.capa);

			printf("\n\n\n\n\n");
			start();
			count++;
			getch();

		}
	 }
	printf("\n\n\t\t\tTHERE ARE %d RECORD(S)",count);
	start();
	getch();
}
void option2(void)
{
	FILE *fpoin;

	char *searchname,*desname,temp[30],temp1[30];
	int count=0;
	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER AIRLINE:");
	gets(temp1);
	searchname=strupr(temp1);
	gotoxy(10,10);
	printf("ENTER DESTINATION:");
	gets(temp);
	desname=strupr(temp);
	fpoin=fopen("c:\\airline.txt","r");

	while((fread(&airline,sizeof(airline),1,fpoin))!=NULL)
	{


	  if((strcmp(searchname,airline.name)==0)&&(strcmp(desname,airline.des)==0))

		{

			cleardevice();
			start();

			gotoxy(9,10);
			printf("AIRLINE NAME");
			gotoxy(26,10);
			puts(airline.name);
			gotoxy(20,11);
			printf("\n\tDESTINATION\t %s \
			 \n\tAIRCRAFT TYPE\t %s       \
			  \n\tDEPARTURE DAY\t %s       \
				\n\tDEPARTURE TIME\t %s     \
				 \n\tARRIVAL DAY\t %s        \
				  \n\tARRIVAL TIME\t %s       \
					\n\tCAPACITY\t %d",airline.des,airline.type,airline.dday,airline.dtime,airline.aday,airline.atime,airline.capa);

			printf("\n\n\n\n\n");
			start();
			count++;
			getch();
			  }

	 }
	printf("\n\n\t\t\tTHERE ARE %d RECORD(S)",count);
	start();
	getch();

}

void edit_airline()
{
	char *searchname,*desname,temp1[30],temp[30];
	int count=0,count1=0,success=0,i,j,k=0,success2=0;

	FILE *fpoin,*fpoin1;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE NAME OF THE AIRLINE:");
	gets(temp1);
	searchname=strupr(temp1);
	gotoxy(10,7);
	printf("ENTER THE NAME OF DESTINATION:");
	gets(temp);
	desname=strupr(temp);
	fpoin=fopen("c:\\airline.txt","r");
	while((fread(&airline,sizeof(airline),1,fpoin))!=NULL)
	{

		count1++;
		if((strcmp(searchname,airline.name)==0)&&(strcmp(desname,airline.des)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("AIRLINE NAME");
			gotoxy(26,10);
			puts(airline.name);
			gotoxy(20,11);
			printf("\n\tDESTINATION\t %s \
			 \n\tAIRCRAFT TYPE\t %s       \
			  \n\tDEPARTURE DAY\t %s       \
				\n\tDEPARTURE TIME\t %s     \
				\n\tARRIVAL DAY\t %s        \
				 \n\tARRIVAL TIME\t %s       \
				  \n\tCAPACITY\t %d",airline.des,airline.type,airline.dday,airline.dtime,airline.aday,airline.atime,airline.capa);

			printf("\n\n\n\n\n");
			start();
			count++;
			gotoxy(20,20);
			printf(" (E)DIT OR (N)EXT RECORD");
			switch(getch())
			{
				case 'e':
				case 'E':
					  k=1;
					  success=1;
					  break;
				case 'N':
				case 'n':
					  break;
				default :
					 success=2;
					 inv();
			}

			  if(success==1)
			  break;
		}

	}



		 if((success2==1)&&(success==1))
	  {
		rewind(fpoin);
		fpoin1=fopen("c:\\temp.txt","w");

		for(i=1;i<count1;i++)
		{
			fread(&airline,sizeof(airline),1,fpoin);
			fwrite(&airline, sizeof(airline),1,fpoin1);
		}

			fread(&airline,sizeof(airline),1,fpoin);

			d=1;
			c=1;
			add_airline();

			for(j=0;j<=5;j++)
			{
				cleardevice();
				start();
				settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
				setcolor(WHITE);
				outtextxy(100,150,"RECORD MODIFYING");
				delay(700);
				setcolor(BLACK);
				outtextxy(100,150,"RECORD MODIFYING");
				delay(700);
				setcolor(WHITE);

			}
				cleardevice();
				start();
				setcolor(RED);
				outtextxy(100,170,"RECORD MODIFIED");
				delay(1500);

			while((fread(&airline,sizeof(airline),1,fpoin))!=NULL)
			fwrite(&airline, sizeof(airline),1,fpoin1);

			start();



			fclose(fpoin1);
			fclose(fpoin);

			remove("c:\\airline.txt");
			rename("c:\\temp.txt","d:\\airline.txt");
			fpoin=fopen("d:\\airline.txt","r");

	  }


		if(success2==0)
	  {
		gotoxy(28,20);
		printf("RECORD NOT FOUND");
		getch();
	  }

	 if((count!=0)&&(k==0))
	 {
		gotoxy(10,22);
		printf("THERE ARE %d RECORD(S) LEFT",count);
		getch();
	 }

}

void add_customer(void)
{
	FILE *fpoin1;
	char temp[30];

	int a=35;
	fpoin1=fopen("d:\\customer.txt","a");
	cleardevice();
	start();

	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(35,40,"ADD CUSTOMER INFORMATION");

	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(60,100,"ENTER CUSTOMER NAME");
	gotoxy(a,7);
	gets(temp);
	strcpy(customer.name,strupr(temp));

	outtextxy(60,115,"ENTER ADDRESS");
	gotoxy(a,8);
	gets(temp);
	strcpy(customer.addr,strupr(temp));

	outtextxy(60,130,"ENTER PHONE NUMBER");
	gotoxy(a,9);
	gets(temp);
	strcpy(customer.pnum,strupr(temp));

	outtextxy(60,145 ,"DATE OF BIRTH");
	gotoxy(a,10);
	gets(temp);
	strcpy(customer.dob,strupr(temp));

	outtextxy(60,160,"NIC NUMBER");
	gotoxy(a,11);
	gets(temp);
	strcpy(customer.nic,strupr(temp));

	outtextxy(60,175,"PASSPORT NUMBER");
	gotoxy(a,12);
	gets(temp);
	strcpy(customer.pass,strupr(temp));


	outtextxy(60,190,"NATIONALITY");
	gotoxy(a,13);
	gets(temp);
	strcpy(customer.nation,strupr(temp));


	outtextxy(60,205,"DESTINATION");
	gotoxy(a,14);
	gets(temp);
	strcpy(customer.dest,strupr(temp));

	outtextxy(60,220,"ENTER AIRLINE");
	gotoxy(a,15);
	gets(temp);
	strcpy(customer.airline,strupr(temp));

	outtextxy(60,235,"DATE OF DEPARTURE");
	gotoxy(a,16);
	gets(temp);
	strcpy(customer.dod,strupr(temp));

	outtextxy(60,250,"TIME OF DEPARTURE");
	gotoxy(a,17);
	gets(temp);
	strcpy(customer.time,strupr(temp));

	  if((c!=1)&&(d!=1))
	  {
	cleardevice();
	start();
	outtextxy(90,290,"RECORD ADDED");
	outtextxy(90,310,"PRESS ANY KEY TO CONTINUE");
	getch();
	  }

	fwrite(&customer, sizeof(customer),1, fpoin1);
	fclose(fpoin1);
	fflush(stdin);
}

void edit_customer(void)
{
	char *searchname,temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin1,*fpoin2;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE NAME OF CUSTOMER:");
	gets(temp);
	searchname=strupr(temp);
	gotoxy(10,7);
	fpoin1=fopen("c:\\customer.txt","r");
	while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
	{

		count1++;
		if((strcmp(searchname,customer.name)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("CUSTOMER NAME");
			gotoxy(34,10);
			puts(customer.name);
			gotoxy(20,11);
			printf("\n\tADDRESS\t\t\t %s \
			 \n\tPHONE NUMBER\t\t %s       \
			  \n\tDATE OF BIRTH\t\t %s       \
				\n\tNIC NUMBER\t\t %s     \
				 \n\tPASSPORT NUMBER\t\t %s        \
				  \n\tNATIONALITY\t\t %s       \
					\n\tDESTINATION\t\t %s      \
				\n\tAIRLINE\t\t\t %s \
				\n\tDAY OF DEPARTURE\t %s  \
				\n\tTIME OF DEPARTURE\t %s",customer.addr,customer.pnum,customer.dob,customer.nic,customer.pass,customer.nation,customer.dest,customer.airline,customer.dod,customer.time);

			start();
			count++;

			gotoxy(20,23);
			printf("(E)DIT OR MOVE (F)URTHER");
			switch(getch())
			{
				case 'E':
				case 'e':
					  k=1;
					  success=1;
					  break;
				case 'F':
				case 'f':
					  break;

					 default  :
					 success=2;
					 inv();
			}

			  if(success==1)
			  break;
		}


	}

		 if((success2==1)&&(success==1))
	  {
		i=1;
		rewind(fpoin1);
		fpoin2=fopen("c:\\temp.txt","w");

		for(i=1;i<count1;i++)
		{
			fread(&customer,sizeof(customer),1,fpoin1);
			fwrite(&customer,sizeof(customer),1,fpoin2);
		}


			fread(&customer,sizeof(customer),1,fpoin1);

			c=1;
			d=1;
			add_customer();

			while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
			fwrite(&customer, sizeof(customer),1,fpoin2);



				 for(j=0;j<=3;j++)
				{
					cleardevice();
					start();
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
					setcolor(WHITE);
					outtextxy(100,150,"RECORD MODIFYING");
					delay(700);
					setcolor(BLACK);
					outtextxy(100,150,"RECORD MODIFYING");
					delay(700);
					setcolor(WHITE);

				 }


			start();
				cleardevice();
				start();
				setcolor(RED);
				outtextxy(100,170,"RECORD MODIFIED");
				delay(1500);



			fclose(fpoin2);
			fclose(fpoin1);

			remove("d:\\customer.txt");
			rename("d:\\temp.txt","d:\\customer.txt");
			fpoin1=fopen("d:\\customer.txt","r");

	  }

		if(success2==0)
	  {
		gotoxy(28,20);
		printf("RECORD NOT FOUND");
		getch();
	  }

		if((count!=0)&&(k==0))
		{
		  gotoxy(10,24);
		  printf("THERE ARE %d RECORD(S) LEFT",count);
		  getch();
		}


}
void delete_customer(void)
{
	char *searchname,temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin1,*fpoin2;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE NAME OF CUSTOMER:");
	gets(temp);
	searchname=strupr(temp);
	gotoxy(10,7);
	fpoin1=fopen("c:\\customer.txt","r");
	while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
	{

		count1++;
		if((strcmp(searchname,customer.name)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("CUSTOMER NAME");
			gotoxy(34,10);
			puts(customer.name);
			gotoxy(20,11);
			printf("\n\tADDRESS\t\t\t %s \
			 \n\tPHONE NUMBER\t\t %s       \
			  \n\tDATE OF BIRTH\t\t %s       \
				\n\tNIC NUMBER\t\t %s     \
				 \n\tPASSPORT NUMBER\t\t %s        \
			     \n\tNATIONALITY\t\t %s       \
			      \n\tDESTINATION\t\t %s      \
				\n\tAIRLINE\t\t\t %s \
				\n\tDAY OF DEPARTURE\t %s  \
				\n\tTIME OF DEPARTURE\t %s",customer.addr,customer.pnum,customer.dob,customer.nic,customer.pass,customer.nation,customer.dest,customer.airline,customer.dod,customer.time);

			start();
			count++;

			gotoxy(10,23);
			printf("(D)ELETE OR MOVE (F)URTHER");
			switch(getch())
			{
				case 'D':
				case 'd':
					  k=1;
					  success=1;
					  break;
				case 'F':
				case 'f':
					  break;

					 default  :
					 success=2;
					 inv();
			}

			  if(success==1)
			  break;
		}


	}

       if((success2==1)&&(success==1))
	  {
		i=1;
		rewind(fpoin1);
		fpoin2=fopen("c:\\temp.txt","w");

		for(i=1;i<count1;i++)
		{
			fread(&customer,sizeof(customer),1,fpoin1);
			fwrite(&customer,sizeof(customer),1,fpoin2);
		}



			fread(&customer,sizeof(customer),1,fpoin1);

			while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
			fwrite(&customer, sizeof(customer),1,fpoin2);



			    for(j=0;j<=3;j++)
				{
					cleardevice();
					start();
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
					setcolor(WHITE);
					outtextxy(100,150,"RECORD DELETING");
					delay(700);
					setcolor(BLACK);
					outtextxy(100,150,"RECORD DELETING");
					delay(700);
					setcolor(WHITE);

				 }


			start();
				cleardevice();
				start();
				setcolor(RED);
				outtextxy(100,170,"RECORD DELETED");
				delay(1500);



			fclose(fpoin2);
			fclose(fpoin1);

			remove("c:\\customer.txt");
			rename("c:\\temp.txt","c:\\customer.txt");
			fpoin1=fopen("d:\\customer.txt","r");

	  }

		if(success2==0)
	  {
		gotoxy(28,20);
		printf("RECORD NOT FOUND");
		getch();
	  }

		if((count!=0)&&(k==0))
		{
		  gotoxy(10,24);
		  printf("THERE ARE %d RECORD(S) LEFT",count);
		  getch();
		}

}
void view_customer(void)
{
	FILE *fpoin1;

	char *searchname,temp[30];
	int count=0;
	cleardevice();
	start();
	gotoxy(10,5);
	printf("Enter the name of customer to search:");
	gets(temp);
	searchname=strupr(temp);
	fpoin1=fopen("c:\\customer.txt","r");

	while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
	{


		if(strcmp(searchname,customer.name)==0)
		{
			cleardevice();
			start();

			gotoxy(9,10);
			printf("CUSTOMER NAME");
			gotoxy(34,10);
			puts(customer.name);
			gotoxy(20,11);
			printf("\n\tADDRESS\t\t\t %s \
			 \n\tPHONE NUMBER\t\t %s       \
			  \n\tDATE OF BIRTH\t\t %s       \
				\n\tNIC NUMBER\t\t %s     \
				 \n\tPASSPORT NUMBER\t\t %s        \
				  \n\tNATIONALITY\t\t %s       \
					\n\tDESTINATION\t\t %s      \
				\n\tAIRLINE\t\t\t %s \
				\n\tDAY OF DEPARTURE\t %s  \
				\n\tTIME OF DEPARTURE\t %s",customer.addr,customer.pnum,customer.dob,customer.nic,customer.pass,customer.nation,customer.dest,customer.airline,customer.dod,customer.time);

			printf("\n\n\n\n");
			start();
			count++;
			getch();

		}
	 }
	printf("\n\t\t\tTHERE ARE %d RECORD(S)",count);
	start();
	getch();

}
void end2(void)
{
	int driver=DETECT,mode;   	//detect best driver and mode
	int i,j=520;

	initgraph(&driver,&mode,"c:\\tc\\bgi"); 	//initialize graphics mode

	for(i=480;i>=0;i--)
	{

		setcolor(WHITE);
		outtextxy(230,i,"DESIGNED BY");
		outtextxy(195,j,"HITESH KUMAR");
		outtextxy(243,j+120,"BCA 3 rd Year");
		outtextxy(243,j+140,"JAMIA HAMDARD");
		outtextxy(243,j+160,"NEW DELHI");

		delay(20);
		j--;

		 cleardevice();
	}
	closegraph();
}

int Password (void)
{
	 char Password[12]="hitesh"; // Already assigned password
	 char pass[20];
	 char UserName[15];
	 char user[15]="hitesh";
	 int sucess=0;                    // Password Verification
	 int x=26,i;

	 cleardevice();

	 line ( 130, 180, 500, 180 );             // creates..
	 rectangle ( 130, 150, 500, 300 );
	 setfillstyle ( SOLID_FILL, 7 );       // ..the dialouge box..
	 bar ( 130, 150, 500, 180 );
	 setfillstyle ( SOLID_FILL, 8 );     // ..where password and user name..
	 bar ( 130, 180, 500, 300 );
	 setcolor ( 4 );                   // ..can be entered
	 outtextxy ( 140, 165, " P A S S W O R D   V E R I F I C A T I O N  " );
	 setfillstyle ( SOLID_FILL, 0 );
	 bar ( 200, 200, 450, 230 );
	 bar ( 200, 247, 450, 277 );

	 outtextxy ( 130, 210, "   NAME " );
	 outtextxy ( 126, 258, " PASSWORD " );

	 gotoxy(26,14);
	 gets(UserName);

	for(i=0;i<20;i++ )       // Gets the password..
  {
	  pass[i]=getch();              // ..until enter key is not pressed..
	  if(pass[i]=='\r')
		{
	pass[i]='\0';                // Enter a NULL character
	break;
		 }

	  else
		{
	 gotoxy(x,17);printf("*");    // ..and prints asterix on the screen
	 x++;
		 }
	}

	if ((strcmp(Password,pass)==0)&&(strcmp(UserName,user)==0))    // checks password character..
		sucess=1;

	else                    // If incorrect password
	 {
		 sucess=0;
		 gotoxy (22, 21);
		 printf ( " INVALID PASSWORD! TRY AGAIN " );
		 getche ();
	  }

	return ( sucess );
}
void inv(void)
{
			sound(700);
			outtextxy(300,430,"INVALID INPUT");
			delay(500);
			nosound();
			setcolor(0);
			outtextxy(300,430,"INVALID INPUT");
}
