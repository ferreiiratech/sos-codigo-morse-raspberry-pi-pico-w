# Tarefa SOS Morse

Este repositório contém o código-fonte e os arquivos relacionados à implementação de um sinal SOS em código Morse, desenvolvido como parte de uma atividade prática no curso de Sistemas Embarcados.

## Descrição do Projeto

O projeto consiste em um firmware desenvolvido em linguagem C para a placa **BitDogLab** (compatível com o Raspberry Pi Pico), que utiliza um LED e um buzzer para gerar o sinal SOS em código Morse. Este sinal é composto por três pontos (`S`), três traços (`O`) e três pontos (`S`), com intervalos de tempo definidos para simular o padrão Morse.

## Arquivos

- **`Tarefa-SOS-Morse.c`**: Arquivo principal contendo o código-fonte do firmware.
- **`diagram.json`**: Descrição do circuito utilizado na simulação no Wokwi.
- **`wokwi.toml`**: Arquivo de configuração para integrar o código com a simulação no Wokwi.
- **`CMakeLists.txt`**: Arquivo de configuração para compilar o firmware.
- **`pico_sdk_import.cmake`**: Arquivo de configuração do PICO-SDK.

## Requisitos

Antes de começar, certifique-se de ter as ferramentas abaixo instaladas no seu ambiente de desenvolvimento:

- [Visual Studio Code](https://code.visualstudio.com/)
- Extensão para Raspberry Pi Pico no Visual Studio Code
- [Wokwi](https://wokwi.com/) para simulação online
- [PICO-SDK](https://github.com/raspberrypi/pico-sdk) configurado no seu ambiente
- [Zadig](https://zadig.akeo.ie/) para configuração do driver USB (Windows)

## Circuito Simulado

O circuito utilizado na simulação é composto pelos seguintes componentes:
- **LED** conectado ao GPIO 13 (pino de saída digital).
- **Buzzer** conectado ao GPIO 10 (pino de saída digital).
- Ambos os componentes estão conectados ao GND.
- Placa Raspberry Pi Pico W

### Link para Simulação

A simulação do projeto pode ser acessada pelo seguinte link:  
[Simulação no Wokwi](https://wokwi.com/projects/419807602815880193)

## Funcionamento do Código

### Configuração

O código inicializa os GPIOs para controlar o LED e o buzzer. As constantes definem os tempos para os sinais em código Morse:

- **Ponto (.)**: LED e buzzer ligados por 200 ms.
- **Traço (-)**: LED e buzzer ligados por 800 ms.
- **Intervalos**:
  - Entre sinais de uma mesma letra: 125 ms.
  - Entre letras: 250 ms.
  - Entre ciclos completos (SOS): 3 segundos.

### Funções Principais

1. **`blink_led_and_buzz()`**  
   Liga o LED e o buzzer por um período de tempo especificado.

2. **`generate_morse_signal()`**  
   Gera os sinais (ponto ou traço) para compor letras em código Morse, incluindo os intervalos apropriados.

3. **`main()`**  
   Executa continuamente o sinal SOS (composto pelas letras `S`, `O` e `S`), utilizando as funções acima para respeitar as regras do código Morse. 
   O **loop principal** gera continuamente o sinal SOS conforme o padrão definido.

## Como Compilar e Executar

1. Configure o **PICO-SDK** no ambiente.
2. Compile o firmware usando o comando `cmake` e `make` no terminal.
3. Conecte a placa BitDogLab ao computador no modo BOOTSEL.
4. Copie o arquivo gerado para a memória flash da placa.
5. A placa executará automaticamente o firmware, gerando o sinal SOS.

## Problemas Comuns

- **Driver USB não reconhecido**: Use o Zadig para instalar o driver correto no Windows.
- **Erro na simulação no Wokwi no VS Code**: Certifique-se de criar o arquivo `wokwi.toml` corretamente para integrar o projeto.

## Autor

Leonardo Ferreira Lima  
Email: ferreiiratech@gmail.com  