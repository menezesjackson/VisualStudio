#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
GLdouble rt1=0,rt=0;
GLdouble m=0,m1=0,m2=0,m3=0,m4=0,sub,ap=0,sp=0,a2,rx=0,ll=0,q=0;
GLint i=0,j=0,z=0;
GLdouble PI=22/7 ; //3.14159;

void wheel1();
void wheel2();
void mudgaurd1();
void mudgaurd2();
void draw_pixel(GLint m,GLint n)
{   
	if(q>0 && q<3)                         //To draw mudgaurd    
	glColor3f(0.0,0.0,0.8);
	else if(q==3)                    //To draw lights on wheels
	glColor3f(1.0,1.0,0.0);
	else                            //To draw wheel
	glColor3f(0.0,0.0,0.0);
    
	glBegin(GL_POINTS);
	glVertex2i(m,n);
	glEnd();

	if(z!=0)                        //To draw spokes
	{
	if(i%250==0)
	{
		glColor3f(0.8,0.8,0.8);
		glBegin(GL_LINES);
		if(z==2)
		    glVertex2f(395.0,183.0);
		else
			glVertex2f(685.0,183.0);
		glVertex2f(m,n);
		glEnd();

	}
	i=i+10;
	
	}
}





void plot_pixel(GLint h,GLint k,GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	
	if(q==0)                        //To draw wheels
	{
	  draw_pixel(x+h,-y+k);
	  draw_pixel(-x+h,-y+k);
	  draw_pixel(-y+h,-x+k);
	  draw_pixel(y+h,-x+k);
	  draw_pixel(y+h,x+k);
	  draw_pixel(-y+h,x+k);
	  draw_pixel(-x+h,y+k);
	}
	if(q==1)                        //To draw mudgaurd1
	{
		draw_pixel(y+h,x+k);
	}
	
	if(q==2)                        //To draw mudgaurd2
	{
		draw_pixel(-y+h,x+k);
	    draw_pixel(-x+h,y+k);
	}
	
	if(q==3 && x < y)                        //To draw lights
	{
		draw_pixel(x+h,y+k);
		draw_pixel(-x+h,-y+k);
	}
	
}

void circle_draw(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		plot_pixel(h,k,x,y);
		if(d<0)
			d=d+2*x+3;
		else
		{
			d=d+2*(x-y)+5;
		    --y;
		}
        ++x;
		plot_pixel(h,k,x,y);
	}
	
}

void road()
{   

	glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);            //To draw road
	   glVertex2f(0,0);
	   glVertex2f(0,300);
	   glVertex2f(1366,300);
	   glVertex2f(1366,0);
	glEnd();

    if(m>=1466)                     //To draw block1
		m=-300;
	glPushMatrix();
    glTranslated(m,0,0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	   glVertex2f(-100,138);
	   glVertex2f(-100,162);
	   glVertex2f(200,162);
	   glVertex2f(200,138);
	glEnd();
	glTranslated(-m,0,0);
	
	
	if(m1>=866)                     //To draw block2
		m1=-900;
	glTranslated(m1,0,0);
	glBegin(GL_POLYGON);
	   glVertex2f(500,138);
	   glVertex2f(500,162);
	   glVertex2f(800,162);
	   glVertex2f(800,138);
	glEnd();
	glTranslated(-m1,0,0);

	if(m2>266)                      //To draw block3
		m2=-1500;
	glTranslated(m2,0,0);
	glBegin(GL_POLYGON);
	   glVertex2f(1100,138);
	   glVertex2f(1100,162);
	   glVertex2f(1400,162);
	   glVertex2f(1400,138);
	glEnd();
	glTranslated(-m2,0,0);
    
	if(m3>690)                      //To draw pole1
	    m3=-1300;
    glTranslated(m3,0,0);
	glColor3f(0.7,0.7,0.7);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	   glVertex2f(1000,320);
	   glVertex2f(1020,320);
	   glVertex2f(1020,680);
	   glVertex2f(1000,680);
	glEnd();

    glColor3f(0,0,0);
	glPushMatrix();
	glLineWidth(10);
	glTranslated(1020,640,0);
    glRotated(-20,0,0,1);
	glTranslated(-1020,-640,0);
	glBegin(GL_LINES);
	   glVertex2f(950,640);
	   glVertex2f(1070,640);
	glEnd();
	glPopMatrix();
	glLineWidth(1);
	glTranslated(-m3,0,0);

	
	if(m4>1490)                          //To draw pole 2
	    m4=-500;
	glPushMatrix();
    glTranslated(m4,0,0);
	glColor3f(0.7,0.7,0.7);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	   glVertex2f(0,320);
	   glVertex2f(20,320);
	   glVertex2f(20,680);
	   glVertex2f(0,680);
	glEnd();
	glColor3f(0,0,0);
	glPushMatrix();
	glLineWidth(10);
	glTranslated(20,640,0);
    glRotated(-20,0,0,1);
	glTranslated(-20,-640,0);
	glBegin(GL_LINES);
	   glVertex2f(-50,640);
	   glVertex2f(60,640);
	glEnd();
    glTranslated(-m4,0,0);
	glPopMatrix();

	glPopMatrix();


	if(sp!=4)                       
	{
		m=m+sp;
		m1=m1+sp;
		m2=m2+sp;
		m3=m3+sp;
		m4=m4+sp;
		a2=sp;
	}
	
	       

	if(m!=0 && m1!=0 && m2!=0)
	{
	if(sp==4)
	{
		if(a2>=0)
		{
			m=m+a2;
			m1=m1+a2;
			m2=m2+a2;
			m3=m3+a2;
			m4=m4+a2;
			a2=a2-0.03;
		}
	}

	
	}

    glPopMatrix();


}
    void drawcircle1(float xc,float yc,float radius,int angle1,int angle2)
{
	glBegin(GL_POLYGON);
	for(int a=angle1;a<=angle2;a=a+5)
	{
		float angle_radians=a*(22/7)/(float)180;
		float x=xc+radius*(float)cos(angle_radians);
		float y=yc+radius*(float)sin(angle_radians);
        glVertex2f(x,y);
	}
	glEnd();
}

void drawcircle2(float xc,float yc,float radius,int angle1,int angle2)
{
    int a1;
	glBegin(GL_LINE_STRIP);
	for(a1=angle1;a1<=angle2;a1=a1+5)
	{
		float angle_radians=a1*(22/7)/(float)180;
		float x=xc+radius*(float)cos(angle_radians);
		float y=yc+radius*(float)sin(angle_radians);
        glVertex2f(x,y);
	}
	glEnd();
}

	 
void display(void)
{
	float angle_radians;
	//printf("rt= %f, rt1=%f, %f, %f", (float)rt, (float)rt1, (float)cos(22.0/7), (float)cos(180.0));
    glClear(GL_COLOR_BUFFER_BIT);
	
	road();

	glLineWidth(2.0);               //To draw wire1
	glBegin(GL_LINES);
	glColor3f(0.5,0.5,0.5);
	   glVertex2f(0,660);
	   glVertex2f(1365,660);
	glEnd();
	glBegin(GL_LINES);              //To draw wire2
	   glVertex2f(0,630);
	   glVertex2f(1365,630);
    glEnd();
	glLineWidth(1.0);
	
	//rt1=45.0;
	glPointSize(3.5);               
	glPushMatrix();
	glTranslated(545.0,185.0,0.0);
    glRotated(rt1,0,0,1);
	glTranslated(-545.0,-185.0,0.0);
	circle_draw(545.0,185.0,30.0);  //To draw pedal wheel

	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);          //To draw pedal  
	   glVertex2f(542.0,145.0);
	   glVertex2f(542.0,225.0);
	   glVertex2f(530.0,225.0);
	   glVertex2f(530.0,230.0);
	   glVertex2f(558.0,230.0);
	   glVertex2f(558.0,225.0);
	   glVertex2f(548.0,225.0);
	   glVertex2f(548.0,145.0);
	   glVertex2f(558.0,145.0);
	   glVertex2f(558.0,140.0);
	   glVertex2f(530.0,140.0);
	   glVertex2f(530.0,145.0);
	glEnd();
	 
	glLineWidth(1.0);
    
	
	glPointSize(3.5);
	circle_draw(545.0,185.0,5.0);
	glPointSize(1.5);
    glPopMatrix();


    glPushMatrix();
	glTranslated(545.0,185.0,0.0);
    glRotated(rt,0,0,1);
	glTranslated(-545.0,-185.0,0.0);
	circle_draw(545.0,185.0,25.0);
    glPopMatrix();
	
	glPushMatrix();
	glTranslated(685.0,183.0,0.0);
    glRotated(rt,0,0,1);
	glTranslated(-685.0,-183.0,0.0);
	wheel1();
	glPopMatrix();

	glPushMatrix();
	glTranslated(395.0,183.0,0.0);
    glRotated(rt,0,0,1);
	glTranslated(-395.0,-183.0,0.0);
    wheel2();
    glPopMatrix();


	rt1=rt1+rx;
	if(sp!=4 )
	{
		rt=rt+sp;
		
        a2=sp;
	}
	

	if(m!=0 && m1!=0 && m2!=0)
	{
	   if(sp==4)
	   {   
		  if(a2>=0)
		  {
		   rt=rt+a2;
		   a2=a2-0.03;
		  }
	   }
	
	
	}

	
	glColor3f(1.0,0.0,0.0);         //To draw Cycle body
	glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
	   glVertex2f(455.0,300.0);
	   glVertex2f(640.0,300.0);
	   glVertex2f(690.0,180.0);
	   glVertex2f(540.0,180.0);
	   glVertex2f(449.0,288.0);
	glEnd();

	glBegin(GL_LINE_LOOP);          //To draw seat base
	   glVertex2f(640.0,300.0);
	   glVertex2f(652.0,315.0);
	   glVertex2f(644.0,315.0);
	   glVertex2f(630.0,300.0);
    glEnd();

	glBegin(GL_POLYGON);            //To draw seat
	glColor3f(0,0,0);
	   glVertex2f(652.0,315.0);
	   glVertex2f(619.0,315.0);
	   glVertex2f(619.0,320.0);
	   glVertex2f(668.0,330.0);
	   glVertex2f(668.0,315.0);
    glEnd();


	


	glColor3f(1.0,0.0,0.0);         //To draw cycle body
	glBegin(GL_LINE_LOOP);
	   glVertex2f(460.0,290.0);
	   glVertex2f(625.0,290.0);
	   glVertex2f(545.0,190.0);
	glEnd();

	glBegin(GL_LINE_LOOP);          //To draw cycle body
	   glVertex2f(635.0,290.0);
	   glVertex2f(680.0,185.0);
	   glVertex2f(550.0,185.0);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(1.5);
    
	glBegin(GL_LINES);              //To draw chain
	   glVertex2f(545.0,215.0);
	   glVertex2f(685.0,198.0);
	glEnd();

	glBegin(GL_LINES);              //To draw cycle body
	   glVertex2f(545.0,153.0);
	   glVertex2f(685.0,169.0);
	glEnd();
	glLineWidth(1.0);

	mudgaurd1();
	
	mudgaurd2();

    glColor3f(0.0,1.0,0.0);          //To draw wheel and handle connecting part
	glLineWidth(3.0);
	glPushMatrix();
	glTranslated(393.0,180.0,0.0);
	glRotated(65,0,0,1);
	glTranslated(-393.0,-180.0,0.0);
	glBegin(GL_LINE_LOOP);
	   glVertex2f(393.0,175.0);
	   glVertex2f(550.0,175.0);
	   glVertex2f(550.0,196.0);
	   glVertex2f(543.0,206.0);
	   glVertex2f(542.0,184.0);
	   glVertex2f(393.0,184.0);
	glEnd();
	glPopMatrix();
	
	

	glPushMatrix();                 //To draw  handlebar
	glTranslated(440.0,328.0,0.0);
    glRotated(30,0,0,1);
	glTranslated(-440.0,-328.0,0.0);
	{
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	   glVertex2f(440.0,330.0);
	   glVertex2f(467.0,330.0);
	   glVertex2f(473.0,337.0);
	   glVertex2f(510.0,337.0);
	   glVertex2f(510.0,348.0);
	   glVertex2f(470.0,348.0);
	   glVertex2f(464.0,338.0);
	   glVertex2f(413.0,338.0);
	   glVertex2f(407.0,348.0);
       glVertex2f(370.0,348.0);
	   glVertex2f(370.0,337.0);
	   glVertex2f(406.0,337.0);
	   glVertex2f(410.0,330.0);
	   glVertex2f(450.0,330.0);
	glEnd();
	}
	glPopMatrix();
	
	glBegin(GL_POLYGON);
	glColor3f(0.8,0.8,0);                     //man body
	   glVertex2f(618.0,323.0);
	    glVertex2f(565.0,450.0);
		glColor3f(0.5,0.5,0);
		 glVertex2f(600.0,450.0);
	   glVertex2f(668.0,328.0);
	 glEnd();
	 glBegin(GL_LINE_LOOP);
	glColor3f(0.9,0.7,0.4);                     //man hands
	   glVertex2f(585.0,450.0);
	    glVertex2f(595.0,430.0);
	    glVertex2f(500.0,320.0);
	   glVertex2f(380.0,314.0);
		 glVertex2f(390.0,334.0);
	    glVertex2f(490.0,330.0);
	 glEnd();
	 glBegin(GL_LINE_LOOP);
	glColor3f(0.9,0.7,0.4);                     //man hands
	   glVertex2f(585.0,450.0);
	    glVertex2f(595.0,430.0);
	    glVertex2f(540.0,325.0);
	   glVertex2f(460.0,364.0);
		 glVertex2f(470.0,384.0);
	    glVertex2f(540.0,340.0);
	 glEnd();

	 glColor3f(0.9,0.7,0.4);
   drawcircle1(575,470,20,0,360);
   glColor3f(1.0, 0.0, 0.0);
   drawcircle1(575,470,22,0,150);
	 glBegin(GL_LINE_LOOP);
	   glVertex2f(559.0,485.0);
	   glVertex2f(610.0,465.0);
	 glEnd();
   glColor3f(0.0, 0.0, 0.0);

   drawcircle1(582,490,2,0,360);
   drawcircle1(559,472,2,0,360);
   drawcircle2(556,479,20,290,330);


   angle_radians = (float)(((float)((long)rt1 % 360))*3.14)/180;
   //printf("\nangle_radians = %f %d ", (float)angle_radians*7, (int)rt1 % 360);
	glLineWidth(3.0);
   glBegin(GL_LINE_LOOP);                        //man legs
	glColor3f(0.0,0.0,0.0);                    
	   glVertex2f(635.0,323.0);
	    glVertex2f(655.0,305.0);
	   glVertex2f(552.0,278.0+20*sin(angle_radians-PI/2));
	   glVertex2f(560.0+50*cos(angle_radians-PI/2),180.0+50*sin(angle_radians-PI/2));
		 glVertex2f(550.0+50*cos(angle_radians-PI/2),180.0+50*sin(angle_radians-PI/2));
		 glVertex2f(539.0,287.0+20*sin(angle_radians-PI/2));
		 glVertex2f(542.0,299.0+20*sin(angle_radians-PI/2));
	 glEnd();
	glLineWidth(3.0);
   glBegin(GL_POLYGON);                        //man pant
	glColor3f(1.0,0,0);                    
	   glVertex2f(637.0,327.0);
	    glVertex2f(657.0,303.0);
	glColor3f(1.0,0.5,0.0);                    
	   glVertex2f(570.0,280.0+15*sin(angle_radians-PI/2));
		 glVertex2f(550.0,308.0+15*sin(angle_radians-PI/2));
	 glEnd();

	 glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);                     //man legs
	   glVertex2f(635.0,323.0);
	    glVertex2f(655.0,305.0);
	   glVertex2f(552.0,278.0+20*sin(angle_radians+PI/2));
	   glVertex2f(560.0+50*cos(angle_radians+PI/2),180.0+50*sin(angle_radians+PI/2));
		 glVertex2f(550.0+50*cos(angle_radians+PI/2),180.0+50*sin(angle_radians+PI/2));
		 glVertex2f(539.0,287.0+20*sin(angle_radians+PI/2));
		 glVertex2f(542.0,299.0+20*sin(angle_radians+PI/2));
	 glEnd();
   glBegin(GL_POLYGON);                        //man pant
	glColor3f(1.0,0,0);                    
	   glVertex2f(637.0,325.0);
	    glVertex2f(657.0,303.0);
	glColor3f(1.0,0.5,0.0);                    
	   glVertex2f(570.0,280.0+15*sin(angle_radians+PI/2));
		 glVertex2f(550.0,308.0+15*sin(angle_radians+PI/2));
	 glEnd();

		glColor3f(1, 1.0, 0.0);
		drawcircle1(558+50*cos(angle_radians+PI/2),182+50*sin(angle_radians+PI/2),10,0,360);
		drawcircle1(558-50*cos(angle_radians+PI/2),182-50*sin(angle_radians+PI/2),10,0,360);

		glColor3f(1, 0.0, 0.0);
		drawcircle1(545+50*cos(angle_radians+PI/2),165+50*sin(angle_radians+PI/2),20,0,180);
		drawcircle1(545-50*cos(angle_radians+PI/2),165-50*sin(angle_radians+PI/2),20,0,180);


	  // glVertex2f(510.0,348.0);
	  // glVertex2f(470.0,348.0);

	glutSwapBuffers();
	glFlush();
    
}


void wheel1()
{

	glColor3f(0.0,0.0,0.0);
	glPointSize(3.5);
	z=z+1;
	circle_draw(685.0,183.0,70.0);
	z=z-1;
	glPointSize(3.5);
	circle_draw(685.0,183.0,72.5);
	glPointSize(3.5);
	circle_draw(685.0,183.0,75.0);
	glPointSize(3.5);
	circle_draw(685.0,183.0,15.0);
	glColor3f(0.0,0.0,1.0);
	glPointSize(3.5);
    circle_draw(685.0,183.0,5.0);

	q=3;
	glPointSize(3.5);
    circle_draw(685.0,183.0,50.0);
	q=0;

}


void wheel2()
{
    
    glColor3f(1.0,1.0,1.0);
	glPointSize(3.5);
	z=z+2;
	circle_draw(395.0,183.0,70.0);
	z=z-2;
	glPointSize(3.5);
	circle_draw(395.0,183.0,72.5);
	glPointSize(3.5);
	circle_draw(395.0,183.0,75.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(3.5);
	circle_draw(395.0,183.0,5.0);

	q=3;
	glPointSize(3.5);
    circle_draw(395.0,183.0,50.0);
	q=0;

    
}

void mudgaurd1()
{   q=1;
    glPointSize(3.5);
	circle_draw(395.0,183.0,90.0);
	glPointSize(2.0);
	circle_draw(395.0,183.0,94.0);
	glPointSize(2.0);
	circle_draw(395.0,183.0,86.0);
	q=0;

}

void mudgaurd2()
{   
	q=2;
    glPointSize(3.5);
	circle_draw(685.0,183.0,90.0);
	glPointSize(2.0);
	circle_draw(685.0,183.0,94.0);
	glPointSize(2.0);
	circle_draw(685.0,183.0,86.0);
    q=0;
}




void myinit()
{
	glClearColor(0.6,0.6,0.8,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,1024.0,0.0,700.0);
}

void speed(int id)
{

	switch(id)
	{
	case 3: sp=2;
		    rx=1;
		    break;
	case 4: sp=5;
		    rx=3;
		     break;
	case 5: sp=8;
		     rx=5;
		     break;

	}
	glutPostRedisplay();
}

void menu(int id)
{

	switch(id)
	{
	
	case 1: sp=4;
		    rx=0;
		    rt1=0;
		    break;
	case 2: sp=0;
		    rx=0;
		    rt1=0;
			break;

	case 3: exit(0);
		    break;
	}
	glutPostRedisplay();
}


void mykey(unsigned char key,int x,int y)
{
	if(key=='s' || key=='S')
	{
		 sp=2;
	     rx=1;
	}
	
	if(key=='d' || key=='D')
	{
		sp=5;
	    rx=3;
	}	
	if(key=='f' || key=='F')
	{
		sp=8;
	    rx=5;
	}
	
	if(key=='q' || key=='Q')
		exit(0);
	
	if(key=='t' || key=='T')
	{
		sp=4;
	    rx=0;
		rt1=0;

	}
		
	if(key=='z' || key=='Z')
	{
		sp=4;
	    rx=0;
		a2=0;
	}
	

}

	



void main(void)
{ 

	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1024,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("my project");
	sub = glutCreateMenu(speed);
	glutAddMenuEntry("SLOW(S)",3);
	glutAddMenuEntry("MEDIUM(D)",4);
	glutAddMenuEntry("FAST(F)",5);

    glutCreateMenu(menu);
	glutAddSubMenu("RUN",sub);
	glutAddMenuEntry("BREAK(T)",1);
	glutAddMenuEntry("STOP(Z)",2);
    glutAddMenuEntry("EXIT(Q)",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutKeyboardFunc(mykey);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	myinit();
	glutMainLoop();
	
}
