void main(void) {
    volatile char* video = (volatile char*)0xb8000;

    char palavra[] = "pneumoultramicroscopicossilicovulcanoconiótico";
    int tamanho = sizeof(palavra)/sizeof(palavra[0]);

    for (int i = 0; i < tamanho; i++)
    {
        video[i*2] = palavra[i];
        video[i*2+1] = 0x07;
    }

    while(1);
}