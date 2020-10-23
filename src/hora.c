#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
/* Se importan las bibliotecas*/
 
void senales(int signum){ // funcion sin retorno llamada senales con el parametro signum
    if (signum == SIGUSR1){//condicion que verifica que la señal corresponda al proceso
	time_t current_time; //se define funciones para almacenar la hora
	char* c_time_string; 
	current_time = time(NULL);//entrega la hora actual
	c_time_string = ctime(&current_time);//convierte la hora a formato de hora local
	printf("Señal SIGUSR1 recibida: %s\n", c_time_string);//se muestra en pantalla la fecha y hora
    }
}

int main(){// funcion principal
	while(True){//bucle infinito
		printf("Listo para recibir la señal PID=%d\n", getpid());// se obtiene el id del proceso
		signal(SIGUSR1, senales);//envia la senal
		sleep(5);//se hace un sleep de 5 segundos en pantalla
	}
}
