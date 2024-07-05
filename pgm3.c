#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

void myinit(){
    glClearColor(1,1,1,0);
    gluOrtho2D(-500,500,-500,500);
}

void drawTriangle(){
    glBegin(GL_POLYGON);
    glVertex2f(100,100);
    glVertex2f(200,100);
    glVertex2f(150,150);
    glEnd();
}

void translate(){
    glPushMatrix();
    glTranslated(100,0,0);
    drawTriangle();
    glPopMatrix();
}

void scale(){
    glPushMatrix();
    glScaled(2,2,1);
    drawTriangle();
    glPopMatrix();
}

void rotate(){
    glPushMatrix();
    glRotated(45,0,0,1);
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

void pivotPointRotate(){
    glPushMatrix();
    glTranslated(100,100,0);
    glRotated(45,0,0,1);
    glTranslated(-100,-100,0);
    drawTriangle();
    glPopMatrix();
}

void displayMe(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangle();
    glFlush();
}

void menu(int ch){
    switch(ch){
        case 1:
            translate();
            break;
        case 2:
            rotate();
            break;
        case 3:
            scale();
            break;
        case 4:
            pivotPointRotate();
            break;
        case 5:
            pivotPointScale();
            break;
        default:
            exit(0);
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Tranformation");

    myinit();
    glutDisplayFunc(displayMe);
    glutCreateMenu(menu);
    glutAddMenuEntry("Translate", 1);
    glutAddMenuEntry("Rotate", 2);
    glutAddMenuEntry("Scale", 3);
    glutAddMenuEntry("Pivot Point Rotate", 4);
    glutAddMenuEntry("Pivot Point Scale", 5);
    glutAddMenuEntry("Exit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}