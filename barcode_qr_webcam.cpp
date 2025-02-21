#include <opencv2/opencv.hpp>
#include <zbar.h>
#include <iostream>

int main() {
    // Abre a webcam
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Erro ao abrir a webcam!" << std::endl;
        return -1;
    }

    // Configura o ZBar
    zbar::ImageScanner scanner;
    scanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);

    cv::Mat frame, gray;
    while (true) {
        // Captura um frame da webcam
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "Erro ao capturar o frame!" << std::endl;
            break;
        }

        // Converte o frame para escala de cinza
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        // Converte a imagem para o formato do ZBar
        zbar::Image zbar_image(gray.cols, gray.rows, "Y800", gray.data, gray.cols * gray.rows);

        // Escaneia a imagem
        scanner.scan(zbar_image);

        // Itera sobre os resultados
        for (zbar::Image::SymbolIterator symbol = zbar_image.symbol_begin(); symbol != zbar_image.symbol_end(); ++symbol) {
            // Exibe o tipo e os dados do código detectado
            std::string type = symbol->get_type_name();
            std::string data = symbol->get_data();

            std::cout << "Tipo: " << type << std::endl;
            std::cout << "Dados: " << data << std::endl;

            // Desenha um retângulo ao redor do código detectado
            std::vector<cv::Point> points;
            for (int i = 0; i < symbol->get_location_size(); i++) {
                points.push_back(cv::Point(symbol->get_location_x(i), symbol->get_location_y(i)));
            }
            cv::polylines(frame, points, true, cv::Scalar(0, 255, 0), 2);

            // Exibe os dados na imagem
            cv::putText(frame, data, points[0], cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 2);
        }

        // Exibe o frame com as anotações
        cv::imshow("Webcam", frame);

        // Aguarda 30 ms e verifica se a tecla 'q' foi pressionada para sair
        if (cv::waitKey(30) == 'q') {
            break;
        }
    }

    // Libera a webcam e fecha a janela
    cap.release();
    cv::destroyAllWindows();

    return 0;
}