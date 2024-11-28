#include <queue>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "HCTree.hpp"
#include "Helper.hpp"
#include "int24.hpp"
using namespace std;

void uncompress(const char* comp_file, const char* uncomp_file){
    FancyInputStream compressed_file = FancyInputStream(comp_file);

    if(!compressed_file.good()){
        error("Problem with opening the compressed file");
    }

    vector <int> freqs(256);

    uint8_t curr_byte_0;
    uint8_t curr_byte_1;
    uint8_t curr_byte_2;
    int numb_char = 0;

    for(int i = 0; i < 256; i++){
        curr_byte_0 = compressed_file.read_byte();
        curr_byte_1 = compressed_file.read_byte();
        curr_byte_2 = compressed_file.read_byte();

        struct int24 freq_reduced;
        freq_reduced.bytes[0] = curr_byte_0;
        freq_reduced.bytes[1] = curr_byte_1;
        freq_reduced.bytes[2] = curr_byte_2;

        int freq = int24::int24_to_int(freq_reduced);

        freqs[i] = freq;
        numb_char += freq;
    }

    HCTree HCT;
    HCT.build(freqs);
    
    FancyOutputStream uncompressed = FancyOutputStream(uncomp_file);

    if(!uncompressed.good()){
        error("Problem with the uncompressed file");
    }

    if(!compressed_file.filesize()){
        return;
    }

    for(int i = 0; i < numb_char; i++){
        unsigned char symbol = HCT.decode(compressed_file);
        uncompressed.write_byte(symbol);
    }

    cout << "file uncompressed" << endl;
    
}

int main(int argc, char* argv[]){
    if(argc != 3){
        error("Wrong parameters for uncompressing");
    }
    else {
        uncompress(argv[1], argv[2]);
        return 0;
    }
}