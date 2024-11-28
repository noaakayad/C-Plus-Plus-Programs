#include <queue>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdint>
#include "HCTree.hpp"
#include "Helper.hpp"
#include "int24.hpp"
using namespace std;

void compress(const char* filename, const char* out_filename){
    FancyInputStream file_to_compress = FancyInputStream(filename);

    if(!file_to_compress.good()){
        error("Problem with file to compress");
    }

    vector<int> freqs(256, 0);

    int curr_byte = file_to_compress.read_byte();

    int numb_char = 0;
    while(curr_byte != -1){
        freqs[curr_byte] += 1;
        curr_byte = file_to_compress.read_byte();
        numb_char += curr_byte;
    }

    HCTree HCT;
    HCT.build(freqs);

    FancyOutputStream compressed_file = FancyOutputStream(out_filename);

    if (!compressed_file.good()) {
        error("Problem compress file");
    }

    if(numb_char == 0){
        return;
    }
    
    for (int i = 0; i < 256; i++){
        int24 int_reduced = int24::int_to_int24(freqs[i]);
        compressed_file.write_byte(int_reduced.bytes[0]);
        compressed_file.write_byte(int_reduced.bytes[1]);
        compressed_file.write_byte(int_reduced.bytes[2]);
    }

    file_to_compress.reset();

    curr_byte = file_to_compress.read_byte();

    while(curr_byte != -1){
        HCT.encode(curr_byte, compressed_file);
        curr_byte = file_to_compress.read_byte();
    }

    cout << "file compressed" << endl;
}

int main(int argc, char* argv[]){
    if(argc != 3){
        error("Wrong parameters");
    }
    else {
        compress(argv[1], argv[2]);
        return 0;
    }
}