typedef struct torre Torre;

Torre * criarTorre();
void iniciarJogo();
void inicializarPinos(Torre * t);
void escolherPinos(Torre * t);
void movimentoPinos(Torre * t);
void verificarTermino(Torre * t);
void ajuda(Torre * t);
