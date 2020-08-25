/*
* Cassia Claudiane Silva da Rosa  
* Trabalho 2
* Professor: Diego Padilha 
*/ 

//ESTOU NO PASSO 3, CRIAR A ÁRVORE DE HUFFMAN
/*
perguntas para o professor:
1 - qual a dimensão inicial do vetor vector v : respondida : o vetor já está alocado, basta inserir
2 - como eu faço para saber as posições cheias sem um atributo contador na minheap 
3 - posso adicionar um novo tributo ?
4 - como funciona a função size? e qual a diferença dela para a função size normal
5 - como vou usar as funções pair pra construir a tabela de dispersão?
6 - como vou saber na minheap a chave? 
*/
//PERGUNTA PRINCIPAL !!!!!! COMO VOU FAZER PRA CONTAR OS BITS RESTANTES NO FINAL DO ARQUIVO??
#include <cstdio>  
#include <cctype>
#include <vector>
#include <utility>
#include <string> 
#include <map>
#include<iostream>
#include<bitset>

using namespace std;

void calcula_frequencia(int *, char *);
void writeBinary(char *, int, FILE *);
/* Nó de uma árvore de Huffman */
class Node {
private:
  int f;     // Frequência
  char c;    // Código ASCII
  Node *l;   // Filho esquerdo
  Node *r;   // Filho direito
  
public:
  Node(int f, int c, Node *l = NULL, Node *r = NULL); // Construtor
  Node(int f = 0, Node *l = NULL, Node *r = NULL);    // Construtor
  int freq(void);    // Devolve a frequência do caractere
  char code(void);   // Devolve o código do caractere
  Node *left(void);  // Devolve o filho esquerdo
  Node *right(void); // Devolve o filho direito
  bool leaf(void);   // Devolve true se é folha e false caso contrário
  void setLeft(Node *);
  void setRight(Node *);
  void setFreq(int);
  void setCode(char);
  void tabelaCodigos(map<unsigned char, string> *, string);
  void percurso_pre_ordem(string *, int op);
  Node* huffman_trie(FILE *, int *, int*, string *, vector<char>);
  void decompressCode(map<unsigned char, string> *, string);
  void printCaracteres(FILE *, FILE *, int *, string *, int, int);
};

//void imprime_arvore(Node *);

/* Lista de min-prioridades (min-heap) com nós de uma árvore de
   Huffman, utilizando a frequência como chave */
class MinHeap {
private:
  vector<Node *> v;  // Elementos
  void up(int i);    // Sobe
  void down(int i);  // Desce
  int parent(int i); // Pai
  int left(int i);   // Filho esquerdo
  int right(int i);  // Filho direito
public:
  MinHeap();            // Construtor padrão
  ~MinHeap();           // Destrutor padrão
  int size(void);       // Tamanho da heap
  void insert(Node *n); // Inserir elemento
  Node *extract(void);  // Remover (menor) elemento
  void define_filhos(void); 
  Node *cria_arvore_huffman();
  void troca(int , int );
  void imprime_heap(void); 
  void copy(Node *, Node*);
};

pair<unsigned char, string> hentry;
map<unsigned char, string> htable;

/* Sugestão para tabela de dispersão */
//string com bits e char vai ser caractere procurado? 
//typedef 
//typedef 
int main(int argc, char *argv[]) {
  
  FILE *arqEntrada, *arqSaida; 
  char operacao, caractere, aux;  
  vector<char> palavra;
  int i, contador = 0, cont_freq[128] = {0}, cont = 0, pos = 0;  
  string codigo, cod_pre_ordem, cod_final;
  MinHeap *heap = new MinHeap();
  Node *huff; 

  operacao = *argv[1];

  if(operacao == 'c') {    
    
    arqEntrada = fopen(argv[2], "r"); //Abrindo arquivo texto
    arqSaida = fopen(argv[3], "wb");  //Abrindo arquivo para escrita em binário


    //Lendo arquivo  
    while(fscanf(arqEntrada, "%c", &aux) != EOF) {
      palavra.push_back(aux);
    }

    //Contando frequência dos caracteres
    for(i = 0; palavra[i] != '\0'; ++i) {
      caractere = palavra[i];
      cont_freq[(int)caractere]++; 
    }

    //Inserindo os caracteres em um vetor e depois transformando em minheap
    for(i = 0; i < 128; ++i) {      
      if(cont_freq[i] > 0) {
        Node *novo = new Node(cont_freq[i], i, NULL, NULL);
        heap->insert(novo);
      }
    }
    
    //Criando árvore de Huffman
    huff = heap->cria_arvore_huffman();
      
    //Tabela hash com o código dos caracteres
    huff->tabelaCodigos(&htable, codigo);
    
    //Contando quantidade de caracteres
    for(auto i = htable.begin(); i != htable.end(); ++i) 
      contador++;
    
    cout <<contador<<endl;
    //Transformando em 2 bytes
    
    char sequencia[8] = {0};
    for(int i = 0; i < 8; ++i) {
      sequencia[i] = contador % 2;
      contador /= 2;
    }
    //bitset<8>p(contador); 
    //char sequencia[8] = {0};
    //for(int i = 0; i < (int)p.size(); ++i) {
      //sequencia[i] = p[i];
    //}
    writeBinary(sequencia, 8, arqSaida);
    //Imprimindo no arquivo a quantidade de caracteres
    //for(i = (int)p.size() / 2 - 1; i >= 0 ; --i) {
      //fputc(p[i] == true? true : false, arqSaida);
    //}

    fputc(' ', arqSaida);

    //for(i = (int)p.size() / 2; i < (int)p.size(); ++i) {
    //  fputc(p[i] == true? true : false, arqSaida);
    //}

    /*cont = 2;

    fputc(' ', arqSaida);
    
    huff->percurso_pre_ordem(&cod_pre_ordem, 1);

    //Impressão do código ascii das palavras 
    for(int i = 0; cod_pre_ordem[i] != '\0'; ++i) {
      bitset<8>x(htable.find(cod_pre_ordem[i])->first);    
      for(int j = (int)x.size() - 1; j >= 0; --j)
        fputc(x[j] == true? true : false, arqSaida);
      cont++;
      if(cont == 5) {
        fputc('\n', arqSaida);
        cont = 0;
      }
      else 
        fputc(' ', arqSaida);
    }

    huff->percurso_pre_ordem(&cod_final, 0);
    
    //Impressão do codigo pré-ordem das palavras
    for(int i = 0; i < (int)cod_final.size(); ++i) {
      if(pos == 8) {
        fputc(' ', arqSaida); 
        cont++;  
        pos = 0;
      } 
      if(cont == 5) {
        fputc('\n', arqSaida);
        cont = 0;
      }
      pos++;
      fputc(cod_final[i], arqSaida);  //ver como esse vai ficar!!!
    }

    //Impressão da palavra codificada
    for(int i = 0; palavra[i] != '\0'; ++i) { 
      auto aux = htable.find(palavra[i])->second;

      for(int f = aux.length() - 1; f >= 0; --f) {
        if(pos == 8) {
          fputc(' ', arqSaida);
          cont++;
          pos = 0;
        }   
        if(cont == 5) {
          fputc('\n', arqSaida);
          cont = 0;
        }
        pos++;
        fputc(aux[f] == '1' ? '1' : '0', arqSaida);
      }
    }
    pos = 8 - pos;
    
    //Colocando 0 nos bits que restaram
    for(int i = 0; i < pos; ++i)
      fputc('0', arqSaida);
    
    cont++;

    if(cont == 5)  
      fputc('\n', arqSaida);
    else
      fputc(' ', arqSaida);

    //Impressão de quantos bits restaram
    bitset<8> t(pos);
    for(i = t.size() - 1; i >= 0; --i) {
      fputc(t[i] == true ? '1' : '0', arqSaida);
    }*/
  }
  else {
    arqEntrada = fopen(argv[2], "r + b");
    arqSaida = fopen(argv[3], "w");

    unsigned char buffer = 0;
    int numeroCaracteres = 0;
    vector<Node*> nosdescomp; 
    vector<char> caracteres;
    int x = 0, y =0;
    string byte;
    Node *aux = new Node(0, 0, NULL, NULL);

    fread(&buffer,1 , 2, arqEntrada);
    numeroCaracteres = buffer + 0;

    //cout << numeroCaracteres;

    for(int i = 0; i < numeroCaracteres; ++i){
      fread(&buffer, 1, 1, arqEntrada);
      caracteres.push_back(buffer + 0);
    }
    //for(int i = 0; caracteres[i] != '\0'; ++i)
      //cout << caracteres[i] + 0 << endl;

    string nova;
    
    aux = aux->huffman_trie(arqEntrada, &x, &y, &byte, caracteres);
    
    //Node *p;
    //for(p = aux; p != NULL; p = p->left()) 
      //cout << p->code() + 0 << endl;
    aux->decompressCode(&htable, nova);
    
    
    //for(auto i = htable.begin(); i != htable.end(); ++i) 
      //cout << i->second << endl;
    for(int i = x; i < 8; ++i) {
      unsigned char num = byte[i] + 0;
      string s;
      s.push_back(num);
      for(auto j = htable.begin(); j != htable.end(); ++j) {
        string f = j->second;
        if(f.compare(s) == 0)
          fwrite(&j->first, 1, 1, arqSaida);
      }
    }

      
    int last = 0, pos = 0;
    long total_size;
    pos = ftell(arqEntrada);
    fseek(arqEntrada, -1, SEEK_END);
    total_size = ftell(arqEntrada) - 1;
    //cout << total_size;
    last = fgetc(arqEntrada);
    fseek(arqEntrada, 0, SEEK_SET);
    fseek(arqEntrada, pos, SEEK_CUR);
    
    int bit = 0;
    string bits;

    //imprime_arvore(aux);
    aux->printCaracteres(arqSaida, arqEntrada, &bit, &bits, total_size, last);

    /*while (fread(&buffer, 1, 1, arqEntrada) != 0) {
      bitset<8> x(buffer);
      string s = x.to_string();
      for(int k = 0; k < 8; ++k) {
        aux->printCaracteres(FILE *arqSaida, s[i]);
      }
    }*/
    
    //Node *aux;
    //int x =0,y=0;
    //aux->huffman_trie(arqEntrada, &x, &y, byte, caracteres);
  
    /*while(fread(&buffer, 1, 1, arqEntrada) != 0) {
      contador++;
      //cout << buffer + 0 << endl;
      if(contador == 1 or contador == 2) {
        bitset<8>x(buffer);
        contador == 1 ? numeroCaracteres = x.to_ulong() : numeroCaracteres += x.to_ulong();
      }
      else if(contador > 2 and contador < numeroCaracteres + 3) {
        caracteres.push_back((char)(buffer + 0));
      }
      else if(arvore_criada == false and contador >= numeroCaracteres + 3){
        Node *aux; 
        bitset<8>bits(buffer); 
      }  
      
    } */
    //cout << numeroCaracteres; 
    //scout << caracteres[0];
    //cout << contador;
  }

  return 0;
}

Node::Node(int freq, int code, Node *left, Node *right) {
  f = freq;
  c = code; 
  r = NULL;
  l = NULL;  
}

Node::Node(int f, Node *left, Node *right) {
  f = 0;
  l = NULL;
  r = NULL;
}

int Node::freq() {
  return f;
}

char Node::code() {
  return c;
}

Node *Node::left() {
  return l;
}

Node *Node::right() {
  return r;
}

bool Node::leaf() {
  if(l == NULL and r == NULL)
    return true;
  return false;
}

MinHeap::MinHeap() {

}

MinHeap::~MinHeap() {

}

int MinHeap::size() {
  return v.size();
}

  
void MinHeap::insert(Node *n) {
  v.push_back(n);
  up(v.size() - 1);
}

Node* MinHeap::extract() {
  Node *menor;

  if(v.size() > 0) {
    menor = v[0];
    v[0] = v[v.size() - 1];
    v.pop_back(); 
    down(0); 
    
    return menor;
  }
  else 
    return NULL;
} 

void MinHeap::up(int i) {

  while(v[parent(i)]->freq() > v[i]->freq()) {
    troca(i, parent(i));  //como não entra em troca??
    i = parent(i);
  }
}

void MinHeap::down(int i) {
  int e, d, menor;

  e = left(i); 
  d = right(i);

  if(e < (int)v.size() and v[e]->freq() < v[i]->freq()) 
    menor = e;
  else 
    menor = i;
  if(d < (int)v.size() and v[d]->freq() < v[menor]->freq())
    menor = d;
  if(menor != i) {
    troca(i, menor);
    down(menor);
  }
} 

int MinHeap::parent(int i) {
  return (i - 1) / 2;
}

int MinHeap::left(int i) {
  return 2 * (i + 1) - 1;
}

int MinHeap::right(int i) {
  return 2 * (i + 1);
}

void MinHeap::troca(int i, int j) {
  //printf("aqui no troca\n");
  Node *aux = new Node();
  copy(aux, v[i]); 
  copy(v[i], v[j]);
  copy(v[j], aux);
  delete aux;
}

void calcula_frequencia(int *count, char *palavra) {
  int k; 
  for(int i = 0; palavra[i] != '\0'; ++i) {
    k = palavra[i];
    count[k]++;

  }
}
void MinHeap::define_filhos(void) {
  for(unsigned i = 0; i < v.size()/2 - 1; i++) {
    v[i]->setLeft(v[left(i)]);
    v[i]->setRight(v[right(i)]);
  }
}

void Node::setLeft(Node *left) {
  l = left;
}

void Node::setRight(Node *right) {
  r = right;
}

void MinHeap::imprime_heap() {
  for(unsigned i = 0; i < v.size(); i++) 
    printf("%d\n", v[i]->freq());
}

void MinHeap::copy(Node *x, Node *y) {
  int a = y->freq();
  char b = y->code(); 
  x->setFreq(a); 
  x->setCode(b);
  //precisar setar direito e esquerdo? ver aula
  x->setLeft(y->left());
  x->setRight(y->right());

}

void Node::setFreq(int freq) {
  f = freq;
}

void Node::setCode(char crt) {
  c = crt;
}

Node *MinHeap::cria_arvore_huffman() {

  while(v.size() > 1) {
    Node *novo = new Node; 
    novo->setLeft(extract());
    novo->setRight(extract());
    novo->setFreq(novo->right()->freq() + novo->left()->freq());
    insert(novo);
  }
  return extract(); 
}

void Node::tabelaCodigos(map<unsigned char, string> *htable, string cod) {
  
  if(leaf()) 
    htable->insert(pair<unsigned char, string>(code(), cod));
  if(left() != NULL) 
    left()->tabelaCodigos(htable, cod + "0");
  if(right() != NULL) 
    right()->tabelaCodigos(htable, cod + "1");
}

void Node::percurso_pre_ordem(string *codigo_pre_ordem, int op) {
  
  if(leaf()) {
    if(op == 0)
      codigo_pre_ordem->push_back('1');
    else 
      codigo_pre_ordem->push_back(code());
  }
  else if(op == 0){
    codigo_pre_ordem->push_back('0');
  }
  if(left() != NULL){
    op == 0 ? left()->percurso_pre_ordem(codigo_pre_ordem, 0) : left()->percurso_pre_ordem(codigo_pre_ordem, 1);
  }
  if(right() != NULL)
    op == 0 ? right()->percurso_pre_ordem(codigo_pre_ordem, 0) : right()->percurso_pre_ordem(codigo_pre_ordem, 1);
}

Node *Node::huffman_trie(FILE *aqrEntrada, int *i, int *j, string *byte, vector<char>caracteres) {
  Node *novo;
  unsigned char buffer = 0;
  char bit;
  
  if(*i == 0) { //Lendo 1 byte
    fread(&buffer, 1, 1, aqrEntrada);
    bitset<8>bits(buffer);
    *byte = bits.to_string();
  }

  bit = (*byte)[*i] + 0;
  //cout << bit ;

  if (bit == '1') {
    novo = new Node(0, caracteres[*j], NULL, NULL);
    (*j)++;
  }
  else 
    novo = new Node(0, -1, NULL, NULL);  

  (*i)++;

  if(*i >= 8) *i = 0;

  if(novo->code() == -1) {
    
    if(novo->left() == NULL){
      novo->l = novo->huffman_trie(aqrEntrada, i, j, byte, caracteres);
      //cout << *i << endl;
    }
    novo->r = novo->huffman_trie(aqrEntrada, i, j, byte, caracteres);    
      //printf("ENTROU\n");
  }

  return novo;
}

void Node::decompressCode(map<unsigned char, string> *htable, string cod) {

  if(code() != -1) {
    htable->insert(pair<unsigned char, string>(code(), cod));
    cout << code() << endl;
  }
  if(left() != NULL) {
    left()->tabelaCodigos(htable, cod + "0");
    //cout << code() + 0 << endl;
  }
  if(right() != NULL) 
    right()->tabelaCodigos(htable, cod + "1");
}

void Node::printCaracteres(FILE *arqSaida, FILE *arqEntrada, int *i, string *byte, int total_size, int sobra) {
  Node *aux;
  unsigned char buffer = 0;
  char bit;
  
  if(*i == 0) { //Lendo 1 byte
    fread(&buffer, 1, 1, arqEntrada);
    bitset<8>bits(buffer);
    *byte = bits.to_string();
    cout << bits << endl;
  }

  bit = (*byte)[*i] + 0;
  cout << bit << endl;
  (*i)++;

  if(code() != -1) {
    char caractere = code();
    cout << caractere << endl;
    fwrite(&caractere, 1, 1, arqSaida);
  }
  else {
    if(bit == 0)
      left()->printCaracteres(arqSaida, arqEntrada, i, byte, total_size, sobra);
    else 
      right()->printCaracteres(arqEntrada, arqSaida, i, byte, total_size, sobra);
  }
}
void writeBinary(char *sequencia, int sequenceLength, FILE *arqSaida)
{    
  unsigned char buf = 0x0;
  int count = 0;
  int i = 0;
  char bit = 0; 


  for(i = 0; i < sequenceLength; ++i) {
    bit = sequencia[i] + '0';
    cout << sequencia[i] + '0' << endl;
    buf |= bit << (7 - count);
    count++;

    //cout << buf + '0' << endl;

    if(count == 7) {
      fwrite(&buf, 1, 1, arqSaida);
      buf = 0x0; 
      count = 0;
    }
  }
}
/*void imprime_arvore(Node * no, FILE *arqEntrada) {
  
  unsigned char buffer;

  if(no->code() != -1)  
    cout << no->code();
  else {
    imprime_arvore(no->left());
    imprime_arvore(no->right());
  }
}*/
