#include <iostream>

#include <windows.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
static double x=0.0;
static double move=-60;
static float rx[100]= {0}, ry[100]= {0};


//control waves
static double w1=0,w2=0,w3=0;
static double wr1 =0, wr2=0, wr3=0;
static bool transmit=false;
static bool rtransmit = false;
static bool sflag = false;
static int lv = 1;
void *font;
void *currentfont;

void setFont(void *font)
{
    currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
    char *c;
    glRasterPos3f(x,y,z);
    for(c=string; *c!='\0'; c++)
    {
        glColor3f(0.0,1.0,1.0);
        glutBitmapCharacter(currentfont,*c);
    }
}

void
stroke_output(GLfloat x, GLfloat y, char *format,...)
{
    va_list args;
    char buffer[200], *p;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    glPushMatrix();
    glTranslatef(-3.0, y, 2);
    glScaled(0.002, 0.003, 0.003);
    for (p = buffer; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}
//satellite used in both the screens

void usr(){
    //body
    glTranslatef(0,0,0);

    glPushMatrix();
    glColor3f(0.21,0.2,0.5);
    glScaled(0.7,1.5,0.7);
    glTranslatef(0.0,-1,0.0);
    glutSolidCube(0.4);
    glPopMatrix();
    //leg1
    glPushMatrix();
    glColor3f(0.152,0.15,0.76);
    glScaled(0.2,1,0.2);
    glTranslatef(-0.5,-2.0,0.0);
    glutSolidCube(0.4);
    glPopMatrix();
    //leg2
    glPushMatrix();
    glColor3f(0.152,0.15,0.76);
    glScaled(0.2,1,0.2);
    glTranslatef(0.5,-2.0,0.0);
    glutSolidCube(0.4);
    glPopMatrix();
    //shoe 1
    glPushMatrix();
    glColor3f(0,0,0);
    glScaled(0.25,0.2,0.2);
    glTranslatef(0.43,-10.9,0.1);
    glutSolidCube(0.4);
    glPopMatrix();

    //shoe2
    glPushMatrix();
    glColor3f(0,0,0);
    glScaled(0.25,0.2,0.2);
    glTranslatef(-0.4,-10.9,0.1);
    glutSolidCube(0.4);
    glPopMatrix();
    //head
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0,-1,0);
    glScaled(0.5,0.6,0.5);
    glutSolidSphere(0.3,50,50);
    glPopMatrix();
    //hand1
    glPushMatrix();
    glColor3f(0.1,0.9,0.244);
    glRotatef(-10,0,0,1);
    glScaled(0.15,0.9,0.2);
    glTranslatef(0.50,-1.63,0.0);
    glutSolidCube(0.4);
    glPopMatrix();
    //hand2
    glPushMatrix();
    glColor3f(0.1,0.9,0.244);
    glScaled(0.15,0.9,0.2);
    glTranslatef(1.2,-1.6,0.0);
    glutSolidCube(0.4);
    glPopMatrix();


    //display screen of computer
    glPushMatrix();
    glColor3f(1,1,1);
    glScaled(1.4,0.9,0.3);
    glTranslatef(0.005,-1.15,-0.5);
    glutSolidCube(0.4);
    glPopMatrix();
    //black border of display of computer
    glPushMatrix();
    glColor3f(0,0,0);
    glScaled(1.6,1.2,0.6);
    glRotatef(-0.5,0,1,0);
    glTranslatef(0.0,-0.9,-0.6);
    glutSolidCube(0.4);
    glPopMatrix();
    //black stand of monitor
    glPushMatrix();
    glColor3f(0,0,0);
    glScaled(0.15,0.4,0.2);
    glRotatef(-0.5,0,1,0);
    glTranslatef(0.0,-3.4,-0.6);
    glutSolidCube(0.4);
    glPopMatrix();

    //cpu
    glPushMatrix();
    glScaled(0.5,1.3,0.7);
    glTranslatef(1.0,-0.95,-0.4);
    glutSolidCube(0.4);
    glPopMatrix();

    //brown desk
    glPushMatrix();
    glColor3f(0.152,0.15,0.06);
    glRotatef(-12,0,1,0);
    glScaled(2.9,1.9,1);
    glTranslatef(0.0,-1,-0.4);
    glutSolidCube(0.4);
    glPopMatrix();

}

void satellite()
{

    glRotatef(85,1,0,0);

//body
    glPushMatrix();
    glColor3f(0.51,0.53,0.544);
    glScaled(1,0.4,1);
    glTranslatef(3.0,0,0.0);
    glutSolidCube(0.4);
    glPopMatrix();

//Solar Panels

    glPushMatrix();
    glColor3f(0.529,0.1,0.80);
    glTranslatef(3,0,0.0);
    glScaled(3.7,0.0,1);
    glutSolidCube(0.4);
    glPopMatrix();

//cube at the satellite
    glPushMatrix();
    glColor3f(1,0.84,0);
    glTranslatef(3.0,-0.5,-0.35);
    glScaled(0.3,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();

//cone at the satellite (antenna)
    glPushMatrix();
    glColor3f(0.041,0.17,0.05);
    glTranslatef(3.0,0,0.5);
    glScaled(0.5,0.5,0.5);
    glRotatef(180,0,5,0);
    glutSolidCone(0.5,0.7,15,15);
    glPopMatrix();

}



void building(float x1,float y1,float z1, float t)
{


    glPushMatrix();
    glColor3f(0.180, 0.435, 0.105);
    glTranslatef(x1,y1,z1);
    if(t==1){
      glScaled(0.1,0.4,0.1);
    }
    else{
        glScaled(0.12,0.51,0.3);
    }
    glutSolidCube(2);
    glPopMatrix();


}




void waves()
{
//sending message
    glPushMatrix();
    glScaled(0.05,0.5,0.1);
    glColor3f(0.241,0.1,0.1);

    switch(lv){
        case 1:drawstring(w1,w2,0,"Hello");
                break;
        case 2:drawstring(w1,w2,0,"How r u?");
                break;
        case 3:drawstring(w1,w2,0,"R u free?");
                break;
    }
    glPopMatrix();
}


void waves2()
{
//receiving message
    glPushMatrix();
    glScaled(0.05,0.5,0.1);
    if(lv==false){
    drawstring(wr1,wr2,0,"Hi");
    }
    switch(lv){
        case 1:drawstring(wr1,wr2,0,"Hi");
                break;
        case 2:drawstring(wr1,wr2,0,"Fine");
                break;
        case 3:drawstring(wr1,wr2,0,"Yeah");
                break;
    }
    glPopMatrix();
}


void sat5()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-13.0f);

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-2,3,0);
    glutSolidCube(0.03);
    glPopMatrix();

    //base station
    glPushMatrix();
    glColor3f(0.001, 0.05, 0.150);
    glTranslatef(-0.2,0.8,0);
    glScalef(2,1.3,1.5);
    glutSolidCube(1);
    glPopMatrix();

//Moon
    glPushMatrix();
    glColor3f(1,0.77,0.30);
    glTranslatef(4,2.8,0);
    glScaled(0.5,0.5,0.5);
    glutSolidSphere(0.6,50,50);
    glPopMatrix();



//Earth
    glPushMatrix();
    glColor3f(0.101, 0.235, 0.150);
    glTranslatef(0,-12,0);
    glutSolidCube(15);
    glPopMatrix();

/*
//Building 1
    glPushMatrix();
    glColor3f(0.121, 0.698, 0.196);
    glRotatef(5,0,0,0);
    building(-4.2,-2.7,0,1);
    glPopMatrix();

//Building 2s
    glPushMatrix();
    glColor3f(0.894, 0.035, 0.027);
    glRotatef(2,0,0,0);
    building(-3.9,-2.7,0,1);
    glPopMatrix();

//Building 3
    glPushMatrix();
    glColor3f(0.894, 0.035, 0.027);
    glRotatef(2,0,0,0);
    building(-4.5,-2.7,0,1);
    glPopMatrix();
*/


//Tower1 (small)
    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(-2.7,-3.9,-4);
    glRotatef(270,1,0,0);
    glScaled(0.4,0.8,1.65);
    glutWireCone(0.5,1,4,10);
    glPopMatrix();

//Tower 2(small)
    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(2.7,-3.9,-4);
    glRotatef(270,1,0,0);
    glScaled(0.4,0.8,1.65);
    glutWireCone(0.5,1,4,10);
    glPopMatrix();
/*
//Building 4
    glPushMatrix();
    glColor3f(0.121, 0.698, 0.196);
    glRotatef(0,0,0,0);
    building(4.2,-2.7,0,2);
    glPopMatrix();

//Building 5
    glPushMatrix();
    glColor3f(0.894, 0.035, 0.027);
    glRotatef(2,0,0,0);
    building(3.8,-2.7,0,2);
    glPopMatrix();

//Building 6
    glPushMatrix();
    glColor3f(0.894, 0.035, 0.027);
    glRotatef(2,0,0,0);
    building(3.4,-2.7,0,2);
    glPopMatrix();
*/
//Saltellites
    glPushMatrix();
    glTranslatef(-3.4,3.0,0);
    satellite();
    glPopMatrix();

//sending signal
    glPushMatrix();
    glTranslatef(-4.3+w1,-2.5+w2,0);
    waves();
    glPopMatrix();

//receiving signal
    glPushMatrix();
    glTranslatef(3.4+wr1,-2.7+wr2,0);
    waves2();
    glPopMatrix();

 //stars
    glPointSize(2);
    for(int j=0; j<100; j++)
    {
        for(int i=0; i<100; i++)
        {
            rx[j]=rand()/500;
            ry[i]=rand()/500;

            glBegin(GL_POINTS);
            glColor3f(0,2,2);
            glVertex3f(-6+rx[j],ry[i],-5);
            glEnd();

        }
    }


    //user
    glPushMatrix();
    glTranslatef(-3.9,-1,0.5);
    glRotatef(15,0,1,0);
    usr();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.7,-1,0.5);
    glRotatef(-15,0,1,0);
    usr();
    glPopMatrix();

//labels
    glPushMatrix();
    glTranslatef(0.0,0.0,-2.0);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1,1,1);
    drawstring(0.7,3.7,-1.0,"Satellite");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1,1,1);
    drawstring(-5.4,-2.1,-1.0,"User 1");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1,1,0);
    glColor3f(1,1,1);
    drawstring(-2.0,-2.0,-1.0,"Network\n Tower 1");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1.0,1.0,1.0);
    drawstring(1,-2.0,-1.0,"Network\n Tower 2");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1,1,1);
    drawstring(3.2,-1.5,3,"User 2");
    drawstring(-0.70,0.7,3.0,"Base Station");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void U()
{
    x += .07;
    if(transmit)
    {
        if(w1<=1.9&&w2<=0.8){
            w1+=0.0095;
            printf("%d a ",w1);
            w2+=0.002;

        }
        else if(w1<3){
            w1+=0.0050;
            w2+=0.0080;
        }
        else if(w1<3.10){
            w1+=0.00019;
            w2+=0.00100;
        }
        else if(w1<3.6){
            w1+=0.0027;
            w2+=0.0040;
        }
        else if (w1<4.3){
            w1+=0.0019;
            w2-=0.0040;
        }
        else if (w1<5.6){
            w1+=0.0055;
            w2-=0.0065;
        }
        else if (w1<8){
            w1+=0.0097;
            w2-=0.0025;
        }

    }

    if(w1>7.9)
    {
        if(wr1>=-1.5&&wr2<=0.8){
            wr1-=0.0080;
            wr2+=0.0033;

        }
        else if(wr1>-3.1){
            wr1-=0.0050;
            wr2+=0.0045;
        }
        else if(wr1>-3.3){
            wr1-=0.0010;
            wr2+=0.0020;
        }
        else if(wr1>-3.7){
            wr1-=0.00100;
            wr2+=0.0030;
        }
        else if(wr1>-4.2){
            wr1-=0.00100;
            wr2-=0.0030;
        }
        else if(wr1>-5.2){
            wr1-=0.0060;
            wr2-=0.0100;
        }
        else if(wr1>-7.7){
            wr1-=0.0070;
            wr2-=0.0010;
        }

    }

    sat5();

}

void doInit()
{

    glClearColor(0.01,0.11,0.17,0);
    glViewport(0,0,640,480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearDepth(2.0f);
    glEnable(GL_DEPTH_TEST);

    glEnable( GL_COLOR_MATERIAL );

    glDepthFunc(GL_LEQUAL);
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-12.0f);
    stroke_output(-2.0, 1.7, "Instructions:");
    stroke_output(-2.0, 0.9, "Press s to send the message to user 2");
    stroke_output(-2.0, 0.3, "Change message by pressing 1,2 or 3");
    stroke_output(-2.0,-1.0, "Transmission of messages");
    stroke_output(-2.0,-1.5, "");
    stroke_output(-2.0,-2.0, " Rohan B K 1DT19CS133");
    stroke_output(-2.0,-2.5, "Venugopal Reddy 1DT19CS130 ");

    GLfloat mat_ambient[]= {0.0f,1.0f,2.0f,1.0f};
    GLfloat mat_diffuse[]= {0.0f,1.5f,.5f,1.0f};
    GLfloat mat_specular[]= {5.0f,1.0f,1.0f,1.0f};
    GLfloat mat_shininess[]= {70.0f};
    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

    //GLfloat lightIntensity[]= {1.7f,1.7f,1.7f,1.0f};
    GLfloat lightIntensity[]= {1.7f,1.7f,1.7f,1.0f};
    GLfloat light_position3[]= {0.0f,8.0f,10.0f,0.0f};
    glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);

    GLfloat lightIntensity1[]= {1.7f,1.7f,1.7f,1.0f};
    GLfloat light_position31[]= {-2.0f,8.0f,10.0f,0.0f};
    glLightfv(GL_LIGHT1,GL_POSITION,light_position31);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,lightIntensity1);

    glEnable(GL_COLOR_MATERIAL);

    glFlush();

    glutSwapBuffers();

}

void menu(int id)
{

    switch(id)
    {
    case 1:
        lv = 1;
        break;


    case 2:
        lv = 2;
        break;
    case 3:
        lv = 3;
        break;
    }
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();

}

void mykey(unsigned char key,int x,int y)
{


    if(key=='s')

    {
        transmit=!transmit;
        wr1=0;
        wr2=0;
        wr3=0;
        if(!transmit)
        {
            w1=0;
            w2=0;
            w3=0;
            sflag=false;

        }
        glutIdleFunc(U);
    }

    if(key=='1'){
        lv=1;
    }
    if(key=='2'){
        lv=2;
    }
    if(key=='3'){
        lv=3;
    }

}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1700,1050);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Transmission of messages");
    glutDisplayFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glutKeyboardFunc(mykey);
    glutCreateMenu(menu);
    glutAddMenuEntry("Level 1",1);
    glutAddMenuEntry("Level 2",2);
    glutAddMenuEntry("Level 3",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    doInit();
    glutMainLoop();
    return 0;
}

