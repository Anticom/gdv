// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

// Timo Mühlbach, Yorrick Schwappacher

#include <iostream>
#include <GL/freeglut.h>         //l�dt alles f�r OpenGL
#include "Cube.h"

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
#define ORTHO_BASE 5.0
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
#define ORTHO_NEAR .0
#endif

#ifndef ORTHO_FAR
#define ORTHO_FAR ORTHO_BASE * 2.5
#endif

//Rotation Y/N
#ifndef ROTATE_BODY
#define ROTATE_BODY true
#endif

//moveSpeeMultiplier
#ifndef MOVE_SPEED_MULTIPLIER
#define MOVE_SPEED_MULTIPLIER 10//3
#endif

//PRECOMPILER CONSTANTS END

bool movementInProgess = false;

float fMoveBody = .0;
float fJumpMoveBody = .0;

float fRotationBody = .0;

float fRotationLegs = .0;
float fRotationLegsToAdd = 1.;

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
    glClearColor(0.0f,.1f,0.1f,1.0f);
}

void renderGuy(float xOffset, float yOffset, float zOffset, bool negateBodyRotation) {
    /*
   * Order
   * Push
   *  MoveParent
   *  RotateParent
   *
   *  Push Child
   *   Move Child
   *   Rotate Child
   *   Scale Child
   *   Create Cube
   *  Pop Child
   *
   *  Scale Parent
   *  Create Cube
   * Pop
   * */

    //Torso
    glPushMatrix();
      //glTranslatef(xOffset  + (movementInProgess ? fMoveBody : 0), yOffset, zOffset);
      glTranslatef(xOffset  + (negateBodyRotation ? -1 : 1) * fMoveBody, yOffset + fJumpMoveBody, zOffset);
      //glTranslatef(xOffset, yOffset, zOffset);
      if(ROTATE_BODY) {
          glRotatef((negateBodyRotation ? -1 : 1) * fRotationBody, 0., 1., 0.);
      }

    //Neck
      glPushMatrix();
        glTranslatef(0., .75, -0.);
        glScalef(.4, .9, 0.4);
        Cube(0.4);
      glPopMatrix();

    //HEAD Cube
      glPushMatrix();
        glTranslatef(0., 1., 0.);
        glRotatef(0.9 * fRotationArms, 0., 1., 0.);
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

        glScalef(0.9, 1., .9);
        Cube(0.4);
      glPopMatrix();

    //Arm Right 1
      glPushMatrix();
        glTranslatef(.3, 0.05, 0.);
        glRotatef(fRotationArms, 0., 0., 1.);


    //Arm Right 2
        glPushMatrix();
          glTranslatef(.3, 0., 0.);
          glRotatef(1.1 * fRotationArms, 0., 0., 1.);
          glScalef(1.05, .5, .25);
          Cube(0.4);
        glPopMatrix();

        glScalef(2., 1., .33);
        Cube(0.4);
      glPopMatrix();

    //Arm Right 1
    glPushMatrix();
      glTranslatef(-.3, 0.05, 0.);
      glRotatef(-fRotationArms, 0., 0., 1.);


    //Arm Right 2
      glPushMatrix();
        glTranslatef(-.3, 0., 0.);
        glRotatef(-1.1 * fRotationArms, 0., 0., 1.);
        glScalef(1.05, .5, .25);
        Cube(0.4);
       glPopMatrix();

      glScalef(2., 1., .33);
      Cube(0.4);
    glPopMatrix();

    //Leg Right
      glPushMatrix();
        glTranslatef(0.18, -.7, 0.005);
        glRotatef((movementInProgess ? fRotationLegs : 0), -1., 0., 0.);

    //Foot Right
        glPushMatrix();
          glTranslatef(0.025, -.35, 0.1);
          glRotatef(fRotationFeet, 0., 1., 0.);
          glScalef(.7, .5, 1.);
          Cube(0.4);
        glPopMatrix();

        glScalef(.6, 1.25, .4);
        Cube(0.4);
      glPopMatrix();


    //Leg left
    glPushMatrix();
      glTranslatef(-0.18, -.7, 0.005);
      glRotatef((movementInProgess ? -fRotationLegs : 0), -1., 0., 0.);

    //Foot left
      glPushMatrix();
        glTranslatef(-0.025, -.35, 0.1);
        glRotatef(-fRotationFeet, 0., 1., 0.);
        glScalef(.7, .5, 1.);
        Cube(0.4);
      glPopMatrix();

      glScalef(.6, 1.25, .4);
      Cube(0.4);
    glPopMatrix();

    glScalef(2., 3., 1.);
    Cube(0.4);
    glPopMatrix();
}

void RenderScene() //Zeichenfunktion
{
    // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
    glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    gluLookAt ( 0., 0., 1., 0., 0., 0., 0., 1., 0.);
    //gluLookAt ( camX, camY, camZ, 0., 0., 0., 0., 1., 0.);

    /*glBegin( GL_POLYGON );
        glColor4f  ( 0.0f, 0.0f, 1.0f, 1.0f );
        glVertex3f(ORTHO_LEFT, -.1, -3. );
        glColor4f  ( 0.0f, 1.0f, 1.0f, 1.0f );
        glVertex3f(ORTHO_LEFT,  -2.5, -.1 );
        glVertex3f(ORTHO_RIGHT, -2.5, -.1);
        glColor4f  ( 0.0f, 0.0f, 1.0f, 1.0f );
        glVertex3f(ORTHO_RIGHT, -.1, -3.);
    glEnd();

    glBegin( GL_POLYGON );
        glColor4f(1.0f,0.0f,0.0f,1.0f);
        glVertex3f(ORTHO_LEFT,  -.55, 3. );
        glColor4f(1.f,0.0f,1.0f,1.0f);
        glVertex3f(ORTHO_LEFT, -3.5, -3.5 );
        glVertex3f(ORTHO_RIGHT, -3.5, -3.5);
        glColor4f(1.0f,0.0f,0.0f,1.0f);
        glVertex3f(ORTHO_RIGHT, -.55, 3.);
    glEnd();*/

    /*renderGuy(0., 1., -1., false);
    renderGuy(3., 1., -1., false);
    renderGuy(-3., 1., -1., false);

    renderGuy(-1.5, 0., 0., true);
    renderGuy(1.5, 0., 0., true);
    */
    renderGuy(0,0.,0., false);
    renderGuy(-2., 0.,0., false);
    renderGuy(2,0.,0., false);

    renderGuy(-1.,1.,-1., true);
    renderGuy(1.,1.,-1., true);
    renderGuy(3.,1.,-1., true);
    renderGuy(-3.,1.,-1., true);

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
    glOrtho(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP, ORTHO_NEAR, ORTHO_FAR);

    // Matrix f�r Modellierung/Viewing
    glMatrixMode(GL_MODELVIEW);
}

void Animate (int value) {
    static int legMoveCounter = 0;
    static float jumpToAdd = .03;

    movementInProgess = fRotationBody == 90 || fRotationBody == 270;
    //move
    if(movementInProgess) {
        fRotationLegs += fRotationLegsToAdd;
        if(fRotationLegs >= 30 || fRotationLegs <= -30) {
            legMoveCounter++;
            fRotationLegsToAdd = (fRotationLegs >= 30 ? -1 : 1);
        }
        if(legMoveCounter >= 2) {
            legMoveCounter = 0;
        }
        fMoveBody += .001 * (fRotationBody == 90 ? 1 : -1) * MOVE_SPEED_MULTIPLIER;
        if(fMoveBody >= 1.5 || fMoveBody <= -1.5) {
            fRotationBody += 1 * MOVE_SPEED_MULTIPLIER;
        }
    //Perform Jump
    } else if(fRotationBody == 0 || fRotationBody == 180) {
        fJumpMoveBody += jumpToAdd;
        if(fJumpMoveBody >= .5) {
            jumpToAdd *= -1;
        } if(fJumpMoveBody <= 0) {
            jumpToAdd *= -1;
            fRotationBody += 1 * MOVE_SPEED_MULTIPLIER;
        }
    }else {
        fRotationBody += 1 * MOVE_SPEED_MULTIPLIER;
    }

    if(fRotationBody >= 360) {
        fRotationBody = 0;
    }

    fRotationArms = fRotationArms + fRotationArmsToAdd;  // Rotationswinkel aendern
    if ( (fRotationArms <= -30.0 && fRotationArmsToAdd < 0) || (fRotationArms >= 30.0 && fRotationArmsToAdd > 0) ) {
        fRotationArmsToAdd *= -1;
    }
    fRotationFeet = fRotationFeet + fRotationFeetToAdd;  // Rotationswinkel aendern
    if ( (fRotationFeet <= 0.0 && fRotationFeetToAdd < 0) || (fRotationFeet >= 20.0 && fRotationFeetToAdd > 0) ) {
        fRotationFeetToAdd *= -1;
    }

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
