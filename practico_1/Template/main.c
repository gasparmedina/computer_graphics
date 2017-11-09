#include "framework/canvas.h"
#include "framework/mm.h"

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



	// Actualizar la pantalla:
	cg_repaint();

	int done = 0;
	while (!done)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_KEYDOWN:
					if (event.key.keysym.sym != SDLK_ESCAPE)
						break;
				case SDL_QUIT : done = 1;
			}
		}
	}

	// Liberar recursos:
	cg_close();

	// Ejemplo del modulo de Manejo de Memoria (MM):
	int* pint = (int *)cg_malloc(10*sizeof(int));
	printf("pint is a pointer: %p\n", pint);
	cg_free(pint); // olvidarse de liberar este objeto produce un mensaje


	return 0;
}
