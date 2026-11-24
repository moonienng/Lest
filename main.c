#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "bib_hasharvre.h"
#include "bib_lest.h"
 
int main()
{
  EQ *TH[M];
  IniciaTH(TH);
  ABB *R = IniciaArvore();
  int op; 
  do
  {
    printf("Digite a opção desejada:");
    scanf("%d",&op);
  switch (op)
  {
    case 1:
      printf("----------------------------- Cadastrar Equipamento -----------------------------");
      /*
        1. Recebe o código único de identificação
          1.1 Verifica se o código já existe
          -> se sim, informe que já existe e encerre o case 1
          -> se não, continue
        2. Recebe o nome do equipamento
        3. Cria um novo equipamento
        4. Cálcula qual a posição que o equipamento vai ser inserido
        5. Insere na posição correta
          5.1 Verifique se a posição está vazia
            -> se sim, crie uma lista e insira o novo equipamento na primeira posição
            -> se não, insira na ultima posição
      */
     int cod;
     char neq[11];
     printf("\nDigite o Código Único de Cadastro:");
     scanf("%d",&cod); //le codigo
     printf("\nDigite o nome do equipamento:");
     fgets(neq, sizeof(neq), stdin);
     while (getchar() != '\n');
     CadastroEQ(cod,neq,TH);
     printf("\nCadastro Realizado!");
     system("pause");
    break;
    case 2:
      printf("----------------------------- Registrar Incidente -----------------------------");
      /*
        1. Recebe o número unico de identificação
          1.1 Verifica se o código já existe
          -> se sim, informe que já existe e pergunte se deseja criar um novo incidente
            -> se sim, volte a 1
            -> se não, encerre o case 2
          -> se não, continue
        2. Recebe o código do incidente
          2.1. Verifica se o código do incidente existe
          -> se não existir informe o usuário e encerre o resto da operação para que ele crie um equipamento
          -> se existir exiba as informações do equipamento e peça a confirmação se é isso mesmo que ele quer
            -> se não, peça novamente o código do incidente
            -> se sim, conttinue.
        3. Recebe a gravidade do incidente
        4. Cria um novo incidente
        5. Insere o incidente na ABB
      */
     int nui, cdu, grv;
     scanf("%d",&nui);
     scanf("%d",&cdu);
     scanf("%d",&grv);

     CadastroIC(nui,cdu,grv);
    break;
    case 3:
      printf("----------------------------- Consultar Equipamento e Incidente -----------------------------");
      
    break;
    case 4:
      printf("----------------------------- Listar todos os Incidentes -----------------------------");
      
    break;
    case 5:
      printf("----------------------------- Excluir um Incidente -----------------------------");
      /*
        1. Recebe o número de identificação do incidente
          1.1 Verifica se o número existe
          -> se não, exibe uma mensagem de erro e encerra case 5
          -> se sim, continue
        2. Exibe o incidente 
        3. Recebe confirmação
          -> se não, exibe mensagem e encerra case 5
          -> se sim, continue
        4. Exclui o incidente
      */
    break;
    case 6:
      printf("----------------------------- Excluir um Equipamento -----------------------------");
      /*
        1. Recebe um código de identificação
          1.1 Verifique se o código existe
            -> se sim, exiba o equipamento e o número de incidentes vinculados e peça confirmação
              -> se não, encerre o case 6
              -> se sim, continue
            -> se não, exiba erro e encerre o case 6;
        2. Exclua da árvore todos os incidentes com o código vinculado
        3. Exclua o Equipamento
      */
    break;
    case 7:
      printf("----------------------------- Encerrar Programa -----------------------------");
      /*
        1. Recebe confirmação
          -> se não, insere 0 em op e encerra case 7
          -> se sim, continue
        2. Apaga equipamentos (Apagar um equipamento vai apagar todos os incidentes relacionados)
        3. Libera listas
        4. Libera ABB
      */
    break;
    default:
      printf("Opção inválida. Tente novamente!");
    break;
  }
  }while(op!=7);
}
