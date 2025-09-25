from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from math import *

vertices = {
    'A': (-0.5, -0.5),
    'B': (0.5, -0.5),
    'C': (0.5, 0.5)
}

def DrawTriangle():
    glBegin(GL_TRIANGLES)

    glColor3f(1.0, 0.0, 0.0)
    glVertex2f(*vertices['A'])

    glColor3f(0.0, 1.0, 0.0)
    glVertex2f(*vertices['B'])

    glColor3f(0.0, 0.0, 1.0)
    glVertex2f(*vertices['C'])

    glEnd()

def GetIncentro():
    Ax, Ay = vertices['A']
    Bx, By = vertices['B']
    Cx, Cy = vertices['C']

    #a = tamanho do lado oposto à aresta A
    a = sqrt(pow(Bx - Cx, 2) + pow(By - Cy, 2))
    b = sqrt(pow(Ax - Cx, 2) + pow(Ay - Cy, 2))
    c = sqrt(pow(Ax - Bx, 2) + pow(Ay - By, 2))

    Ix = (a*Ax + b*Bx + c*Cx)/(a + b + c)
    Iy = (a*Ay + b*By + c*Cy)/(a + b + c)

    #https://www.universoformulas.com/matematicas/geometria/incentro-triangulo/
    s = (a+b+c)/2
    r = sqrt(((s-a)*(s-b)*(s-c))/s)

    return [Ix, Iy, r]

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

    DrawTriangle()

    incentro = GetIncentro()
    print(incentro)
    DrawCircle(incentro[0], incentro[1], incentro[2], 100)

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