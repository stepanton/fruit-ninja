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
	subject **p;
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
	p = new subject*[21];

	for (int i=0;i<10;i++)
	f[i]=new fruit(rand()%Xwin,-1*rand()%Ywin,2,rand()%3-1,1,rand()%10*10); 
	for (int i=0;i<20;i++)
	p[i]=new part; 
}
void back:: bg() { //paint background
	  glBegin(GL_QUADS);	
	glColor3f(0.5,0.5,0.5);glVertex3f( 0, 0, 0.0f);glVertex3f( 0,Ywin, 0.0f);glVertex3f(Xwin,Ywin, 0.0f);	glVertex3f(Xwin,0,0);
	glEnd();
}
void back::collision(){
	for (int i=0;i<10;i++)
	if ((sw->x > f[i]->rx()-5)&&(sw->x < f[i]->rx()+20)&&(sw->y > f[i]->ry())&&(sw->y-35 < f[i]->ry()+35)){ 
printf("score %d\n",sw->score);		
{
p[i]=new part(f[i]->rx(),f[i]->ry(),4,-2);
p[i+10]=new part(f[i]->rx(),f[i]->ry(),4,2);
f[i]=new fruit(rand()%Xwin,-1*rand()%Ywin,2,rand()%3-1,1,rand()%10*10);
sw->score+=f[i]->rscore();
}
}

}
void back::draw(){
	bg();
	for (int i=0;i<10;i++){	
	f[i]->show();p[i]->show();p[i+10]->show();}
	sw->show();
	
}
void back::move(){
	for (int i=0;i<10;i++){	
	f[i]->move();p[i]->move();p[i+10]->move();
	if ((f[i]->rx() < 0)||(f[i]->rx() > Xwin)||(f[i]->ry() > Ywin)) 
	f[i]=new fruit(rand()%Xwin,-1*rand()%Ywin,2,rand()%3-1,1,0); 

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
