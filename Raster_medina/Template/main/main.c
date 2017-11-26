#include "../framework/canvas.h"
#include "../framework/mm.h"
#include "../structs/Obj.h"

//Esta es la librería a importar para tener acceso a la api de OpenGL
#include "GL/gl.h"

/*

Rasterización de modelos OBJ, dibujando triángulos sólidos y en forma de “malla de
alambre” (puede utilizar el framework provisto por la Cátedra1).

@see - https://wiki.libsdl.org/SDL_Keycode
       http://www.glprogramming.com/red/chapter05.html

*/

// Globals
float ang = -70.0f;
float pitch = 0.0f;
float ang_vel = 1.0f;
char done = 0;
char backFaceCulling = 0;
char lighting = 0;
char wireframe = 0;
char gourandShading = 0;
unsigned char key_pressed[1024];
Obj *result = NULL;



int main(int argc, char* argv[])
{

#ifdef WIN32
    freopen( "CON", "w", stdout );
    freopen( "CON", "w", stderr );
#endif

    // Crear una ventana de 500x500 pixels.
    int cw = 500;
    int ch = 500;
    cg_init(cw, ch, NULL);

    //Seteamos las matrices de Escala y Projección en el pipeline
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,cw, ch);
    glFrustum(-1,1,-1,1,1,1000);

    // Habilito la iluminacion
    enableLighting();

    //Iniciamos la matriz vista*modelo con una identidad (es decir sin transformaciones)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Reservamos un espacio de memoria para el obj que vamos a cargar con vertices y caras
    result = (Obj *)malloc(sizeof(Obj));

    // Cargamos la informacion del archivo al espacio de memoria antes reservado
    loadObj("data/models/obj/knight_texturas.obj", result);

    memset(key_pressed, 0, 1024);

    // Inicializo el gameLoop
    initGameLoop();

    // Liberamos los recursos
    freeMemoryObj(result);
    cg_close();

    return 0;

}

void initGameLoop()
{

// Definimos el gameloop
    while (!done)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                key_pressed[event.key.keysym.sym] = 1;
                // Con la tecla F1 se habilita la malla de alambre
                if (event.key.keysym.sym == SDLK_F1)
                {
                    wireframe = !wireframe;
                    if(wireframe)
                        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    else
                        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                    break;

                }
                // Con la tecla F2 se habilita la optimización por Backface culling.
                else if (event.key.keysym.sym == SDLK_F2)
                {
                    backFaceCulling = !backFaceCulling;
                    if(backFaceCulling)
                    {
                        glEnable(GL_CULL_FACE);
                        glCullFace(GL_BACK);
                        glFrontFace(GL_CW);
                    }
                    else
                        glDisable(GL_CULL_FACE);
                    break;
                }
                // Con la tecla F3 se habilita las luces
                else if (event.key.keysym.sym == SDLK_F3)
                {
                    lighting = !lighting;
                    if(lighting)
                    {
                        glEnable(GL_LIGHTING);
                        glEnable(GL_LIGHT0);

                    }
                    else
                        glDisable(GL_LIGHT0);
                    break;
                }
                // Con la tecla F4 se habilita el gourand shading
                else if (event.key.keysym.sym == SDLK_g)
                {
                    gourandShading = !gourandShading;
                    if(gourandShading)
                        glShadeModel(GL_FLAT);
                    else
                        glShadeModel(GL_SMOOTH);
                    break;
                }
                else if (event.key.keysym.sym != SDLK_ESCAPE)
                    break;
            case SDL_QUIT :
                done = 1;
                break;
            case SDL_KEYUP:
                key_pressed[event.key.keysym.sym] = 0;

            }
        }

        //Con la llamada a glEnable(GL_DEPTH_TEST) habilitamos la comprobación de la
        //profundidad en el dibujado.
        glEnable(GL_DEPTH_TEST);

        //Inicio la matriz modelo en una identidad, para resetar la matriz del cuadro anterior
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Ralizamos las rotaciones y traslaciones necesarias para ubicar al objeto en su posicion correcta
        glTranslatef(0.0f, 0.0f, -50.0f);
        glRotatef(pitch, 1.0f, 0.0f, 0.0f);
        glRotatef(ang, 0.0f, 1.0f, 0.0f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

        // Asociamos los eventos de las flechas del teclado a los movimientos del objeto, para poder rotarlo.
        if(key_pressed[SDLK_RIGHT]) ang += ang_vel;
        if(key_pressed[SDLK_LEFT]) ang -= ang_vel;
        if(key_pressed[SDLK_UP]) pitch += ang_vel;
        if(key_pressed[SDLK_DOWN]) pitch -= ang_vel;

        //Limpio el canvas, para empezar a dibujar un nuevo cuadro
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        // Mostramos el obj a la geometria de OPENGL
        showObj(result);

        //Por último, actualizo el canvas para que lo renderizado sea visible.
        cg_repaint();
    }
}

void enableLighting()
{
    GLfloat light_ambient1[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat light_diffuse1[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position1[] = { 1.0, 1.0, 1.0, 0.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular1);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position1);

}
