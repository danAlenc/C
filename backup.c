#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


void cadastros(){														//Função para cadastros de cliente e colaboradores
    char op; 															// Variavel da seleção de opções do usuario
    char i; 															// Contador do FOR para animação de saida de tela
    char idade[20]; 													//Variavel ao qual será atribuida a idade do cliente/funcionario
    char salario[10]; 													//Variavel ao qual será atribuida o salario do funcionario
    char nome[10]; 														//Variavel ao qual será atribuida o nome do cliente/funcionario
    system("cls"); 														// Limpa  a tela para seguir para a proxima etapa
    fflush (stdin); 													// Limpa os dados do teclado
    printf("--------Central de Cadastros--------\n\n"); 				// Tela de bem vindo da Fnção de cadastros
    printf("1) Cadastrar Funcionario\n");								// Opção para cadastrar funcionario
    printf("2) Cadastrar Cliente\n"); 									// Opção para cadastrar cliente
    printf("0) Sair\n"); 												// Opção para retornar a tela anterior
    scanf("%d", &op); 													//Aguarda a entrada do usuario com a opção desejada
    if(op == 1){ 														// Valida a opção selecionada
        FILE *func; 												    // referencia o arquivo
        func = fopen("func.db", "a"); 								    // Abre o arquivo descrito em modo de incremento
        if(func == NULL){                                         	    // Valida se o arquivo foi aberto com sucesso,
            printf("Erro no arquivo!");							 	    //caso não, da o aviso de erro
            system("pause");										    //Pausa a mensagem na tela do cliente, aguardando o mesmo confirma com alguma tecla
            exit(main());											    //Retorna para o menu principal
        }
        system("cls");										    	    //Limpa a tela para seguir para a proxima etapa
        fflush (stdin);											        //Limpa os dados do teclado
        printf("\nDigite o nome do Funcionario:\n");			        //Pergunta o nome do Funcionario a ser cadastrado
        scanf("%s", &nome);										        //Aguarda o usuario entrar com os dados
        printf("\nDigite a idade do Funcionario:\n");			        //Pergunta a idade do funcionario
        scanf("%s", &idade);									        //Aguarda o usuario entrar com os dados
        printf("\nDigite o salario do Funcionario:\n");			        //Pergunta o salario do funcionario
        scanf("%s", &salario);									        //Aguarda o usuario entrar com os dados
        fprintf(func, "%s,%s,%s\n", nome, idade,salario);		        //Guarda as entradas do usuario no arquivo externo
        fclose(func);
        system("cls");											        //Fecha o arquivo para salvar os dados sem erros
        printf("Cadastro feito com Sucesso!\n");				        //Avisa o usuario que os dados foram salvos
        printf("Aguarde...");									        //Mensagem exibida para o usuario de saindo
        for(i = 1; i< 4; i++){									        //Contagem para prosseguir a proxima etapa
            printf("%d...", i);
            sleep(1);
        }
        fflush (stdin);												    //Limpa os dados do teclado que ficaram na memoria
        return(cadastros());										    //Retorna ao menu de cadastros
    }
    if(op == 2){														// O mesmo processo acima se repete, mudando o local de salvamento
        FILE *func;													    //e uma pergunta que foi retirada
        func = fopen("client.db", "a");
        if(func == NULL){
            printf("Erro no arquivo!");
            system("pause");
            exit(main());
        }
        system("cls");
        printf("\nDigite o nome do Cliente:\n");
        scanf("%s", &nome);
        printf("\nDigite a idade do Cliente:\n");
        scanf("%s", &idade);
        fprintf(func, "%s,%s\n", nome, idade);
        fclose(func);
        system("cls");
        printf("Cadastro feito com Sucesso!\n");
        printf("Aguarde...");
        for(i = 1; i< 4; i++){
            printf("%d...", i);
            sleep(1);
        }
        fflush (stdin);
        return(cadastros());
    }
    if(op == 0){														//Valida a opção
        system("cls");
        printf("Retornando, ");					                        //Exibe que irá retornar ao menu principal
        printf("aguarde...");										    //Processo de animaçao do aguarde
        for(i = 1; i< 4; i++){
            printf("%d...", i);
            sleep(1);
        }
    }
    fflush (stdin);													    //Limpa os dados do teclado antes de retornar
    exit(main());													    //Retornaao menu principal
}
void financeiro(){														//Função para atividades relacionadas ao controle financeiro
    int op;																//Variavel da seleção de opções do usuario
    float nvl;															//Variavel atribuida para o valor a soma no saldo
    int i;																//Contador do for
	float b;															//Variavel da conversão de char para float
    float c;															//Variavel de soma do saldo anterior com o informado pelo usuario
    char arqir[100];                                                    //Variavel da coleta de informações do arquivo externo
	char dateStr[9];														//Variavel de armazenamento da data
	system("cls");														//Limpa a tela anterior para mostrar a nova
    fflush(stdin);														//Limpa os dados do teclado que haviam
    printf("--------Central Financeira--------\n\n");					//Tela de boas vindas
    printf("1) Controle de gastos\n");
    printf("2) Consultar Saldo\n");
    printf("0) Sair\n");
    scanf("%d", &op);													//Aguarda a entrada do usuario com a opção desejada
    if(op == 1){														//Valida a opção do usuario
        system("cls");													//Limpa a tela anterior
        fflush(stdin);													//Limpa os dados da ultima etapa do teclado
        printf("---------Controle de gastos---------\n\n");				//Tela que o usuario irá informar o lucro ou divida
        printf("1) Informar lucro\n");
        printf("2) Informar divida\n");
        printf("0) Sair\n");
        scanf("%d", &op);												//Aguarda a entrada do usuario com a opçao desejada
        if(op ==1){														//valida a opçao do usuario
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
			system("pause");										    //Aguarda a confirmação do usuario para prosseguir
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
                printf("\nRetornando, aguarde...");					    //retorna ao financeiro
                for(i = 1; i< 4; i++){
                    printf("%d...", i);
                    sleep(1);
                }
                return(financeiro());
            }
            b = atof(arqir);											//Conversão de CHAR para float para efetuar soma do saldo
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
            fprintf(rendm,"%2.f %s\n", nvl, dateStr);						//escreve no arquivo a entrada do usuario + a data do dia que foi feito
			fclose(rendm);												//fecha o arquivo
			printf("\nRetornando, aguarde...");     					//Retorna ao menu do financeiro
			for(i = 1; i< 4; i++){
			printf("%d...", i);
			sleep(1);
			}
			return(financeiro());
         }
         if(op == 2){													//Valida a opção do usuario
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
                printf("Valor a quitar INVALIDO! Verifique!");			//retorna que o valor é invalido
                system("pause");
                printf("\nRetornando, aguarde...");					    //retorna ao financeiro
                for(i = 1; i< 4; i++){
                    printf("%d...", i);
                    sleep(1);
                }
            return(financeiro());
            }
            if(j < nvl){
                fprintf(rendm,"%2.f", j);
                fclose(rendm);                                                    //Valida se o saldo lido é suficiente para pagar a divida
                system("cls");
                printf("SALDO INSUFICIENTE PARA PAGAMENTO! VERIFIQUE!\n");
                system("pause");
                printf("\nRetornando, aguarde...");
                for(i = 1; i< 4; i++){
                    printf("%d...", i);
                    sleep(1);
                }
            return(financeiro());
            }
            if(j >= nvl){ 												//Valida se o saldo é maior que a divida para pagamento
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
				fprintf(rendm,"%2.f %s\n", nvl, dateStr);					//escreve no arquivo a entrada do usuario + a data do dia que foi feito
				fclose(rendm);
				printf("\nRetornando, aguarde...");					//Retorna para o menu do Financeiro
				for(i = 1; i< 4; i++){
                    printf("%d...", i);
                    sleep(1);
                }
            return(financeiro());
            }
        return(financeiro());
        }
        if(op == 0){
            printf("\nRetornando, aguarde...");							    //retorna ao financeiro
            for(i = 1; i< 4; i++){
                printf("%d...", i);
                sleep(1);
            }
            return(financeiro());
        }
    }
    if(op ==2){															//Valida a opção do usuario
        system("cls");
        fflush(stdin);
        printf("---------Consultar Saldo---------\n\n");
		FILE *rendm;
		rendm = fopen("rendm.db", "r");									//Abre o arquivo em modo de leitura
        if(rendm == NULL){
            printf("Erro no arquivo [ir]\n");
            system("pause");
            return(financeiro());
        }
        fflush(stdin);
        fgets(arqir, 100, rendm);
		float g = atof(arqir);
        printf("Seu Saldo é de: %.2f\n\n", g);						    //Mostra o saldo para o usuario
        system("pause");												//Aguarda entrada no teclado para continuar
        fclose(rendm);
        printf("\nRetornando, aguarde...");							    //retorna ao financeiro
        for(i = 1; i< 4; i++){
            printf("%d...", i);
            sleep(1);
        }
        return(financeiro());
    }
    if(op == 0){														//Valida a opção do usuario
       system("cls");
       printf("Retornando, aguarde...");							    //retorna ao menu principal
       for(i = 1; i< 4; i++){
            printf("%d...", i);
            sleep(1);
       }
        return(main());
    }
}
void relatorios(){														//Função para relatorios serem executados
    system("cls");
    fflush(stdin);
    int op;
    int i;
    char arqir[100];
	char fin1[100];
	char fin2[100]
    printf("--------Relatorios--------\n\n");
    printf("1) Historico de dividas pagas\n");
    printf("2) Historico de saldos informados\n");
    printf("3) Funcionarios cadastrados\n");
    printf("4) Clientes cadastrados\n");
    printf("0) Sair\n");
    scanf("%d", &op);
    if(op == 1){
        system("cls");
        FILE *rendm;
        rendm = fopen("historyDF.db", "r");                                 //Abre o arquivo em modo leitura
        if(rendm == NULL){
            printf("Erro no arquivo [ir]\n");
            system("pause");
            return(relatorios());
        }
        printf("----------Historico de Dividas----------\n");
        printf("Primeira coluna VALOR\nSegunda coluna DATA\n");
        printf("----------------------------------------\n");
        while(fgets(arqir, 100, rendm)!= NULL){;
            printf("%s", arqir);                                                //Motra o relatorio para o usuario
        }
        system("pause");
        fclose(rendm);													   //fecha o arquivo
        printf("Retornando, aguarde...");							        //retorna ao menu principal
        for(i = 1; i< 4; i++){
            printf("%d...", i);
            sleep(1);
        }
        return(relatorios());
    }
    if(op == 2){
        system("cls");
        FILE *rendm;
        rendm = fopen("historyF.db", "r");                                 //Abre o arquivo em modo leitura
        if(rendm == NULL){
            printf("Erro no arquivo [ir]\n");
            system("pause");
            return(relatorios());
        }
        printf("----------Historico de Saldos-----------\n");
        printf("Primeira coluna VALOR\nSegunda coluna DATA\n");
        printf("----------------------------------------\n");
        while(fgets(arqir, 100, rendm)!= NULL){;
            printf("%s", arqir);                                            //Motra o relatorio para o usuario
        }
        system("pause");
        fclose(rendm);                                                      //fecha o arquivo
        printf("Retornando, aguarde...");							    //retorna ao menu principal
        for(i = 1; i< 4; i++){
            printf("%d...", i);
            sleep(1);
        }
        return(relatorios());
    }
    if(op == 3){
        system("cls");
        FILE *rendm;
        rendm = fopen("func.db", "r");                                      //Abre o arquivo em modo leitura
        if(rendm == NULL){
            printf("Erro no arquivo [ir]\n");
            system("pause");
            return(relatorios());
        }
        printf("----------Historico de Funcionarios----------\n");
        printf("Separado por virgula NOME -- IDADE -- SALARIO\n");
        printf("---------------------------------------------\n");
        while(fgets(arqir, 100, rendm)!= NULL){;
            printf("%s", arqir);                                             //Motra o relatorio para o usuario
        }
        system("pause");
        fclose(rendm);													     //fecha o arquivo
        printf("Retornando, aguarde...");							    //retorna ao menu principal
        for(i = 1; i< 4; i++){
            printf("%d...", i);
            sleep(1);
        }
        return(relatorios());
    }
    if(op == 4){
        system("cls");
        FILE *rendm;
        rendm = fopen("client.db", "r");                                     //Abre o arquivo em modo leitura
        if(rendm == NULL){
            printf("Erro no arquivo [ir]\n");
            system("pause");
            return(relatorios());
        }
        printf("----------Historico de Clientes-----------\n");
        printf("separado por virgula NOME -- IDADE\n");
        printf("------------------------------------------\n");
        while(fgets(arqir, 100, rendm)!= NULL){;
            printf("%s", arqir);                                              //Motra o relatorio para o usuario
        }
        system("pause");
        fclose(rendm);													      //fecha o arquivo
        printf("Retornando, aguarde...");							    //retorna ao menu principal
        for(i = 1; i< 4; i++){
            printf("%d...", i);
            sleep(1);
        }
        return(relatorios());
    }
	 if(op == 5){
        system("cls");
        FILE *rendm;
        rendm = fopen("historyF.db", "r");                                 //Abre o arquivo em modo leitura
        if(rendm == NULL){
            printf("Erro no arquivo [ir]\n");
            system("pause");
            return(relatorios());
        }
        printf("----------Historico de Saldos X Dividas-----------\n");
        printf("Primeira coluna VALOR\nSegunda coluna DATA\n");
        printf("----------------------------------------\n");
        while(fgets(fin1, 100, rendm)!= NULL){;
            printf("%s", fin2);                                            //Motra o relatorio para o usuario
        }
        system("pause");
        fclose(rendm);                                                      //fecha o arquivo
        printf("Retornando, aguarde...");							    //retorna ao menu principal
        for(i = 1; i< 4; i++){
            printf("%d...", i);
            sleep(1);
        }
        return(relatorios());
    }
    if(op == 0){
        system("cls");
        printf("\nRetornando, Aguarde...");
        for(i = 1; i< 4; i++){
           printf("%d...", i);
           sleep(1);
        }
        return(main());
    }
    if(op > 4){
        printf("Opção invalida! Verifique!");
        system("pause");
        return(relatorios());
    }
    if(op < 0){
        printf("Opção invalida! Verifique!");
        system("pause");
        return(relatorios());
    }
}
int main(){																//Função principal
    setlocale(LC_ALL, "Portuguese_Brazil");								//Define a localição para não haver erros ao compilar
    int op;
    int i;
    while(op != 4){														//Tela de bem vindo em laço até o usuario optar por sair do sistema
        fflush (stdin);
        system("cls");
        printf("\n------------------------------------------\n");
        printf("\n-----------------Bem Vindo----------------\n");
        printf("\n------------------------------------------\n");
        printf("\n\n---------Digite a opção desejada----------\n\n");
        printf("\n1) Cadastros\n");
        printf("2) Financeiro\n");
        printf("3) Relatorios\n");
        printf("4) Sair\n");
        scanf("%d", &op);
        if(op == 1){ 														//chama função de cadastros
            cadastros();
        }
        if(op == 2){ 														//chama função do financeiro
            financeiro();
        }
        if(op == 3){ 														//chama função de relatorios
            relatorios();
        }
        if(op == 4){ 														//Sair do sistema
            system("cls");
            printf("Saindo...");
            printf("Aguarde...");
            for(i = 1; i< 4; i++){
                printf("%d...", i);
                sleep(1);
           }
            exit(0);
        }
        if(op >4){ 															//Tratamento para o caso do cliente digitar opção invalida
            printf("\nOpção invalida! Verifique..\n");
            system("pause");
            system("cls");
        }
        if(op <1){ 															//Tratamento para o caso do cliente digitar opção invalida
            printf("\nOpção invalida! Verifique..\n");
            system("pause");
            system("cls");
        }
    }
    return 0;
}
