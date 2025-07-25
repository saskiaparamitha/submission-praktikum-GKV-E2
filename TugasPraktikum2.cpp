/* Nama : Saskia Putri Paramitha
   NIM  : 24060123140144
   Lab  : GKV E2
   File : TugasPraktikum2
*/

#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265

/* 1. Buatlah sebuah lingkaran. */
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

/* Buatlah sebuah mobil 2D yang memanfaatkan object2 primitif dan transformasi (translasi 
dan rotasi). Penggunaan stack disarankan! */
float carX = -0.5f; 
float speed = 0.01f; 

void drawCar() {
    glPushMatrix();
    glTranslatef(carX, -0.5f, 0.0f); 

    // Badan mobil
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glEnd();

    // Atap mobil
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.07f, 0.2f);
    glVertex2f(-0.07f, 0.2f);
    glEnd();

    // Roda mobil
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.15f, -0.02f);
    glVertex2f(-0.13f, -0.02f);
    glVertex2f(-0.13f, 0.02f);
    glVertex2f(-0.15f, 0.02f);

    glVertex2f(0.13f, -0.02f);
    glVertex2f(0.15f, -0.02f);
    glVertex2f(0.15f, 0.02f);
    glVertex2f(0.13f, 0.02f);
    glEnd();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCar();
    glutSwapBuffers();
}

void update(int value) {
    carX += speed; // Gerakkan mobil sesuai kecepatan

    if (carX > 1.2f) carX = -1.2f;
    if (carX < -1.2f) carX = 1.2f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); 
}

// Fungsi untuk menangani input keyboard
void keyboard(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) speed = 0.01f; // Maju
    if (key == GLUT_KEY_LEFT) speed = -0.01f; // Mundur
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Animasi Mobil dengan Kontrol");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard); 
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
