/*Projeto 2: Lista Encadeada 
FUNCIONLIDADES
    0) Sair
    01) Zerar lista
    02) Exibir lista
    03) Adicionar node no inicio
    04) Adicionar node no final 
    05) Escolher onde inserir
    06) Remover node no inicio
    07) Remover node no final
    08) Escolher qual elemento retirar
    09) Buscar elemento
    10) Inverter lista
    11) Ordenar Lista
    12) Obter Tamanho
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>//Import the boolean header file 

typedef struct Node{
    int elemento; //Elemento a ser adicionado a lista
    struct Node *prox; //Ponteiro para o proximo elemento
} celula;

celula *cabeca = NULL;

//Cria uma lista encadeada
//Função 'createNode' que retorna um ponteiro do tipo 'struct Node'
struct Node* createNode(int x){
    //Aloca espaço na memória
    celula *novo = (struct Node*)malloc(sizeof(struct Node));

    //Verifica se houve falha na alocação
    if(novo == NULL){
        printf("\nError: Falha ao alocar memória para o novo nó.\n");
        exit(1); 
    };

    //Alocação bem sucedida
    novo -> elemento = x; //atribui o valor passado por x
    novo -> prox = NULL; //novo nó aponta para NULL
    
    return novo;
};
//Remover todos os nós da Lista
void clearLista(){
    celula *curr = cabeca, *aux=NULL;

    while (curr != NULL){
        aux = curr;
        curr = curr->prox;
        free(aux);
    };
    
    int x = tamanhoLista();
    printf("\nLista encadeada foi zerada %d\n",x);
};

//Imprime a lista encadeada criada
void printList(){
    celula *aux = cabeca;
    printf("\nImprime Lista encadeada: ");
    while(aux != NULL){
        printf("%d ",aux->elemento);
        aux = aux->prox;
    };
    printf("\n");
    return;
};

// Função que insere um elemento na lista  x e y==NULL insere elemento na cabeça, y!=NULL add x na posição de y, se não add elemento na cald
void insereElement(int x,int y){
    celula *novo = createNode(x);//Obtem o novo endereço
    celula *temp = createNode(x);
    
    if(cabeca==NULL || y==NULL){//insere elemento no inicio
        if(cabeca==NULL){
            cabeca = novo;
            printf("\nLista Criada com sucesso\n" );
            printf("\n  Elemento %d inserido a lista\n",cabeca->elemento);
            return;
        };
        novo->prox = cabeca;
        cabeca = novo;
        
        printf("\n  Elemento %d inserido a lista na cabeca\n",cabeca->elemento);
        return;
    };
    
    if(y!=false){//atualiza o ponteiro na cauda ou na posição escolhida
        celula *aux = cabeca;
        while (aux->prox != NULL){
            if(aux->prox->elemento==y){
                temp=aux->prox;
                aux->prox = novo;
                novo->prox =  temp;
                printf("\n  Elemento %d inserido com sucesso na posicao do elemento %d\n",novo->elemento,y);
                return;
            };
            aux = aux->prox;
        };
        aux->prox = novo;
    }
    printf("\n  Elemento %d inserido com sucesso na cauda\n",novo->elemento);
    return;
};

// Função que remove um elemento, se x==NULL remove o primeiro elemento, x!=NULL o elemento escolhido ou elemento da calda se não existir
void removeElement(int x){
    celula *aux = cabeca;

    if(x==NULL){//remove o primeiro elemento e atualiza a cabeça
        printf("  Elemento %d removido com sucesso da cabeca\n",cabeca->elemento);
        cabeca = aux->prox;
        free(aux);
        return;
    };

    celula *prev = NULL;
    //procura o no a ser removido
    while (aux->prox != NULL) {
        if(aux->prox->elemento==x){//remover elemento escolhido
           prev = aux->prox;
           printf("  Elemento %d removido com sucesso\n",prev->elemento);
           aux->prox = aux->prox->prox;
           free(prev);
           return;
        };
        prev = aux;
        aux = aux->prox;
    };

    if(aux==NULL){
        return;
    };

    prev->prox = aux->prox;
    printf("  Elemento %d removido com sucesso da calda\n",aux->elemento);
    free(aux);
};

//Procura um elemento na lista encadeada
void searchElement(int x){
    celula *curr = cabeca;
    while(curr->prox != NULL){
        if(curr->elemento == x){
            printf("\nElemento %d foi encontrado na lista\n", curr->elemento);
            return;
        };
        curr = curr->prox;
    };
    printf("\nElemento %d NAO foi encontrado na lista\n", x);
    return;
};

//inverter lista encadeada
void inverterLista(){
    celula *prev = NULL, *next=cabeca, *aux=cabeca;

    printList();
    do{
        //printf(" aux: %d ",aux);
        next = next->prox;//Next é o proximo ponteiro da lista
        if(prev==NULL){
            aux->prox = NULL;//Atualiza a cabeca para calda
            prev = aux;//Prev atualisa para o ponteiro atual
        }else{
            aux->prox = prev;//Atualiza o ponteiro para indicar o anterior
            prev=aux;
            
        };
        aux = next;//Atualiza o ponteiro para o proximo atual
    }while(next->prox!=NULL);
    aux->prox = prev;
    cabeca = aux;
    printf("\nA lista foi invertida\n");
    printList();
    return;
};

//Ordenar lista encadeada
void ordeneList(bool sort){
    celula *temp, *curr = cabeca;

    while(curr->prox != NULL){
        if(curr->elemento > curr->prox->elemento){
            temp = curr->elemento;
            curr->elemento = curr->prox->elemento;
            curr->prox->elemento = temp;
            
            sort = false;
        };
        curr = curr->prox;
    };
    
    if(sort == true){//checa setoda a lista foi ordenada
        printf("\nLista foi ordenada com sucesso\n");
        printList();
        return;
    }else{
        ordeneList(true);
        return;
    };
};

//Procura um elemento na lista encadeada
int tamanhoLista(){
    int i = 0;
    celula *aux = cabeca;
    while (aux != NULL){
        i++;
        aux = aux->prox;
    };
    printf("\nTamanho da lista: %d\n",i);
    return i;
};

int menu(opcao){
    int elemento;
    int posicao;

    printf("\nESCOLHA A OPCAO: \n0- Sair\n01- Zerar lista\n02- Exibir lista\n03- Adicionar node no inicio\n04- Adicionar node no final");
    printf("\n05- Escolher onde inserir\n06- Remover node no inicio\n07- Remover node no final\n08- Escolher qual elemento retirar\n09- Buscar elemento");
    printf("\n10- Inverter lista\n11- Ordenar Lista\n12- Obter Tamanho\n\n");

    switch (opcao){
            case 1://Limpar lista
                printf("\n\nOPCAO 1     ");
                clearLista();
                break;
                
            case 2://Exibir list
                printf("\n\nOPCAO 2     ");
                printList(); 
                break;
                
            case 3://Inserir elemento no inicio
                printf("\n\nOPCAO 3     ");
                printf("Qual elemento quer inserir:");
                scanf("%d", &elemento,0);
                insereElement(elemento,false);
                break;
                
            case 4://Inserir elemento no final
                printf("\n\nOPCAO 4     ");
                printf("Qual elemento quer inserir:");
                scanf("%d", &elemento,1);
                insereElement(elemento,true);
                break;
                
            case 5://Inserir elemento na posicao escolhida
                printf("\n\nOPCAO 5     ");
                printf("Onde quer inserir:");
                scanf("%d", &posicao);
                printf("Qual elemento quer inserir:");
                scanf("%d", &elemento,2);
                break;
                
            case 6://Remover elemento no inicio
                printf("\n\nOPCAO 6     ");
                removeElement(NULL);
                break;

            case 7://Remover elemento no final
                printf("\n\nOPCAO 7     ");
                removeElement(-1);
                break;

            case 8://Remover elemento escolhido
                printf("\n\nOPCAO 8     ");
                printf("Qual elemento quer remover: ");
                scanf("%d", &elemento);
                removeElement(elemento);
                break;

            case 9://Procurarr elemento
                printf("\n\nOPCAO 9     ");
                printf("Qual elemento procurar: ");
                scanf("%d", &elemento);
                searchElement(elemento);
                break;

            case 10://Inverter lista
                printf("\n\nOPCAO 10     ");
                inverterLista();
                break;

            case 11://Ordenar lista
                printf("\n\nOPCAO 11     ");
                ordeneList(true);
                break;

            case 12://Obter tamanho da lista
                printf("\n\nOPCAO 12     ");
                tamanhoLista();
                break;

            default:
                return 0;
        };
        return opcao;
};

int main(){
    int opcao;
    //printf("%d - %d\n\n",&opcao,opcao);
    do{
        //opcao = menu(opcao);
        //printf("OPCAO: ");
        //scanf("%d", &opcao);
        
        //printf("%d - %d\n\n",&opcao,opcao);
        opcao = 0;
    } while (opcao != 0);
    insereElement(20,NULL);
    insereElement(5,true);//Insere elemento na calda
    insereElement(18,true);
    insereElement(9,true);
    insereElement(26,true);
    insereElement(3,true);
    insereElement(12,NULL);//Insere elemento na cabeça
    inverterLista();
    printList();
    insereElement(37,true);
    insereElement(13,true);
    insereElement(24,true);
    insereElement(7,18);//Insere elemento na posição escolhida não substitui elemento
    insereElement(14,3);
    printList();
    tamanhoLista();
    removeElement(NULL);//Remover elemento da cabeça
    printList();
    removeElement(5);//Remover elemento 5
    printList();
    removeElement(2);//Como elemento não existe, remove elemento da calda
    printList();
    tamanhoLista();
    ordeneList(true);
    tamanhoLista();
    searchElement(15);//Procura elemento 15
    searchElement(18);//Procura elemento 18

    inverterLista();//inverter lista
    clearLista();

    return 0;
};
