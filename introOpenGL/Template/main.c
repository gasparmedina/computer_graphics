
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
	(-1, 1, -1, 1, 1, 1000);

    //Iniciamos la matriz vista*modelo con una identidad (es decir sin transformaciones)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int done = 0;

}
