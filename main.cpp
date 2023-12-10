#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>



class Image{
    std::vector<std::vector<uint16_t>> mImage;
    std::string mType;
    uint16_t mWidth=0, mHeight=0, mWhite=0;
    uint16_t pixel(int pozx, int pozy){
        if(pozx>=0 && pozx<=mHeight-1 && pozy>=0 && pozy<=mWidth-1){
            return mImage[pozx][pozy];
        }
        if (pozx<0){
            pozx=0;
        }
        if (pozy<0){
            pozy=0;
        }
        if (pozx>mHeight-1){
            pozx=mHeight-1;
        }
        if (pozy>mWidth-1){
            pozy=mWidth-1;
        }
        return mImage[pozx][pozy];
    }
    uint16_t border(uint16_t pozx, uint16_t pozy, uint16_t window_size, const std::string& algorithm){
        std::vector<uint16_t> window(window_size*window_size);
        uint16_t k=0;
        for(int i=(-1)*(window_size/2);i<=(window_size/2);i++){
            for(int j=(-1)*(window_size/2);j<=(window_size/2);j++){
                window[k]= pixel(pozx+i, pozy+j);
                k++;
            }
        }
        if(algorithm=="merge"){
            std::sort(window.begin(), window.end());
        }
        else{
            for(int i=0;i<k-1;i++){
                for(int j=i+1;j<k;j++){
                    if(window[i]>window[j]) {
                        uint16_t aux = window[i];
                        window[i] = window[j];
                        window[j] = aux;
                    }
                }
            }
        }
        return window[(k-1)/2];
    }
public:
    Image():mImage(std::vector<std::vector<uint16_t>>()), mWidth(0), mHeight(0), mWhite(0){

    }
    Image(const std::string& input){
        std::fstream file(input, std::ios::in);
        if(!file.is_open()){
            std::cerr<<"The file couldn't be open";
            exit(1);
        }
        std::string read_data;
        file>>mType;
        file.get();
        while (std::getline(file, read_data) && read_data[0] == '#') {}
        std::stringstream data(read_data);
        data>>mWidth>>mHeight;
        file>>mWhite;
        mImage.resize(mHeight, std::vector<uint16_t>(mWidth));
        for(int i=0;i<mHeight;i++){
            for(int j=0;j<mWidth;j++) {
                uint16_t aux;
                file>>aux;
                mImage[i][j]=aux;
            }
        }
        file.close();
    }
    void Filtru_Median(uint16_t window_size, const std::string& algorithm){
        std::vector<std::vector<uint16_t>> aux=mImage;
        std::vector<uint16_t> window(window_size*window_size);
        for(int i=0;i<mHeight;i++){
            for(int j=0;j<mWidth;j++){
                aux[i][j]= border(i, j, window_size, algorithm);
            }
        }
        this->mImage=aux;
    }
    void print(const std::string &output){
        std::fstream fout(output, std::ios::out);
        fout<<mType<<'\n'<<mWidth<<' '<<mHeight<<'\n'<<mWhite<<'\n';
        for(int i=0;i<mHeight;i++){
            for(int j=0;j<mWidth;j++){
                fout<<mImage[i][j]<<' ';
            }
            fout<<'\n';
        }
        fout.close();
    }
};

int main() {
    std::string algorithm, input, output;
    uint16_t window_size;
    std::cin>>algorithm>>window_size>>input>>output;

    Image imagine(input);
    imagine.Filtru_Median(window_size, algorithm);
    imagine.print(output);

    return 0;
}
