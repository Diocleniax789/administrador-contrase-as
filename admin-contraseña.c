#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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

void carga_usuarios(struct usuario *usuarios,int *cantidad_usuarios_cargados){
    int i;
    char cod_usu[8];

    printf("\n - Para finalizar con la carga, al momento de cargar el codigo de usuario, coloque el '*' - \n");
    printf("\n");
    printf("\n CARGA DE DATOS DEL USUARIO \n");
    printf("\n");
    for(i = 0; i < 10000; i++){
        system("cls");
        fflush(stdin);
        printf("\n Usuario nro %i", i + 1);
        printf("\n");
        printf("\n + Codigo de usuario: ");
        scanf("%s",cod_usu);
        if(strcmp(usuarios[i].cod_usu,"*") == 0){
            break;
        } else{
            strcpy(usuarios[i].cod_usu,cod_usu);
            printf("\n + Nombre de usuario: ");
            scanf("%s",usuarios[i].nom_usu);
            printf("\n + password: ");
            scanf("%s",usuarios[i].password);
            printf("\n + Mail: ");
            scanf("%s",usuarios[i].mail);
            (*cantidad_usuarios_cargados)++;
            printf("\n");
            system("pause");
        }
    }
}
