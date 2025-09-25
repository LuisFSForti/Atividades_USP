from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from math import *

def DrawCircle(Xc, Yc, r, num):
    glBegin(GL_LINE_LOOP)
    for i in range(num):
        theta = 2*pi*(i)/num
        x = r*cos(theta) + Xc
        y = r*sin(theta) + Yc

        glVertex2f(x, y)

    glEnd()

def display():
    glClear(GL_COLOR_BUFFER_BIT)

    DrawCircle(0.2, -0.2, 0.5, 1000)
    DrawCircle(0.2, 0.2, 0.5, 1000)
    DrawCircle(0.2, -0.2, 0.75, 1000)
    DrawCircle(-0.2, -0.2, 0.3, 1000)

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