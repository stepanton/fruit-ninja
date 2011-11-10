#include <GL/glut.h>
#include <cstdio>	//printf
#include <cmath>	//sin
#include <unistd.h> //usleep
#include "fruit.h"
#include "sword.h"
#define ESCAPE 27
//sword sw;
class back {
	public:
	sword *sw;
	subject **f;
	void create();
	void bg();
	void draw();
	void move();
	void collision();

};
back b;
void back:: create() {
	sw = new sword;
	f = new subject*[10];
	for (int i=0;i<10;i++)
	f[i]=new fruit(rand()%Xwin,-1*rand()%Ywin,2,rand()%3-1,1,0); 
}
void back:: bg() { //paint background
	  glBegin(GL_QUADS);	
	glColor3f(0.5,0.5,0.5);glVertex3f( 0, 0, 0.0f);glVertex3f( 0,Ywin, 0.0f);glVertex3f(Xwin,Ywin, 0.0f);	glVertex3f(Xwin,0,0);
	glEnd();
}
void back::draw(){
	bg();
	for (int i=0;i<10;i++)	
	f[i]->show();
	sw->show();
}
void back::move(){
	for (int i=0;i<10;i++){	
	f[i]->move();
	if ((f[i]->x < 0)||(f[i]->x > Xwin)||(f[i]->y > Ywin)) 
	f[i]=new fruit(rand()%Xwin,-1*rand()%Ywin,2,rand()%3-1,1,0); 
}
	
}
void back::collision(){
	for (int i=0;i<10;i++)
	if ((sw->x > f[i]->x)&&(sw->x < f[i]->x+20)&&(sw->y > f[i]->y)&&(sw->y-30 < f[i]->y+30)){ printf("collision with %d\n",i);
f[i]=new part;
}
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	b.draw();
	glutSwapBuffers();
	
}
void timer(int=0)
{
		b.move();
		b.collision();
     display();
     glutTimerFunc(10,timer,0);
}
void mouse(int button,int state,int ax,int ay){b.sw->x=ax;b.sw->y=Ywin-ay;}
void motion(int ax,int ay){b.sw->x=ax;b.sw->y=Ywin-ay;}
void keyboard(unsigned char key, int x, int y){
	usleep(100);
    if (key == ESCAPE)  exit(0);   
}



void glinit() {
	    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  
	    glutInitWindowSize(Xwin, Ywin); 
	    glutInitWindowPosition(300, 0);  
	    glutCreateWindow("fruit ninja");
	    glClearDepth(1.0);	
		glMatrixMode(GL_MODELVIEW);
		glShadeModel(GL_SMOOTH);
		glClearColor(0.0,0.0,0.0,1.0);
		glMatrixMode(GL_PROJECTION);
		glutSetCursor(GLUT_CURSOR_NONE);
 	    glLoadIdentity();
	    glOrtho(0,Xwin,0,Ywin,-1,1);
	    glutDisplayFunc(display);
	    b.create();  
	    
	    timer();
		glutMouseFunc(mouse);
		glutPassiveMotionFunc(motion);
		glutKeyboardFunc(keyboard);
		glutMainLoop();
		
}
