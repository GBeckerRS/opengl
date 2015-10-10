#include        <iostream>
#include        <cstring>

#include        "arquivo.h"
#include        "PTMreader.h"

int main (void)
{
    char* pcTexto = new char[10];
    pcTexto = strcpy (pcTexto, "img_txt.PTM");
    GBK::PTMreader ptm (pcTexto);
    ptm.getImagem ();

    return 0;
}
