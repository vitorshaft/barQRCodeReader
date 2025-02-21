# barQRCodeReader

Um projeto em C++ que utiliza OpenCV e ZBar para detectar e ler QR codes e códigos de barras em tempo real a partir da webcam.

## Descrição

Este projeto é um exemplo prático de como usar a biblioteca OpenCV para capturar vídeo da webcam e a biblioteca ZBar para detectar e decodificar QR codes e códigos de barras. O programa exibe as informações decodificadas na tela e desenha um retângulo ao redor do código detectado.

## Funcionalidades

- Detecção de QR codes e códigos de barras em tempo real.
- Exibição das informações decodificadas no terminal e na janela da webcam.
- Desenho de um retângulo ao redor do código detectado.
- Fácil integração com sistemas que necessitam de leitura de códigos.

## Demonstração

### Leitura de Código de Barras

![Leitura de Código de Barras](barcode.gif)

### Leitura de QR Code

![Leitura de QR Code](QRCodeCPP.gif)

## Como Usar

### Pré-requisitos

- Compilador C++ (g++ ou similar).
- OpenCV instalado.
- ZBar instalado.

### Instalação

1. Clone o repositório:
   ```bash
   git clone https://github.com/vitorshaft/barQRCodeReader.git
   cd barQRCodeReader
   ```

2. Compile o código:
   ```bash
   g++ -I"C:/msys64/mingw64/include/opencv4" -I"C:/msys64/mingw64/include/zbar" -o barcode_qr_webcam barcode_qr_webcam.cpp -L"C:/msys64/mingw64/lib" -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lzbar
   ```

### Execução

Execute o programa:
```bash
./barcode_qr_webcam
```

### Controles

- **Pressione `q`** para sair do programa.

## Estrutura do Projeto

```
barQRCodeReader/
├── barcode_qr_webcam.cpp  # Código-fonte principal
├── barcode_qr_webcam.exe  # Executável (após compilação)
├── README.md              # Este arquivo
├── barcode.gif            # GIF de demonstração (código de barras)
└── QRCodeCPP.gif          # GIF de demonstração (QR code)
```

## Contribuição

Contribuições são bem-vindas! Siga os passos abaixo:

1. Faça um fork do projeto.
2. Crie uma branch para sua feature (`git checkout -b feature/nova-feature`).
3. Commit suas mudanças (`git commit -m 'Adicionando nova feature'`).
4. Push para a branch (`git push origin feature/nova-feature`).
5. Abra um Pull Request.

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.