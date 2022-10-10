#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void retorno(){
    int i;
    printf("Retornando aguarde...");
    for(i = 1; i< 4; i++){									        //Contagem para prosseguir a proxima etapa
            printf("%d...", i);
            sleep(1);
        }
}
void cadastros(){														//Fun��o para cadastros de cliente e colaboradores
    char op; 															// Variavel da sele��o de op��es do usuario
    char i; 															// Contador do FOR para anima��o de saida de tela
    char idade[20]; 													//Variavel ao qual ser� atribuida a idade do cliente/funcionario
    char salario[10]; 													//Variavel ao qual ser� atribuida o salario do funcionario
    char nome[10]; 														//Variavel ao qual ser� atribuida o nome do cliente/funcionario
    system("cls"); 														// Limpa  a tela para seguir para a proxima etapa
    fflush (stdin); 													// Limpa os dados do teclado
    printf("--------Central de Cadastros--------\n\n"); 				// Tela de bem vindo da Fn��o de cadastros
    printf("1) Cadastrar Funcionario\n");								// Op��o para cadastrar funcionario
    printf("2) Cadastrar Cliente\n"); 									// Op��o para cadastrar cliente
    printf("0) Sair\n"); 												// Op��o para retornar a tela anterior
    scanf("%d", &op); 													//Aguarda a entrada do usuario com a op��o desejada
    if(op == 1){ 														// Valida a op��o selecionada
        FILE *func; 												    // referencia o arquivo
        func = fopen("func.db", "a"); 								    // Abre o arquivo descrito em modo de incremento
        if(func == NULL){                                         	    // Valida se o arquivo foi aberto com sucesso,
            printf("Erro no arquivo!");							 	    //caso n�o, da o aviso de erro
            system("pause");										    //Pausa a mensagem na tela do cliente, aguardando o mesmo confirma com alguma tecla
            exit(inicio());											    //Retorna para o menu principal
        }
        system("cls");										    	    //Limpa a tela para seguir para a proxima etapa
        fflush (stdin);											        //Limpa os dados do teclado
        printf("\nDigite o nome do Funcionario:\n");			        //Pergunta o nome do Funcionario a ser cadastrado
        scanf("%s", &nome);										        //Aguarda o usuario entrar com os dados
        printf("\nDigite a idade do Funcionario:\n");			        //Pergunta a idade do funcionario
        scanf("%s", &idade);									        //Aguarda o usuario entrar com os dados
        printf("\nDigite o salario do Funcionario:\n");			        //Pergunta o salario do funcionario
        scanf("%s", &salario);									        //Aguarda o usuario entrar com os dados
        fprintf(func, "%s,\t %s,\t %s\n", nome, idade,salario);		        //Guarda as entradas do usuario no arquivo externo
        fclose(func);
        system("cls");											        //Fecha o arquivo para salvar os dados sem erros
        printf("Cadastro feito com Sucesso!\n");				        //Avisa o usuario que os dados foram salvos
        retorno();									                    //chama fun��o de conagem regressiva para menu anterior
        fflush (stdin);												    //Limpa os dados do teclado que ficaram na memoria
        return(cadastros());										    //Retorna ao menu de cadastros
    }
    if(op == 2){														// O mesmo processo acima se repete, mudando o local de salvamento
        FILE *func;													    //e uma pergunta que foi retirada
        func = fopen("client.db", "a");
        if(func == NULL){
            printf("Erro no arquivo!");
            system("pause");
            exit(inicio());
        }
        system("cls");
        printf("\nDigite o nome do Cliente:\n");
        scanf("%s", &nome);
        printf("\nDigite a idade do Cliente:\n");
        scanf("%s", &idade);
        fprintf(func, "%s,\t %s\n", nome, idade);
        fclose(func);
        system("cls");
        printf("Cadastro feito com Sucesso!\n");
        retorno();
        fflush (stdin);
        return(cadastros());
    }
    if(op == 0){														//Valida a op��o
        system("cls");
        retorno();
        fflush (stdin);													//Limpa os dados do teclado antes de retornar
        exit(inicio());													//Retorna ao  menu principal
    }
    if(op > 2 || op < 0){                                               //Tratamento para o caso do cliente digitar op��o invalida
        printf("Op��o invalida! Verifique!\n");
        system("pause");
        return(cadastros());
    }
}
void financeiro(){														//Fun��o para atividades relacionadas ao controle financeiro
    int op;																//Variavel da sele��o de op��es do usuario
    float nvl;															//Variavel atribuida para o valor a soma no saldo
    int i;																//Contador do for
	float b;															//Variavel da convers�o de char para float
    float c;															//Variavel de soma do saldo anterior com o informado pelo usuario
    char arqir[100];                                                    //Variavel da coleta de informa��es do arquivo externo
	char dateStr[9];													//Variavel de armazenamento da data
	system("cls");														//Limpa a tela anterior para mostrar a nova
    fflush(stdin);														//Limpa os dados do teclado que haviam
    printf("--------Central Financeira--------\n\n");					//Tela de boas vindas
    printf("1) Controle de gastos\n");
    printf("2) Consultar Saldo\n");
    printf("0) Sair\n");
    scanf("%d", &op);													//Aguarda a entrada do usuario com a op��o desejada
    if(op == 1){														//Valida a op��o do usuario
        system("cls");													//Limpa a tela anterior
        fflush(stdin);													//Limpa os dados da ultima etapa do teclado
        printf("---------Controle de gastos---------\n\n");				//Tela que o usuario ir� informar o lucro ou divida
        printf("1) Informar lucro\n");
        printf("2) Informar divida\n");
        printf("0) Sair\n");
        scanf("%d", &op);												//Aguarda a entrada do usuario com a op�ao desejada
        if(op ==1){														//valida a op�ao do usuario
            system("cls");												//Limpa a tela anterior
			fflush(stdin);												//Limpa os dados da ultima etapa do teclado
            printf("-----------Informar Lucro-----------\n\n");
            FILE *rendm;
            rendm = fopen("rendm.db", "r");								//Abre o arquivo descrito em modo de leitura para capturar saldo do usuario no arquivo
            if(rendm == NULL){											//valida se o arquivo foi aberto com sucesso
                printf("Erro no arquivo [ir]\n");
                system("pause");
                return(financeiro());
            }
			fflush(stdin);
			fscanf(rendm, "%[^\n]s", arqir);							//Captura o que estava dentro do arquivo e salva na variavel arqir
			float h = atof(arqir);
			printf("Saldo Atual: %.2f\n\n", h);					        //Mostra o saldo atual para o usuario
			system("pause");										    //Aguarda a confirma��o do usuario para prosseguir
			fclose(rendm);
            rendm = fopen("rendm.db", "w");								//Abre o arquivo em modo de reescrita
            if(rendm == NULL){
                fclose(rendm);
                printf("Erro no aquivo[ire]\n");
                system("pause");
                return(financeiro());
            }
            system("cls");
            fflush(stdin);
            printf("\nQual o novo valor a somar?\n");					//Pergunta o valor a se somar
            scanf("%f", &nvl);											//Aguarda a entrada do usuario
            if(nvl <= 0){
                fprintf(rendm,"%2.f", h);
                fclose(rendm);
                system("cls");
                printf("Valor INVALIDO! Verifique!\n");
                system("pause");
                retorno();
                return(financeiro());
            }
            b = atof(arqir);											//Convers�o de CHAR para float para efetuar soma do saldo
            c = b + nvl;												//Soma do saldo anterior com a entrada do usuario
            fprintf(rendm,"%f", c);                                     //Escreve no arquivo o valor somado
            system("cls");
            printf("\n\nAdicionado SALDO com sucesso!\n\n");			//Informa que foi salvo com sucesso
            fclose(rendm);												//Fecha o arquivo
			rendm = fopen("historyF.db", "a");							//Abre o arquivo de historico de entradas em modo incremento
            if(rendm == NULL){											//Valida se foi aberto
                printf("Erro no aquivo[HF]\n");
                system("pause");
                return(financeiro());
            }
			_strdate( dateStr);											//captura a data do computador
            fprintf(rendm,"%2.f\t %s\n", nvl, dateStr);						//escreve no arquivo a entrada do usuario + a data do dia que foi feito
			fclose(rendm);												//fecha o arquivo
			retorno();
			return(financeiro());
         }
         if(op == 2){													//Valida a op��o do usuario
            system("cls");
            fflush(stdin);
            printf("-----------Informar Divida-----------\n\n");
            FILE *rendm;
            rendm = fopen("rendm.db", "r");								//Abre o arquivo em modo leitura
            if(rendm == NULL){
                printf("Erro no arquivo [ir]\n");
                system("pause");
                return(financeiro());
            }
            fflush(stdin);
            fgets(arqir, 100, rendm);
			float j = atof(arqir);                                      //converte char para float
            printf("Saldo Atual: %.2f\n\n", j);						    //Mostra o saldo atual para o usuario
            system("pause");
            fclose(rendm);												//fecha o arquivo
            rendm = fopen("rendm.db", "w");								//Abre o arquivo em modo de reescrita
            if(rendm == NULL){
                printf("Erro no aquivo[ire]\n");
                system("pause");
                retorno();
                return(financeiro());
            }
            system("cls");
            printf("\nQual o valor da divida a quitar?\n"); 			//Pergunta o valor da divida a debitar
            fflush(stdin);
            scanf("%f", &nvl);											//Aguarda  a entrada do usuario
            if(nvl <= 0){												//Valida se o valor informado for menor ou igual a 0
                fprintf(rendm,"%2.f", j);
                fclose(rendm);
                system("cls");
                printf("Valor a quitar INVALIDO! Verifique!");			//retorna que o valor � invalido
                system("pause");
                printf("\nRetornando, aguarde...");					    //retorna ao financeiro
                retorno();
                return(financeiro());
            }
            if(j < nvl){
                fprintf(rendm,"%2.f", j);
                fclose(rendm);                                          //Valida se o saldo lido � suficiente para pagar a divida
                system("cls");
                printf("SALDO INSUFICIENTE PARA PAGAMENTO! VERIFIQUE!\n");
                system("pause");
                printf("\nRetornando, aguarde...");
                retorno();
                return(financeiro());
            }
            if(j >= nvl){ 												//Valida se o saldo � maior que a divida para pagamento
                c =j-nvl;											    //Diminui o valor da divida do saldo
                fprintf(rendm,"%2.f", c);								//Grava no arquivo o novo saldo
                system("cls");
                printf("\nEfetuando pagamento, aguarde...");     		//Retorna ao menu do financeiro
                for(i = 1; i< 4; i++){
                    printf("%d...", i);
                    sleep(1);
                }
                printf("\n\nDivida paga com SUCESSO!\n\n");				//Informa o usuario que a divida foi paga
                system("pause");
                fclose(rendm);
				rendm = fopen("historyDF.db", "a");						//Abre o arquivo de historico de entradas em modo incremento
				if(rendm == NULL){										//Valida se foi aberto
					printf("Erro no aquivo[HDF]\n");
					system("pause");
					return(financeiro());
				}
				_strdate( dateStr);										//captura a data do computador
				fprintf(rendm,"%2.f\t %s\n", nvl, dateStr);					//escreve no arquivo a entrada do usuario + a data do dia que foi feito
				fclose(rendm);
				printf("\nRetornando, aguarde...");					//Retorna para o menu do Financeiro
				retorno();
                return(financeiro());
            }
        return(financeiro());
        }
        if(op == 0){
            retorno();
            return(financeiro());
        }
        if(op > 2 || op < 0){                                               //Tratamento para o caso do cliente digitar op��o invalida
        printf("Op��o invalida! Verifique!\n");
        system("pause");
        return(financeiro());
        }
    }
    if(op ==2){															//Valida a op��o do usuario
        system("cls");
        fflush(stdin);
        printf("---------Consultar Saldo---------\n\n");
		FILE *rendm;
		rendm = fopen("rendm.db", "r");									//Abre o arquivo em modo de leitura
        if(rendm == NULL){
            printf("Erro no arquivo [ir]\n");
            system("pause");
            retorno();
            return(financeiro());
        }
        fflush(stdin);
        fgets(arqir, 100, rendm);
		float g = atof(arqir);
        printf("Seu Saldo � de: %.2f\n\n", g);						    //Mostra o saldo para o usuario
        system("pause");												//Aguarda entrada no teclado para continuar
        fclose(rendm);
        retorno();
        return(financeiro());
    }
    if(op == 0){														//Valida a op��o do usuario
       system("cls");
       retorno();
       return(inicio());
    }
    if(op > 2 || op < 0){                                               //Tratamento para o caso do cliente digitar op��o invalida
        printf("Op��o invalida! Verifique!\n");
        system("pause");
        return(financeiro());
    }
}
void relatorios(){														//Fun��o para relatorios serem executados
    system("cls");
    fflush(stdin);                                                      //Limpa o cache do teclado
    int op;                                                             //Variavel das op��es do usuario
    int i;                                                              //contador
    char arqir[100];                                                    //variavel de armazenamento de texto
    printf("--------Relatorios--------\n\n");                           //menu principal
    printf("1) Historico de dividas pagas\n");
    printf("2) Historico de saldos informados\n");
    printf("3) Funcionarios cadastrados\n");
    printf("4) Clientes cadastrados\n");
    printf("0) Sair\n");
    scanf("%d", &op);
    if(op == 1){                                                        //valida��o da op��o do usuario
        system("cls");
        FILE *rendm;
        rendm = fopen("historyDF.db", "r");                             //Abre o arquivo em modo leitura
        if(rendm == NULL){                                              //Valida��o do arquivo
            printf("Erro no arquivo [ir]\n");
            system("pause");
            retorno();
            return(relatorios());
        }
        printf("----------Historico de Dividas----------\n");           //Relatorio de Dividas
        printf("Primeira coluna VALOR\nSegunda coluna DATA\n");         //Orienta��o do layout
        printf("----------------------------------------\n");
        while(fgets(arqir, 100, rendm)!= NULL){;                        //La�o para que, enquanto n�o retorne vazio, continue lendo
            printf("%s", arqir);                                        //Motra o relatorio para o usuario
        }
        system("pause");
        fclose(rendm);													//fecha o arquivo
        retorno();
        return(relatorios());
    }
    if(op == 2){                                                        //valida��o da op��o do usuario
        system("cls");
        FILE *rendm;
        rendm = fopen("historyF.db", "r");                              //Abre o arquivo em modo leitura
        if(rendm == NULL){
            printf("Erro no arquivo [ir]\n");
            system("pause");
            return(relatorios());
        }
        printf("----------Historico de Saldos-----------\n");           //Relatorio de saldos informados
        printf("Primeira coluna VALOR\nSegunda coluna DATA\n");         //Orienta��o do layout
        printf("----------------------------------------\n");
        while(fgets(arqir, 100, rendm)!= NULL){;                        //La�o para que, enquanto n�o retorne vazio, continue lendo
            printf("%s", arqir);                                        //Motra o relatorio para o usuario
        }
        system("pause");
        fclose(rendm);                                                  //fecha o arquivo
        retorno();
        return(relatorios());
        }
    if(op == 3){                                                        //Valida��o da op��o do usuario
        system("cls");
        FILE *rendm;
        rendm = fopen("func.db", "r");                                  //Abre o arquivo em modo leitura
        if(rendm == NULL){
            printf("Erro no arquivo [ir]\n");
            system("pause");
            return(relatorios());
        }
        printf("----------Historico de Funcionarios----------\n");      //Relatorio de funcionarios
        printf("Separado por virgula NOME -- IDADE -- SALARIO\n");      //Orienta��o do layout
        printf("---------------------------------------------\n");
        while(fgets(arqir, 100, rendm)!= NULL){;                        //La�o para que, enquanto n�o retorne vazio, continue lendo
            printf("%s", arqir);                                        //Motra o relatorio para o usuario
        }
        system("pause");
        fclose(rendm);													//fecha o arquivo
        retorno();
        return(relatorios());
    }
    if(op == 4){                                                        //valida��o da op��o do usuario
        system("cls");
        FILE *rendm;
        rendm = fopen("client.db", "r");                                //Abre o arquivo em modo leitura
        if(rendm == NULL){
            printf("Erro no arquivo [ir]\n");
            system("pause");
            return(relatorios());
        }
        printf("----------Historico de Clientes-----------\n");         //Relatorio de clientes
        printf("separado por virgula NOME -- IDADE\n");                 //Orienta��o do layout
        printf("------------------------------------------\n");
        while(fgets(arqir, 100, rendm)!= NULL){;                        //La�o para que, enquanto n�o retorne vazio, continue lendo
            printf("%s", arqir);                                        //Motra o relatorio para o usuario
        }
        system("pause");
        fclose(rendm);													//fecha o arquivo
        retorno();
        return(relatorios());
    }
    if(op == 0){                                                        //Valida a op��o do usuario
        system("cls");
        retorno();
        return(inicio());                                                 //Retorna ao menu principal
    }
    if(op > 4 || op < 0){                                               //Tratamento para o caso do cliente digitar op��o invalida
        printf("Op��o invalida! Verifique!\n");
        system("pause");
        return(relatorios());
    }
}
void inicio(){															//Menu principal
    setlocale(LC_ALL, "Portuguese_Brazil");								//Define a locali��o para n�o haver erros ao compilar
    int op;                                                             //Variavel que armazena a op��o do usuario
    int i;                                                              //Contador
    while(op != 4){														//Tela de bem vindo em la�o at� o usuario optar por sair do sistema
        fflush (stdin);                                                 //limpa os dados do teclado
        system("cls");                                                  //Limpa os dados anteriores da tela
        printf("\n------------------------------------------\n");
        printf("\n-----------------Bem Vindo----------------\n");       //Menu Principal
        printf("\n------------------------------------------\n");
        printf("\n\n---------Digite a op��o desejada----------\n\n");
        printf("\n1) Cadastros\n");
        printf("2) Financeiro\n");
        printf("3) Relatorios\n");
        printf("4) Sair\n");
        scanf("%d", &op);
        if(op == 1){ 	    											//Valida��o da op��o do usuario
            cadastros();                                                //chama fun��o de cadastros
        }
        if(op == 2){ 													//valida��o da op��o do usuario
            financeiro();                                               //chama fun��o do financeiro
        }
        if(op == 3){ 													//Valida��o da op��o do usuario
            relatorios();                                               //chama fun��o de relatorios
        }
        if(op == 4){ 													//Valida��o do usuario
            system("cls");                                              //limpa a tela
            printf("Saindo...");                                        //Inicia contagem para saida do sistema
            printf("Aguarde...");
            for(i = 1; i< 4; i++){
                printf("%d...", i);
                sleep(1);
           }
            exit(0);                                                    //Sai do sistema
        }
        if(op > 4 || op < 1){ 											//Tratamento para o caso do cliente digitar op��o invalida
            printf("\nOp��o invalida! Verifique..\n");
            system("pause");
            system("cls");
        }
      }
}

int main(){
    char user[100];
    char us[30];
    char se[70];


    FILE *users;
    users = fopen("users.db", "r");
    if(users == NULL){
        printf("ERRO NO ARQUIVO[US]");
        system("pause");
        fclose(users);
        exit(0);
    }
    while(fgets(user, "%[^\n]s", users)!= NULL){
    }


            printf("Digite seu usuario: \n");
            scanf("%s", &us);
            printf("Digite sua senha: \n");
            scanf("%s", &se);
            strncat(us, se, 12);
            fflush(stdin);
            if(strcmp(us, user) == 0){
                printf("Logado com SUCESSO!\n");
                system("pause");
                fclose(users);
                inicio();
            }
            else{
                printf("USUARIO/SENHA INVALIDOS!\n");
                system("pause");
                fclose(users);

            }






}
