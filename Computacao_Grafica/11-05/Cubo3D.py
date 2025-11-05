from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

pilhaDeComandos = []

def drawCube():
    glBegin(GL_QUADS)

    #Frente (z = 1)
    glColor3f(0, 1, 0)
    glVertex3f(-1, -1, 1)
    glVertex3f(-1, 1, 1)
    glVertex3f(1, 1, 1)
    glVertex3f(1, -1, 1)

    #Trás (z = -1)
    glColor3f(1, 0, 0)
    glVertex3f(-1, -1, -1)
    glVertex3f(-1, 1, -1)
    glVertex3f(1, 1, -1)
    glVertex3f(1, -1, -1)

    #Topo (y = 1)
    glColor3f(0, 0, 1)
    glVertex3f(-1, 1, -1)
    glVertex3f(-1, 1, 1)
    glVertex3f(1, 1, 1)
    glVertex3f(1, 1, -1)

    #Baixo (y = -1)
    glColor3f(1, 1, 0)
    glVertex3f(-1, -1, -1)
    glVertex3f(-1, -1, 1)
    glVertex3f(1, -1, 1)
    glVertex3f(1, -1, -1)

    #Direita (x = 1)
    glColor3f(1, -1, 1)
    glVertex3f(1, -1, -1)
    glVertex3f(1, -1, 1)
    glVertex3f(1, 1, 1)
    glVertex3f(1, 1, -1)

    #Esquerda (x = -1)
    glColor3f(1, 1, 1)
    glVertex3f(-1, -1, -1)
    glVertex3f(-1, -1, 1)
    glVertex3f(-1, 1, 1)
    glVertex3f(-1, 1, -1)    

    glEnd()

def display():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    gluLookAt(3, 3, 5, 0.5, 0.5, 0.5, 0, 1, 0)

    glPushMatrix()
    for i in range(0, len(pilhaDeComandos)):
        chave = pilhaDeComandos[-1 - i]
        #del pilhaDeComandos[-1]

        match chave:
            case 'W':
                glTranslatef(0, 0.1, 0)
            case 'A':
                glTranslatef(-0.1, 0, 0)
            case 'S':
                glTranslatef(0, -0.1, 0)
            case 'D':
                glTranslatef(0.1, 0, 0)
            case '+':
                glScalef(1.1, 1.1, 1.1)
            case '-':
                glScalef(0.9, 0.9, 0.9)
            case "Cima":
                glRotatef(-5, 1, 0, 0)
            case "Baixo":
                glRotatef(5, 1, 0, 0)
            case "Esquerda":
                glRotatef(-5, 0, 1, 0)
            case "Direita":
                glRotatef(5, 0, 1, 0)

    drawCube()
    glPopMatrix()

    glutSwapBuffers()

def init():
    glEnable(GL_DEPTH_TEST)
    glClearColor(0, 0, 0, 1)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(45, 1, 0.1, 50.0)
    glMatrixMode(GL_MODELVIEW)

def keyboard(key, x, y):
    match key:
        case b'w':
            pilhaDeComandos.append("W")
        case b'a':
            pilhaDeComandos.append("A")
        case b's':
            pilhaDeComandos.append("S")
        case b'd':
            pilhaDeComandos.append("D")
        case b'+':
            pilhaDeComandos.append("+")
        case b'-':
            pilhaDeComandos.append("-")

    glutPostRedisplay()

def keyboardSpecial(key, x, y):
    if key == GLUT_KEY_UP:
        pilhaDeComandos.append("Cima")
    elif key == GLUT_KEY_DOWN:
        pilhaDeComandos.append("Baixo")
    elif key == GLUT_KEY_LEFT:
        pilhaDeComandos.append("Esquerda")
    elif key == GLUT_KEY_RIGHT:
        pilhaDeComandos.append("Direita")

    glutPostRedisplay()
            

def main():
    glutInit()
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
    glutInitWindowSize(600, 600)
    glutCreateWindow(b"Cena 3D")

    glutKeyboardFunc(keyboard)
    glutSpecialFunc(keyboardSpecial)

    init()
    glutDisplayFunc(display)
    glutMainLoop()

    return 0

if __name__ == "__main__":
    main()