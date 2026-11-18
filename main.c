#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "bib_hasharvre.h"
#include "bib_lest.h"

int main()
{
  int op; 
  do
  {
    printf("Digite a opção desejada:");
    scanf("%d",&op);
  switch (op)
  {
    case 1:
      printf("----------------------------- Cadastrar Equipamento -----------------------------");
    break;
    case 2:
      printf("----------------------------- Registrar Incidente -----------------------------");
    break;
    case 3:
      printf("----------------------------- Consultar Equipamento e Incidente -----------------------------");
    break;
    case 4:
      printf("----------------------------- Listar todos os Incidentes -----------------------------");
    break;
    case 5:
      printf("----------------------------- Excluir um Incidente -----------------------------");
    break;
    case 6:
      printf("----------------------------- Excluir um Equipamento -----------------------------");
    break;
    case 7:
      printf("----------------------------- Encerrar Programa -----------------------------");
    break;
    default:
      printf("Opção inválida. Tente novamente!");
    break;
  }
  }while(op!=7);
}
