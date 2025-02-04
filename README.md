# Projeto de Alternância de LEDs com Temporizador no Raspberry Pi Pico 🚦⏲️

## 📋 Tabela de Conteúdos
- [📌 Introdução](#-introdução)
- [🛠️ Componentes Necessários](#-componentes-necessários)
- [🔧 Configuração do Hardware](#-configuração-do-hardware)
- [💻 Código Fonte](#-código-fonte)
- [🚀 Funcionamento do Código](#-funcionamento-do-código)

## 📌 Introdução
Este projeto utiliza um Raspberry Pi Pico para controlar três LEDs (vermelho, amarelo e verde) que alternam entre si a cada 3 segundos. O código foi desenvolvido em C utilizando a SDK do Raspberry Pi Pico e faz uso de um temporizador de hardware para gerenciar a alternância dos LEDs.

## 🛠️ Componentes Necessários
- 🖥️ Raspberry Pi Pico
- 🔴 LED Vermelho
- 🟡 LED Amarelo
- 🟢 LED Verde
- 🔌 Resistores (330Ω para os LEDs)

## 🔧 Configuração do Hardware
1. **LEDs**:
   - Conecte o ânodo (perna longa) do LED Vermelho ao pino GPIO 11.
   - Conecte o ânodo do LED Amarelo ao pino GPIO 12.
   - Conecte o ânodo do LED Verde ao pino GPIO 13.
   - Conecte os cátodos (pernas curtas) dos LEDs a resistores de 220Ω e depois ao GND.

### Estrutura do Código
- **Inicialização**:
  - Configura os pinos dos LEDs como saídas.
  - Inicializa um temporizador de repetição para alternar os LEDs a cada 3 segundos.

- **Loop Principal**:
  - O loop principal imprime no console qual LED está ativo no momento.
  - O temporizador gerencia a alternância dos LEDs.

- **Callback do Temporizador**:
  - A função `repeating_timer_callback` é chamada a cada 3 segundos para desligar o LED atual e ligar o próximo.

## 🚀 Funcionamento do Código
1. **Inicialização**:
   - O programa configura os pinos dos LEDs como saídas e inicia o temporizador de repetição.

2. **Temporizador**:
   - O temporizador chama a função `repeating_timer_callback` a cada 3 segundos.
   - A função desliga o LED atual e liga o próximo na sequência (vermelho → amarelo → verde → vermelho).

3. **Loop Principal**:
   - O loop principal imprime no console qual LED está ativo no momento.
   - O programa entra em um loop infinito, mantendo a alternância dos LEDs.