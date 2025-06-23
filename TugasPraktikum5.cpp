/* Nama : Saskia Putri Paramitha
   NIM  : 24060123140144
   Lab  : GKV E2
   File : TugasPraktikum5
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double rotAngle = 15;    // sudut rotasi diubah dari 10 ke 15
double rotAngle1 = 15;   // sudut rotasi diubah dari 10 ke 15

void init()
{
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        0.0, 0.0, 5.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();
    glRotated(rotAngle, 0, 1, 0);
    glRotated(rotAngle1, 1, 0, 0);
    
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0, 0.1, 0.1);
    glutSolidTeapot(1);
    
    glPopMatrix();
    
    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char k, int x, int y)
{
    switch (k)
    {
        // Modifikasi: mengubah tombol keyboard yang digunakan
        case 'd':           // ganti 'a' dengan 'd' (kanan)
            rotAngle += 10; // ubah increment dari 5 ke 10
            break;
        case 'w':           // ganti 'y' dengan 'w' (atas)
            rotAngle1 += 10;
            break;
        case 's':           // ganti 'b' dengan 's' (bawah)
            rotAngle1 -= 10;
            break;
        case 'a':           // ganti 'l' dengan 'a' (kiri)
            rotAngle -= 10;
            break;
        case 'r':           // tambahan tombol untuk reset
            rotAngle = 0;
            rotAngle1 = 0;
            break;
        case 'q':
            exit(0);
    }
    glutPostRedisplay();
}

int main()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutCreateWindow("Praktikum 5 - Kamera Modified (WASD Controls)");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    printf("Kontrol:\n");
    printf("W - Rotasi ke atas\n");
    printf("S - Rotasi ke bawah\n");
    printf("A - Rotasi ke kiri\n");
    printf("D - Rotasi ke kanan\n");
    printf("R - Reset rotasi\n");
    printf("Q - Keluar\n");
    
    init();
    glutMainLoop();
    return 0;
}
