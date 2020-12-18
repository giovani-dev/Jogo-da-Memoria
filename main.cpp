#include <iostream>
// #include <stdlib>
#define TAMANHO 4
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "barra.hpp"

using namespace std;


int main(){
    int x, y, carta_1_posicao_x, carta_1_posicao_y, carta_2_posicao_x, carta_2_posicao_y, carta;
    int erro = 0;
    int loop = 1;
    int contador_acertos = 0;
    int movimenta, inverso;
    int len_map = TAMANHO-1;

    system("clear");
    barra_de_carregamento();
    system("clear");

    int mapa[TAMANHO][TAMANHO] = {
        {1,2,3,4},
        {1,2,3,4},
        {5,6,7,8},
        {5,6,7,8},
    };
    srand ( time(NULL) );

    for(int i=0; i<=rand()%1000; i++ ){
        for(x=0; x<=len_map; x++){
            // srand ( time(NULL) );
            if(x%2 == rand()%3){
                for(y=0; y<=len_map; y++){
                    movimenta = mapa[x][y];
                    // inverso = y-x;
                    mapa[x][y] = mapa[y][x];
                    mapa[y][x] = movimenta;
                }
            }
        }
    }
    // O array acertos e o gabarito do nosso jogo, pois e com ele que verificamos se a carta que o jogados retirou seja printada na tela, assim como verificarmos se o jogo acabou
    // A variavel acertos deve conter a posicao exata da carta de acordo com o eixo y
    // e logo em seguida armazena a posicao do eixo x como se fosse uma fila
    int acertos[TAMANHO][TAMANHO] = {
        {-1,-1,-1,-1},
        {-1,-1,-1,-1},
        {-1,-1,-1,-1},
        {-1,-1,-1,-1}
    };
    

    while(1){
        if(contador_acertos == (TAMANHO*TAMANHO)/2 ){
            break;
        }
        
        // Nesse loop nos printamos o array mapa, e caso tenhamos acertado algmas cartas, nos podemos printa-la gracas ao nosso array de gabarito (acertos)
        for(x=0; x<=len_map; x++){
            for(y=0; y<=len_map; y++){
                if(acertos[x][y] > -1){
                    carta = acertos[x][y];
                    // Aqui imprimimos o mapa de acordo com os valores gravados no acertos
                    cout << mapa[x][carta] << " ";
                } else{
                    cout << "# ";
                }
            }
            cout << endl;
        }

        cout << "Carta 1: Escolha uma linha: ";
        cin >> carta_1_posicao_y;
        cout << "Carta 1: Escolha uma coluna: ";
        cin >> carta_1_posicao_x;

        if(carta_1_posicao_y > len_map || carta_1_posicao_x > len_map){
            cout << "Os valores permitidos para linhas e colunas variam de 0 a 3. Escolha novamente" << endl;
            sleep(5);
            erro = 1;
        }

        system("clear");

        for(y=0; y<=len_map; y++){
            for(x=0; x<=len_map; x++){
                if(y == carta_1_posicao_y && x == carta_1_posicao_x){
                    cout << mapa[carta_1_posicao_y][carta_1_posicao_x] << " ";
                } else{
                    cout << "# ";
                }
            }
            cout << endl;
        }

        cout << endl;
        cout << endl;

        cout << "Carta 2: Escolha uma linha: ";
        cin >> carta_2_posicao_y;
        cout << "Carta 2: Escolha uma coluna: ";
        cin >> carta_2_posicao_x;

        cout << endl;

        if(carta_2_posicao_y > len_map || carta_2_posicao_x > len_map){
            cout << "Os valores permitidos para linhas e colunas variam de 0 a 3. Escolha novamente";
            sleep(5);
            erro = 1;
        }
        
        system("clear");

        // Aqui adicionamos as 2 cartas que retiramos do deck no array acertos (bagarito)
        if(mapa[carta_1_posicao_y][carta_1_posicao_x] == mapa[carta_2_posicao_y][carta_2_posicao_x] && erro == 0){
            cout << "voce acertou, muito bem!" << endl;

            contador_acertos += 1;
            int max = 0;
            for(x=0; x<=len_map; x++){
                if(max >=2){
                    break;
                }
                if(acertos[carta_1_posicao_y][x] == -1 && carta_1_posicao_x == x){
                    acertos[carta_1_posicao_y][x] = carta_1_posicao_x;
                    max += 1;
                }
                if(acertos[carta_2_posicao_y][x] == -1 && carta_2_posicao_x == x){
                    acertos[carta_2_posicao_y][x] = carta_2_posicao_x;
                    max += 1;
                }
            }
            sleep(5);
        }
        system("clear");

    }
    cout << "Parabens, voce ganhou o jogo. +++++++++";
    return 0;
}