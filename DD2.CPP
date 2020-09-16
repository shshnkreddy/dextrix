#include <iostream.h>
#include <graphics.h>
#include <fstream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dos.h>
#include <time.h>

//player position values
//central values
int xl=265,yl=300,x2l=305,y2l=340;       //left box
int xr=306,yr=300,x2r=346,y2r=340;       //right box
//split values
int sxl=211,syl=300,sx2l=251,sy2l=340;   //left box
int sxr=369,syr=300,sx2r=409,sy2r=340;   //right box
//left jump values
int lxl=211,lyl=300,lx2l=251,ly2l=340;   //left box
int lxr=252,lyr=300,lx2r=292,ly2r=340;   //right box
//right jump values
int rxl=328,ryl=300,rx2l=368,ry2l=340;   //left box
int rxr=369,ryr=300,rx2r=409,ry2r=340;   //right box

//obstacle bar values
int a=297,ft=34,b=409,fb=84;                 //type 1
int a2=211,ft2=34,b2=325,fb2=84;             //type 2
int a3=254,ft3=34,b3=366,fb3=84;             //type 3
int al4=211,ftl4=34,bl4=263,fbl4=84;         //type 4 (left box)
int ar4=348,ftr4=34,br4=409,fbr4=84;         //type 4 (right box)

class object{
		  public:
			 int x,y,x2,y2,x3,y3,x4,y4;

			 void converge()    //teleport to central position, uses central values
			 {
			  setfillstyle(SOLID_FILL,BLACK);
			  bar(x,y,x2,y2);
			  setfillstyle(SOLID_FILL,BLACK);
			  bar(x3,y3,x4,y4);

			  x=xl,y=yl,x2=x2l,y2=y2l,x3=xr,y3=yr,x4=x2r,y4=y2r;

			  setfillstyle(SOLID_FILL,LIGHTBLUE);
			  bar(x,y,x2,y2);
			  setfillstyle(SOLID_FILL,LIGHTRED);
			  bar(x3,y3,x4,y4);
			 }

			 void diverge()     //teleport to split position, uses split values
			 {
			  setfillstyle(SOLID_FILL,BLACK);
			  bar(x,y,x2,y2);
			  setfillstyle(SOLID_FILL,BLACK);
			  bar(x3,y3,x4,y4);

			  x=sxl,y=syl,x2=sx2l,y2=sy2l,x3=sxr,y3=syr,x4=sx2r,y4=sy2r;

			  setfillstyle(SOLID_FILL,LIGHTBLUE);
			  bar(x,y,x2,y2);
			  setfillstyle(SOLID_FILL,LIGHTRED);
			  bar(x3,y3,x4,y4);
			 }

			 void leftjump()
			 {
			  setfillstyle(SOLID_FILL,BLACK);
			  bar(x,y,x2,y2);
			  setfillstyle(SOLID_FILL,BLACK);
			  bar(x3,y3,x4,y4);

			  x=lxl,y=lyl,x2=lx2l,y2=ly2l,x3=lxr,y3=lyr,x4=lx2r,y4=ly2r;

			  setfillstyle(SOLID_FILL,LIGHTBLUE);
			  bar(x,y,x2,y2);
			  setfillstyle(SOLID_FILL,LIGHTRED);
			  bar(x3,y3,x4,y4);
			 }

			 void rightjump()
			 {
			  setfillstyle(SOLID_FILL,BLACK);
			  bar(x,y,x2,y2);
			  setfillstyle(SOLID_FILL,BLACK);
			  bar(x3,y3,x4,y4);

			  x=rxl,y=ryl,x2=rx2l,y2=ry2l,x3=rxr,y3=ryr,x4=rx2r,y4=ry2r;

			  setfillstyle(SOLID_FILL,LIGHTBLUE);
			  bar(x,y,x2,y2);
			  setfillstyle(SOLID_FILL,LIGHTRED);
			  bar(x3,y3,x4,y4);
			 }

			 void showplayer(int a,int b, int a2, int b2, int a3,int b3,int a4,int b4)  //displays player at given position, uses values that coresspond to a position
			 {
			  x=a,y=b,x2=a2,y2=b2,x3=a3,y3=b3,x4=a4,y4=b4;

			  setfillstyle(SOLID_FILL,LIGHTBLUE);
			  bar(x,y,x2,y2);
			  setfillstyle(SOLID_FILL,LIGHTRED);
			  bar(x3,y3,x4,y4);
			 }
		 }dex;                          //dex is the main player object

//base class for obstacle types
class obstacle{
		public:
				 int z,v,z2,v2;
				 int c,d,c2,d2; //meant to store copy for reset.

				 int movement(int s)    //function for movement of obstacle depending on speed input.
				 {
				  int speed=s;
				  setfillstyle(SOLID_FILL,BLACK);
				  bar(z,v,z2,v2);

				  v+=speed;
				  v2=v+50;

				  setfillstyle(SOLID_FILL,WHITE);
				  bar(z,v,z2,v2);

				  if(v>getmaxy())
				  {
				   z=c,v=d,z2=c2,v2=d2;
				   return 5;
				  }
				  else
				  {
				   return 0;
				  }
				 }

	      };
//obstacle type 1
class type1:public obstacle{     //inherits from base class obstacle


				 public:
					type1()     //constructor
					{
					 z=a,v=ft,z2=b,v2=fb;
					 c=z,d=v,c2=z2,d2=v2; //note c,d,c2,d2 are inherited
					}
					void reset()  //resets values upon restart
					{
					 z=c,v=d,z2=c2,v2=d2;
					}
				}t1;

//obstacle type 2
class type2:public obstacle{   //inherits from base class obstacle


				 public:
					type2()  //constructor
					{
					 z=a2,v=ft2,z2=b2,v2=fb2;
					 c=z,d=v,c2=z2,d2=v2;   //note c,d,c2,d2 are inherited
					}
					void reset()
					{
					 z=c,v=d,z2=c2,v2=d2;
					}
				}t2;
//obstacle type 3
class type3:public obstacle{       //inherits from base class obstacle


				 public:
					type3()   //constructor
					{
					 z=a3,v=ft3,z2=b3,v2=fb3;
					 c=z,d=v,c2=z2,d2=v2;
					}
					void reset()
					{
					 z=c,v=d,z2=c2,v2=d2;

					}
				}t3;
//obstacle type 4
class type4{    //stand alone class does not inherit from anyone.
		  public:

				 int z,v,z2,v2,z3,v3,z4,v4;  //meant to store copy for reset.(left box)
				 int c,d,c2,d2,c3,d3,c4,d4;  //meant to store copy for reset.(right box)

				 type4()
				 {
					z=al4,v=ftl4,z2=bl4,v2=fbl4;
					z3=ar4,v3=ftr4,z4=br4,v4=fbr4;

					c=z,d=v,c2=z2,d2=v2;
					c3=z3,d3=v3,c4=z4,d4=v4;
				 }
				 int movement(int s)
				 {
					int speed=s;
					setfillstyle(SOLID_FILL,BLACK);
					bar(z,v,z2,v2);

					v+=speed;
					v2=v+50;

					setfillstyle(SOLID_FILL,WHITE);
					bar(z,v,z2,v2);

					setfillstyle(SOLID_FILL,BLACK);
					bar(z3,v3,z4,v4);

					v3+=speed;
					v4=v3+50;

					setfillstyle(SOLID_FILL,WHITE);
					bar(z3,v3,z4,v4);

					if(v3>getmaxy())
					{
					 z=c,v=d,z2=c2,v2=d2;
					 z3=c3,v3=d3,z4=c4,v4=d4;
					 return 5;
					}
					else
					{
					 return 0;
					}
				 }

				 void reset()
				 {
				  z=c,v=d,z2=c2,v2=d2;
				  z3=c3,v3=d3,z4=c4,v4=d4;
				 }

	   }t4;

class player{                         //records to store score and names
		  protected:
				 int score;
				 char name[50];
		  public:
			 void getdata(int s)     //to get input data,score is passed at the end of the game.
			 {
			  clrscr();
			  cout<<"\nENTER PLAYER NAME: ";
			  gets(name);
			  score=s;
			 }
			 void disp()
			 {
			  cout<<"\n\nPLAYER NAME: ";
			  puts(name);
			  cout<<"BEST SCORE: "<<score;
			 }
			 char* getname()
			 {
			  return name;
			 }
			 int getscore()
			 {
			  return score;
			 }
			 void modify(int s)
			 {
			  score=s;
			 }
		 };

void save_file(int s)    //function to save score
{
 int score=s;           //stores score passed from game.
 fstream old,ne;
 player ob,n;

 n.getdata(score);      //gets players name from user.

 int i=0;    //keeps track of how many records read.
 int flag=0; //flag to check if record is a new addition or a record that has to be modified.

 old.open("SAVEFILE.dat",ios::binary|ios::in);    //links old to savefile.dat
 ne.open("TEMP.dat",ios::binary|ios::in|ios::out);//links ne to temp.dat

 while(old.read((char*)&ob,sizeof(ob)))   //reading through savefile.dat
 { ++i;

  if(!strcmpi(n.getname(),ob.getname())) //checks for matching name
  { flag=1;  //implies that record is not new but an old one needs to be updated.
   if(n.getscore()>ob.getscore()) //checks if current score is greater than old.
   {
    ne.close(); //closes ne's link to temp.dat

      fstream t,t1,fob;
      player T,T1;
      char name[50],last='y';//flag to check if record to be added will be last.

      t.open("TEMP.dat",ios::binary|ios::in|ios::out); //opens temp again but links another fileobject to it.
      t1.open("TEMP1.dat",ios::binary|ios::in|ios::out);//creates new file temp1.dat which will serve as the final file.

      int j=0;  //to keep track of number of records read.
      while(t.read((char*)&T,sizeof(T))) //reads through temp.
      {

       if(n.getscore()>=T.getscore())  //if new score>old one
       {
	t1.write((char*)&n,sizeof(n)); //writes new score
	last='n';
	break;
       }
       else
       {
	t1.write((char*)&T,sizeof(T));
       }
       ++j;
      }

      if(last=='y')  //if record to be added is last then adds it
      {
       t1.write((char*)&n,sizeof(n));
      }
      else          //if record to be added is not last
      {
       t.seekg(j*sizeof(T),ios::beg);     //moves file pointer to position after the record that matched int the old file.
       while(t.read((char*)&T,sizeof(T))) //reads from then on and writes the remaining records.
       {
	t1.write((char*)&T,sizeof(T));
       }
      }

      t.close();
      t1.close();
      remove("TEMP.dat");
      rename("TEMP1.dat","TEMP.dat"); //renames temp1.dat to temp
   }
    ne.open("TEMP.dat",ios::binary|ios::app|ios::in|ios::out); //relinks ne to temp in app mode.so that rest can be added.
  }

  else
  {
   ne.write((char*)&ob,sizeof(ob));
  }

 }

 old.close();
 ne.close();
 remove("SAVEFILE.dat");
 rename("TEMP.dat","SAVEFILE.dat"); //performs upper operations and renames.

 if(flag==0)//if flag==0 implies new record that has to be added
 {          //works similar to previous segment basically checks order and places the new record in place.
  fstream ol,nee,fob;
  player OL,N;
  char name[50],last='y';

  ol.open("SAVEFILE.dat",ios::binary|ios::in|ios::out);
  nee.open("TEMP.dat",ios::binary|ios::in|ios::out);

  int k=0;
  while(ol.read((char*)&OL,sizeof(OL)))
  {

   if(n.getscore()>=OL.getscore())
   {
    nee.write((char*)&n,sizeof(n));
    last='n';
    break;
   }
   else
   {
    nee.write((char*)&OL,sizeof(OL));
   }
   ++k;
  }

  if(last=='y')
  {
   nee.write((char*)&n,sizeof(n));
  }
  else
  {
   ol.seekg(k*sizeof(OL),ios::beg);
   while(ol.read((char*)&OL,sizeof(OL)))
   {
    nee.write((char*)&OL,sizeof(OL));
   }
  }

  ol.close();
  nee.close();
  remove("SAVEFILE.dat");
  rename("TEMP.dat","SAVEFILE.dat");
 }
}  //end of save_file(int s)

void displayfile()  //function to display savefile.dat
{
  fstream fob;
  player ob;

  fob.open("SAVEFILE.dat",ios::binary|ios::in);


  while(fob.read((char*)&ob,sizeof(ob)))
  {
   setcolor(CYAN);
   ob.disp();
  }

  getch();
  fob.close();
}

char creditdisplay()              //credits display n main menu
{
 cleardevice();
 settextstyle(3,0,3);
 cleardevice();
 setcolor(CYAN);
 outtextxy(110,200,"UTSAV ASHRIT & SHASHANK of XII C");
 delay(2000);
 cleardevice();
 setcolor(WHITE);
 outtextxy(260,200,"PRESENT");
 delay(2000);
 cleardevice();
 setcolor(CYAN);
 outtextxy(260,200,"DEXTRIX");
 setcolor(12);
 outtextxy(350,200,"C++");
 settextstyle(0,0,1);
 outtextxy(230,250,"PRESS I FOR INSTRUCTIONS");
 outtextxy(260,270,"PRESS S TO START");
 outtextxy(263,290,"PRESS E TO EXIT");
 delay(3000);

 char ch;     //stores users choice
 ch=getch();  //inputs
 return ch;   //returns users choice.
}

void instrucdisp()                  //instructions display.
{
 object a;
 cleardevice();

 settextstyle(3,0,3);

 setcolor(12);
 outtextxy(240,70,"INSTRUCTIONS!");

 setcolor(CYAN);
 outtextxy(240,200,"S -> DIVERGE");
 a.showplayer(sxl,syl,sx2l,sy2l,sxr,syr,sx2r,sy2r);  //displays what the player would look like when said key is pressed.

 delay(3000); //timedelay
 cleardevice();

 setcolor(CYAN);
 outtextxy(240,200,"W -> CONVERGE");
 a.showplayer(xl,yl,x2l,y2l,xr,yr,x2r,y2r);

 delay(3000);
 cleardevice();

 setcolor(CYAN);
 outtextxy(240,200,"A -> JUMP LEFT");
 a.showplayer(lxl,lyl,lx2l,ly2l,lxr,lyr,lx2r,ly2r);

 delay(3000);
 cleardevice();

 setcolor(CYAN);
 outtextxy(240,200,"D -> JUMP RIGHT");
 a.showplayer(rxl,ryl,rx2l,ry2l,rxr,ryr,rx2r,ry2r);

 delay(3000);
 cleardevice();
}

void cnter()                       //pre game counter.
{
 cleardevice();
 settextstyle(3,0,3);
 setcolor(CYAN);
 outtextxy(240,200,"GAME BEGINS IN");
 setcolor(12);
 outtextxy(310,220,"3");

 delay(1000);
 cleardevice();

 setcolor(CYAN);
 outtextxy(240,200,"GAME BEGINS IN");
 setcolor(12);
 outtextxy(310,220,"2");

 delay(1000);
 cleardevice();

 setcolor(CYAN);
 outtextxy(240,200,"GAME BEGINS IN");
 setcolor(12);
 outtextxy(310,220,"1");

 delay(1000);
 cleardevice();
}

char endmenu(int s)                  //end menu display.
{
  int score=s;
  char ch,string[25];

  cleardevice();
  delay(20);

  settextstyle(3,0,3);

  setcolor(12);
  outtextxy(240,220,"GAME");
  setcolor(CYAN);
  outtextxy(305,220,"OVER");
  outtextxy(250,250,"SCORE:");
  setcolor(CYAN);
  itoa(score,string,10);
  outtextxy(330,250,string);
  setcolor(12);
  outtextxy(230,280,"RESTART");
  setcolor(CYAN);
  outtextxy(330,280,"-> Y");
  setcolor(12);
  outtextxy(250,310,"EXIT");
  setcolor(CYAN);
  outtextxy(300,310,"-> N");

  ch=getch();   //inputs users choice
  return ch;    //returns it.

}

void arena()              //game setting/background.
{
 setbkcolor(BLACK);
 setfillstyle(SOLID_FILL,CYAN);
 bar(200,0,210,getmaxy());
 bar(410,0,420,getmaxy());
}

void printscore(int s)   //function to print score.
{
 char string[25];
 int score=s;

 setfillstyle(SOLID_FILL,BLACK);
 bar(20,20,145,50);

 itoa(score,string,10);      //converts a integer to char string so as to use outtextxy.

 settextstyle(3,0,3);
 setcolor(12);
 outtextxy(20,20,"SCORE");
 setcolor(CYAN);
 outtextxy(100,20,string);

}

int updatespeed(int s)       //updates speed of obstacle based on score.
{
 int score=s;
 int speed=3;

 if(score>=30)
 {
  speed=4;
 }

 if(score>=60)
 {
  speed=6;
 }

 return speed;
}

int checkcol()           //checks for collisions
{
 if(dex.x3>=t1.z&&dex.y3==t1.v2)  //type 1
 {
  return 1;
 }

 if(dex.x<=t2.z2&&dex.y==t2.v2)   //type 2
 {
  return 1;
 }

 if(dex.x3<=t3.z2&&dex.y3==t3.v2)  //type 3
 {
  return 1;
 }
 if(dex.x>=t3.z&&dex.y==t3.v2)   //type 3
 {
  return 1;
 }
 if(dex.x3<=t4.z2&&dex.y3==t4.v2)   //type 4
 {
  return 1;
 }
 if(dex.x3>=t4.z3&&dex.y3==t4.v2)   //type 4
 {
  return 1;
 }
 return 0;
}

void main()
{

 {//following segment for checking graphics driver etc.

  //request auto detection
  int gdriver = DETECT, gmode,errorcode;
  initgraph(&gdriver,&gmode,"");
  errorcode=graphresult();
  if(errorcode!=grOk) //error occured
  {
	printf("GRAPHICS ERROR:%s\n",grapherrormsg(errorcode));
	printf("PRESS ANY KEY TO HALT:");
	getch();
	exit(1);
  }

 }
  //menu for the game.
  char op;

  menu:
  op=creditdisplay();

  switch(op)
  {
	case 'i':{
		  instrucdisp();
		  cnter();
		  break;
		 }

	case 'I':{
		  instrucdisp();
		  cnter();
		  break;
		 }

	case 's':{
		  cnter();
		  break;
		 }

	case 'S':{
		  cleardevice();
		  cnter();
		  break;
		 }

	case 'e':{
		  cleardevice();
		  settextstyle(0,0,1);
		  outtextxy(220,260,"THANK YOU FOR PLAYING!");
		  getch();
		  exit(1);
		 }

	case 'E':{
		  cleardevice();
		  settextstyle(0,0,1);
		  outtextxy(220,260,"THANK YOU FOR PLAYING!");
		  getch();
		  exit(1);
		 }

	default:{
		 goto menu;
		}
  }

 // start:

  int score=0;
  int q;
  int u;
  char c; //key
  int rs;

  rs=0;  //flag to check for restart

  start:

  int speed=3;

  if(rs==1)       //if flag implies restart then resets everything.
  {
	speed=3;
	score=0;
	t1.reset();
	t2.reset();
	t3.reset();
	t4.reset();
  }

  randomize();       //
  int p=random(4);   //  random generation of numbers from 0 to 3.

  arena();
  printscore(score);

  dex.converge();   //spawning the player.

  int i; //loop variable.

  for(i=0;;++i)   //game loop
  {
	delay(10);

	switch(p)     //checks value store in p
	{
	 case 0:{      //obstacle type 1 is spawned.
		 q=t1.movement(speed);

		 if(q==5)   //if obstacle is dodged
		 {
		  p=random(4); //stores random value of p for next obstacle generation.
		  score+=q;
		  printscore(score);
		 }
		 speed=updatespeed(score);  //updates speed depending on score.
		 break;
		}

	 case 1:{    //obstacle type 2 is spawned
		 q=t2.movement(speed);

		 if(q==5)
		 {
		  p=random(4);
		  score+=q;
		  printscore(score);
		 }
		 speed=updatespeed(score);
		 break;
		}

	 case 2:{   //obstacle type 3 is spawned.
		 q=t3.movement(speed);

		 if(q==5)
		 {
		  p=random(4);
		  score+=q;
		  printscore(score);
		 }
		 speed=updatespeed(score);
		 break;
		}

	 case 3:{   //obstacle type 4 is spawned.
		 q=t4.movement(speed);
		 if(q==5)
		 {
		  p=random(4);
		  score+=q;
		  printscore(score);
		 }
		 speed=updatespeed(score);
		 break;
		}
	}

	u=checkcol();      //checks for collisions and returns value for the flag.
	if(u==1)           //if the condition for collision is met, breaks out of game loop.
	{
	 break;
	}

	//restricts movement into obstacle type 1
	if(t1.v>dex.y3&&t1.v<dex.y4)
	{continue;}
	//restricts movement into obstacle type 2
	if(t2.v>dex.y&&t2.v<dex.y2)
	{continue;}
	//restricts movement into obstacle type 3
	if(t3.v>dex.y3&&t3.v<dex.y4)
	{continue;}
	//restricts movement into obstacle type 4
	if((t4.v3>dex.y3&&t4.v3<dex.y4)&&(t4.v>dex.y&&t4.v<dex.y2))
	{continue;}

	if(kbhit())    //checks for any input from user.
	{
	  c=getch();   //stores input

	  switch(c)    //checks which key was hit and teleports player to position
	  {
		case 'w':{
			  if(t1.v2>=dex.y3&&t1.v2<=dex.y4)
			  {break;}
			  if(t2.v2>=dex.y&&t2.v2<=dex.y2)     //restrict movement into obstacles
			  {break;}
			  if(t3.v2>=dex.y3&&t3.v2<=dex.y4)
			  {break;}
			  if(t4.v2>=dex.y3&&t4.v2<=dex.y4)
			  {break;}

			  dex.converge();
			  break;
			 }

		case 's':{
			  if(t1.v2>=dex.y3&&t1.v2<=dex.y4)
			  {break;}
			  if(t2.v2>=dex.y&&t2.v2<=dex.y2)
			  {break;}                         //restrict movement into obstacles
			  if(t3.v2>=dex.y3&&t3.v2<=dex.y4)
			  {break;}
			  if(t4.v2>=dex.y3&&t4.v2<=dex.y4)
			  {break;}

			  dex.diverge();
			  break;
			 }

		case 'a':{
			  if(t1.v2>=dex.y3&&t1.v2<=dex.y4)
			  {break;}
			  if(t2.v2>=dex.y&&t2.v2<=dex.y2)
			  {break;}                         //restrict movement into obstacles
			  if(t3.v2>=dex.y3&&t3.v2<=dex.y4)
			  {break;}
			  if(t4.v2>=dex.y3&&t4.v2<=dex.y4)
			  {break;}

			  dex.leftjump();
			  break;
			 }

		case 'd':{
			  if(t1.v2>=dex.y3&&t1.v2<=dex.y4)
			  {break;}
			  if(t2.v2>=dex.y&&t2.v2<=dex.y2)
			  {break;}                         //restrict movement into obstacles
			  if(t3.v2>=dex.y3&&t3.v2<=dex.y4)
			  {break;}
			  if(t4.v2>=dex.y3&&t4.v2<=dex.y4)
			  {break;}

			  dex.rightjump();
			  break;
			 }

		case 'b':{                   //if all goes to hell hit that b....
			  cout<<"BREAKING...";
			  break;
			 }
	  }

	  if(c=='b')   //to exit infinite loop; for developer.
	  {break;}
	}
  } // out of game loop.

  char ch;

  end:
  ch=endmenu(score);

  switch(ch)
  {
	case 'y':{
		  clrscr();
		  cleardevice();
		  rs=1;
		  goto start;
		 }

	case 'Y':{
		  clrscr();
		  cleardevice();
		  rs=1;
		  goto start;
		 }

	case 'n':{
		  cleardevice();
		  save_file(score); //calls func to save file
		  getch();
		  cleardevice();
		  displayfile();
		  getch();
		  cleardevice();
		  settextstyle(0,0,1);
		  outtextxy(220,260,"THANK YOU FOR PLAYING!");
		  break;
		 }

	case 'N':{

		  cleardevice();
		  save_file(score);
			  getch();
		  cleardevice();
		  displayfile();
		  getch();
		  cleardevice();
		  settextstyle(0,0,1);
		  outtextxy(220,260,"THANK YOU FOR PLAYING!");
		  break;
		 }

	default:{
		 goto end;
		}
  }

 getch();
 /* clean up */

 closegraph();
}
