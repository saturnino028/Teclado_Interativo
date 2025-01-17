#include <stdio.h>
#include "pico/stdlib.h"


#define LED_G       11 //LED verde
#define LED_B       12 //LED Azul
#define LED_R       13 //LED Vermelho
#define buzzer_pin  21 //Buzzer A da BitDog

//definição dos pinos do teclado matricial
#define lins 4
#define cols 4

//vetores pinos teclado
const uint8_t lin_pins[lins] = {8,7,6,5};
const uint8_t col_pins[cols] = {4,3,2,1};

//prototipo de funções
void iniciar_pinos();
char ler_teclado();
void som_buz(uint16_t freq, uint16_t duration_ms);

//Funções
int main() {
  stdio_init_all();
  iniciar_pinos();

    while (true) 
    {
        //Fazer leitura do teclado
        char tecla = ler_teclado();

        //Verificar a ação a ser adotada
        switch (tecla)
        {
        case '1':
            som_buz(261, 500); // Frequência da nota dó e duração de 0,5 segundo
            break;
        case '2':
            /* code */
            break;
        case '3':
            /* code */
            break;
        case '4':
            /* code */
            break;
        case '5':
            /* code */
            break;
        case '6':
            /* code */
            break;
        case '7':
            /* code */
            break;
        case '8':
            /* code */
            break;
        case '9':
            /* code */
            break;
        case '0':
            /* code */
            break;
        case 'A':
            gpio_put(LED_G, 1); // Acende o LED verde
            break;
        case 'B':
            /* code */
            break;
        case 'C':
            /* code */
            break;
        case 'D':
            /* code */
            break;
        case '*':
            /* code */
            break;
        case '#':
            /* code */
            break;
        default:
            break;
        }

    sleep_ms(100);
  }
}

void iniciar_pinos(){

    //Iniciar buzzer
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT);

    //Iniciar LEDs
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);

    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);

    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);

  for(int i = 0; i<cols; i++)
  {
    gpio_init(col_pins[i]);
    gpio_set_dir(col_pins[i], GPIO_OUT);
    gpio_put(col_pins[i], 0);
  }

  for(int i = 0; i<lins; i++)
  {
    gpio_init(lin_pins[i]);
    gpio_set_dir(lin_pins[i], GPIO_IN);
    gpio_pull_down(lin_pins[i]);
  }
}

char ler_teclado(){
  //mapa de teclas do teclado
  const char key_map[lins][cols] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
  };

  for(int col = 0; col<cols; col++)
  {
    gpio_put(col_pins[col], 1);
    for(int row= 0; row<lins; row++)
    {
      if(gpio_get(lin_pins[row]))
      {
        gpio_put(col_pins[col], 0);
        return key_map[row][col];
      }
    }
    gpio_put(col_pins[col], 0);
  }
  return '\0';
}

void som_buz(uint16_t freq, uint16_t duration_ms)
{
    uint period = 1000000 / freq;  // Período do sinal em microssegundos
    uint cycles = (duration_ms * 1000) / period;  // Número de ciclos a gerar

    for (uint i = 0; i < cycles; i++) 
    {
        gpio_put(buzzer_pin, 1);  // Liga o buzzer
        sleep_us(period / 2);  // Espera metade do período
        gpio_put(buzzer_pin, 0);  // Desliga o buzzer
        sleep_us(period / 2);  // Espera metade do período
    }

}