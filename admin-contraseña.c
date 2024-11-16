#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

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
    struct usuario usuarios[5];
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

    for(i = 0; i < 10000; i++){
        system("cls");
        fflush(stdin);
        printf("\n - Para finalizar con la carga, al momento de cargar el codigo de usuario, coloque el '*' - \n");
        printf("\n");
        printf("\n CARGA DE DATOS DEL USUARIO \n");
        printf("\n");
        printf("\n Usuario nro %i", i + 1);
        printf("\n");
        printf("\n + Codigo de usuario: ");
        scanf("%s",cod_usu);
        if(strcmp(cod_usu,"*") == 0){
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

    printf("\n");
    printf("\n * Carga finalizada * \n");
    system("pause");

}

char * carga_caract_no_permitidos(){
    int i;
    static char caract_no_permitidos[5];

    system("pause");
    printf("\n");
    printf("\n ----------------------------------------------- \n");
    printf("\n Cargue cadena de caracteres no permitidos: ");
    scanf("%s",caract_no_permitidos);

    printf("\n * Carga finalizada * \n");
    printf("\n");
    printf("\n ------------------------------------------------ \n");

    return caract_no_permitidos;
}


void valida_usuarios(struct usuario *usuarios, int cantidad_usuarios_cargados, char *caracteres_no_validos){
    int i;
    static char password_usuario[30];

    for(i = 0; i < cantidad_usuarios_cargados; i++){
        printf("\n ================================= \n");
        printf("\n Verificando al usuario nro %i",i + 1);
        strcpy(password_usuario,usuarios[i].password);
        usuarios[i].accion = valida_clave(password_usuario,caracteres_no_validos);
    }

    printf("\n *** Verificaciones completadas *** \n");
}

int valida_clave(char *password_usuario, char *caracteres_no_validos){
    int longitud_clave,longitud_carac_no_validos,flag = 0,detectar_caracter_no_valido = 0,pos = 0,i,j,contador_numeros = 0;
    char caracter;

    longitud_clave = strlen(password_usuario);
    longitud_carac_no_validos = strlen(caracteres_no_validos);

    if(longitud_clave >= 16 && longitud_clave <= 30){
        Sleep(1000);
        printf("\n * Longitud valida * \n");

        for(i = 0; i < longitud_clave; i++){
            caracter = password_usuario[i];

            do{
                if(caracter == caracteres_no_validos[pos]){
                    flag = 1;
                    break;
                } else{
                    pos++;
                }

            } while(pos < longitud_carac_no_validos && flag == 0);

            if(flag == 1){
                detectar_caracter_no_valido++;
                Sleep(1000);
                break;
                printf("\n x Se encontro un caracter no valido x \n");
            }
        }

        if(detectar_caracter_no_valido == 0){
            Sleep(1000);
            printf("\n * No se han detectado caracteres no validos * \n");

            for(j = 0; j < longitud_clave; j++){
                if(isdigit(password_usuario[j]) != 0){
                    contador_numeros++;
                }
            }

            if(contador_numeros >= 3){
                Sleep(1000);
                printf("\n * Cantidad permitida * \n ");
                return 0;
            } else{
                Sleep(1000);
                printf("\n x Poca cantidad de caracteres x \n");
                return 1;
            }

        } else{
            Sleep(1000);
            printf("\n x Se han detectado caracteres no validos x \n");
            return 1;
        }


    } else{
        Sleep(1000);
        printf("\n x Longitud no valida x \n");
        return 1;
    }
}

void envia_mail(struct usuario *usuarios, int cantidad_usuarios_cargados){
    int i;
    printf("\n");
    printf("\n **************************************************************** \n");
    printf("\n Listado de los usuarios forzados a cambiar la clave \n");
    printf("\n Nombre de usuario\t Mail\t Codigo de usuario \n");
    for(i = 0; i < cantidad_usuarios_cargados; i++){
        if(usuarios[i].accion == 1){
            printf("\n %s\t %s\t %s\n",usuarios[i].nom_usu,usuarios[i].mail,usuarios[i].cod_usu);
        }
        printf("\n");
    }
}
