/* Nama : Saskia Putri Paramitha
   NIM  : 24060123140144
   Lab  : GKV E2
   File : TugasPraktikum4
*/

#include <GL/glut.h>

static int shoulder = 0, elbow = 0;
static int palm = 0, finger1 = 0, finger2 = 0, finger3 = 0, finger4 = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(int angle) {
    glPushMatrix();
        glRotatef((GLfloat)angle, 0.0, 0.0, 1.0);
        glTranslatef(0.3, 0.0, 0.0);
        glScalef(0.6, 0.1, 0.2);
        glutWireCube(1.0);
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0); // posisi awal bahu
        glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);

        // Lengan atas
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);

        // Lengan bawah
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat)palm, 0.0, 0.0, 1.0);

        // Telapak tangan
        glPushMatrix();
            glScalef(1.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        // Jari-jari (empat buah)
        glPushMatrix();
            glTranslatef(0.5, 0.2, 0.0); drawFinger(finger1);
            glTranslatef(0.0, -0.2, 0.0); drawFinger(finger2);
            glTranslatef(0.0, -0.2, 0.0); drawFinger(finger3);
            glTranslatef(0.0, -0.2, 0.0); drawFinger(finger4);
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        case 'p': palm = (palm + 5) % 360; break;
        case 'P': palm = (palm - 5) % 360; break;
        case '1': finger1 = (finger1 + 5) % 360; break;
        case '!': finger1 = (finger1 - 5) % 360; break;
        case '2': finger2 = (finger2 + 5) % 360; break;
        case '@': finger2 = (finger2 - 5) % 360; break;
        case '3': finger3 = (finger3 + 5) % 360; break;
        case '#': finger3 = (finger3 - 5) % 360; break;
        case '4': finger4 = (finger4 + 5) % 360; break;
        case '$': finger4 = (finger4 - 5) % 360; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lengan dengan Jari");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
