#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

void myinit(){
	glClearColor(1,1,1,0);
	gluOrtho2D(0,500,0,500);
}

void drawTriangle(){
	glColor3d(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(100,100);
	glVertex2f(200,100);
	glVertex2f(150,150);
	glEnd();
}

void translation(){
	glPushMatrix();
	glTranslated(100,0,0);
	drawTriangle();
	glPopMatrix();
}

void scaling(){
	glPushMatrix();
	glScaled(2,2,1);
	drawTriangle();
	glPopMatrix();
}

void rotation(){
	glPushMatrix();
	glRotated(45,0,0,1);
	drawTriangle();
	glPopMatrix();
}

void pivotPointRotate(){
	glPushMatrix();
	glTranslated(100,100,0);
	glRotated(45,0,0,1);
	glTranslated(-100,-100,0);
	drawTriangle();
	glPopMatrix();
}

void pivotPointScale(){
	glPushMatrix();
	glTranslated(100,100,0);
	glScaled(2,2,1);
	glTranslated(-100,-100,0);
	drawTriangle();
	glPopMatrix();
}

void menu(int ch){
	switch(ch){
		case 1:
			drawTriangle();
			break;
		case 2:
			translation();
			break;
		case 3:
			scaling();
			break;
		case 4:
			rotation();
			break;
		case 5:
			pivotPointRotate();
			break;
		case 6:
			pivotPointScale();
			break;
		case 7:
			exit(0);
	}
}

void displayMe(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawTriangle();
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("2d transformation");
	myinit();
	glutDisplayFunc(displayMe);
	glutCreateMenu(menu);
	glutAddMenuEntry("Triangle", 1);
	glutAddMenuEntry("Translate", 2);
	glutAddMenuEntry("Scale", 3);
	glutAddMenuEntry("Rotate", 4);
	glutAddMenuEntry("Pivot point rotate", 5);
	glutAddMenuEntry("Pivot point scale", 6);
	glutAddMenuEntry("Exit", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
