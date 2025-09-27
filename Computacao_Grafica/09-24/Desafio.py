from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from math import *
from random import *

def GetIncentro(vertices):
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

    return [Ix, Iy], r

def GetCricuncentro(vertices):
    Ax, Ay = vertices['A']
    Bx, By = vertices['B']
    Cx, Cy = vertices['C']

    Ax2, Ay2 = pow(Ax, 2), pow(Ay, 2)
    Bx2, By2 = pow(Bx, 2), pow(By, 2)
    Cx2, Cy2 = pow(Cx, 2), pow(Cy, 2)
    
    D = 2*(Ax*(By-Cy) + Bx*(Cy - Ay) + Cx*(Ay-By))
    
    Ix = ((Ax2+Ay2)*(By-Cy) + (Bx2+By2)*(Cy-Ay) + (Cx2+Cy2)*(Ay-By))/D
    Iy = ((Ax2+Ay2)*(Cx-Bx) + (Bx2+By2)*(Ax-Cx) + (Cx2+Cy2)*(Bx-Ax))/D

    r = sqrt(pow(Ix - Ax, 2) + pow(Iy - Ay, 2))

    return [Ix, Iy], r

def DrawTriangle(vertices):
    glBegin(GL_TRIANGLES)

    glColor3f(1.0, 0.0, 0.0)
    glVertex2f(*vertices['A'])

    glColor3f(0.0, 1.0, 0.0)
    glVertex2f(*vertices['B'])

    glColor3f(0.0, 0.0, 1.0)
    glVertex2f(*vertices['C'])

    glEnd()

def DrawCircle(centro, r, num):
    glBegin(GL_LINE_LOOP)
    for i in range(num):
        theta = 2*pi*(i)/num
        x = r*cos(theta) + centro[0]
        y = r*sin(theta) + centro[1]

        glVertex2f(x, y)

    glEnd()

def display():
    glClear(GL_COLOR_BUFFER_BIT)

    vertices = {
        'A': (uniform(-1, 1), uniform(-1, 1)),
        'B': (uniform(-1, 1), uniform(-1, 1)),
        'C': (uniform(-1, 1), uniform(-1, 1))
    }

    DrawTriangle(vertices)

    incentro, raio = GetIncentro(vertices)
    glColor3f(uniform(0.1, 1.0), uniform(0.1, 1.0), uniform(0.1, 1.0))
    DrawCircle(incentro, raio, 100)

    circuncentro, raio = GetCricuncentro(vertices)
    glColor3f(uniform(0.1, 1.0), uniform(0.1, 1.0), uniform(0.1, 1.0))
    DrawCircle(circuncentro, raio, 100)

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