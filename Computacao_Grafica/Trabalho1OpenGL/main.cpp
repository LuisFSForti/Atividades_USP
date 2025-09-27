#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <cmath>
#include <algorithm>
#include <utility>

#include <GL/glut.h>

//REMOVER DEPOIS, APENAS PARA TESTE
#include <random>
#include <chrono>

using namespace std;

struct Vertice
{
    float x, y;
};

struct DadosET
{
    float yMax;
    float xMin;
    float m;
};

struct ET
{
    int yMin, nroNiveis;
    vector<DadosET>* lista;
};

void OrdenaPorX(vector<DadosET>* nivel)
{
    sort(nivel->begin(), nivel->end(),
                 [](const DadosET &a, const DadosET &b)
                 {
                     return a.xMin < b.xMin;
                 });
}

ET* CriaET(vector<Vertice> vertices, vector<array<int, 2>> arestas)
{
    float yMin = numeric_limits<float>::max(), yMax = numeric_limits<float>::min();
    for(Vertice ver : vertices)
    {
        if(ver.y < yMin)
            yMin = ver.y;

        if(ver.y > yMax)
            yMax = ver.y;
    }

    int yMinInt = static_cast<int>(ceil(yMin));
    int yMaxInt = static_cast<int>(floor(yMax));
    int nroNiveis = yMaxInt - yMinInt;

    ET* listaET = new ET();
    listaET->yMin = yMinInt;
    listaET->nroNiveis = nroNiveis;
    listaET->lista = new vector<DadosET>[nroNiveis];

    for(array<int, 2> ar : arestas)
    {
        Vertice ver1;
        Vertice ver2;

        if(vertices[ar[0]].y > vertices[ar[1]].y)
        {
            ver1 = vertices[ar[1]];
            ver2 = vertices[ar[0]];
        }
        else
        {
            ver1 = vertices[ar[0]];
            ver2 = vertices[ar[1]];
        }

        int indice = ceil(ver1.y) - listaET->yMin;
        float m = (ver2.y - ver1.y)/(ver2.x - ver1.x);
        //Retas horizontais tem m==0, o algoritmo não precisa tratar elas
        if(m == 0)
            continue;

        listaET->lista[indice].push_back({
                                         ver2.y, ver1.x, m});
    }

    for(int i = 0; i < listaET->nroNiveis; i++)
    {
        if(!listaET->lista[i].empty())
        {
            OrdenaPorX(&(listaET->lista[i]));
        }
    }

    return listaET;
}

void PreenchimentoDePoligonos(ET* listaET)
{
    glBegin(GL_POINTS);
    vector<DadosET> listaAET;
    for(int i = 0; i < listaET->nroNiveis; i++)
    {
        int yNivel = i + listaET->yMin;
        for(int j = 0; j < (int)listaAET.size(); j++)
        {
            //Se a iteração está no nível ou acima do y máximo da aresta
            if(listaAET[j].yMax <= yNivel)
            {
                //Remove ela
                listaAET.erase(listaAET.begin() + j);
                j--;
                continue;
            }

            listaAET[j].xMin += 1/listaAET[j].m;
        }
        //Move todos os dados do nível pra lista AET
        listaAET.insert(listaAET.end(),
                        make_move_iterator(listaET->lista[i].begin()),
                        make_move_iterator(listaET->lista[i].end()));
        //Limpa o nível original
        listaET->lista[i].clear();
        //Reordena a lista
        OrdenaPorX(&listaAET);

        int verticesCruzados = 0;
        for(int x = listaAET[0].xMin; x < listaAET.back().xMin; x++)
        {
            while(x >= listaAET[verticesCruzados].xMin)
                verticesCruzados++;

            if(verticesCruzados % 2 == 1)
            {
                glVertex2f(x, yNivel);
            }
        }
    }
    glEnd();
}

void display()
{
    //REMOVER: APENAS PARA TESTE
    random_device rd;
    mt19937 engine(rd());
    uniform_real_distribution distX(-300.0f, 300.0f);
    uniform_real_distribution distY(-150.0f, 150.0f);
    uniform_int_distribution nro(3, 15);
    int nroVertices = nro(engine);

    vector<Vertice> vertices;
    for(int i = 0; i < nroVertices; i++)
        vertices.push_back({distX(engine), distY(engine)});

    vector<array<int, 2>> arestas;
    arestas.push_back({0, nroVertices-1});
    for(int i = 0; i < nroVertices-1; i++)
        arestas.push_back({i, i+1});

    ET* listaET = CriaET(vertices, arestas);

    /*for(int i = 0; i < listaET->nroNiveis; i++)
    {
        cout << listaET->yMin + i;
        for(DadosET dado : listaET->lista[i])
        {
            cout << " Y: " << dado.yMax << " X: " << dado.xMin << " M: " << dado.m;
        }
        cout << endl;
    }*/



    glClear(GL_COLOR_BUFFER_BIT);

    //glPointSize(2);
    glColor3f(1.0, 1.0, 1.0);
    PreenchimentoDePoligonos(listaET);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Hello world");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -200, 200);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
