#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>


class student
{
private:
	int rollno;
	char name[50];
	int p_marks, c_marks, m_marks, e_marks, cs_marks;
	float per;
	char grade;
	void calculate();	//function to calculate grade
public:
	void getdata();		//function to accept data from user
	void showdata();	//function to show data on screen
	void show_tabular();
	int retrollno();
	friend void start(void);
}; //class ends here


void student::calculate()
{
	per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
	if(per>=60)
		grade='A';
	else if(per>=50)
		grade='B';
	else if(per>=33)
		grade='C';
	else
		grade='F';
}

void student::getdata()
{
	cleardevice();
	cout<<"\nEnter The roll number of student ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student ";
	gets(name);
	cout<<"\nEnter The marks in physics out of 100 : ";
	cin>>p_marks;
	cout<<"\nEnter The marks in chemistry out of 100 : ";
	cin>>c_marks;
	cout<<"\nEnter The marks in maths out of 100 : ";
	cin>>m_marks;
	cout<<"\nEnter The marks in english out of 100 : ";
	cin>>e_marks;
	cout<<"\nEnter The marks in computer science out of 100 : ";
	cin>>cs_marks;
	calculate();
}

void student::showdata()
{
	
	cleardevice();
	start();
	cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nMarks in Physics : "<<p_marks;
	cout<<"\nMarks in Chemistry : "<<c_marks;
	cout<<"\nMarks in Maths : "<<m_marks;
	cout<<"\nMarks in English : "<<e_marks;
	cout<<"\nMarks in Computer Science :"<<cs_marks;
	cout<<"\nPercentage of student is  :"<<per;
	cout<<"\nGrade of student is :"<<grade;
}

void student::show_tabular()
{
	cout<<rollno<<setw(6)<<" "<<name<<setw(10)<<p_marks<<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)
		<<e_marks<<setw(4)<<cs_marks<<setw(6)<<per<<setw(6)<<" "<<grade<<endl;
}

int  student::retrollno()
{
	return rollno;
}


//***************************************************************
//    	function declaration
//****************************************************************


void write_student();	//write the record in binary file
void display_all();	    //read all records from binary file
void display_sp(int);	//accept rollno and read record from binary file
void modify_student(int);	//accept rollno and update record of binary file
void delete_student(int);	//accept rollno and delete selected records from binary file
void class_result();	//display all records in tabular format from binary file
void result();		    //display result menu
void intro();		    //display welcome screen
void menu(void);	    //display entry menu on screen
void start(void);       //display the starting screen
void password(void);    //Password Authontication
void inv(void);         //For Input Invalidation
void printTitle(void);  //For Printing the heading
void showMenu(void);    //For showing menu again 
void result();          //For result Menu
void entry_menu();      //For Entry Menu
void end(void);         //For Ending the sub menu
void end2(void);        //For Ending the main menu


//***************************************************************
//    	function to write in file
//****************************************************************

void write_student()
{
	cleardevice();
	start();
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write((char *) &st, sizeof(student));
	outFile.close();
    	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	getch();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************

void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	getch();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	
	cleardevice();
	start();
	
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}

	int flag=0;
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retrollno()==n)
		{
			 st.showdata();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nrecord not exist";
	getch();
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_student(int n)
{
	int found=0;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	while(File.read((char *) &st, sizeof(student)) && found==0)
	{
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    	int pos=(-1)*sizeof(st);
		    	File.seekp(pos,ios::cur);
		    	File.write((char *) &st, sizeof(student));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retrollno()!=n)
		{
			outFile.write((char *) &st, sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}

//***************************************************************
//    	function to display all students grade report
//****************************************************************

void class_result()
{
	cleardevice();
	start();
	
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"==========================================================\n";
	cout<<"R.No       Name        P   C   M   E   CS   %age   Grade"<<endl;
	cout<<"==========================================================\n";
	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.show_tabular();
	}
	getch();
	inFile.close();
}

//***************************************************************
//    	function to display result menu
//****************************************************************

void result()
{
	char ch;
	int rno;
	
	cleardevice();
	start();
	
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	setcolor(LIGHTBLUE);
	outtextxy(25,40," RESULT MENU ");
	setcolor(YELLOW);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);

	outtextxy(60,150,"1)CLASS RESULT");
	outtextxy(60,210,"2)STUDENT REPORT CARD");
	outtextxy(60,270,"3)BACK TO MAIN MENU");
	switch(getch())
	{
	case '1' :class_result(); break;
	case '2' :cout<<"\n\n\tEnter Roll Number Of Student : ";
		  cin>>rno;
		  display_sp(rno); break;
	case '3' :break;
	default :cout<<"\a";
	}
}


//***************************************************************
//    	ENTRY / EDIT MENU FUNCTION
//****************************************************************

void entry_menu()
{
	char ch;
	int num;
     cleardevice();
     start();
 
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	setcolor(LIGHTBLUE);
	outtextxy(25,40," ENTRY MENU ");
	setcolor(YELLOW);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);

	outtextxy(60,150,"1)CREATE STUDENT RECORD");
	outtextxy(60,210,"2)DISPLAY ALL STUDENTS RECORDS");
	outtextxy(60,270,"3)SEARCH STUDENT RECORD");
	outtextxy(60,330,"4)MODIFY STUDENT RECORD");
	outtextxy(60,390,"5)GO BACK TO THE MAIN MENU");
	
	switch(getch())
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			    display_sp(num); break;
	case '4':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			modify_student(num);break;
	case '5':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			delete_student(num);break;
	case '6':	break;
	default:	cout<<"\a"; entry_menu();
	}
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

void start(void)
{                                          //	FUNTION USED FOR MAKING THE
	setcolor(RED);
	setlinestyle(SOLID_LINE,1,3);
	rectangle(0,0,639,479);            // 	RECTANGLE WHICH IS THE BORDER

	setcolor(BLUE);
	setlinestyle(SOLID_LINE,1,2);     //	... COLORS ARE USED IN THEM..
	rectangle(10,10,629,469);
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


void printTitle(void)
{
		int temp, temp2;

		temp=(rand()% 15)+1;
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);		//set tect style for the heading
		setcolor(temp);						//set colour for the fonts
		outtextxy(16,40,"WELCOME TO THE MARKS SYSTEM ANALYSIS");	//setting the position and the font

		temp2=(rand()%15)+1;
		setcolor(temp2);						//set colour for the underline
		line(20,80,621,80);       				//set position for the line

		delay(400);						//blinking the heading

}

void showMenu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		//set text style for the options
		setcolor(WHITE);					//set colour for the fonts
		outtextxy(60,150,"1) RESULT MENU");	//setting the position and the font
		outtextxy(60,210,"2) ENTRY/EDIT MENU");		//setting the position and the font
		outtextxy(60,270,"3) EXIT");			//setting the position and the font
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

void menu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		//set text style for the options
		setcolor(WHITE);					//set colour for the fonts
		outtextxy(60,150,"1) RESULT MENU");	//setting the position and the font
		outtextxy(60,210,"2) ENTRY/EDIT MENU");		//setting the position and the font
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
			outtextxy(60,150,"1) RESULT MENU");	//setting the position and the font
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		//set text style for the options
			setcolor(10);					//set colour for the fonts
			outtextxy(60,150,"1) RESULT MENU");	//setting the position and the font
			delay(500);

			result();
			cleardevice();
			start();
			showMenu();
			break;
			
		case '2':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		//set text style for the options
			setcolor(0);					//set colour for the fonts
			outtextxy(60,210,"2) ENTRY/EDIT MENU");	//setting the position and the font
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		//set text style for the options
			setcolor(10);					//set colour for the fonts
			outtextxy(60,210,"2) ENTRY/EDIT MENU");	//setting the position and the font
			delay(500);

			entry_menu();
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
