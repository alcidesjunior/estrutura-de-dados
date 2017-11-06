typedef struct NO* arvBin;
arvBin* cria_arv();
void libera_arv(arvBin *raiz);
int estaVazia_arv(arvBin *raiz);
int altura_arv(arvBin *raiz);
int totalNO_arv(arvBin *raiz);
void preOrdem_arv(arvBin *raiz);
void emOrdem_arv(arvBin *raiz);
void posOrdem_arv(arvBin *raiz);
int insere_arv(arvBin *raiz, int valor);
int remove_arv(arvBin *raiz, int valor);
int consulta_item_arv(arvBin *raiz, int valor);

int consulta_emordem(arvBin *raiz, int valor);
int consulta_preordem(arvBin *raiz, int valor);
int consulta_posordem(arvBin *raiz, int valor);