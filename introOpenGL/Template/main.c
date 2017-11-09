#include "framework/canvas.h"
#include "framework/mm.h"

//Esta es la librería a importar para tener acceso a la api de OpenGL
#include "GL/gl.h"

int main(int argc, char* argv[])
{
#ifdef WIN32
	freopen( "CON", "w", stdout );
	freopen( "CON", "w", stderr );
#endif
	// Crear una ventana de 500x500 pixels:
	int cw = 500;
	int ch = 500;
	cg_init(cw, ch, NULL);

    //obtenemos la versión de OpenGL soportada por nuestro driver de video
	printf("%s\n", glGetString(GL_VERSION));

    //Seteamos las matrices de Escala y Projección en el pipeline
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,cw,ch);
	glFrustum(-1, 1, -1, 1, 1, 1000);

    //Iniciamos la matriz vista*modelo con una identidad (es decir sin transformaciones)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int done = 0;

    //Estas variables las usamos para modificar el ángulo de rotación al presionar la tecla ->, y para saber cuando la
    //tecla está presionada
	float ang = 0.0;
    char pressed = 0;
	while (!done)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch (event.type)
			{
                case SDL_KEYUP:
                    //chequeo eventos de teclado, si suelto la tecla ->, des-marco el flag que indica que hay que incremetar el
                    //ángulo de rotación
                    if (event.key.keysym.sym == SDLK_RIGHT)
                        pressed = 0;
                    break;
				case SDL_KEYDOWN:
                    //chequeo eventos de teclado, si presiono la tecla ->, marco el flag que indica que hay que incremetar el
                    //ángulo de rotación
                    if (event.key.keysym.sym == SDLK_RIGHT)
                        pressed = 1;
					if (event.key.keysym.sym != SDLK_ESCAPE)
						break;

				case SDL_QUIT : done = 1;
			}
		}
        //Si la tecla -> está presionada, incremeto el ángulo de rotación.
		if(pressed) ang += 1.0f;

        //Limpio el canvas, para empezar a dibujar un nuevo cuadro
        glClear(GL_COLOR_BUFFER_BIT);


        //Inicio la matriz modelo en una identidad, para resetar la matriz del cuadro anterior
		glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //Devuelvo el objeto a su posición original
        glTranslatef(0,0,-2);
        //Aplico la rotación adecuada, según el valor de la variable ang
        glRotatef(ang, 0,1,0);
        //Traslado el objeto al centro de coordenadas
        glTranslatef(0,0,2);

        //Este bloque comentado a continuación es lo que se conoce como modo directo de OpenGL
        //Se encuentra deprecado y no es recomendable su uso, aunque es mas sencillo de usar que otros modos.
        /*glBegin(GL_TRIANGLES);
            glColor3f(1,1,1);
            glVertex3f(-1.0,-1.0,-2.0);
            glColor3f(0.4,0.4,0.4);
            glVertex3f(1.0,-1.0,-2.0);
            glColor3f(0.1,0.1,0.1);
            glVertex3f(0.0,1.0,-2.0);
        glEnd();*/

        //Declaramos e inicializamos los vectores que describen la geometría a dibujar.
        float verts[12] = {-1,-1,-2,1,-1,-2,0,1,-2, 1, 1, -2};
        unsigned int indexs[6] = {0,1,2,1,2,3};
        float colors[12] = {1,0,0,0,1,0,0,0,1, 1, 1, 0};

        //Le indicamos a la trajeta de video cuales son los punteros que apuntan a la info de la geometría
        //En este caso seteamos las coordenadas de los vértices y el color de cada uno.
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, verts);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, colors);

        //Esta función lee el array de vertices de forma secuencial y cada 3 elementos dibuja un triángulo.
        //glDrawArrays(GL_TRIANGLES, 0, 4);

        //Este otro método es más eficiente (aunque no siempre se puede usar, depende de como esté definida la geometría)
        //En lugar de repetir las coordenadas de algunos vértices de forma secuencial, paso por separado un array de vértivces, con
        //valores sin repetir, y un array de índices que define los triángulos que voy a dibujar con esos vértices
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indexs);

        //una vez finalizado el renderizado, libero los recursos
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);

        //Por último, actualizo el canvas para que lo renderizado sea visible.
        cg_repaint();
	}

	// Liberar recursos:
	cg_close();

	// Ejemplo del modulo de Manejo de Memoria (MM):
	int* pint = (int *)cg_malloc(10*sizeof(int));
	printf("pint is a pointer: %p\n", pint);
	cg_free(pint); // olvidarse de liberar este objeto produce un mensaje


	return 0;
}
