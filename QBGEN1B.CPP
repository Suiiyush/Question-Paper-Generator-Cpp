
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                                                                           
																		   
   // PROJECT MADE BY KUNAL TULSIDASANI AND SUYASH VYAS OF CLASS: XII-A

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------																		   
																		   
// SUBJECTIVE QUESTION CLASS = sque																		  
// OBJECTIVE QUESTION CLASS = mque
																		    
// FILE CONTAINING SUBJECTIVE CLASS 10 QUESTIONS PHYSICS = s10p.dat
// FILE CONTAINING SUBJECTIVE CLASS 10 QUESTIONS CHEMISTRY = s10c.dat
// FILE CONTAINING SUBJECTIVE CLASS 10 QUESTIONS MATHS = s10m.dat

// FILE CONTAINING SUBJECTIVE CLASS 11 QUESTIONS PHYSICS = s11p.dat
// FILE CONTAINING SUBJECTIVE CLASS 11 QUESTIONS CHEMISTRY = s11c.dat
// FILE CONTAINING SUBJECTIVE CLASS 11 QUESTIONS MATHS = s11m.dat

// FILE CONTAINING SUBJECTIVE CLASS 12 QUESTIONS PHYSICS = s12p.dat
// FILE CONTAINING SUBJECTIVE CLASS 12 QUESTIONS CHEMISTRY = s12c.dat
// FILE CONTAINING SUBJECTIVE CLASS 12 QUESTIONS MATHS = s12m.dat

// FILE CONTAINING SUBJECTIVE CLASS 10 QUESTIONS PHYSICS = m10p.dat
// FILE CONTAINING SUBJECTIVE CLASS 10 QUESTIONS CHEMISTRY = m10c.dat
// FILE CONTAINING SUBJECTIVE CLASS 10 QUESTIONS MATHS = m10m.dat

// FILE CONTAINING SUBJECTIVE CLASS 11 QUESTIONS PHYSICS = m11p.dat
// FILE CONTAINING SUBJECTIVE CLASS 11 QUESTIONS CHEMISTRY = m11c.dat
// FILE CONTAINING SUBJECTIVE CLASS 11 QUESTIONS MATHS = m11m.dat

// FILE CONTAINING SUBJECTIVE CLASS 12 QUESTIONS PHYSICS = m12p.dat
// FILE CONTAINING SUBJECTIVE CLASS 12 QUESTIONS CHEMISTRY = m12c.dat
// FILE CONTAINING SUBJECTIVE CLASS 12 QUESTIONS MATHS = m12m.dat

// FILE IN WHICH SUBJECTIVE PAPER GENERATES = spaper.dat
// FILE IN WHICH OBJECTIVE PAPER GENERATES = mpaper.dat
// FILE WHICH STORES ANSWERS TO GENERATED OBJECTIVE PAPER = answers.dat

// FILE ANMT CONTAINS WELCOME SCREEN RECTANGLE ANIMATION

// sgenerate() TO GENERATE SUBJECTIVE PAPER
// mgenerate() TO GENERATE OBJECTIVE PAPER
// swrite() TO ADD SUBJECTIVE QUESTIONS
// mwrite() TO ADD OBJECTIVE QUESTIONS

#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include "ANMT.CPP"

class sque{int qno;         // CLASS FOR SUBJECTIVE QUESTIONS
	       char que[200];
		   int marks;

		   public:

	       int assignqno(char str[]);

		   void enter(char str[])
			{cout<<"Enter Question:"<<' ';gets(que);
			 cout<<"Enter Marks:"<<' ';cin>>marks;
			 qno=assignqno(str);
			 cout<<"Question Number Is: "<<qno;getch();
			}

			void display()
		    {cout<<que<<'\n';
		    }

			int retqno(){return qno;}

		    int retmarks(){return marks;}
	       };

int sque::assignqno(char str[])            // ASSIGNING QUESTION NUMBER AUTOMATICALLY
{ifstream fin(str,ios::binary|ios::app);
 int size;
 fin.seekg(0,ios::end);
 size=fin.tellg();
 if(size<0)size=0;
 size=fin.tellg()/sizeof(sque);
 fin.close();
 return size;
}


class mque{int qno;
	       char ans;
	       char que[200];
		   char o1[50];
		   char o2[50];
		   char o3[50];
		   char o4[50];

		   public:

		   int assignqno(char str[]);

		   void enter(char str[])
		   {cout<<"Enter Question:"<<' ';gets(que);
		    cout<<"Enter Option 1:"<<' ';gets(o1);
			cout<<"Enter Option 1:"<<' ';gets(o2);
			cout<<"Enter Option 1:"<<' ';gets(o3);
			cout<<"Enter Option 1:"<<' ';gets(o4);
			cout<<"Enter Answer:"<<' ';cin>>ans;
		    qno=assignqno(str);
			cout<<"Question Number Is: "<<qno;getch();
		   }

		   void display()
		   {cout<<que<<'\n';
		    cout<<"(a). "<<o1<<'\n'
			    <<"(b). "<<o2<<'\n';
			cout<<"(c). "<<o3<<'\n'
				<<"(d). "<<o4<<'\n';
	       }

	       int retqno(){return qno;}

		   int retans(){return ans;}
		   
		   void cans()
		   {cout<<"Enter Changed Answer: ";cin>>ans;}
	      };

int mque::assignqno(char str[])            // ASSIGNING QUESTION NUMBER AUTOMATICALLY
{ifstream fin(str,ios::binary|ios::app);
 int size;
 fin.seekg(0,ios::end);
 size=fin.tellg();
 if(size<0)size=0;
 size=fin.tellg()/sizeof(mque);
 fin.close();
 return size;
}

void suwrite(int claus)
{
 sque q; int sc;
 char str[10];


 do{clrscr();
	cleardevice();
	setcolor(CYAN);
    rectangle(20,20,625,460);
	setfillstyle(1,3);
	floodfill(21,21,CYAN);
    setcolor(BLACK);

	outtextxy(250,145,"Enter Subject:");
    outtextxy(250,165,"1. Physics");
	outtextxy(250,180,"2. Chemistry");
	outtextxy(250,195,"3. Maths");
	outtextxy(250,210,"4. Exit");
	outtextxy(250,235,"Enter Choice: ");

	cin>>sc;
	if(sc<1||sc>4){outtextxy(250,265,"Enter Again");getch();getch();}
    if(sc==4)exit(0);
   }while(sc<1||sc>4);

  if(claus==10 && sc==1)
  {strcpy(str,"s10p.dat");}

  else if(claus==10 && sc==2)
  {strcpy(str,"s10c.dat");}

  else if(claus==10 && sc==3)
  {strcpy(str,"s10m.dat");}

  else if(claus==11 && sc==1)
  {strcpy(str,"s11p.dat");}

  else if(claus==11 && sc==2)
  {strcpy(str,"s11c.dat");}

  else if(claus==11 && sc==3)
  {strcpy(str,"s11m.dat");}

  else if(claus==12 && sc==1)
  {strcpy(str,"s12p.dat");}

  else if(claus==12 && sc==2)
  {strcpy(str,"s12c.dat");}

  else if(claus==12 && sc==3)
  {strcpy(str,"s12m.dat");}

 ofstream fout(str,ios::binary|ios::app);


 cleardevice();
 setbkcolor(BLACK);
 setcolor(WHITE);

 q.enter(str);
 fout.write((char*)&q,sizeof(q));
 fout.close();
 cleardevice();
}

void mwrite(int claus)
{
 mque q; int sc;
 char str[10];


 do{clrscr();
	cleardevice();
	setcolor(CYAN);
    rectangle(20,20,625,460);
	setfillstyle(1,3);
    floodfill(21,21,CYAN);
    setcolor(BLACK);

	outtextxy(250,145,"Enter Subject:");
    outtextxy(250,165,"1. Physics");
	outtextxy(250,180,"2. Chemistry");
	outtextxy(250,195,"3. Maths");
	outtextxy(250,210,"4. Exit");
	outtextxy(250,235,"Enter Choice: ");

	cin>>sc;
	if(sc<1||sc>4){outtextxy(250,265,"Enter Again");getch();getch();}
    if(sc==4)exit(0);
   }while(sc<1||sc>4);

  if(claus==10 && sc==1)
  strcpy(str,"m10p.dat");

  else if(claus==10 && sc==2)
  strcpy(str,"m10c.dat");

  else if(claus==10 && sc==3)
  strcpy(str,"m10m.dat");

  else if(claus==11 && sc==1)
  strcpy(str,"m11p.dat");

  else if(claus==11 && sc==2)
  strcpy(str,"m11c.dat");

  else if(claus==11 && sc==3)
  strcpy(str,"m11m.dat");

  else if(claus==12 && sc==1)
  strcpy(str,"m12p.dat");

  else if(claus==12 && sc==2)
  strcpy(str,"m12c.dat");

  else if(claus==12 && sc==3)
  strcpy(str,"m12m.dat");

 ofstream fout(str,ios::binary|ios::app);
 
 cleardevice();
 setbkcolor(BLACK);
 setcolor(WHITE);

 q.enter(str);
 fout.write((char*)&q,sizeof(q));
 fout.close();
 cleardevice();
}

void sgenerate(int no[],int claus)  // FUNCTION TO GENERATE SUBJECTIVE QUESTION PAPER
{
 sque q;int qno[4],flag1=0; // ARRAY no[] CONTAINS HOW MANY QUESTIONS OF SPECIFIC MARK ARE TO BE INCLUDED IN PAPER
 char str[10]; int filemarks[4]; // ARRAY insertedque[] CONTAIN QUESTION NUMBER OF QUESTION INCLUDED IN PAPER
 int insertedque[20]; int i; int j; int lastqno; int sc;
 int flag=0; int qnum; int sofinsertedque=0; int generatedqno;
 int l=0;int k=0;               // sofinsertdque IS THE NUMBER OF ELEMENTS IN ARRAY insertedque[]
				   // lastqno IS THE QUESTION NUMBER OF THE LAST QUESTION
 do{cleardevice();
    setcolor(CYAN);
    rectangle(20,20,625,460);
	setfillstyle(1,3);
	floodfill(21,21,CYAN);
    setcolor(BLACK);

	outtextxy(250,145,"Enter Subject:");
    outtextxy(250,165,"1. Physics");
	outtextxy(250,180,"2. Chemistry");
	outtextxy(250,195,"3. Maths");
	outtextxy(250,210,"4. Exit");
	outtextxy(250,235,"Enter Choice: ");

	cin>>sc;
	if(sc<1||sc>4){outtextxy(250,265,"Enter Again");getch();getch();}
    if(sc==4)exit(0);
   }while(sc<1||sc>4);

  if(claus==10 && sc==1)
  {strcpy(str,"s10p.dat");}

  else if(claus==10 && sc==2)
  {strcpy(str,"s10c.dat");}

  else if(claus==10 && sc==3)
  {strcpy(str,"s10m.dat");}

  else if(claus==11 && sc==1)
  {strcpy(str,"s11p.dat");}

  else if(claus==11 && sc==2)
  {strcpy(str,"s11c.dat");}

  else if(claus==11 && sc==3)
  {strcpy(str,"s11m.dat");}

  else if(claus==12 && sc==1)
  {strcpy(str,"s12p.dat");}

  else if(claus==12 && sc==2)
  {strcpy(str,"s12c.dat");}

  else if(claus==12 && sc==3)
  {strcpy(str,"s12m.dat");}

 cleardevice();
 setbkcolor(BLACK);
 setcolor(WHITE);

 for(i=0;i<4;i++)          // INITIALISING insertedque[] WITH -1 AS WELL AS STORING THE SIZE OF insertedque[] IN sofinsertedque
 {for(j=0;j<no[i];j++)
  {
   sofinsertedque++;}
  }

 for(i=0;i<=sofinsertedque;i++)
  insertedque[i]=-1;

 ifstream fin(str,ios::binary);   // OPENING FILE TO PICK QUESTIONS FROM
 if( !fin )
 {outtextxy(230,150,"Error Opening The File");getch();}  // IF OPENING FILE FAILS

 for(i=0;i<4;i++)
 qno[i]=0;

  fin.seekg(0);                                    
  while(fin.read((char*)&q,sizeof(q)))
	 {
	  if(q.retmarks()==1)
	  qno[0]++;
	  else if(q.retmarks()==2)
      qno[1]++;	 
      else if(q.retmarks()==3)
      qno[2]++;
      else if(q.retmarks()==4)
      qno[3]++;	  
	 }
  	 
  for(i=0;i<4;i++)
  {if(qno[i]<no[i])  
   {flag1=1;break;}
  }

 if(flag1==1)
 {clrscr();cleardevice();cout<<"Not Sufficient Questions In File";getch();
  fin.close();clrscr();cleardevice();
 }

else{

 ofstream fout("spaper.dat",ios::binary|ios::trunc);   // OPENING FILE IN WHICH QUESTION PAPER WILL BE GENERATED

 fin.seekg(0,ios::end);    // GETTING THE LAST QUESTION NUMBER IN QUESTION'S FILE
 lastqno=(fin.tellg()/sizeof(sque));

 for(i=0;i<4;i++)
 {for(j=0;j<no[i];j++)
  {flag=0;                          // RESETTING FLAG
   generatedqno=random(lastqno);   // RANDOMLY GENERATING A QUESTION NO BETWEEN 0 AND LASTQNO AND STORING IN generatedqno
   for(k=0;k<=sofinsertedque;k++) // CHECKING IF THE GENERATED QUESTION NO IS ALREADY INCLUDED IN PAPER
    {if(generatedqno==insertedque[k])
	 {flag=1;break;}
	}

   if(flag==1)
   {j--;continue;}    // EXECUTED IF THE GENERATED QUESTION NO IS ALREADY IN PAPER

   fin.seekg(0);

   while(fin.read((char*)&q,sizeof(q)))   // GETTING THE RANDOMLY GEMERATED QUESTION FROM QUESTION'S FILE
   {if(q.retqno()==generatedqno)
     {if(q.retmarks()==(i+1))    // TO CHECK IF THE RANDOMLY CHOOSEN QUESTION IS OF REQUIRED MARKS
       break;
      else{flag=1;break;}
	 }
    }

   if(flag==1)       // EXECUTED IF QUESTION MARKS DON'T MATCH
   {j--;continue;}

   fout.write((char*)&q,sizeof(q));   // IF ALL CHECKS CLEARED QUESTION GETS WRITTEN IN PAPER FILE
   insertedque[l]=generatedqno;      // IF ALL CHECKS CLEARED THEN QUESTION NO GETS ADDED TO insertedqno[]
   l=l+1;
  }
 } if(i==4){outtextxy(259,150,"Paper Generated");getch();}
 fout.close();
 fin.close();
 }
 cleardevice();
 }



void mgenerate(int no,int claus)   // FUNCTION TO GENERATE MCQ QUESTION PAPER
{
 mque q;        // no CONTAINS HOW MANY QUESTIONS ARE TO BE INCLUDED IN PAPER
 char str[10];int flag1=0; // ARRAY insertedque[] CONTAIN QUESTION NUMBER OF QUESTION INCLUDED IN PAPER
 int insertedque[20]; int i; int k; int l; int sc; // totalfileque COUNTS THE TOTAL NUMBER OF QUESTIONS IN OBJECTIVE QUESTIONS FILE
 int lastqno; int flag=0; int qnum; int generatedqno;char answer[20]; // sofinsertdque IS THE NUMBER OF ELEMENTS IN ARRAY insertedque[]
										 // lastqno IS THE QUESTION NUMBER OF THE LAST QUESTION
 do{cleardevice();
    setcolor(CYAN);
    rectangle(20,20,625,460);
	setfillstyle(1,3);
	floodfill(21,21,CYAN);
    setcolor(BLACK);

	outtextxy(250,145,"Enter Subject:");
    outtextxy(250,165,"1. Physics");
	outtextxy(250,180,"2. Chemistry");
	outtextxy(250,195,"3. Maths");
	outtextxy(250,210,"4. Exit");
	outtextxy(250,235,"Enter Choice: ");

	cin>>sc;
	if(sc<1||sc>4){outtextxy(250,265,"Enter Again");getch();getch();}
    if(sc==4)exit(0);
   }while(sc<1||sc>4);

  if(claus==10 && sc==1)
  strcpy(str,"m10p.dat");

  else if(claus==10 && sc==2)
  strcpy(str,"m10c.dat");

  else if(claus==10 && sc==3)
  strcpy(str,"m10m.dat");

  else if(claus==11 && sc==1)
  strcpy(str,"m11p.dat");

  else if(claus==11 && sc==2)
  strcpy(str,"m11c.dat");

  else if(claus==11 && sc==3)
  strcpy(str,"m11m.dat");

  else if(claus==12 && sc==1)
  strcpy(str,"m12p.dat");

  else if(claus==12 && sc==2)
  strcpy(str,"m12c.dat");

  else if(claus==12 && sc==3)
  strcpy(str,"m12m.dat");

 for(i=0;i<no;i++)              // INITIALISING insertedque[] WITH -1
 insertedque[i]=-1;

 cleardevice();
 setbkcolor(BLACK);
 setcolor(WHITE);

 ifstream fin(str,ios::binary);   // OPENING FILE TO PICK QUESTIONS FROM
 if( !fin )
 {outtextxy(230,150,"Error Opening The File");getch();}  // IF OPENING FILE FAILS

 ofstream fout("mpaper.dat",ios::binary|ios::trunc); // OPENING FILE IN WHICH QUESTION PAPER WILL BE GENERATED

 for(i=0;i<no;i++)
  insertedque[i]=-1;

  fin.seekg(0,ios::end);     // GETTING THE LAST QUESTION NUMBER IN QUESTION'S FILE
  lastqno=(fin.tellg()/sizeof(mque));

  if(lastqno>=no)
  flag1=1;

if(flag1==0)
{clrscr();cleardevice();cout<<"Not Sufficient Questions In File";getch();
 fin.close();fout.close();cleardevice();
}

else{

 for(i=0;i<no;i++)
 { flag=0;         // RESETTING FLAG
   generatedqno=random(lastqno);   // RANDOMLY GENERATING A QUESTION NO BETWEEN 0 AND LASTQNO AND STORING IN generatedqno
   for(k=0;k<no;k++)    // CHECKING IF THE GENERATED QUESTION NO IS ALREADY INCLUDED IN PAPER
    {if(generatedqno==insertedque[k])
	 {flag=1;break;}
	}

   if(flag==1)
   {i--;continue;}  // EXECUTED IF THE GENERATED QUESTION NO IS ALREADY IN PAPER

   fin.seekg(0);

   while(fin.read((char*)&q,sizeof(q)))  // GETTING THE RANDOMLY GEMERATED QUESTION FROM QUESTION'S FILE
   {if(q.retqno()==generatedqno)
     break;  // BREAKS WHILE IF REQUIRED QUESTION IS FOUND
   }

   fout.write((char*)&q,sizeof(q));  // IF ALL CHECKS CLEARED QUESTION GETS WRITTEN IN PAPER FILE
   insertedque[i]=generatedqno;   // IF ALL CHECKS CLEARED THEN QUESTION NO GETS ADDED TO insertedqno[]
   answer[i]=q.retans();  // STORING ANSWER TO QUESTION
 }
 if(i==no){outtextxy(259,150,"Paper Generated");getch();}

 fout.close();
 fin.close();

 ofstream fout1;
 fout1.open("answerkey.dat",ios::binary|ios::trunc);  // STORING ALL THE ANSWERS IN A FILE
 for(i=0;i<no;i++)
  {fout1<<answer[i];}
 fout1.close();
}
cleardevice();
}


void spaperdisplay()        // FUNCTION TO DISPLAY GENERATED SUBJECTIVE QUESTION PAPER
{
 sque q;int n=1;

 ifstream fin("spaper.dat",ios::binary|ios::nocreate);
 
 clrscr();
 cleardevice();
 setbkcolor(BLACK);
 cout<<'\n';
 if(!fin){clrscr();cout<<"ERROR OPENING THE FILE!";getch();}  // IF ERROR WHILE OPENING QUESTION PAPER FILE

 else{while(fin.read((char*)&q,sizeof(q)))
       {cout<<n<<"."<<' ';q.display();cout<<'\n';n++;}
	    getch();
	   }
 fin.close();
 cleardevice();
}

void mpaperdisplay()  // FUNCTION TO DISPLAY GENERATED MCQ QUESTION PAPER
{
 int n=1;char choice;mque q;

 ifstream fin("mpaper.dat",ios::binary|ios::nocreate);

 clrscr();
 cleardevice();
 setbkcolor(BLACK);
 setcolor(WHITE);
 cout<<'\n';
 if( !fin )
 {clrscr();cout<<"ERROR OPENING THE FILE!";getch();} // IF ERROR OPENING QUESTION PAPER FILE

 else{while(fin.read((char*)&q,sizeof(q)))
      {cout<<n<<"."<<' ';q.display();cout<<'\n';n++;}

	  getch();
	  clrscr();
	  cleardevice();
	  
	  cout<<'\n';
	  
	  cout<<"Do You Want To Display Answer Key?(y/n): ";cin>>choice;  // OPTION TO GENERATE ANSWER KEY
      if(choice=='y'||choice=='Y')
      {fin.close();char m;n=1;

	   fin.open("answerkey.dat",ios::binary|ios::nocreate);

	   if(!fin){clrscr();cout<<"Error Opening Answer Key";getch();} // IF ERROR OPENING ANSWER FILE

	   else{while(fin>>m)
	        {
	         cout<<n<<"."<<' '<<m<<'\n';n++;}
	       }
      }getch();
	 }
 fin.close();
 cleardevice();
}

void sdelete(int claus)  // To Delete A Question From Subjective Questions File
{int sc;
 sque q; char str[10]; int qno; int flag=0;
 do{cleardevice();
    setcolor(CYAN);
    rectangle(20,20,625,460);
	setfillstyle(1,3);
	floodfill(21,21,CYAN);
    setcolor(BLACK);

	outtextxy(250,145,"Enter Subject:");
    outtextxy(250,165,"1. Physics");
	outtextxy(250,180,"2. Chemistry");
	outtextxy(250,195,"3. Maths");
	outtextxy(250,210,"4. Exit");
	outtextxy(250,235,"Enter Choice: ");
	
	cin>>sc;
	if(sc<1||sc>4){outtextxy(250,265,"Enter Again");getch();getch();} // If File Opening Fails
    if(sc==4)exit(0);
   }while(sc<1||sc>4);

  if(claus==10 && sc==1)
  strcpy(str,"s10p.dat");

  else if(claus==10 && sc==2)
  strcpy(str,"s10c.dat");

  else if(claus==10 && sc==3)
  strcpy(str,"s10m.dat");

  else if(claus==11 && sc==1)
  strcpy(str,"s11p.dat");

  else if(claus==11 && sc==2)
  strcpy(str,"s11c.dat");

  else if(claus==11 && sc==3)
  strcpy(str,"s11m.dat");

  else if(claus==12 && sc==1)
  strcpy(str,"s12p.dat");

  else if(claus==12 && sc==2)
  strcpy(str,"s12c.dat");

  else if(claus==12 && sc==3)
  strcpy(str,"s12m.dat");
 
 cleardevice();
 setcolor(CYAN);
 rectangle(20,20,625,460);
 setfillstyle(1,3);
 floodfill(21,21,CYAN);
 setcolor(BLACK);

 outtextxy(150,150,"Enter Question No. Of the Question You Want To Delete: ");  //Getting The Question Number Of the Question To Delete
 
 cin>>qno;
 
 cleardevice();
 setcolor(CYAN);
 rectangle(20,20,625,460);
 setfillstyle(1,3);
 floodfill(21,21,CYAN);
 setcolor(BLACK);

 ifstream fin (str,ios::binary);
 ofstream fout ("temp.dat",ios::binary|ios::trunc);

 fin.seekg(0);
 fout.seekp(0);
 
 while(fin.read((char*)&q,sizeof(q)))                         // Searching For The Question Number In The File
 {
  if(q.retqno()==qno)
  {flag=1;}
  else
  {fout.write((char*)&q,sizeof(q));}
 }

 if(flag==1)                                      // If Question Number Found
 {outtextxy(250,165,"Question Deleted");getch();
  fin.close();
  fout.close();
  remove(str);
  rename("temp.dat",str);
 }
 else{outtextxy(250,165,"Question Not Found");   // If Question Number Not Found In The File
	  fin.close();
      fout.close();
	 }

cleardevice();
}

void mdelete(int claus)    // To Delete A Question From Objective Questions File
{int sc;
 mque q; char str[10]; int qno; int flag=0;
 do{cleardevice();
    setcolor(CYAN);
    rectangle(20,20,625,460);
	setfillstyle(1,3);
	floodfill(21,21,CYAN);
    setcolor(BLACK);
    
    outtextxy(250,145,"Enter Subject:");
    outtextxy(250,165,"1. Physics");
	outtextxy(250,180,"2. Chemistry");
	outtextxy(250,195,"3. Maths");
	outtextxy(250,210,"4. Exit");
	outtextxy(250,235,"Enter Choice: ");
	
	cin>>sc;
	if(sc<1||sc>4){outtextxy(250,265,"Enter Again");getch();}
    if(sc==4)exit(0);
   }while(sc<1||sc>4);

  if(claus==10 && sc==1)
  strcpy(str,"m10p.dat");

  else if(claus==10 && sc==2)
  strcpy(str,"m10c.dat");

  else if(claus==10 && sc==3)
  strcpy(str,"m10m.dat");

  else if(claus==11 && sc==1)
  strcpy(str,"m11p.dat");

  else if(claus==11 && sc==2)
  strcpy(str,"m11c.dat");

  else if(claus==11 && sc==3)
  strcpy(str,"m11m.dat");

  else if(claus==12 && sc==1)
  strcpy(str,"m12p.dat");

  else if(claus==12 && sc==2)
  strcpy(str,"m12c.dat");

  else if(claus==12 && sc==3)
  strcpy(str,"m12m.dat");

 cleardevice();
 setcolor(CYAN);
 rectangle(20,20,625,460);
 setfillstyle(1,3);
 floodfill(21,21,CYAN);
 setcolor(BLACK);

 outtextxy(150,150,"Enter Question No. Of the Question You Want To Delete: ");  //Getting The Question Number Of the Question To Delete   
 
 cin>>qno;
 
 cleardevice();
 setcolor(CYAN);
 rectangle(20,20,625,460);
 setfillstyle(1,3);
 floodfill(21,21,CYAN);
 setcolor(BLACK);

 ifstream fin (str,ios::binary);
 ofstream fout ("temp.dat",ios::binary|ios::trunc);

 fin.seekg(0);
 fout.seekp(0);
 
 while(fin.read((char*)&q,sizeof(q)))           // Searching For The Question Number In The File
 {
  if(q.retqno()==qno)
  {flag=1;}
  else
  {fout.write((char*)&q,sizeof(q));}
 }

 if(flag==1)             // If Question Number Found
 {outtextxy(250,165,"Question Deleted");getch();
  fin.close();
  fout.close();
  remove(str);
  rename("temp.dat",str);
 }
 else{outtextxy(250,165,"Question Not Found");getch();  // If Question Number Not Found In The File
      fin.close();
      fout.close();
	 }
cleardevice();
}

void manschange(int claus) // To Change Answer To A Objective Question
{int sc;
 mque q; char str[10]; int qno; int flag=0;
 do{cleardevice();
    setcolor(CYAN);
    rectangle(20,20,625,460);
	setfillstyle(1,3);
	floodfill(21,21,CYAN);
    setcolor(BLACK);
    	
	outtextxy(250,145,"Enter Subject:");
    outtextxy(250,165,"1. Physics");
	outtextxy(250,180,"2. Chemistry");
	outtextxy(250,195,"3. Maths");
	outtextxy(250,210,"4. Exit");
	outtextxy(250,235,"Enter Choice: ");
	
	cin>>sc;
	if(sc<1||sc>4){outtextxy(250,265,"Enter Again");getch();}
    if(sc==4)exit(0);
   }while(sc<1||sc>4);

  if(claus==10 && sc==1)
  strcpy(str,"m10p.dat");

  else if(claus==10 && sc==2)
  strcpy(str,"m10c.dat");

  else if(claus==10 && sc==3)
  strcpy(str,"m10m.dat");

  else if(claus==11 && sc==1)
  strcpy(str,"m11p.dat");

  else if(claus==11 && sc==2)
  strcpy(str,"m11c.dat");

  else if(claus==11 && sc==3)
  strcpy(str,"m11m.dat");

  else if(claus==12 && sc==1)
  strcpy(str,"m12p.dat");

  else if(claus==12 && sc==2)
  strcpy(str,"m12c.dat");

  else if(claus==12 && sc==3)
  strcpy(str,"m12m.dat");

 cleardevice();
 setcolor(CYAN);
 rectangle(20,20,625,460);
 setfillstyle(1,3);
 floodfill(21,21,CYAN);
 setcolor(BLACK);
 
 outtextxy(80,140,"Enter Question No. Of the Question You Want To Change Answer To: "); // Getting the Question Number From The User
 
 cin>>qno;
 
 clrscr();
 cleardevice();
 setbkcolor(BLACK);
 setcolor(WHITE);

 ifstream fin (str,ios::binary);
 ofstream fout ("temp.dat",ios::binary|ios::trunc);

 fin.seekg(0);
 fout.seekp(0);

 while(fin.read((char*)&q,sizeof(q)))  // Searching For The Question In the File 
 {
  if(q.retqno()==qno)
  {flag=1;
   q.display();
   cout<<"\n\n";
   q.cans();
   clrscr();
   cleardevice();
   fout.write((char*)&q,sizeof(q));
  }
  else
  {fout.write((char*)&q,sizeof(q));}
  }

 if(flag==1)        // If Question Found
 {outtextxy(250,165,"Answer Changed");getch();
  fin.close();
  fout.close();
  remove(str);
  rename("temp.dat",str);
 }
 else{outtextxy(250,165,"Question Not Found");getch();  // If Question Not Found
      fin.close();
      fout.close();
	 }
cleardevice();
}

void main()        // MAIN STARTS
{
	
	int gdrive=DETECT , gmode , errorcode ;
	initgraph(&gdrive,&gmode,"C:\\TURBOC3\\BGI");
	errorcode=graphresult();
	if(errorcode!=grOk)
	{
		printf("%S",grapherrormsg(errorcode));
		exit(0);
	}
	
 clrscr(); 
 cleardevice();
 
 rectangle(5,10,635,470);

 outtextxy(182,160,"WelCome To The Question Bank Generator");
 outtextxy(90,175,"Made By Suyash Vyas And Kunal Tulsidasani || Class XII- A");
 outtextxy(212,230,"Press Any  Key To Start");getch();
 
 anmt();
 
 cleardevice();
 
 setcolor(CYAN);
 
 char mc;
 
 do{cleardevice();
    int a;
    do{cleardevice();
	   setcolor(CYAN);
	   rectangle(20,20,625,460);
	   setfillstyle(1,3);
	   floodfill(21,21,CYAN);
       setcolor(BLACK);
	   outtextxy(250,145,"1. Admin Mode");   // Menu 1
       outtextxy(250,160,"2. User Mode");
	   outtextxy(250,175,"3. Exit");
	   outtextxy(250,195,"Enter Choice: ");
	   
	   cin>>a;
		   if(a<1||a>3)
	       {outtextxy(250,225,"Enter Again!");getch();}
       if(a==3)exit(0);
	  }while(a<1||a>3);
		   
	    cleardevice();
		setcolor(CYAN);
		rectangle(20,20,625,460);
	    setfillstyle(1,3);
	    floodfill(21,21,CYAN);
        setcolor(BLACK);
		 
		if(a==1)
		{char pass[4];char c;int i=0; int x=310; char sc;
		 outtextxy(230,150,"Password: ");                 // Password For Admin Mode
		 while((c=getch())!=13)
		 {pass[i]=c;
		  outtextxy(x,150,"*");
		  x=x+10;
		  i++;
		 }pass[i]='\0';
		 
		 cleardevice();
		 setcolor(CYAN);
		 rectangle(20,20,625,460);
	     setfillstyle(1,3);
	     floodfill(21,21,CYAN);
         setcolor(BLACK);
		 
		 if(strcmp(pass,"abcd")!=0)
		 {outtextxy(250,145,"Wrong Password!");getch();exit(0);}	 
         else
		 {do
		   {
            do
		     {cleardevice();
			  setcolor(CYAN);
			  rectangle(20,20,625,460);
	          setfillstyle(1,3);
	          floodfill(21,21,CYAN);
              setcolor(BLACK);
			  
			  outtextxy(220,150,"1. Add Subjective Question");            // Menu 1 Admin Mode
	          outtextxy(220,165,"2. Add Objective Question");
	          outtextxy(220,180,"3. Delete Subjective Question");
	          outtextxy(220,195,"4. Delete Objective Question");
	          outtextxy(220,210,"5. Chanqe Answer to a Objective Question");
	          outtextxy(220,225,"6. Exit");
	          outtextxy(220,245,"7. Enter Choice: ");	  
			
			  cin>>a;
			   if(a<1||a>6)
	           {outtextxy(240,275,"Enter Again!");getch();}
               if(a==6)exit(0);
	         }while(a<1||a>6);
			
		    if(a==1)
            {int claus;
             do{cleardevice();
			    setcolor(CYAN);
			    rectangle(20,20,625,460);
	            setfillstyle(1,3);
	            floodfill(21,21,CYAN);
                setcolor(BLACK);
				
			    outtextxy(150,150,"Enter Class(between 10 To 12) OR Press 0 To Exit: ");
				
	            cin>>claus;
		        if((claus<10||claus>12) && (claus!=0))
		        {outtextxy(250,180,"Enter Again!");getch();}
	            if(claus==0)exit(0);
	           }while(claus<10||claus>12);
		      suwrite(claus);                                                     
	        }
		  
		   else if(a==2)
 	       {int claus;
            do{cleardevice();
			   setcolor(CYAN);
			   rectangle(20,20,625,460);
	           setfillstyle(1,3);
	           floodfill(21,21,CYAN);
               setcolor(BLACK);
			  
			   outtextxy(150,150,"Enter Class(between 10 To 12) OR Press 0 To Exit: ");
			   
	           cin>>claus;
	           if((claus<10||claus>12) && (claus!=0))
               {outtextxy(250,180,"Enter Again!");getch();}
	           if(claus==0)exit(0);
	          }while(claus<10||claus>12);
	        mwrite(claus);                                                      
	       }

          else if(a==3)
          {int claus;
           do{cleardevice();
		      setcolor(CYAN);
		      rectangle(20,20,625,460);
	          setfillstyle(1,3);
	          floodfill(21,21,CYAN);
              setcolor(BLACK);
			  
			  outtextxy(150,150,"Enter Class(between 10 To 12) OR Press 0 To Exit: ");
			  
	           cin>>claus;
	           if((claus<10||claus>12) && (claus!=0))
               {outtextxy(250,180,"Enter Again!");getch();}
	           if(claus==0)exit(0);
	          }while(claus<10||claus>12);
	        sdelete(claus);                                                      
	      }

          else if(a==4)
           {int claus;
            
	        do{cleardevice();
			   setcolor(CYAN);
			   rectangle(20,20,625,460);
	           setfillstyle(1,3);
	           floodfill(21,21,CYAN);
               setcolor(BLACK);
				
				outtextxy(150,150,"Enter Class(between 10 To 12) OR Press 0 To Exit: ");
				
	           cin>>claus;
	           if((claus<10||claus>12) && (claus!=0))
               {outtextxy(250,180,"Enter Again!");getch();}
	           if(claus==0)exit(0);
	         }while(claus<10||claus>12);
	        mdelete(claus);                                                      
	       }
 
          else if(a==5)
           {int claus;
            do{cleardevice();
			   setcolor(CYAN);
			   rectangle(20,20,625,460);
	           setfillstyle(1,3);
	           floodfill(21,21,CYAN);
               setcolor(BLACK);
			  
			   outtextxy(150,150,"Enter Class(between 10 To 12) OR Press 0 To Exit: ");
			   
	           cin>>claus;
	           if((claus<10||claus>12) && (claus!=0))
               {outtextxy(250,180,"Enter Again!");getch();}
	           if(claus==0)exit(0);
	          }while(claus<10||claus>12);
	        manschange(claus);                                                     
	       }				
		
        clrscr();
		cleardevice();
		setcolor(CYAN);
		rectangle(20,20,625,460);
	    setfillstyle(1,3);
	    floodfill(21,21,CYAN);
        setcolor(BLACK);

		 outtextxy(230,150,"Return To Main Menu?(y/n): ");
		
	 cin>>sc;
		}while(sc=='y'||sc=='Y');
    
	  }
		}
	   
	   else if(a==2)
	   {char sc;
		do{
           do{cleardevice();
		      setcolor(CYAN);
		      rectangle(20,20,625,460);
	          setfillstyle(1,3);
	          floodfill(21,21,CYAN);
              setcolor(BLACK);
		      
			  outtextxy(220,150,"1. Generate Subjective Question Paper");  // Menu 1 User Mode
	          outtextxy(220,165,"2. Generate Objective Question Paper");
	          outtextxy(220,180,"3. Display Generated Subjective Paper");
	          outtextxy(220,195,"4. Display Generated Objective Paper");
	          outtextxy(220,210,"5. Exit");
	          outtextxy(220,230,"Enter Choice: "); 
			  
			  cin>>a;
              if(a<1||a>5)
	           {outtextxy(240,250,"Enter Again!");getch();}
              if(a==5)exit(0);
	         }while(a<1||a>5);
           
		   if(a==1)
           {int claus;int no[4];
            do{cleardevice();
			   setcolor(CYAN);
			   rectangle(20,20,625,460);
	           setfillstyle(1,3);
	           floodfill(21,21,CYAN);
               setcolor(BLACK);
				
			   outtextxy(150,150,"Enter Class(between 10 To 12) OR Press 0 To Exit: ");
			   
	           cin>>claus;
		       if((claus<10||claus>12) && (claus!=0))
		       {outtextxy(250,180,"Enter Again!");getch();}
	           if(claus==0)exit(0);
	          }while(claus<10||claus>12);

	        cleardevice();
			setcolor(CYAN);
			rectangle(20,20,625,460);
	        setfillstyle(1,3);
	        floodfill(21,21,CYAN);
            setcolor(BLACK);

			outtextxy(220,150,"Enter No. Of Question Of 1 Marks: ");
	        cin>>no[0];
			
			cleardevice();
			setcolor(CYAN);
			rectangle(20,20,625,460);
	        setfillstyle(1,3);
	        floodfill(21,21,CYAN);
            setcolor(BLACK);

	        outtextxy(220,150,"Enter No. Of Question Of 2 Marks: ");
	        cin>>no[1];
			
			cleardevice();
			setcolor(CYAN);
			rectangle(20,20,625,460);
	        setfillstyle(1,3);
	        floodfill(21,21,CYAN);
            setcolor(BLACK);

	        outtextxy(220,150,"Enter No. Of Question Of 3 Marks: ");
	        cin>>no[2];
			
			cleardevice();
			setcolor(CYAN);
			rectangle(20,20,625,460);
	        setfillstyle(1,3);
	        floodfill(21,21,CYAN);
            setcolor(BLACK);

	        outtextxy(220,150,"Enter No. Of Question Of 4 Marks: ");
	        cin>>no[3];
			
			cleardevice();

			sgenerate(no,claus);                                          

	       }

           else if(a==2)
		   {int claus;int no;
            do{cleardevice();
			   setcolor(CYAN);
			   rectangle(20,20,625,460);
	           setfillstyle(1,3);
	           floodfill(21,21,CYAN);
               setcolor(BLACK);
			   
			   outtextxy(150,150,"Enter Class(between 10 To 12) OR Press 0 To Exit: ");
			   
	           cin>>claus;
		       if((claus<10||claus>12) && (claus!=0))
		       {outtextxy(250,180,"Enter Again!");getch();}
	           if(claus==0)exit(0);
	          }while(claus<10||claus>12);

	        cleardevice();
			setcolor(CYAN);
			rectangle(20,20,625,460);
	        setfillstyle(1,3);
	        floodfill(21,21,CYAN);
            setcolor(BLACK);

			outtextxy(220,150,"Enter No. Of Question Of 1 Marks: ");
	        cin>>no;

	        cleardevice();

	        mgenerate(no,claus);                                        

	       }
		   
		   else if(a==3)
	       {cleardevice();spaperdisplay();}

           else if(a==4)
	       {cleardevice();mpaperdisplay();}
		  
		   clrscr();
		   cleardevice();
		   setcolor(CYAN);
		   rectangle(20,20,625,460);
	       setfillstyle(1,3);
	       floodfill(21,21,CYAN);
           setcolor(BLACK);

		   outtextxy(230,150,"Return To Main Menu?(y/n): ");
	   cin>>sc;
 
          }while(sc=='y'||sc=='Y');
	   }
      
	  outtextxy(230,165,"Return To Main Menu?(y/n): ");
	  
	  cin>>mc;
     }while(mc=='y'||mc=='Y'); 
closegraph();
}                // End Of Main