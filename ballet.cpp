// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

// Timo Mühlbach, Yorrick Schwappacher

#include <iostream>
#include <GL/freeglut.h>         //l�dt alles f�r OpenGL
#include "Cube.h"
#include <math.h>

//PRECOMPILER CONSTANTS BEGIN
//WINSIZE
#ifndef WINSIZE_X
#define WINSIZE_X 600
#endif

#ifndef WINSIZE_Y
#define WINSIZE_Y 600
#endif

//glOrtho
#ifndef ORTHO_BASE
#define ORTHO_BASE 2.0
#endif

#ifndef ORTHO_LEFT
#define ORTHO_LEFT -ORTHO_BASE
#endif

#ifndef ORTHO_RIGHT
#define ORTHO_RIGHT ORTHO_BASE
#endif

#ifndef ORTHO_BOTTOM
#define ORTHO_BOTTOM -ORTHO_BASE
#endif

#ifndef ORTHO_TOP
#define ORTHO_TOP ORTHO_BASE
#endif

#ifndef ORTHO_NEAR
#define ORTHO_NEAR 0.0
#endif

#ifndef ORTHO_FAR
#define ORTHO_FAR ORTHO_BASE * 2.5
#endif

//PRECOMPILER CONSTANTS END

float fRotationBody = .0;

float fRotationArms = 30.0;
float fRotationArmsToAdd = -1.0;

float fRotationFeet = 20.0;
float fRotationFeetToAdd = -1.0;

float camX = 0.0;
float camY = 0.0;
float camZ = 1.0;

void Init()
{
    // Hier finden jene Aktionen statt, die zum Programmstart einmalig
    // durchgef�hrt werden m�ssen
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    //glClearColor(1.0, 0.5, 0.0, 1.0);
    glClearColor(0.0f,1.0f,0.0f,1.0f);
}
/*
void oldRenderGuy(float xOffset, float yOffset, float zOffset) {
    //Torso
    glPushMatrix();
    glScalef(2., 3., 1.);
    Cube(0.4);
    glPopMatrix();

    //HEAD
    glPushMatrix();
    glColor4f(1.0f,1.0f,1.0f,1.0f);
    glTranslatef(0., 1.2, 0.);
    glBegin( GL_POLYGON );
    GLUquadricObj *quadric;
    quadric = gluNewQuadric();

    gluQuadricDrawStyle(quadric, GLU_FILL );
    gluSphere( quadric , .4 , 36 , 18 );

    gluDeleteQuadric(quadric);
    glEndList();

    glEnd();
    glPopMatrix();

    //Neck
    glPushMatrix();
    glTranslatef(0. + xOffset, 0.7 + yOffset, -0. + zOffset);
    glScalef(.7, 0.9, 0.9);
    Cube(0.4);
    glPopMatrix();


    //Arm Right 1
    glPushMatrix();
    glRotatef(fRotationArms, 0., 0., 1.);
    glTranslatef(0.4 + xOffset, 0. + yOffset, 0. + zOffset);
    glScalef(2, 1., 1.);
    Cube(0.4);
    //glPopMatrix();

    //Arm Right 2
    glPushMatrix();
    glRotatef(-fRotationArms, 0., 0., 1.);
    //glTranslatef(1. + xOffset, 0. + yOffset, 0. + zOffset);
    glScalef(1.5, .5, 1.);
    Cube(0.4);
    glPopMatrix();
    glPopMatrix();

    //Arm Left 1
    glPushMatrix();
    glRotatef(-fRotationArms, 0., 0., 1.);
    glTranslatef(-0.4 + xOffset, 0. + yOffset, 0. + zOffset);
    glScalef(2, 1., 1.);
    Cube(0.4);
    //glPopMatrix();

    //Arm Left 2
    glPushMatrix();
    glRotatef(fRotationArms, 0., 0., 1.);
    //glTranslatef(-1. + xOffset, 0. + yOffset, 0. + zOffset);
    glScalef(1.5, .5, 1.);
    Cube(0.4);
    glPopMatrix();
    glPopMatrix();

    //Leg Right
    glPushMatrix();
    glTranslatef(0.2 + xOffset, -0.5 + yOffset, 0. + zOffset);
    glScalef(.5, 2., 1.);
    Cube(0.4);
    glPopMatrix();

    //Foot Right
    glPushMatrix();
    glRotatef(fRotationFeet, 0., 1., 0.);
    glTranslatef(0.3 + xOffset, -1. + yOffset, 0. + zOffset);
    glScalef(1., .5, 1.);
    Cube(0.4);
    glPopMatrix();

    //Leg Left
    glPushMatrix();
    glTranslatef(-0.2 + xOffset, -0.5 + yOffset, 0. + zOffset);
    glScalef(.5, 2., 1.);
    Cube(0.4);
    glPopMatrix();

    //Foot Left
    glPushMatrix();
    glRotatef(-fRotationFeet, 0., 1., 0.);
    glTranslatef(-0.3 + xOffset, -1. + yOffset, 0. + zOffset);
    glScalef(1., .5, 1.);
    Cube(0.4);
    glPopMatrix();
}
*/

void renderGuy(float xOffset, float yOffset, float zOffset) {
    //Torso
    glPushMatrix();
      glRotatef(fRotationBody, 0., 1., 0.);
      glTranslatef(xOffset, yOffset, zOffset);
      glScalef(2., 3., 1.);
      Cube(0.4);

    //Neck
      glPushMatrix();
        glTranslatef(0., 0.1, -0.);
        glScalef(.2, 0.9, 0.4);
        Cube(0.4);
      glPopMatrix();

    //HEAD round
      /*glPushMatrix();
        glColor4f(1.0f,.0f,1.0f,1.0f);
        glTranslatef(0., .35, 0.);
        glBegin( GL_POLYGON );
        GLUquadricObj *quadric;
        quadric = gluNewQuadric();

        gluQuadricDrawStyle(quadric, GLU_FILL );
        gluSphere( quadric , .1 , 36 , 18 );

        gluDeleteQuadric(quadric);
        glEndList();

        glEnd();
      glPopMatrix();*/
    //HEAD Cube
      glPushMatrix();
        glTranslatef(0., 0.36, 0.);
        glScalef(0.55, .4, .9);
        Cube(0.4);
        //Eye left
        glPushMatrix();
          glTranslatef(-.1, .06, .2);
          glScalef(.1, .1, .1);
          Cube(.4);
        glPopMatrix();

        //Eye right
        glPushMatrix();
          glTranslatef(.1, .06, .2);
          glScalef(.1, .1, .1);
          Cube(.4);
        glPopMatrix();

        //Nose
        glPushMatrix();
          glTranslatef(.0, .01, .2);
          glScalef(.1, .1, .1);
          Cube(.4);
        glPopMatrix();

        //Mouth
        glPushMatrix();
          glTranslatef(.0, -.08, .2);
          glScalef(.5, .1, .1);
          Cube(.4);
        glPopMatrix();
      glPopMatrix();

    //Arm Right 1
      glPushMatrix();
        glRotatef(fRotationArms, 0., 0., 1.);
        glTranslatef(.3, 0.05, 0.);
        glScalef(.8, 0.33, .33);
        Cube(0.4);

    //Arm Right 2
        glPushMatrix();
          glRotatef(-fRotationArms, 0., 0., 1.);
          glTranslatef(0.25, 0., 0.);
          glScalef(0.5, .5, 1.);
          Cube(0.4);
        glPopMatrix();
      glPopMatrix();

    //Arm Left 1
      glPushMatrix();
        glRotatef(-fRotationArms, 0., 0., 1.);
        glTranslatef(-.3, 0.05, 0.);
        glScalef(.8, 0.33, .33);
        Cube(0.4);

    //Arm Left 2
        glPushMatrix();
          glRotatef(fRotationArms, 0., 0., 1.);
          glTranslatef(-.25, 0., 0.);
          glScalef(0.5, .5, 1.);
          Cube(0.4);
        glPopMatrix();
      glPopMatrix();

    //Leg Right
      glPushMatrix();
        glTranslatef(0.1, -.25, 0.);
        glScalef(.3, .3, 1.);
        Cube(0.4);

    //Foot Right
        glPushMatrix();
          glRotatef(fRotationFeet, 0., 1., 0.);
          glTranslatef(0.1, -.3, 0.);
          glScalef(1.8, .55, 1.);
          Cube(0.4);
        glPopMatrix();
      glPopMatrix();

    //Leg Left
      glPushMatrix();
        glTranslatef(-0.1, -.25, 0.);
        glScalef(.3, .3, 1.);
        Cube(0.4);

    //Foot Left
        glPushMatrix();
          glRotatef(-fRotationFeet, 0., 1., 0.);
          glTranslatef(-0.1, -.3, 0.);
          glScalef(1.8, .55, 1.);
          Cube(0.4);
        glPopMatrix();
      glPopMatrix();

    glPopMatrix();
}

void RenderScene() //Zeichenfunktion
{
    // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
    glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    gluLookAt ( 0., 0., 1., 0., 0., 0., 0., 1., 0.);
    //gluLookAt ( camX, camY, camZ, 0., 0., 0., 0., 1., 0.);

    //glutWireCube(0.2);

    renderGuy(0.,0.,0.);

    //renderGuy(5., 0., 0.);
    //renderGuy(-5., 0., 0.);
    //renderGuy(0., 3., .5);

    glutSwapBuffers();

}

void Reshape(int width,int height)
{
    // Hier finden die Reaktionen auf eine Ver�nderung der Gr��e des
    // Graphikfensters statt
    // Matrix f�r Transformation: Frustum->viewport
    glMatrixMode(GL_PROJECTION);
    // Aktuelle Transformations-Matrix zuruecksetzen
    glLoadIdentity();
    // Viewport definieren
    glViewport(0, 0, width, height);

    // Frustum definieren (siehe unten)
    //glOrtho(-10., 10., -10., 10., 0., 10.);
    //glOrtho(-2., 2., -2., 2., 0., 5.);
    glOrtho(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP, ORTHO_NEAR, ORTHO_FAR);
    // gluPerspective(senkr. Oeffnungsw., Seitenverh., zNear, zFar);
    //gluPerspective(45., 1., 0.1, 2.0);

    // Matrix f�r Modellierung/Viewing
    glMatrixMode(GL_MODELVIEW);
}

void Animate (int value) {

    fRotationBody += 1;
    if(fRotationBody >= 360) {
        fRotationBody = 0;
    }

    fRotationArms = fRotationArms + fRotationArmsToAdd;  // Rotationswinkel aendern
    if ( (fRotationArms <= -30.0 && fRotationArmsToAdd < 0) || (fRotationArms >= 30.0 && fRotationArmsToAdd > 0) ) {
        fRotationArmsToAdd *= -1;

        std::cout << "Arm rotation switched " << std::endl;
    }
    fRotationFeet = fRotationFeet + fRotationFeetToAdd;  // Rotationswinkel aendern
    if ( (fRotationFeet <= 0.0 && fRotationFeetToAdd < 0) || (fRotationFeet >= 20.0 && fRotationFeetToAdd > 0) ) {
        fRotationFeetToAdd *= -1;
    }

    //std::cout << "fRotationArms=" << fRotationArms << std::endl;

    glutPostRedisplay();
    // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
    unsigned int wait_msec = 10;
    glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
    glutInit( &argc, argv );                // GLUT initialisieren
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize( WINSIZE_X, WINSIZE_Y );         // Fenster-Konfiguration
    glutCreateWindow( "Schwappacher; Mühlbach" );   // Fenster-Erzeugung
    glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
    glutReshapeFunc( Reshape );

    /*//mouse Function
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMove);
    */

    // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0
    glutTimerFunc( 10, Animate, 0);
    Init();
    glutMainLoop();
    return 0;
}
