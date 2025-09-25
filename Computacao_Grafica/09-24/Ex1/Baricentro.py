from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

vertices = {
    'A': (-0.5, -0.5),
    'B': (0.5, -0.5),
    'C': (0, 0.5)
}

def GetBaricenter():
    Ax, Ay = vertices['A']
    Bx, By = vertices['B']
    Cx, Cy = vertices['C']

    Gx = (Ax + Bx + Cx)/3
    Gy = (Ay + By + Cy)/3

    return (Gx, Gy)

def DrawBaricenter():
    pontoBaricentro = GetBaricenter()

    glBegin(GL_LINES)

    glColor3f(1.0, 0.0, 0.0)
    glVertex2f(*pontoBaricentro)
    glVertex2f(*vertices['A'])

    glEnd()

    glBegin(GL_LINES)

    glColor3f(0.0, 1.0, 0.0)
    glVertex2f(*pontoBaricentro)
    glVertex2f(*vertices['B'])

    glEnd()

    glBegin(GL_LINES)

    glColor3f(0.0, 0.0, 1.0)
    glVertex2f(*pontoBaricentro)
    glVertex2f(*vertices['C'])

    glEnd()

    glPointSize(10)
    glBegin(GL_POINTS)

    glColor3f(1.0, 1.0, 1.0)
    glVertex2f(*pontoBaricentro)

    glEnd()

def DrawTriangle():
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

    DrawTriangle()
    DrawBaricenter()

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