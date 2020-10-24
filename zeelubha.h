
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>

float BackgroundPixel[3] ;	

void draw_pixel(int x, int y) 
{

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int y1, int x2, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}

void draw_dash_line(int x1, int y1, int x2, int y2,int gap) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;
	int temp1=0,temp2=0;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			if(temp1>=gap)
			{
				draw_pixel(x, y);
			}
			temp1++;
			if(temp1==gap+gap)
			{
				temp1=0;
			}
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			if(temp2>=gap)
			{
				draw_pixel(x, y);
			}
			temp2++;
			if(temp2==gap+gap)
			{
				temp2=0;
			}
		}
	}
}

void draw_fixed_bolt_line(int x1, int y1, int x2, int y2,int bolt) {
	int dx, dy, i, e, j;
	int incx, incy, inc1, inc2;
	int x,y;
	int fline = (int)round(bolt/2);
	int bline = (int)floor(bolt/2);
	
	//printf("%d",fline);

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;

				for(j=0;j<=fline;j++)
				{
					draw_pixel(x-j, y);
				}
				for(j=1;j<=bline;j++)
				{
					draw_pixel(x+j, y);
				}
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;

				for(j=0;j<=fline;j++)
				{
					draw_pixel(x-j, y);
				}
				for(j=1;j<=bline;j++)
				{
					draw_pixel(x+j, y);
				}

		}
	}
}

void draw_flexy_bolt_line(int x1, int y1, int x2, int y2,int bolt) {
	int dx, dy, i, e, j;
	int incx, incy, inc1, inc2;
	int x,y;
	int fline = (int)round(bolt/2);
	int bline = (int)floor(bolt/2);
	
	//printf("%d",fline);

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;

				for(j=0;j<=fline;j++)
				{
					draw_pixel(x-j, y);
				}
				for(j=1;j<=bline;j++)
				{
					draw_pixel(x+j, y);
				}
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;

				for(j=0;j<=fline;j++)
				{
					draw_pixel(x-j, y+j);
				}
				for(j=1;j<=bline;j++)
				{
					draw_pixel(x+j, y-j);
				}

		}
	}
}

void zeelLineDisplay(int x1, int y1, int x2, int y2) {
		
	draw_line(x1, y1, x2, y2);
	glFlush();
}

void zeelDashLineDisplay(int x1, int y1, int x2, int y2,int gap) 
{
 	draw_dash_line(x1, y1, x2, y2,gap);
	glFlush();
}

void zeelFixedBoltLineDisplay(int x1, int y1, int x2, int y2,int bolt) 
{
 	draw_fixed_bolt_line(x1, y1, x2, y2,bolt);
	glFlush();
}

void zeelFlexyBoltLineDisplay(int x1, int y1, int x2, int y2,int bolt) 
{
 	draw_flexy_bolt_line(x1, y1, x2, y2,bolt);
	glFlush();
}

void zeelTriangleDisplay(int x1,int y1,int x2,int y2,int x3,int y3) {
	
		int triangle[6];
	
		triangle[0] = x1;
		triangle[1] = y1;
		triangle[2] = x2;
		triangle[3] = y2;
		triangle[4] = x3;
		triangle[5] = y3;
	
		draw_line(triangle[0],triangle[1], triangle[2], triangle[3]);
		draw_line(triangle[2],triangle[3], triangle[4], triangle[5]);
		draw_line(triangle[4],triangle[5], triangle[0], triangle[1]);

	glFlush();
}

void zeelSquareDisplay(int x1,int y1,int y2) {
	
		int square[3];
	
		square[0]=x1;
		square[1]=y1;
		square[2]=y2;
	
		draw_line(square[0],square[1], square[0], square[2]);
		int r = y2-y1;		
		draw_line(square[0],square[2], square[0]+r, square[2]);
		draw_line(square[0]+r,square[2], square[0]+r, square[1]);
		draw_line(square[0]+r,square[1], square[0], square[1]);

	glFlush();
}

void zeelRectDisplay(int x1,int y1,int y2,int x3) {
	
		int square[4];
	
		square[0]=x1;
		square[1]=y1;
		square[2]=y2;
		square[3]=x3;
			
		draw_line(square[0],square[1], square[0], square[2]);
		draw_line(square[0],square[2], square[3], square[2]);
		draw_line(square[3],square[2], square[3], square[1]);
		draw_line(square[3],square[1], square[0], square[1]);

	glFlush();
}

void eightplotcircle(int xc,int yc,int x,int y)  
{  
    draw_pixel(x+xc,y+yc);  
    draw_pixel(x+xc,-y+yc);  
    draw_pixel(-x+xc,-y+yc);  
    draw_pixel(-x+xc,y+yc);  
    draw_pixel(y+xc,x+yc);  
    draw_pixel(y+xc,-x+yc);  
    draw_pixel(-y+xc,-x+yc);  
    draw_pixel(-y+xc,x+yc);  
    glFlush();
  } 

void zeelCircleDisplay(float xcenter , float ycenter, float radius){
	
	int x=0,y=radius,d=3-(2*radius);  
    eightplotcircle(xcenter,ycenter,x,y);  
  
    while(x<=y)  
     {  
      if(d<=0)  
             {  
        d=d+(4*x)+6;  
      }  
     else  
      {  
        d=d+(4*x)-(4*y)+10;  
        y=y-1;  
      }  
       x=x+1;  
        eightplotcircle(xcenter,ycenter,x,y);  
    }  
	
}

void zeelFontDisplay(int x, int y, char *string) 
{
  char* c;
  
  glRasterPos2f(x, y);

  for ( c = string; *c != '\0'; c++) 
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); 
    glFlush();
  }
  
}

void zeelFont24Display(int x, int y, char *string) 
{
  char* c;
  
  glRasterPos2f(x, y);

  for ( c = string; *c != '\0'; c++) 
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c); 
    glFlush();
  }
  
}

void zeelFillColor(int x, int y,float NewColor[3]) 
{
	static int i=0;
	if(i==0)
	{
		glReadPixels(x, y , 1, 1, GL_RGB, GL_FLOAT, &BackgroundPixel);	
		//printf("%f",NewColor[0]);
		i++;
	}
	
	float CurentPixel[3] ;
	glReadPixels(x, y , 1, 1, GL_RGB, GL_FLOAT, &CurentPixel);
	//printf("%f",CurentPixel[2]);
	if ( CurentPixel[0] == BackgroundPixel[0] && CurentPixel[1] == BackgroundPixel[1] && CurentPixel[2] == BackgroundPixel[2]  )
	{
		glColor3f(NewColor[0],NewColor[1],NewColor[2]);
		draw_pixel(x,y);
		glFlush();
		
		//printf("%d  %d  \n",x,y);
		zeelFillColor( x + 1, y, NewColor ) ;
		zeelFillColor( x - 1, y, NewColor ) ;
		zeelFillColor( x, y - 1, NewColor ) ;
		zeelFillColor( x, y + 1, NewColor ) ;
		
		//zeelFillColor( x-1, y + 1, NewColor ) ;
//		zeelFillColor( x+1, y + 1, NewColor ) ;
//		zeelFillColor( x-1, y - 1, NewColor ) ;
//		zeelFillColor( x+1, y - 1, NewColor ) ;
	}
	return ; 
	
}

void zeelArcDisplay(float xc,float yc,float theta,float x,float y)
{

	float dth, angle, rtheta;

	dth = 1/(3.2 * abs(x-xc) + abs(y-yc));

	if(dth > 0.01)
	{
		dth = 0.01;

		angle = 0.0;
	}	

	rtheta = 3.14159 * theta / 180.0;

	glBegin(GL_POINTS);
	while(angle < rtheta)
	{
		glVertex2f(x,y);
		x = x - ((y-yc) * dth);
		y = y + ((x-xc) * dth);
		angle = angle + dth;
	}
	glEnd();
	glFlush();
}




