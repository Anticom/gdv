// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

// Timo Mühlbach, Yorrick Schwappacher

#include <iostream>
#include <GL/freeglut.h>         //l�dt alles f�r OpenGL
#include "Cube.h"

void Init()
{
    // Hier finden jene Aktionen statt, die zum Programmstart einmalig
    // durchgef�hrt werden m�ssen
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    glClearColor(1.0, 0.5, 0.0, 1.0);
}

void RenderScene() //Zeichenfunktion
{
    // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
    glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    gluLookAt ( 0., 0., 1., 0., 0., 0., 0., 1., 0.);

    //Ursprungs-Helper
    glBegin( GL_POLYGON );
    //glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(  0.01, -0.01, -0.01 );
    glVertex3f(  0.01,  0.01, -0.01 );
    glVertex3f(-0.01, 0.01, -0.01);
    glVertex3f(-0.01, -0.01, -0.01);
    glEnd();

    glRotatef(-45, 0., 0., 1.);

    glPushMatrix();
    //glRotatef(-45, 0., 0., 1.);
    glTranslatef(0.4, 0., 0.);
    glScalef(2, 1., 1.);
    Cube(0.4);
    glPopMatrix();

    glPushMatrix();
    //glRotatef(-45, 0., 0., 1.);
    glTranslatef(1., 0., 0.);
    glScalef(1.5, .5, 1.);
    Cube(0.4);
    glPopMatrix();



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
    glOrtho(-2., 2., -2., 2., 0., 1.5);
    // gluPerspective(senkr. Oeffnungsw., Seitenverh., zNear, zFar);
    //gluPerspective(45., 1., 0.1, 2.0);

    // Matrix f�r Modellierung/Viewing
    glMatrixMode(GL_MODELVIEW);
}

void Animate (int value)
{
    // Hier werden Berechnungen durchgef�hrt, die zu einer Animation der Szene
    // erforderlich sind. Dieser Prozess l�uft im Hintergrund und wird alle
    // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins
    // inkrementiert und dem Callback wieder uebergeben.
    std::cout << "value=" << value << std::endl;
    // RenderScene aufrufen
    glutPostRedisplay();
    // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
    unsigned int wait_msec = 10;
    glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
    glutInit( &argc, argv );                // GLUT initialisieren
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize( 600, 600 );         // Fenster-Konfiguration
    glutCreateWindow( "Schwappacher; Mühlbach" );   // Fenster-Erzeugung
    glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
    glutReshapeFunc( Reshape );
    // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0
    glutTimerFunc( 10, Animate, 0);
    Init();
    glutMainLoop();
    return 0;
}
