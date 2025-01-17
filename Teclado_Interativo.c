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
void doh();
void re();
void mi();
void fa();
void sol();
void la();
void si();

//Funções
int main() {
  stdio_init_all();
  iniciar_pinos();

    while (true) 
    {
        //Fazer leitura do teclado
        char tecla = ler_teclado();
        if(tecla != '\0')
        {
            printf("%c", tecla);
            sleep_ms(100);
        }

        //Verificar a ação a ser adotada
        switch (tecla)
        {
        case '1':
            doh();
            break;
        case '2':
            re();
            break;
        case '3':
            mi();
            break;
        case '4':
            fa();
            break;
        case '5':
            sol();
            break;
        case '6':
            la();
            break;
        case '7':
            si();
            break;
        case '8':
            /* code */
            break;
        case '9':
            toca_jingle_bells();
            break;
        case '0':
            toca_we_wish_you();
            break;
        case 'A':
            gpio_put(LED_G, 1); // Acende o LED verde
            break;
        case 'B':
            /* code */
            break;
        case 'C':
            gpio_put(LED_R, 1); // Acende o LED vermelho
            break;
        case 'D':
            gpio_put(LED_R, 1); // Acende o LED vermelho
            gpio_put(LED_G, 1); // Acende o LED verde
            gpio_put(LED_B, 1); // Acende o LED azul
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

// Funções das notas musicais

void doh(){
    som_buz(261, 500); // Frequência da nota dó e duração de 0,5 segundo
}

void re(){
    /*code*/
}

void mi(){
    som_buz(330, 500); // Frequência da nota mi e duração de 0,5 segundo
}

void fa(){
    /*code*/
}

void sol(){
    /*code*/
}

void la(){
    /*code*/
}

void si(){
    /*code*/
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

void toca_musica(uint buzzer, int frequencia, int duracao) {
    if (frequencia == 0) {
        sleep_ms(duracao);
        return;
    }
    int half_period = 1000000 / (2 * frequencia);
    int cycles = frequency * duracao / 1000;

    for (int i = 0; i < cycles; i++) {
        gpio_put(buzzer, 1);
        sleep_us(half_period);
        gpio_put(buzzer, 0);
        sleep_us(half_period);
    }
}

void toca_jingle_bells() {
    int melody[] = {330, 330, 330, 330, 330, 330, 330, 392, 261, 294, 330, 349, 349, 349, 349, 349, 330, 330, 330, 294, 294, 330, 294, 392};
    int durations[] = {250, 250, 500, 250, 250, 500, 250, 250, 250, 250, 500, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 500, 500, 1000};
    int length = sizeof(melody) / sizeof(melody[0]);

    for (int i = 0; i < length; i++) {
        play_tone(BUZZER_PIN, melody[i], durations[i]);
        sleep_ms(100);
    }
}

void toca_we_wish_you() {
    int melody[] = {392, 330, 349, 392, 392, 392, 440, 392, 349, 330, 330, 349, 392, 330, 349, 392, 392, 349, 330, 349, 294};
    int durations[] = {500, 500, 500, 500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 1000};
    int length = sizeof(melody) / sizeof(melody[0]);

    for (int i = 0; i < length; i++) {
        play_tone(BUZZER_PIN, melody[i], durations[i]);
        sleep_ms(100);
    }
}
