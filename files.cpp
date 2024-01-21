# include <iostream>
# include <fstream>

int main() {
    /* Criação e escrita de arquivo */
    std::ofstream file("file_name.txt");
    file << "Arquivo de text, aqui é onde é inserido o texto que estára dentro do arquivo.";
    file.close(); // Nunca esqueça de fechar!!

    /* Leitura de arquivo */
    std::ifstream file_in("file_name.txt");
    std::string txt;
    while (getline(file_in, txt)) {
        std::cout << txt;
    }
    file_in.close();
}