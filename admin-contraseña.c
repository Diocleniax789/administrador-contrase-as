#include <stdio.h>

#define TOTAL_USUARIOS 10000

struct usuario{
    char cod_usu[8];
    char nom_usu[80];
    char password[30];
    char mail[100];
    int accion;
};

void carga_usuarios(struct usuario*,int*);
char * carga_caract_no_permitidos();
void valida_usuarios(struct usuario*,int,char*);
int valida_clave(char*,char*);

int main(){






    return 0;
}
