#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

void p1();
void e1();
void p2();
void p3();
void p4();
void p5();
void p6();
void clrgetch();

void clrgetch(int track){

    system("cls");
    switch(track)
    {
    case 1:
        p1();
        break;
    case 2:
        e1();
        break;
    case 3:
        p2();
        break;
    case 4:
        p3();
        break;
    case 5:
        p4();
        break;
    case 6:
        p5();
        break;
    case 7:
        p6();
        break;
    }
}

void p1(){
    int array[4] = {6, 8 ,4 ,2};
    int arrSize = (sizeof(array)/sizeof(*array));
    printf("(1)(Premir A e D Para navegar)\nint array[4] = {6, 8 ,4 ,2};\n\n");

    for(int i = 0; i < arrSize; i++)
    {
        printf("\n valor %d - no endere�o %p ", *(array + i), array + i);
    }

    printf("\n\nTamanho do array -> %d ", (sizeof(array)/sizeof(*array)));
    printf("\nTamanho do array em mem�ria -> %d", sizeof(array));
    printf("\n\nPorque %d? Corresponde a sizeof(*array) = %d * sizeof(int) = %d", sizeof(array), sizeof(*array), sizeof(int));
    printf("\n\nComo tal, o tamanho do array pode ser obtido por: \n\t(sizeof(array) = %d /sizeof(*array) = %d) = %d", sizeof(array), sizeof(*array), arrSize);
    printf("\n\n\nCada int ocupa 4bytes na mem�ria. Por curiosidade, podes ver que o mesmo sizeof retorna o tamanho dos outros tipos de dados\n");
    printf("\nsizeof(char) = %d | sizeof(float) = %d | sizeof(double) = %d", sizeof(char), sizeof(float) , sizeof(double));
}

void e1(){

    int array[4] = {1, 2 ,3 ,6};

    printf("(1)(Premir A e D Para navegar)\nQual o problema de declarar int array[4] = {1, 2 ,3 ,6}; ?\n"
           "N�o existe maneira de aumentar o tamanho do array depois de declarado\n\n"
           "Fun fact: se for�armos o preenchimento de uma posi��o n�o existente, a formula \n(ponteiro inicial) + (posi��o)*(espa�o) continua a ser utilizada"
           "\n\narray[5] = 222222;\narray[6] = 242422;\n");
           array[4] = 222222;
           array[5] = 242422;

        for(int i = 0; i < 6; i++)
    {
        printf("\n valor %d - no endere�o %p ", *(array + i), array + i);
    }

    printf("\n\nNo entanto, quando fazes (array[5] = 222222;), simplesmente est�s a atirar o valor para l�, n�o est�s a dizer \n\"quero que guardes mem�ria para que o n�mero n�o seja esquecido\" ");
}

void p2(){

    int *arrayAlloc = NULL;


    printf("(2)(Premir A e D Para navegar)\nComo alternativa, podemos declarar o array forma din�mica \n");
    printf("\nint *arrayAlloc = NULL;");

    printf("\n\nTamanho do array -> %d ", (sizeof(arrayAlloc)/sizeof(*arrayAlloc)));
    printf("\nTamanho do array em mem�ria -> %d", sizeof(arrayAlloc));

    printf("\nMas que valores temos agora? Bem... n�o temos\n"
           "\nDo mesmo modo que n�o podes fazer um sizeof() de um array enviado como parametro num procedimento, \ntamb�m n�o consegues determinar a mem�ria alocada atrav�s de um ponteiro"
           "\n\nTirado do StackOverflow: \n\t \"sizeof is a static operator and hence cannot be used to return the size of anything that's determined at runtime.\" ");

    printf("\n\nVamos ent�o abstrair-nos do facto de que n�o conseguimos obter o tamanho de algo que cri�mos"
           "\nSe te ajuda, pensa que \"� por esta raz�o\" que faz sentido criar estruturas com o tamanho delas l� dentro");


    printf("\n\nEnt�o como declaramos o nosso array de forma a que possa ser alterado?\n\n\t\tarrayAlloc = (int *) calloc(6, sizeof(int))\n\n"
           "\t(int *) \t-> ponteiro de um inteiro\n\n"
           "\tcalloc \t\t-> aloca��o de mem�ria deixando os valores a 0\n\n"
           "\t6 \t\t-> n�mero de posi��es \n\n"
           "\tsizeof(int) \t-> tamanho das posi��es \n\n");


}

void p3(){
    int *arrayAlloc = NULL;
    arrayAlloc = (int *) calloc(4, sizeof(int));
    int vamosImaginarQue = 4;

            printf("(2)(Premir A e D Para navegar)\n\nEm vez de usar o 4 directamente, podemos usar uma vari�vel com o valor 4\n"
                   "Deste modo, � mais f�cil lembrar em que tamanho est� o nosso array"
                   "\n\n\tint vamosImaginarQue = 4;\n"
                   "\t\tarrayAlloc = (int *) calloc(vamosImaginarQue, sizeof(int));"
                   );

           printf("\n\nImpress�o do array:\n");

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc + %d = %d - no endere�o %p ",i, *(arrayAlloc + i), arrayAlloc + i);
    }

    printf("\n\nComo usamos o calloc em vez de malloc, os valores s�o iniciados a 0");

    *(arrayAlloc + 2) = 5;
    printf("\n\n\t\t*(arrayAlloc + 2) = 5; \n");

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc + %d = %d - no endere�o %p ",i, *(arrayAlloc + i), arrayAlloc + i);
    }

    printf("\n\nFoi atribuido o valor 5 � posi��o 2");

    printf("\n\n\t\tarrayAlloc = (int *) calloc(vamosImaginarQue, sizeof(int));\n");
    arrayAlloc = (int *) calloc(vamosImaginarQue, sizeof(int));

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc + %d = %d - no endere�o %p ",i, *(arrayAlloc + i), arrayAlloc + i);
    }

    printf("\n\nComo usamos o calloc novamente, a mem�ria foi limpa e os endere�os alterados");
}

void p4(){
    int vamosImaginarQue = 4;
    int *arrayAlloc = (int *) calloc(vamosImaginarQue, sizeof(int));

    printf("(2)(Premir A e D Para navegar)\n\tfor(int i = 0; i < vamosImaginarQue; i++){\n\t  *(arrayAlloc + i) = i+2;\n\t}\n\n");

    for(int i = 0; i < vamosImaginarQue; i++){
        *(arrayAlloc + i) = i+2;
    }

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc + %d = %d - no endere�o %p ",i, *(arrayAlloc + i), arrayAlloc + i);
    }

    printf("\n\nAtribui��o de valores ao nosso array");

    printf("\n\n\tvamosImaginarQue = 2 * vamosImaginarQue;"
           "\n\n\tarrayAlloc = (int *) realloc(arrayAlloc,vamosImaginarQue * sizeof(int));\n"
           "\n\t(int *) \t-> ponteiro de um inteiro\n"
           "\trealloc \t-> realoca��o de mem�ria\n"
           "\tarrayAlloc \t-> ponteiro de origem\n"
           "\tvamosImaginarQue-> n�mero de posi��es \n"
           "\tsizeof(int) \t-> tamanho das posi��es \n");

    vamosImaginarQue = 2 * vamosImaginarQue;
    arrayAlloc = (int *) realloc(arrayAlloc, vamosImaginarQue * sizeof(int));

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc + %d = %d - no endere�o %p ",i, *(arrayAlloc + i), arrayAlloc + i);
    }

    printf("\n\nNova dimens�o do array, com \"lixo\" nas posi��es n�o atribuidas");
}

void p5(){
    int vamosImaginarQue = 8;
    int *arrayAlloc = (int *) calloc(vamosImaginarQue, sizeof(int));

    printf("(2)(Premir A e D Para navegar)\n   Duplique o tamanho do array (realloc);\n\n");

    for(int i = 0; i < vamosImaginarQue/2; i++){
        *(arrayAlloc + i) = i+2;
    }

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc + %d = %d - no endere�o %p ",i, *(arrayAlloc + i), arrayAlloc + i);
    }

    printf("\n\n   Na segunda \"metade\" coloque o dobro dos valores respetivos da primeira metade."
           "\n\n\tfor(int i = vamosImaginarQue/2; i < vamosImaginarQue; i++){\n\t *(arrayAlloc + i) = *(arrayAlloc + (i-(vamosImaginarQue/2)))*2;\n\t}"
           "\n\n   Come�amos na segunda \"metade\" at� ao final colocando o dobro dos valores respetivos da primeira metade.\n"
           "\n   Por exemplo, quando i = 6, subtraimos a metade (4) indo assim parar � posi��o 6-4 = 2\n\n");

    for(int i = vamosImaginarQue/2; i < vamosImaginarQue; i++){
        *(arrayAlloc + i) = *(arrayAlloc + (i-(vamosImaginarQue/2)))*2;
    }

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc + %d = %d - no endere�o %p ",i, *(arrayAlloc + i), arrayAlloc + i);
    }
}

void p6(){
    printf("(2)(Premir A e D Para navegar)\nExemplo que a stora deu na aula (faz um pouco parte \"do que n�o se deve fazer\")\n");
    int vamosImaginarQue = 2;
    int *arrayAlloc = (int *) calloc(vamosImaginarQue, sizeof(int));

    printf("\n\tint *arrayAlloc = (int *) calloc(vamosImaginarQue, sizeof(int));\n\n");

    for(int i = 0; i < (vamosImaginarQue); i++){
        *(arrayAlloc + i) = i+2;
        printf("\n arrayAlloc + %d = %d - no endere�o %p ",i, *(arrayAlloc + i), arrayAlloc + i);
    }

    int *arrayAlloc2 = (int *) calloc(vamosImaginarQue, sizeof(int));

    printf("\n\n\tint *arrayAlloc2 = (int *) calloc(vamosImaginarQue, sizeof(int));\n\n");

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc2 + %d = %d - no endere�o %p ",i, *(arrayAlloc2 + i), arrayAlloc2 + i);
    }

    printf("\n\nComo podes ver os endere�os de mem�ria s�o diferentes (s�o variaveis diferentes)");

    arrayAlloc2 = (int *) realloc(arrayAlloc, vamosImaginarQue * sizeof(int));

    printf("\n\n\tarrayAlloc2 = (int *) realloc(arrayAlloc, vamosImaginarQue * sizeof(int))\n\n"
           "Realoca��o do arrayAlloc2 baseada no arrayAlloc\n\n");


    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc  + %d = %d - no endere�o %p ",i, *(arrayAlloc2 + i), arrayAlloc2 + i);
    }
        printf("\n");

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc2 + %d = %d - no endere�o %p ",i, *(arrayAlloc2 + i), arrayAlloc2 + i);
    }

    printf("\n\nO que fizemos n�o foi \"copiar\" os valores, mas sim redirecionar o endere�o\n"
           "Se fizermos:\n\n\t*(arrayAlloc2 + 0) = 2000;\n\nObservamos que os arrays est�o dependentes um do outro:\n");

    *(arrayAlloc2 + 0) = 2000;

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc  + %d = %d - no endere�o %p ",i, *(arrayAlloc2 + i), arrayAlloc2 + i);
    }
        printf("\n");

    for(int i = 0; i < (vamosImaginarQue); i++){
        printf("\n arrayAlloc2 + %d = %d - no endere�o %p ",i, *(arrayAlloc2 + i), arrayAlloc2 + i);
    }

}

void allocRealloc(){

    /**< (1) Declara��o de um array pela forma convencional */
    int array[4] = {1, 2 ,3 ,4};

    /**< (2) Declara��o de um array pela forma convencional */
    int *arrayAlloc = NULL;
    int vamosImaginarQue = 4;

    arrayAlloc = (int *) calloc(vamosImaginarQue, sizeof(int));
    vamosImaginarQue = 2 * vamosImaginarQue;
    arrayAlloc = (int *) realloc(arrayAlloc, vamosImaginarQue * sizeof(int));

}

int main()
{
    setlocale(LC_CTYPE,"Portuguese");
    system("mode 140, 40");

    char arrows;

    int track = 1;
    clrgetch(track);
    do{
        arrows = getch();
        switch(arrows){
    case 'a':
        if(track > 1){track--;
        clrgetch(track);}

        break;

    case 'd':
        if(track < 7){track++;
        clrgetch(track);}

        break;}
    }while(arrows !=13);

}
