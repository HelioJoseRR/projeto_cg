# Projeto CG

Casa Museu do primeiro presidente do Brasil feito em openGL com a linguagem C.

## Estrutura do Projeto

O projeto está organizado da seguinte forma:

```
.
├── assets/
├── bin/
├── build/
├── include/
├── src/
│   ├── main.c
│   └── ...
├── .gitignore
└── README.md
```

  - **`assets/`**: Contém todos os arquivos externos utilizados pelo projeto, como texturas, modelos 3D, shaders, etc.
  - **`bin/`**: Contém os arquivos binários executáveis gerados após a compilação e linkagem.
  - **`build/`**: Contém os arquivos objeto (`.o`) gerados durante o processo de compilação.
  - **`include/`**: Contém os arquivos de cabeçalho (`.h`) com as declarações de funções e estruturas.
  - **`src/`**: Contém o código-fonte (`.c`), incluindo o arquivo `main.c` que é o ponto de entrada do programa.

## Makefile

| Comando | Função |
|---------|--------|
| `make` ou `make all` | Compila todo o projeto |
| `make clean` | Remove arquivos objeto (.o) |
| `make cleanall` | Remove arquivos objeto e executável |
| `make run` | Compila e executa o programa |
| `make install-deps` | Instala dependências OpenGL (Ubuntu/Debian) |
| `make info` | Mostra informações do projeto |
| `make debug` | Mostra variáveis internas do Makefile |
