# C

void retorno(){                                     //Nome da função utilizada para retorno para uma tela anterior
    int i;
    printf("Retornando aguarde...");
    for(i = 1; i< 4; i++){									        //Contagem para prosseguir/retornar a proxima etapa
            printf("%d...", i);
            sleep(1);
        }
}
