#include <stdio.h>

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
void envia_mail();

int main(){
    struct usuario usuarios[10000];
    int cantidad_usuarios_cargados = 0;
    char *caracteres_no_validos;

    carga_usuarios(usuarios,&cantidad_usuarios_cargados);
    caracteres_no_validos = carga_caract_no_permitidos();
    valida_usuarios(usuarios,cantidad_usuarios_cargados,caracteres_no_validos);
    envia_mail(usuarios,cantidad_usuarios_cargados);

    return 0;
}
