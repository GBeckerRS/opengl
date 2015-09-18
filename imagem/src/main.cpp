#include        <iostream>

#include        "inc/display.h"
#include        "inc/imagem.h"

int main (int argc, char* argv[])
{
    GBK::Imagem* img = new GBK::Imagem (10, 10);
    img->noise ();

    GBK::inicializa (argc, argv, 400, 400, 100, 100);

    return 0;
}

