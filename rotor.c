#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// define a estrutura de um rotor 


typedef struct rotor
{
  char string[257];
  char hash[257];// para poder decifrar em O(n) onde n é o tamanho do antrada 
  int indice;
  int k;
  int l;
  int cont;
} Rotor;

void tratamentoDeExecao( int , char **);
char roda(Rotor *, char c);
char * rc4 ( char * chave);
void troca ( char * a, char *b);
void novoRotor(Rotor *,int indice, int k , int l,char * chave);//otimização criar novoRotoList
int main (int argc, char** argv)
{
  tratamentoDeExecao(argc,argv);
  
return 0;
}

char roda(Rotor * r, char c)
{
   r->cont++;
   if(r->k==r->cont)
   {
      r->indice=(r->l+r->indice)%256;
      r->cont=0;
   }
      return  r->string[(c+r->indice)%256];
   
}
void tratamentoDeExecao( int argc, char ** argv)
{
  
}
void novoRotor(Rotor * this,int indice, int k , int l,char * chave)
{
    int i;
    this->indice=indice;
    this->k=k;
    this->l=l;
    char * s= rc4(chave);
     for(i=0;i<256;i++)
     {
       this->string[i]=s[i];
       this->hash[s[i]]=i;
     }
    
}
void troca ( char * a, char *b)
{
  int aux;
  aux=(*a);
  (*a)=(*b);
  (*b)=aux;
}
char * rc4(char * chave)
{
  char *s = (char *) malloc(257);
  char t[257];
  int i, n;
  n=strlen(chave);
  for(i=0;i<256;i++)
  {
      s[i]=i;
      t[i]=chave[i%n];
  }
  int j=0;
  for(i=0;i<256;i++)
  {
    j=(j+s[i]+t[i])%256;
    troca (&s[i],&t[j]);
  }
  
    
}