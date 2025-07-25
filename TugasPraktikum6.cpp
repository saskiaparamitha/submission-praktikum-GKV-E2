/* Nama : Saskia Putri Paramitha
   NIM  : 24060123140144
   Lab  : GKV E2
   File : TugasPraktikum6
*/

#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 5.0f, z = 20.0f; // posisi kamera lebih tinggi untuk melihat mobil
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0, h, w;

// Variabel untuk animasi mobil
float mobilPosX = 0.0f;
float mobilPosZ = 0.0f;
float mobilRotY = 0.0f;
float rodaRotasi = 0.0f;

void Reshape(int w1, int h1)
{
    if(h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void orientMe(float ang)
{
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i)
{
    x = x + i * (lx) * 0.3;
    z = z + i * (lz) * 0.3;
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void Grid() 
{
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 2.0;
    
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_LINES);
    for(i = Z_MIN; i < Z_MAX; i += gap)
    {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for(i = X_MIN; i < X_MAX; i += gap)
    {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
}

// Fungsi untuk membuat roda
void drawRoda(float radius, float width)
{
    glPushMatrix();
    
    // Warna roda (hitam)
    glColor3f(0.1, 0.1, 0.1);
    
    // Roda sebagai silinder
    GLUquadric* quad = gluNewQuadric();
    glRotated(90, 0, 1, 0);
    gluCylinder(quad, radius, radius, width, 16, 1);
    
    // Tutup depan roda
    glColor3f(0.2, 0.2, 0.2);
    gluDisk(quad, 0, radius, 16, 1);
    
    // Tutup belakang roda
    glTranslatef(0, 0, width);
    gluDisk(quad, 0, radius, 16, 1);
    
    gluDeleteQuadric(quad);
    glPopMatrix();
}

// Fungsi untuk membuat badan mobil
void drawBadanMobil()
{
    // Badan bawah mobil (persegi panjang)
    glColor3f(0.8, 0.1, 0.1); // Merah
    
    glPushMatrix();
    glScalef(4.0, 0.8, 2.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Badan atas mobil (kabin)
    glColor3f(0.7, 0.05, 0.05); // Merah lebih gelap
    
    glPushMatrix();
    glTranslatef(0.5, 1.2, 0);
    glScalef(2.5, 1.0, 1.8);
    glutSolidCube(1.0);
    glPopMatrix();
}

// Fungsi untuk membuat kaca mobil
void drawKacaMobil()
{
    glColor4f(0.5, 0.8, 1.0, 0.7); // Biru transparan
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Kaca depan
    glPushMatrix();
    glTranslatef(1.7, 1.2, 0);
    glScalef(0.1, 0.8, 1.6);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaca belakang
    glPushMatrix();
    glTranslatef(-0.7, 1.2, 0);
    glScalef(0.1, 0.8, 1.6);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaca samping kiri
    glPushMatrix();
    glTranslatef(0.5, 1.2, 0.85);
    glScalef(2.3, 0.8, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaca samping kanan
    glPushMatrix();
    glTranslatef(0.5, 1.2, -0.85);
    glScalef(2.3, 0.8, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glDisable(GL_BLEND);
}

// Fungsi untuk membuat lampu mobil
void drawLampuMobil()
{
    // Lampu depan kiri
    glColor3f(1.0, 1.0, 0.8); // Putih kekuningan
    glPushMatrix();
    glTranslatef(2.2, 0.2, 0.6);
    glutSolidSphere(0.2, 12, 12);
    glPopMatrix();
    
    // Lampu depan kanan
    glPushMatrix();
    glTranslatef(2.2, 0.2, -0.6);
    glutSolidSphere(0.2, 12, 12);
    glPopMatrix();
    
    // Lampu belakang kiri
    glColor3f(1.0, 0.0, 0.0); // Merah
    glPushMatrix();
    glTranslatef(-2.2, 0.2, 0.6);
    glutSolidSphere(0.15, 12, 12);
    glPopMatrix();
    
    // Lampu belakang kanan
    glPushMatrix();
    glTranslatef(-2.2, 0.2, -0.6);
    glutSolidSphere(0.15, 12, 12);
    glPopMatrix();
}

// Fungsi untuk menggambar mobil lengkap
void drawMobil()
{
    glPushMatrix();
    
    // Posisi dan rotasi mobil
    glTranslatef(mobilPosX, 0.8, mobilPosZ);
    glRotatef(mobilRotY, 0, 1, 0);
    
    // Gambar badan mobil
    drawBadanMobil();
    
    // Gambar kaca mobil
    drawKacaMobil();
    
    // Gambar lampu mobil
    drawLampuMobil();
    
    // Roda depan kiri
    glPushMatrix();
    glTranslatef(1.5, -0.5, 1.2);
    glRotatef(rodaRotasi, 1, 0, 0);
    drawRoda(0.4, 0.3);
    glPopMatrix();
    
    // Roda depan kanan
    glPushMatrix();
    glTranslatef(1.5, -0.5, -1.5);
    glRotatef(rodaRotasi, 1, 0, 0);
    drawRoda(0.4, 0.3);
    glPopMatrix();
    
    // Roda belakang kiri
    glPushMatrix();
    glTranslatef(-1.5, -0.5, 1.2);
    glRotatef(rodaRotasi, 1, 0, 0);
    drawRoda(0.4, 0.3);
    glPopMatrix();
    
    // Roda belakang kanan
    glPushMatrix();
    glTranslatef(-1.5, -0.5, -1.5);
    glRotatef(rodaRotasi, 1, 0, 0);
    drawRoda(0.4, 0.3);
    glPopMatrix();
    
    glPopMatrix();
}

void display() 
{
    // Update pergerakan kamera
    if (deltaMove)
        moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Gambar grid lantai
    Grid();
    
    // Gambar mobil
    drawMobil();
    
    glutSwapBuffers();
    glFlush();
}

void pressKey(int key, int x, int y) 
{
    switch (key) {
        case GLUT_KEY_LEFT: deltaAngle = -0.02f; break;
        case GLUT_KEY_RIGHT: deltaAngle = 0.02f; break;
        case GLUT_KEY_UP: deltaMove = 1; break;
        case GLUT_KEY_DOWN: deltaMove = -1; break;
    }
}

void releaseKey(int key, int x, int y) 
{
    switch (key) {
        case GLUT_KEY_LEFT:
            if (deltaAngle < 0.0f) deltaAngle = 0.0f;
            break;
        case GLUT_KEY_RIGHT:
            if (deltaAngle > 0.0f) deltaAngle = 0.0f;
            break;
        case GLUT_KEY_UP:
            if (deltaMove > 0) deltaMove = 0;
            break;
        case GLUT_KEY_DOWN:
            if (deltaMove < 0) deltaMove = 0;
            break;
    }
}

// Kontrol untuk menggerakkan mobil
void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 'i': // Mobil maju
            mobilPosX += sin(mobilRotY * M_PI / 180.0) * 0.5;
            mobilPosZ += cos(mobilRotY * M_PI / 180.0) * 0.5;
            rodaRotasi += 10;
            break;
        case 'k': // Mobil mundur
            mobilPosX -= sin(mobilRotY * M_PI / 180.0) * 0.5;
            mobilPosZ -= cos(mobilRotY * M_PI / 180.0) * 0.5;
            rodaRotasi -= 10;
            break;
        case 'j': // Mobil belok kiri
            mobilRotY += 5;
            break;
        case 'l': // Mobil belok kanan
            mobilRotY -= 5;
            break;
        case 'r': // Reset posisi mobil
            mobilPosX = 0;
            mobilPosZ = 0;
            mobilRotY = 0;
            rodaRotasi = 0;
            break;
        case 27: // ESC
            exit(0);
            break;
    }
    glutPostRedisplay();
}

// Variabel untuk pencahayaan
const GLfloat light_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 10.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 50.0f };

void lighting()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init(void)
{
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0.2, 0.2, 0.4, 1.0); // Background biru gelap
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Praktikum 6 - Mobil 3D dengan Depth dan Lighting");
    
    printf("=== KONTROL MOBIL 3D ===\n");
    printf("Kontrol Kamera:\n");
    printf("- Arrow Keys: Gerakkan kamera\n");
    printf("\nKontrol Mobil:\n");
    printf("- I: Mobil maju\n");
    printf("- K: Mobil mundur\n");
    printf("- J: Belok kiri\n");
    printf("- L: Belok kanan\n");
    printf("- R: Reset posisi mobil\n");
    printf("- ESC: Keluar\n");
    
    glutIgnoreKeyRepeat(1);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);
    
    lighting();
    init();
    glutMainLoop();
    return(0);
}
