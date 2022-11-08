#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Cabecalho do jogo
  printf("**********************************\n");
  printf("*Bem-vindo ao Jogo de Adivinhação*\n");
  printf("**********************************\n");

  // fazendo o rand
  int segundos = time(0);
  srand(segundos);
  int num_grande = rand();
  int num_secreto = num_grande % 100;  // de 0 ate 99;
  printf("%d", num_secreto);

  
  int chances = 0, tentativas = 1, chute, nivel;
  float pontos_perdidos = 0, pontos = 1000;

  printf("\n\nEscolha o nível que você deseja:\n");
  printf("1 - fácil\n2 - Médio\n3 - Difícil\n");
  printf("\n\nDigite o nível que você deseja: ");
  
  scanf("%d", &nivel);

  switch(nivel){

    case 1:
      chances =30;
      break;
    case 2: 
      chances =20;
      break;
    case 3: 
      chances =10;
      break;
    default: 
      chances =3;
      break;
  }
  

  while(tentativas <= chances) {

    printf("\n\nDigite um número: ");
    scanf("%d", &chute);

    if(chute == num_secreto){
      printf("\n*******************************");
      printf("\n*Parabéns, você acertou! (ᵔᵕᵔ)* ");
      printf("\n*******************************");
      break;
    }
    else{
      printf("\n*********************");
      printf("\n*Você errou. (ಥ﹏ಥ) *");
      printf("\n*********************\n");

      if (chute > num_secreto){
      printf("\n******************************************");
      printf("\n*Seu chute foi maior que o número secreto*");
      printf("\n******************************************\n");
      }
      else if(chute < num_secreto) {
        printf("\n******************************************");
      printf("\n*Seu chute foi menor que o número secreto*");
      printf("\n******************************************\n");
      }
      // como pegar o valor absoluto abs
      pontos_perdidos = (abs)((chute - num_secreto)/(float)2);

      pontos = pontos - pontos_perdidos;
    }
    if(tentativas == chances) {
      printf("\n\nvc perdeu :( \n\n");
      printf("\nTotal de pontos: %.2f", pontos);
    }
    else{
    printf("\nTotal de pontos: %.2f", pontos);
    printf("\n\nRestam %d chances. ʕ•ᴥ•ʔ", chances - tentativas);}
    
    tentativas++;
    
  }

  


}