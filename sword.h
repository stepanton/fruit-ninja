
class sword {
    public:
	int x,y,score;
	sword (int ix=0, int iy=0, int iscore=0)
	{x=ix; y=iy; score=iscore;}
	void show();

};
void sword::show(){
	 glColor3f(0, 0, 0);
glBegin(GL_LINES);
 glVertex2f(x,y-20); glVertex2f(x, y+20);
 glEnd();
 glBegin(GL_QUADS);					
		glColor3f(1,0,1);			
		glVertex3f(x, y+10, 0.0f);		
		glVertex3f(x-10, y, 0.0f);
		glVertex3f(x,y-10, 0.0f);		
		glVertex3f(x+10,y,0);		
	glEnd();
	};

