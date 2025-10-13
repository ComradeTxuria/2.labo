#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
  char text[] = "RIJ AZKKZHC PIKCE XT ACKCUXJHX SZX, E NZ PEJXKE, PXGIK XFDKXNEQE RIPI RIPQEHCK ET OENRCNPI AXNAX ZJ RKCHXKCI AX CJAXDXJAXJRCE AX RTENX, E ACOXKXJRCE AXT RITEQIKERCIJCNPI OKXJHXDIDZTCNHE AX TE ACKXRRCIJ EJEKSZCNHE. AZKKZHC OZX ZJ OERHIK AX DKCPXK IKAXJ XJ XT DEDXT AX TE RTENX IQKXKE XJ REHETZJVE XJ GZTCI AX 1936. DXKI AZKKZHC, RIPI IRZKKX RIJ TEN DXKNIJETCAEAXN XJ TE MCNHIKCE, JI REVI AXT RCXTI. DXKNIJCOCREQE TE HKEACRCIJ KXVITZRCIJEKCE AX TE RTENX IQKXKE. NZ XJIKPX DIDZTEKCAEA XJHKX TE RTENX HKEQEGEAIKE, KXOTXGEAE XJ XT XJHCXKKI PZTHCHZACJEKCI XJ QEKRXTIJE XT 22 AX JIVCXPQKX AX 1936,PZXNHKE XNE CAXJHCOCRERCIJ. NZ PZXKHX OZX NCJ AZAE ZJ UITDX IQGXHCVI ET DKIRXNI KXVITZRCIJEKCI XJ PEKRME. NCJ AZKKZHC SZXAI PEN TCQKX XT REPCJI DEKE SZX XT XNHETCJCNPI, RIJ TE RIPDTCRCAEA AXT UIQCXKJI AXT OKXJHX DIDZTEK V AX TE ACKXRRCIJ EJEKSZCNHE, HXKPCJEKE XJ PEVI AX 1937 TE HEKXE AX TCSZCAEK TE KXVITZRCIJ, AXNPIKETCLEJAI E TE RTENX IQKXKE V OERCTCHEJAI RIJ XTTI XT DINHXKCIK HKCZJOI OKEJSZCNHE.";
  char new_text[strlen(text)];
  char c; 
  char s;
  char ordered_abc[] = {"ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"};
  char new_char[] = {"EQRAXOUMCGYTPJÑIDSKNHZVWFVL"};
  char counted_char[26] = {'\0'};
  char real_abc[26] = {"EAOLSNDRUITCPMYQBHGFVJNZXKW"}; 
  float real_num[26] = {16.78, 11.96, 8.69, 8.37, 7.88, 7.01, 6.87, 4.94, 4.8, 4.15, 3.31, 2.92, 2.776, 2.12, 1.54, 1.53, 0.92, 0.89, 0.73, 0.52, 0.39, 0.30, 0.29, 0.15, 0.06, 0.00, 0.00};
  float numbers[26] ={'\0'};
  int j = 0, count = 0, pointer = -1, k = 0;
  float num = 0, real_size = 0;
  bool counted = false, found = false;
  
  for (int i = 0; i < strlen(text); i++){
    pointer++;
    c = text[i];
    if (c < 'A' || c > 'Z'){ continue; }
    real_size++;
    while(j < count && counted == false){
      s = counted_char[j];
      j++;
      if (c == s){
        counted = true;
      } 
    }
    j = 0;
    if (counted){
      counted = false;
      continue;
    }
    for (int k = pointer; k < strlen(text); k++){
      if (text[k] == c){
        num++;
      }
    }
    numbers[count] = num;
    counted_char[count] = c;
    count++;
    num = 0;
  }
  
  for (int i = 0; i < 26; i++){
   // printf("%c - %f ", counted_char[i], numbers[i]);
    numbers[i] = numbers[i]/real_size*100;
  //  printf(" %c - %f\n",counted_char[i] ,(numbers[i]/real_size)*100);
  }
  for (int i = 0; i < 26; i++){
    for (int j = i; j < 26; j++){
      if (numbers[i] < numbers[j]){
        float aux_num = numbers[i];
        numbers[i] = numbers [j];
        numbers[j] = aux_num;
        char aux_char = counted_char[i];
        counted_char[i] = counted_char[j];
        counted_char[j] = aux_char;
      }
    }
    printf("%c - %f / %c - %f\n",counted_char[i], numbers[i], real_abc[i], real_num[i]);
  }
  
  
  for (int i = 0; i < strlen(text); i++){
    while(found == false){
      if (text[i] == new_char[k]){
        new_text[i] = ordered_abc[k];
       // printf(" %c-%c ", new_char[k], ordered_abc[k]);
        found = true;
      }
      k++;
    }
    if (text[i] < 'A' || text[i] > 'Z'){
      new_text[i] = text[i];
    }
    found = false;
    k = 0;
  }
  printf("\n\n");
  for (int i = 0; i < strlen(text); i++){
    printf("%c", text[i]);
  }
  
    printf("\n\n");
  for (int i = 0; i < strlen(new_text); i++){
    printf("%c", new_text[i]);
  }
  printf("\n\n");
  
  return 0;
}


