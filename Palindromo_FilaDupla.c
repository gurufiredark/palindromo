#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

struct FD
{
    char vetor[100];
    int direita;
    int esquerda;
};

void Inicializa_FilaDupla(struct FD *D)
{
    (*D).esquerda = floor(99/2);
    (*D).direita = (*D). esquerda;
}

bool FilaDupla_Vazia (struct FD *D)
{
    return (*D).esquerda == (*D).direita;
}

bool FilaDupla_Cheia (struct FD *D)
{
    return (((*D).esquerda == -1)&&((*D).direita == 99));
}

void Insere_Esquerda_FilaDupla(struct FD *D, char x)
{
    if(FilaDupla_Cheia(&D) == false)
    {
        if((*D).esquerda == -1)
        {
            Desloca_FilaDupla(&D);
        }
        (*D).vetor[(*D).esquerda] = x;
        (*D).esquerda = (*D).esquerda - 1;
    }
    
    else
    {
        printf("Fila Dupla cheia!!");
    }
}

void Insere_Direita_FilaDupla(struct FD *D, char x)
{
    if(FilaDupla_Cheia(&D) == false)
    {
        if((*D).direita == 99)
        {
            Desloca_FilaDupla(&D);
        }
        (*D).direita = (*D).direita + 1;
        (*D).vetor[(*D).direita] = x;
    }
    else
    {
        printf("Fila Dupla cheia!!");
    }
}

void Remove_Esquerda_FilaDupla(struct FD *D, char *x)
{
    if(FilaDupla_Vazia(&D) == false)
    {
        (*D).esquerda = (*D).esquerda +1;
        *x = (*D).vetor[(*D).esquerda];
        if(FilaDupla_Vazia(&D) == true)
        {
            Inicializa_FilaDupla(&D);
        }
    }
    else
    {
        printf("Fila Dupla vazia!!");
    }
}

void Remove_Direita_FilaDupla(struct FD *D, char *x)
{
    if(FilaDupla_Vazia(&D) == false)
    {
        *x = (*D).vetor[(*D).direita];
        (*D).direita = (*D).direita - 1;
        if(FilaDupla_Vazia(&D) == true)
        {
            Inicializa_FilaDupla(&D);
        }
    }
    else
    {
        printf("Fila Dupla vazia!!");
    }
}

char Elemento_Esquerda_FilaDupla (struct FD *D)
{
    if (FilaDupla_Vazia(&D) == false)
    {
        return (*D).vetor[(*D).esquerda+1];
    }

    else
    {
        printf("Fila Dupla vazia!!");
    }
}

char Elemento_Direita_FilaDupla(struct FD *D)
{
    if (FilaDupla_Vazia(&D) == false)
    {
        return (*D).vetor[(*D).direita];
    }

    else
    {
        printf("Fila Dupla vazia!!");
    }
}

void Desloca_FilaDupla(struct FD *D)
{
    int deslocamento, i;

    if((*D).direita == 99)
    {
        deslocamento = ceil(((*D).esquerda+1)/2);

        for(i=((*D).esquerda+1); i<= (*D).direita; i++)
        {
            (*D).vetor[i-deslocamento] = (*D).vetor[i];
        }
        (*D).esquerda = (*D).esquerda - deslocamento;
        (*D).direita = (*D).direita - deslocamento;
    }
    
    else
    {
        deslocamento = ceil((99 - (*D).direita)/2);
        for(i=((*D).direita); i<= (*D).esquerda+1; i--)
        {
            (*D).vetor[i+deslocamento] = (*D).vetor[i];
        }
        (*D).esquerda = (*D).esquerda + deslocamento;
        (*D).direita = (*D).direita + deslocamento;
    }
}

void main ()
{
    struct FD D;
    char letraDir, letraEsq, x;
    int i, tamfrase, nletras;
    i=0;
    nletras = 0;
    
    char frase[100];

    printf("Programa Verificador de Palindromos \n\n");
    printf("Digite uma  palavra ou frase : \n\n");
    fgets(frase, 100, stdin);

    
    tamfrase = strlen(frase);

    frase[strlen(frase)-1] = '\0';

    Inicializa_FilaDupla(&D);

    for(i=0; i < tamfrase; i++)
    {
        if(((frase[i] >= 'A') && (frase[i] <= 'Z')) || ((frase[i] >= 'a') &&(frase[i] <= 'z')))
        {
           Insere_Direita_FilaDupla(&D, tolower(frase[i]));
           nletras++;
        }

   }

    do
    {
        letraDir = Elemento_Direita_FilaDupla(&D);
        letraEsq = Elemento_Esquerda_FilaDupla(&D);
        
                Remove_Esquerda_FilaDupla(&D, &x);
            if(!(FilaDupla_Vazia(&D)))
            {
                Remove_Direita_FilaDupla(&D, &x);
            }
           
           if(letraDir == letraEsq)
            {
               nletras = nletras - 2;
            }
    
    }while(!(FilaDupla_Vazia(&D)));

    if(nletras <= 1)
    {
        printf(" '%s' Eh um palindromo", frase);

    }
    else
    {
        printf(" '%s' Nao eh um palindromo", frase);
    }
}