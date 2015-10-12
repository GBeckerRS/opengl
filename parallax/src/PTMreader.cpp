#include        "inc/PTMreader.h"

#include        <iostream>

GBK::PTMreader::PTMreader (std::string nome)
{
    this->arq = new GBK::Arquivo ((char*)nome.c_str (), true);
}

GBK::Imagem* GBK::PTMreader::getImagem ()
{
    int estado = 0;
    int valorMaximoCanal = 0;
    int tamanho = 0;
    int largura = 0;
    int altura = 0;
    GBK::Imagem* img = 0;
    this->buffer << this->arq->le ();
    while (true)
    {
        std::string linha;
        getline (this->buffer,linha);
        switch (estado)
        {
            case 0:
                if (linha == "P7")
                {
                    std::cout << "linha: " << linha << std::endl;
                    estado = 10;
                }
            break;
            case 10:
                {
                    std::stringstream ss;
                    largura = 0;
                    altura = 0;
                    ss << linha;
                    while (!ss.eof ())
                    {
                        if (largura == 0)
                        {
                            ss >> largura;
                        }
                        else
                        {
                            if (altura == 0)
                            {
                                ss >> altura;
                            }
                        }
                    }
                    if (largura != 0 && altura != 0)
                    {
                        img = new GBK::Imagem (largura, altura);
                        tamanho = largura * altura;
                        estado = 30;
                    }
                }
            break;
            case 30:
                {
                    std::stringstream ss;
                    ss << linha;
                    ss >> valorMaximoCanal;
                    estado = 40;
                }
            break;
            case 40:
                {
                    if (linha[0] == '#')
                    {
                        break;
                    }
                    std::stringstream ss;
                    ss << linha;
                    int alpha = 0, red = 0, green = 0, blue = 0;
                    int i = 0;  // Contador de pixels
                    while (!ss.eof () && (i < tamanho))
                    {
                        ss >> alpha >> red >> green >> blue;
                        int argb = 0;
                        int pX = i % largura;
                        int pY = ((tamanho-1) - i) / largura;
                        img->empacotaPixel (alpha, red, green, blue, &argb);
                        img->setPixel (argb, pX, pY);
                        i++;
                        
                    }
                    estado = 50;
                }
            break;
        };
        if (estado == 50)
        {
            break;
        }
    }
    return img;
}

