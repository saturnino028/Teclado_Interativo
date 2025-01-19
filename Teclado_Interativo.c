#include <stdio.h>
#include "pico/stdlib.h"

//Definição dos pinos de GPIO
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
void natal1();
void natal2();
void natal3();
void desligar_tudo();
void ligar_tudo();
void notas();

//Funções
int main() {
  stdio_init_all();
  iniciar_pinos();

    while (true) 
    {
        //Fazer leitura do teclado
        char tecla = ler_teclado();

        //Printar a tecla pressionada
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
            natal1();
            break;
        case '9':
            natal2();
            break;
        case '0':
            natal3();
            break;
        case 'A':
            gpio_put(LED_G, 1); // Acende o LED verde
            break;
        case 'B':
            gpio_put(LED_B, 1); // Acende o LED azul
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
            desligar_tudo();
            break;
        case '#':
            ligar_tudo();
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
    som_buz(293, 500); // Frequência da nota ré e duração de 0,5 segundo
}

void mi(){
    som_buz(330, 500); // Frequência da nota mi e duração de 0,5 segundo
}

void fa(){
    som_buz(349, 500); // Frequência da nota fá e duração de 0,5 segundo
}

void sol(){
    som_buz(392, 500); // Frequência da nota sol e duração de 0,5 segundo
}

void la(){
  som_buz(440, 500); // Frequência da nota mi e duração de 0,5 segundo
}

void si(){
    som_buz(493, 500); // Frequência da nota si e duração de 0,5 segundo
}

//Noite Feliz - Natal 1
void natal1() {
    // Noite Feliz - Melodia com notas longas e curtas
    som_buz(392, 500);  // Sol
    sleep_ms(200);      // Pausa
    som_buz(440, 500);  // Lá
    sleep_ms(200);      // Pausa
    som_buz(392, 500);  // Sol
    sleep_ms(200);      // Pausa
    som_buz(330, 1200); // Mi (nota longa)
    sleep_ms(400);      // Pausa longa

    som_buz(392, 500);  // Sol
    sleep_ms(200);      // Pausa
    som_buz(440, 500);  // Lá
    sleep_ms(200);      // Pausa
    som_buz(392, 500);  // Sol
    sleep_ms(200);      // Pausa
    som_buz(330, 1200); // Mi (nota longa)
    sleep_ms(400);      // Pausa longa

    som_buz(294, 500);  // Ré
    sleep_ms(200);      // Pausa
    som_buz(294, 500);  // Ré
    sleep_ms(200);      // Pausa
    som_buz(246, 800);  // Si
    sleep_ms(200);      // Pausa
    som_buz(261, 500);  // Dó
    sleep_ms(200);      // Pausa
    som_buz(261, 500);  // Dó longa
    sleep_ms(400);      // Pausa longa
    som_buz(220, 900);  // Sol
    sleep_ms(200);      // Pausa

     som_buz(220, 400);  // Lá
    sleep_ms(200);      // Pausa
    som_buz(220, 400);  // Lá
    sleep_ms(200);      // Pausa
    som_buz(261, 400);  // Dó
    sleep_ms(200);      // Pausa
    som_buz(246, 400);  // Si
    sleep_ms(200);      // Pausa
    som_buz(220, 400);  // Lá
    sleep_ms(200);      // Pausa
    som_buz(196, 800);  // Sol
    sleep_ms(400);      // Pausa longa
    som_buz(220, 400);  // Lá
    sleep_ms(200);      // Pausa
    som_buz(196, 400);  // Sol
    sleep_ms(200);      // Pausa
    som_buz(164, 800);  // Mi
    sleep_ms(500);
    som_buz(220, 400);  // Lá
    sleep_ms(200);      // Pausa
    som_buz(220, 400);  // Lá
    sleep_ms(200);      // Pausa
    som_buz(261, 400);  // Dó
    sleep_ms(200);      // Pausa
    som_buz(246, 400);  // Si
    sleep_ms(200);      // Pausa
    som_buz(220, 400);  // Lá
    sleep_ms(200);      // Pausa
    som_buz(196, 800);  // Sol
    sleep_ms(400);      // Pausa longa
    som_buz(220, 400);  // Lá
    sleep_ms(200);      // Pausa
    som_buz(196, 400);  // Sol
    sleep_ms(200);      // Pausa
    som_buz(164, 800);  // Mi

    sleep_ms(500);

        som_buz(293, 400);  // Ré
    sleep_ms(200);      // Pausa
    som_buz(293, 400);  // Ré
    sleep_ms(200);      // Pausa
    som_buz(349, 400);  // Fá
    sleep_ms(200);      // Pausa
    som_buz(293, 400);  // Ré
    sleep_ms(200);      // Pausa
    som_buz(246, 400);  // Si
    sleep_ms(200);      // Pausa
    som_buz(261, 400);  // Dó
    sleep_ms(200);      // Pausa
    som_buz(330, 800);  // Mi (longa)
    sleep_ms(400);      // Pausa longa

    som_buz(261, 400);  // Dó
    sleep_ms(200);      // Pausa
    som_buz(196, 400);  // Sol
    sleep_ms(200);      // Pausa
    som_buz(330, 400);  // Mi
    sleep_ms(200);      // Pausa
    som_buz(196, 400);  // Sol
    sleep_ms(200);      // Pausa
    som_buz(349, 400);  // Fá
    sleep_ms(200);      // Pausa
    som_buz(293, 400);  // Ré
    sleep_ms(200);      // Pausa
    som_buz(261, 400);  // Dó
    sleep_ms(200);      // Pausa    // Pausa
}


//Jingle Bells - Natal 2
void natal2() {
    // Natal 2 - Jingle Bells (Parte 2)
    som_buz(330, 300);  // Mi
    sleep_ms(100);      // Pausa
    som_buz(330, 300);  // Mi
    sleep_ms(100);      // Pausa
    som_buz(330, 500);  // Mi longa
    sleep_ms(300);      // Pausa

    som_buz(330, 300);  // Mi
    sleep_ms(100);      // Pausa
    som_buz(330, 300);  // Mi
    sleep_ms(100);      // Pausa
    som_buz(330, 500);  // Mi longa
    sleep_ms(300);      // Pausa

    som_buz(330, 300);  // Mi
    sleep_ms(100);      // Pausa
    som_buz(392, 300);  // Sol
    sleep_ms(100);      // Pausa
    som_buz(261, 300);  // Dó
    sleep_ms(100);      // Pausa
    som_buz(293, 300);  // Ré
    sleep_ms(100);      // Pausa
    som_buz(330, 800);  // Mi longa
    sleep_ms(300);      // Pausa

    som_buz(349, 300);  // Fá
    sleep_ms(100);      // Pausa
    som_buz(349, 300);  // Fá
    sleep_ms(100);      // Pausa
    som_buz(349, 300);  // Fá longa
    sleep_ms(100);      // Pausa
    som_buz(349, 300);  // Fá
    sleep_ms(100);      // Pausa
    som_buz(349, 300);  // Fá
    sleep_ms(100);      // Pausa
    som_buz(330, 300);  // Mi
    sleep_ms(100);      // Pausa
    som_buz(330, 300);  // Mi
    sleep_ms(100);      // Pausa
    som_buz(330, 300);  // Mi
    sleep_ms(100);      // Pausa
    som_buz(330, 300);  // Mi
    sleep_ms(100);      // Pausa
    som_buz(392, 400);  // Sol longa
    sleep_ms(100);      // Pausa
    som_buz(392, 500);  // Sol
    sleep_ms(100);      // Pausa
    som_buz(349, 500);  // Fá
    sleep_ms(100);      // Pausa
    som_buz(293, 500);  // Ré
    sleep_ms(100);      // Pausa
    som_buz(261, 1200);
}

// We wish you a Merry Christmas - Natal 3
void natal3() {
    sol(); la(); sol(); fa();
    mi(); fa();
    sol(); sol(); sol(); fa();
    mi(); re();
    sleep_ms(200);

    la(); la(); sol(); fa();
    mi(); fa();
    sol(); sol(); la(); sol();
    fa();
    sleep_ms(200);

    la(); la(); si(); la();
    sol(); fa();
    sol(); doh(); doh(); si();
    la(); sol();
    sleep_ms(400);

    sol(); sol(); la(); sol();
    fa(); mi(); fa();
    sol(); sol(); la(); sol();
    fa();
    sleep_ms(200);

    la(); la(); si(); la();
    sol(); fa();
    sol(); doh(); doh(); si();
    la(); sol();
    sleep_ms(400);

    sol(); sol(); la(); sol();
    fa(); mi(); fa();
    sol(); sol(); la(); sol();
    fa();
    sleep_ms(200);

    la(); la(); si(); la();
    sol(); fa();
    sol(); doh(); doh(); si();
    la(); sol();
    sleep_ms(800);
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

// Função para desligar tudo (LEDs e buzzer)
void desligar_tudo() {
    gpio_put(LED_G, 0); // Desliga o LED verde
    gpio_put(LED_B, 0); // Desliga o LED azul
    gpio_put(LED_R, 0); // Desliga o LED vermelho
    gpio_put(buzzer_pin, 0); // Desliga o buzzer
}

// Função para ligar tudo (LEDs e buzzer)
void ligar_tudo() {
    gpio_put(LED_G, 1); // Liga o LED verde
    gpio_put(LED_B, 1); // Liga o LED azul
    gpio_put(LED_R, 1); // Liga o LED vermelho
    gpio_put(buzzer_pin, 1); // Liga o buzzer
    som_infinito(1000); // Toca as notas musicais
}

void som_infinito(uint16_t freq) {
    uint period = 1000000 / freq;  // Período do sinal em microssegundos

    while (1) {  // Loop infinito para som contínuo
        gpio_put(buzzer_pin, 1);  // Liga o buzzer
        sleep_us(period / 2);  // Espera metade do período
        gpio_put(buzzer_pin, 0);  // Desliga o buzzer
        sleep_us(period / 2);  // Espera metade do período

        // Lê o teclado
        char key = ler_teclado();

        // Verifica se a tecla '*' foi pressionada
        if (key == '*') {
            break;  // Encerra o loop se '*' for pressionado
        }
    }
}
