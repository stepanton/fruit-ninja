class subject {
	public:
		int x,y,angle;
		double m,v;
		float vv;
	
      subject (int ix=0, int iy=0,double im=0, double iv=0,int iangle=0)
           { x=ix;y=iy;m=im;v=iv;angle=iangle; }
           virtual void show(){};
           void move();
};

void subject:: move () {
x+=v;
y+=m;

}

class fruit: public subject {
	protected :
		int score;
	public:
      fruit (int ix=0, int iy=0,int im=0, double iv=0,double iangle=0, int iscore=0)
           {x=ix;y=iy;m=im;v=iv;angle=iangle; score=iscore;  }
           void show();
};

void fruit:: show () {     
         glBegin(GL_TRIANGLES);					
		glColor3f(1,1,0);			
		glVertex3f( x, y+35, 0.0f);		
		glVertex3f( x+20,y, 0.0f);
		glVertex3f(x,y-35, 0.0f);		
		//glVertex3f(x-5,y,0);		
	glEnd();
}

class part: public subject {
	protected :
		int type;
	public:
      part (int ix=0, int iy=0,double im=0, double iv=0,int iangle=0, int itype=0)
           {x=ix;y=iy;m=im;v=iv;angle=iangle; type=itype; }
           void show();
           void move();
};
void part:: show () {     
         glBegin(GL_TRIANGLES);					
		glColor3f(1,1,0);			
		glVertex3f( x, y+35, 0.0f);		
		glVertex3f( x+20,y, 0.0f);
		glVertex3f(x,y, 0.0f);		
		//glVertex3f(x-5,y,0);		
	glEnd();
}
void part::move(){
x+=v;	
	
}
