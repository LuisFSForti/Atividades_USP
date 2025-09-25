from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import numpy as np

verticesGlobal = {
    'A': (-0.1, -0.1),
    'B': (0.1, -0.1),
    'C': (0, 0.1)
}

def DrawTriangle(vertices):
    glBegin(GL_TRIANGLES)

    glColor3f(1.0, 0.0, 0.0)
    glVertex2f(*vertices['A'])

    glColor3f(0.0, 1.0, 0.0)
    glVertex2f(*vertices['B'])

    glColor3f(0.0, 0.0, 1.0)
    glVertex2f(*vertices['C'])

    glEnd()

def display():
    glClear(GL_COLOR_BUFFER_BIT)

    DrawTriangle(verticesGlobal)
    glPushMatrix()

    glTranslatef(-0.5, 0.5, 0.0)
    glScalef(0.5, 0.5, 1)
    #glRotatef(90, 0, 0, 1)

    DrawTriangle(verticesGlobal)
    glPushMatrix()

    glTranslatef(2, 0, 0.0)
    glRotatef(-90, 0, 0, 1)

    DrawTriangle(verticesGlobal)

    glFlush()

def main():
    glutInit()
    glutInitWindowSize(600, 600)
    glutCreateWindow(b"Hello World")

    glutDisplayFunc(display)
    glutMainLoop()
    return 0

if __name__ == "__main__":
    main()