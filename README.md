# Trabalho 1 - Montador de Passagem Única e Simulador

Aluno: Fábio Rodrigues de Andrade Santos - 16/0151783

## Introdução
O‌‌ trabalho‌‌ consiste‌‌ em‌‌ implementar‌‌ em‌‌ C/C++‌‌ um‌‌ método‌‌ de‌‌ tradução‌‌ de‌‌ uma‌‌ linguagem‌‌ de‌‌
montagem‌ ‌simples‌ ‌para‌ ‌uma‌ ‌representação‌ ‌de‌ ‌código‌‌ objeto.‌‌O‌‌ tradutor‌‌ a‌‌ ser‌‌ implementado‌‌
será‌ ‌um‌ ‌Assembler‌ ‌da‌ ‌linguagem‌ ‌hipotética‌ ‌vista‌ ‌em‌ ‌sala‌ ‌de‌ ‌aula.‌

## Objetivo
Fixar‌ ‌o‌ ‌funcionamento‌ ‌de‌ ‌um‌ ‌processo‌ ‌de‌ ‌tradução.‌ ‌Especificamente‌ ‌as‌ ‌etapas‌ ‌de‌ ‌análise‌‌
léxica,‌ ‌sintática‌ ‌e‌ ‌semântica‌ ‌e‌ ‌a‌ ‌etapa‌ ‌de‌ ‌geração‌ ‌de‌ ‌código‌ ‌objeto.‌ ‌Ligação‌.

## Compilação
O desenvolvimento do código foi realizado no ambiente linux, com o SO Ubuntu versão 18.04.5 LTS. O compilador utilizado nos dois códigos, montador.cpp e simulador.cpp, foi o g++, seguindo o seguintes comandos respectivamente:

```bash
g++ montador.cpp -o montador
```

```bash
g++ simulador.cpp -o simulador
```

Caso o computador utilizado não tenha suporte para versões mais recentes do c++, será necessário a seguinte diretiva de compilação:

```bash
-std=c++17
```

## Execução
Ambos os códigos necessitam que se passe o nome do arquivo juntamente com sua extensão, .asm para o montador e .obj para o simulador. Então aa execuções do montador e simulador devem seguir os seguintes comandos:
```bash
./montador myprogram.asm
```
e
```bash
./simulador myprogram.obj

```

