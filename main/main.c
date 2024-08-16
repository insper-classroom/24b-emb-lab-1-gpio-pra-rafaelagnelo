/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int led = 18;
const int botao_vermelho = 4;
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5; 

int main() {
    stdio_init_all();

    gpio_init(botao_vermelho);
    gpio_set_dir(botao_vermelho, GPIO_IN);
    gpio_pull_up(botao_vermelho);

    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);

    gpio_init(led1);
    gpio_set_dir(led1, GPIO_OUT);

    gpio_init(led2);
    gpio_set_dir(led2, GPIO_OUT);

    gpio_init(led3);
    gpio_set_dir(led3, GPIO_OUT);

    gpio_init(led4);
    gpio_set_dir(led4, GPIO_OUT);

    while (true) {
        printf("Hello, world!\n");
        gpio_put(led, 0);

        if (!gpio_get(botao_vermelho)){
            gpio_put(led,1);
            for(int i = 0; i < 515; i++){
                gpio_put(led1,1);
                sleep_ms(8);
                gpio_put(led1,0);
                gpio_put(led2,1);
                sleep_ms(8);
                gpio_put(led2,0);
                gpio_put(led3,1);
                sleep_ms(8);
                gpio_put(led3,0);
                gpio_put(led4,1);
                sleep_ms(8);
                gpio_put(led4,0);
            }
        }

    }
}
