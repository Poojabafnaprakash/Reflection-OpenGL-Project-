/* Copyright (c) 2013 Pooja Prakashchand. All rights reserved. */


#include<GLUT/glut.h>
#include<stdio.h>
#include<stdlib.h>
#define   drawOneLine(x1,y1,x2,y2) glBegin(GL_LINES); \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

void *currentfont;				//output char
GLint i,j,c=0;;

void setFont(void *font)
{
	currentfont=font;
}



void drawstring(float x,float y,float z,char *string)                 //string display
{
	    char *c;
	glRasterPos3f(x,y,z);
 
	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void draw(GLfloat x1,GLfloat x2) // TO DRAW POLYGON FOR DISPLAY MENUS 
{

	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);  // plane mirror
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(x2,425);
	glVertex2i(x1,425);
	glVertex2i(x1,395);
    glVertex2i(x2,395);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // concave mirror
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(x2,370);
	glVertex2i(x1,370);
	glVertex2i(x1,340);
    glVertex2i(x2,340);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // convex mirror
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(x2,315);
	glVertex2i(x1,315);
	glVertex2i(x1,285);
    glVertex2i(x2,285);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // exit
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(x2,150);
	glVertex2i(x1,150);
	glVertex2i(x1,120);
    glVertex2i(x2,120);
	glEnd();
	glFlush();

}

void text(GLfloat x)											// to draw the text in menu screen
{

	

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(x,405.0,1.0,"PLANE MIRROR");				

	glColor3f(1.0,1.0,1.0);
	drawstring(x,350.0,1.0," CONCAVE MIRROR");

	glColor3f(1.0,1.0,1.0);
	drawstring(x,295.0,1.0,"CONVEX MIRROR");


	glColor3f(1.0,1.0,1.0);
	drawstring(x,130.0,1.0,"   MAIN MENU");
	glFlush();
}


void myInit()
{
    glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glShadeModel (GL_FLAT);
}

void delay()
{
  j=28000;
	while(j!=0)
	{
		j--;
		i=28000;
		while(i!=0)
		{
			i--;
			
		}
	}
}
void shading(GLfloat x,GLfloat y)                         //drawing shades of mirror
{
	glBegin(GL_LINES);
	glVertex2f(x,y);
	glVertex2f(x+7.0,y+2.0);
	glEnd();
	glFlush();
}

void drawpixel(GLfloat x,GLfloat y)           
{
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	c++;
	if(c%5==0)
		shading(x,y);
}
void plotpixel(GLfloat h,GLfloat k,GLfloat x,GLfloat y)	 // for concave mirror
{
	drawpixel(y+h,x+k);
	drawpixel(y+h,-x+k);
}
void circle(GLfloat h,GLfloat k,GLfloat r)					//for concave mirror
{
	GLfloat d=1-r,x=0,y=r;
	while(y>x)
	{
		plotpixel(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixel(h,k,x,y);
	glFlush();
}

void plotpixel1(GLfloat h,GLfloat k,GLfloat x,GLfloat y)		//for convex mirror
{
	drawpixel(-y+h,x+k);
	drawpixel(-y+h,-x+k);
}
void circle1(GLfloat h,GLfloat k,GLfloat r)						//for convex mirror
{
	GLfloat d=1-r,x=0,y=r;
	while(y>x)
	{
		plotpixel1(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixel1(h,k,x,y);
	glFlush();
}

void dec()														//initial declaration
{

	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(350,480);
	glVertex2f(370,480);
	glVertex2f(365,485);
	glVertex2f(370,480);
	glVertex2f(365,475);
	glVertex2f(370,480);
	glEnd();

	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(350,470);
	glVertex2f(370,470);
	glVertex2f(365,475);
	glVertex2f(370,470);
	glVertex2f(365,465);
	glVertex2f(370,470);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(360,460);
	glVertex2f(360,440);
	glVertex2f(360,460);
	glVertex2f(355,455);
	glVertex2f(365,455);
	glVertex2f(360,460);
	glEnd();

	glColor3f(1.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(360,430);
	glVertex2f(360,410);
	glVertex2f(360,430);
	glVertex2f(355,425);
	glVertex2f(365,425);
	glVertex2f(360,430);
	glEnd();

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(100,300);
	glVertex2f(400,300);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2f(250.0,300.0);
	glEnd();

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(240.0,290.0,1.0,"P");
	glColor3f(1.0,1.0,1.0);
	drawstring(380.0,477.0,1.0,"Incident ray");				

	glColor3f(1.0,1.0,1.0);
	drawstring(378.0,467.0,1.0," Reflected ray");

	glColor3f(1.0,1.0,1.0);
	drawstring(380.0,450.0,1.0,"Object");


	glColor3f(1.0,1.0,1.0);
	drawstring(375.0,420.0,1.0,"  Image");
	
	glFlush();
}
void planemirror1()												//plane mirror concept
{
	dec();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,1.0,1.0);
	drawstring(200.0,455.0,1.0,"P L A N E  M I R R O R");
	glFlush();
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(195.0,450.0);
	glVertex2f(300.0,450.0);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINES);
	glVertex2f(250,400);
	glVertex2f(250,200);
	glEnd();
	GLfloat l;
	for(l=205.0;l<400.0;l+=5.0)
		shading(250.0,l);

	glColor3f(1.0,1.0,0.0);									//incident ray
    glBegin(GL_LINES);
	glVertex2f(100,350);
	glVertex2f(250,350);
    glVertex2f(100,250);
	glVertex2f(250,250);

	glVertex2f(245,355);
	glVertex2f(250,350);
    glVertex2f(245,345);
	glVertex2f(250,350);

	glVertex2f(245,255);
	glVertex2f(250,250);
    glVertex2f(245,245);
	glVertex2f(250,250);
	glEnd();
	glFlush();
	delay();

	glColor3f(0.0,0.0,0.0);									//clear traces
	glBegin(GL_LINES);
	glVertex2f(245,355);
	glVertex2f(250,350);
    glVertex2f(245,345);
	glVertex2f(250,350);

	glVertex2f(245,255);
	glVertex2f(250,250);
    glVertex2f(245,245);
	glVertex2f(250,250);
	glEnd();

	glColor3f(0.0,1.0,0.0);									//reflected ray
    glBegin(GL_LINES);
	glVertex2f(100,350);
	glVertex2f(250,350);
    glVertex2f(100,250);
	glVertex2f(250,250);

	glVertex2f(230,350);
	glVertex2f(235,355);
	glVertex2f(230,350);
	glVertex2f(235,345);

	glVertex2f(230,250);
	glVertex2f(235,255);
	glVertex2f(230,250);
	glVertex2f(235,245);
	glEnd();
	glFlush();
	delay();
	
	
	glColor3f(1.0,1.0,0.0);								//image
    glBegin(GL_LINES);
	glVertex2f(200,325);
	glVertex2f(250,300);
    glVertex2f(250,300);
	glVertex2f(245,305);
	glVertex2f(250,300);
	glVertex2f(244,301);
	glEnd();
	glFlush();
	delay();

	glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
	glVertex2f(200,275);
	glVertex2f(250,300);
	glVertex2f(200,275);
	glVertex2f(203,280);
	glVertex2f(200,275);
	glVertex2f(205,275);
	glEnd();
	glFlush();
}
void planemirror()											//plane mirror ray diagram
{
	dec();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,1.0,1.0);
	drawstring(200.0,455.0,1.0,"P L A N E  M I R R O R");
	glFlush();
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(195.0,450.0);
	glVertex2f(300.0,450.0);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINES);
	glVertex2f(250,400);
	glVertex2f(250,200);
	glEnd();
	GLfloat l;
	for(l=205.0;l<400.0;l+=5.0)
		shading(250.0,l);


	glColor3f(1.0,0.0,0.0);								//object
    glBegin(GL_LINES);
	glVertex2f(200,300);
	glVertex2f(200,325);
    glVertex2f(200,325);
	glVertex2f(195,320);
	glVertex2f(200,325);
	glVertex2f(205,320);
	glEnd();
	glFlush();
	delay();

	glColor3f(1.0,1.0,0.0);								//incident ray
    glBegin(GL_LINES);
	glVertex2f(200,325);
	glVertex2f(250,300);
    glVertex2f(250,300);
	glVertex2f(245,305);
	glVertex2f(250,300);
	glVertex2f(244,301);
	glVertex2f(200,325);
	glVertex2f(250,325);

	glVertex2f(250,325);
	glVertex2f(244,327);
	glVertex2f(250,325);
	glVertex2f(244,323);
	glEnd();
	glFlush();
	delay();

	glColor3f(0.0,0.0,0.0);								//clear traces
	glBegin(GL_LINES);
    glVertex2f(250,325);
	glVertex2f(244,327);
	glVertex2f(250,325);
	glVertex2f(244,323);
	glEnd();
	
	
    glColor3f(0.0,1.0,0.0);								//reflected ray
    glBegin(GL_LINES);
	glVertex2f(200,325);
	glVertex2f(250,325);
	glVertex2f(225,325);
	glVertex2f(229,329);
    glVertex2f(225,325);
	glVertex2f(229,321);

	glVertex2f(200,275);
	glVertex2f(250,300);

	glVertex2f(200,275);
	glVertex2f(203,280);
	glVertex2f(200,275);
	glVertex2f(205,275);
	
	glEnd();

	glColor3f(0.0,1.0,0.0); 
	 glPushAttrib(GL_ENABLE_BIT);					//dashed line
	 glLineStipple(4,0xAAAA);
	 glEnable(GL_LINE_STIPPLE);
	 drawOneLine(250,300,300,325);
     drawOneLine(250,325,300,325);
	 glPopAttrib();

    glColor3f(1.0,0.0,1.0);							//image
	glBegin(GL_LINES);
    glVertex2f(300,325);
	glVertex2f(300,300);
	glVertex2f(295,320);
	glVertex2f(300,325);
    glVertex2f(305,320);
	glVertex2f(300,325);

	glEnd();
	

	glFlush();
}

void concavemirror1()								//concave mirror concept
{
	dec();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,1.0,1.0);
	drawstring(190.0,455.0,1.0,"C O N C A V E  M I R R O R");
	glFlush();
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(185.0,450.0);
	glVertex2f(310.0,450.0);
	glEnd();
	circle(120,300,130);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2f(120.0,300.0);
	glVertex2f(185.0,300.0);
	glEnd();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(120.0,290.0,1.0,"R");				
	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,290.0,1.0,"F");				
	glFlush();

	glColor3f(1.0,1.0,0.0);							//incident ray
    glBegin(GL_LINES);
	glVertex2f(110,350);
	glVertex2f(250,300);
    glVertex2f(250,300);
	glVertex2f(245,305);
	glVertex2f(250,300);
	glVertex2f(244,301);
	glEnd();
	glFlush();
	delay();

	glColor3f(0.0,1.0,0.0);							//reflected ray
    glBegin(GL_LINES);
	glVertex2f(110,250);
	glVertex2f(250,300);
	glVertex2f(110,250);
	glVertex2f(113,255);
	glVertex2f(110,250);
	glVertex2f(115,250);
	glEnd();
	glFlush();
	delay();

	glColor3f(1.0,1.0,0.0);							//incident ray
    glBegin(GL_LINES);
	glVertex2f(160,350);
	glVertex2f(240,350);
	glVertex2f(240,350);
	glVertex2f(234,353);
	glVertex2f(240,350);
	glVertex2f(234,347);

	glVertex2f(160,250);
	glVertex2f(240,250);
	glVertex2f(240,250);
	glVertex2f(234,253);
	glVertex2f(240,250);
	glVertex2f(234,247);
	glEnd();
	glFlush();
	delay();	
	
    glColor3f(0.0,1.0,0.0);							//reflected ray
    glBegin(GL_LINES);
	glVertex2f(185,300);
	glVertex2f(240,350);
	glVertex2f(185,300);
	glVertex2f(195,303);
    glVertex2f(185,300);
	glVertex2f(187,305);

	glVertex2f(185,300);
	glVertex2f(240,250);
	glVertex2f(185,300);
	glVertex2f(195,297);
    glVertex2f(185,300);
	glVertex2f(187,295);	
	glEnd();
	glFlush();
}
void concavemirror()									//concave mirror ray diagram
{
	dec();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,1.0,1.0);
	drawstring(190.0,455.0,1.0,"C O N C A V E  M I R R O R");
	glFlush();
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(185.0,450.0);
	glVertex2f(310.0,450.0);
	glEnd();
	circle(120,300,130);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2f(120.0,300.0);
	glVertex2f(185.0,300.0);
	glEnd();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(120.0,290.0,1.0,"R");				
	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,290.0,1.0,"F");				
	
	glColor3f(1.0,0.0,0.0);								//object
    glBegin(GL_LINES);
	glVertex2f(110,300);
	glVertex2f(110,350);
    glVertex2f(110,350);
	glVertex2f(105,345);
	glVertex2f(110,350);
	glVertex2f(115,345);
	glEnd();
	glFlush();
	delay();

	glColor3f(1.0,1.0,0.0);									//incident ray
    glBegin(GL_LINES);
	glVertex2f(110,350);
	glVertex2f(250,300);
    glVertex2f(250,300);
	glVertex2f(245,305);
	glVertex2f(250,300);
	glVertex2f(244,301);

	glVertex2f(110,350);
	glVertex2f(240,350);
	glVertex2f(240,350);
	glVertex2f(234,353);
	glVertex2f(240,350);
	glVertex2f(234,347);
	glEnd();
	glFlush();
	delay();	
	
    glColor3f(0.0,1.0,0.0);									//reflected ray
    glBegin(GL_LINES);
	glVertex2f(130,250);
	glVertex2f(240,350);
	glVertex2f(185,300);
	glVertex2f(195,303);
    glVertex2f(185,300);
	glVertex2f(187,305);

	glVertex2f(110,250);
	glVertex2f(250,300);

	glVertex2f(110,250);
	glVertex2f(113,255);
	glVertex2f(110,250);
	glVertex2f(115,250);
	glEnd();
	glFlush();
	delay();

	glColor3f(1.0,0.0,1.0);									//image
    glBegin(GL_LINES);
	glVertex2f(142.941,300);
	glVertex2f(142.941,261.1765);
    glVertex2f(142.941,261.1765);
	glVertex2f(141,267);
	glVertex2f(142.941,261.1765);
	glVertex2f(144.882,267);
	glEnd();
	glFlush();
}

void convexmirror1()											//convex mirror concept
{
	dec();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,1.0,1.0);
	drawstring(190.0,455.0,1.0,"C O N V E X  M I R R O R");
	glFlush();
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(185.0,450.0);
	glVertex2f(310.0,450.0);
	glEnd();
	circle1(380,300,130);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2f(315.0,300.0);
	glVertex2f(380.0,300.0);
	glEnd();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(380.0,290.0,1.0,"R");				
	glColor3f(1.0,1.0,1.0);
	drawstring(315.0,290.0,1.0,"F");				
	glFlush();

	glColor3f(1.0,1.0,0.0);											//incident ray
    glBegin(GL_LINES);
	glVertex2f(110,350);
	glVertex2f(250,300);
    glVertex2f(250,300);
	glVertex2f(245,305);
	glVertex2f(250,300);
	glVertex2f(244,301);
	glEnd();
	glFlush();
	delay();

	glColor3f(0.0,1.0,0.0);										//reflected ray
    glBegin(GL_LINES);
	glVertex2f(110,250);
	glVertex2f(250,300);
	glVertex2f(110,250);
	glVertex2f(113,255);
	glVertex2f(110,250);
	glVertex2f(115,250);
	glEnd();
	glFlush();
	delay();

	glColor3f(1.0,1.0,0.0);										//incident ray
    glBegin(GL_LINES);
	glVertex2f(160,350);
	glVertex2f(260,350);
	glVertex2f(260,350);
	glVertex2f(254,353);
	glVertex2f(260,350);
	glVertex2f(254,347);

	glVertex2f(160,250);
	glVertex2f(260,250);
	glVertex2f(260,250);
	glVertex2f(254,253);
	glVertex2f(260,250);
	glVertex2f(254,247);
	glEnd();
	glFlush();
	delay();	
	
    
    glColor3f(0.0,1.0,0.0);										//reflected ray
    glBegin(GL_LINES);
	glVertex2f(150,450);
	glVertex2f(260,350);
	glVertex2f(150,450);
	glVertex2f(156,447);
    glVertex2f(150,450);
	glVertex2f(153,445);

	glVertex2f(150,150);
	glVertex2f(260,250);
	glVertex2f(150,150);
	glVertex2f(156,153);
    glVertex2f(150,150);
	glVertex2f(153,155);
	glEnd();
	
	glPushAttrib(GL_ENABLE_BIT);								//dashed line
	 glLineStipple(4,0xAAAA);
	 glEnable(GL_LINE_STIPPLE);
	 drawOneLine(260,250,315,300);
     drawOneLine(260,350,315,300);
	 glPopAttrib();
	glFlush();
	delay();
	glFlush();
}

void convexmirror()													//convex mirror ray diagram
{
	
	dec();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,1.0,1.0);
	drawstring(190.0,455.0,1.0,"C O N V E X  M I R R O R");
	glFlush();
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(185.0,450.0);
	glVertex2f(310.0,450.0);
	glEnd();
	circle1(380,300,130);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2f(315.0,300.0);
	glVertex2f(380.0,300.0);
	glEnd();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(380.0,290.0,1.0,"R");				
	glColor3f(1.0,1.0,1.0);
	drawstring(315.0,290.0,1.0,"F");				
	
	glColor3f(1.0,0.0,0.0);											//object
    glBegin(GL_LINES);
	glVertex2f(110,300);
	glVertex2f(110,350);
    glVertex2f(110,350);
	glVertex2f(105,345);
	glVertex2f(110,350);
	glVertex2f(115,345);
	glEnd();
	glFlush();
	delay();

	glColor3f(1.0,1.0,0.0);												//incident ray
    glBegin(GL_LINES);
	glVertex2f(110,350);
	glVertex2f(250,300);
    glVertex2f(250,300);
	glVertex2f(245,305);
	glVertex2f(250,300);
	glVertex2f(244,301);

	glVertex2f(110,350);
	glVertex2f(260,350);
	glVertex2f(260,350);
	glVertex2f(254,353);
	glVertex2f(260,350);
	glVertex2f(254,347);
	glEnd();
	glFlush();
	delay();

    glColor3f(0.0,1.0,0.0);											//reflected ray
    glBegin(GL_LINES);
	glVertex2f(150,450);
	glVertex2f(260,350);
	glVertex2f(150,450);
	glVertex2f(156,447);
    glVertex2f(150,450);
	glVertex2f(153,445);

	glVertex2f(110,250);
	glVertex2f(250,300);
	glVertex2f(110,250);
	glVertex2f(113,255);
	glVertex2f(110,250);
	glVertex2f(115,250);
	glEnd();
	
	glPushAttrib(GL_ENABLE_BIT);										//dashed line
	 glLineStipple(4,0xAAAA);
	 glEnable(GL_LINE_STIPPLE);
	 drawOneLine(250,300,390,350);
     drawOneLine(260,350,315,300);
	 glPopAttrib();
	glFlush();
	delay();

	glColor3f(1.0,0.0,1.0);												//image
    glBegin(GL_LINES);
	glVertex2f(296.667,300);
	glVertex2f(296.667,316.667);
	glVertex2f(294,313);
	glVertex2f(296.667,316.667);
	glVertex2f(300.33,313);
	glVertex2f(295.667,316.667);
	glEnd();

	glFlush();
}

void mainmenu()												//initial menu
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);  
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(190,315);
	glVertex2i(65,315);
	glVertex2i(65,285);
    glVertex2i(190,285);
	glEnd();

	glBegin(GL_POLYGON);  
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(420,315);
	glVertex2i(295,315);
	glVertex2i(295,285);
    glVertex2i(420,285);
	glEnd();

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(120.0,455.0,1.0,"*  *  *  *  *  *  *  *  *  R E F L E C T I O N  *  *  *  *  *  *  *  *  *");
		
	glColor3f(1.0,1.0,1.0);
	drawstring(95.0,295.0,1.0,"  CONCEPT");

	glColor3f(1.0,1.0,1.0);
	drawstring(95.0,265.0,1.0,"  PRESS C/c");


	glColor3f(1.0,1.0,1.0);
	drawstring(325.0,295.0,1.0,"  RAY DIAGRAM");

	glColor3f(1.0f,1.0f,1.0f);
	drawstring(325.0,265.0,1.0,"PRESS R/r");
	glColor3f(1.0f,1.0f,1.0f);
	drawstring(200.0,110.0,1.0," PRESS N TO EXIT");
	glFlush();
}

void key(char *s)				// text for keyboard interaction

{

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,135);
	glVertex2f(500,135);
	glVertex2f(500,0);
	glEnd();
	glFlush();


	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(360.0,130.0,1.0,"DO U WISH TO CONTINUE?");
	glColor3f(1.0f,1.0f,1.0f);
	drawstring(360.0,110.0,1.0,s);
	glFlush();
}
void concept()												//menu of concept
{
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,0.0,1.0);
	drawstring(90.0,400.0,1.0,"P A R A L L E L  M I R R O R");

	glColor3f(1.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(85.0,395.0);
	glVertex2f(210.0,395.0);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	drawstring(50.0,375.0,1.0,"1)       Rays  normal  to  the mirror  gets");

	glColor3f(1.0,1.0,1.0);
	drawstring(100.0,365.0,1.0,"  reflected  normally");

	glColor3f(1.0,1.0,1.0);
	drawstring(50.0,345.0,1.0,"2)       Rays  incident  at  an  angle follows");

	glColor3f(1.0,1.0,1.0);
	drawstring(100.0,335.0,1.0,"LAW  OF  REFLECTION , i.e.,");
	glColor3f(1.0,1.0,1.0);
	drawstring(65.0,320.0,1.0,"angle  of  INCIDENCE  =  angle  of  REFLECTION");

	glColor3f(1.0,0.0,1.0);
	drawstring(90.0,250.0,1.0,"S P H E R I C A L  M I R R O R");

	glColor3f(1.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(85.0,245.0);
	glVertex2f(210.0,245.0);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	drawstring(50.0,225.0,1.0,"1)       Rays  coming from infinity , parallel");

	glColor3f(1.0,1.0,1.0);
	drawstring(70.0,215.0,1.0,"to  the  principal  axis  after  reflection");

	glColor3f(1.0,1.0,1.0);
	drawstring(70.0,205.0,1.0,"passes  or  appears  to  pass  through  FOCUS");

	glColor3f(1.0,1.0,1.0);
	drawstring(50.0,185.0,1.0,"2)       Rays  incident  at  P(pole)  follows");

	glColor3f(1.0,1.0,1.0);
	drawstring(100.0,175.0,1.0,"LAW  OF  REFLECTION , i.e.,");
	glColor3f(1.0,1.0,1.0);
	drawstring(65.0,160.0,1.0,"angle  of  INCIDENCE  =  angle  of  REFLECTION");
	glFlush();
}	

void mykeyboard(unsigned char key,int x,int y)						//for keyboard interaction
{
	if(key=='1' || key=='r' || key=='R')
	{
		draw(180.0,305.0);
		text(200.0);
		glColor3f(1.0,1.0,1.0);
		drawstring(120.0,455.0,1.0,"*  *  *  *  *  *  *  *  *  R A Y   D I A G R A M  *  *  *  *  *  *  *  *  *");
		glFlush();
	}
	else if(key=='y' || key=='Y' || key=='c' || key=='C')
	{
		draw(295.0,420.0);
		text(315.0);
		glColor3f(1.0,1.0,0.0);
		drawstring(135.0,455.0,1.0,"*  *  *  *  *  *  *  *  *  C O N C E P T *  *  *  *  *  *  *  *  *");
		concept();
		glFlush();
	}
	else if(key=='N' || key=='n' || key=='0')
	{
		exit(0);
	}


}

void myMouse(int btn, int state, int x, int y)							//for mouse interaction
{

	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		x=x/2;
		y=(1000-y)/2;
			if ((x>=180 && x<=305) && (y>=420 && y<=445 ))
			
			{
				planemirror();
				key("PRESS 1/0");
			
			}
			
			if((x>=180 && x<=305) && (y>=380 && y<=410))
			{	
				concavemirror();
				key("PRESS 1/0");
			}
			if((x>=180 && x<=305) && (y>=340 && y<=370 )) 
			{
				
				convexmirror();
				key("PRESS 1/0");
			}
			
			if(((x>=180 && x<=305) || (x>=295 && x<=420)) && (y>=220 && y<=250)) 
			{
					mainmenu();
			}

			if ((x>=295 && x<=420) && (y>=420 && y<=445 ))
			
			{
				planemirror1();
				key("PRESS Y/N");
			
			}
			
			if((x>=295 && x<=420)&& (y>=380 && y<=410))
			{	
				concavemirror1();
				key("PRESS Y/N");
			}
			if((x>=295 && x<=420) && (y>=340 && y<=370 )) 
			{
				
				convexmirror1();
				key("PRESS Y/N");
			}
	}

}


void display(void)											//display function
{  

	glClear(GL_COLOR_BUFFER_BIT);
	mainmenu();	
}


int main(int argc,char **argv)								//main function
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Reflection");
    glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(mykeyboard);
	myInit();
	glutMainLoop();
    return 0;
}