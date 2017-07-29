/*
MIT License

Copyright (c) 2017 eykop

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <iostream>
#include <fstream>
#include <string>

bool readFileContent(const std::string& filePath, std::string& fileContent){  
    std::ifstream fin(filePath.c_str(), std::ios::binary | std::ios::in);
    if (fin) {
        long buff_size =1024*1000;
        long begin = fin.tellg();
        fin.seekg (0, std::ios::end);
        long end = fin.tellg();
        fin.seekg (0, std::ios::beg);
        long file_size = end - begin;
        long readed_data_size = 0;      
        while(readed_data_size< file_size) {      
            if (file_size - readed_data_size>buff_size){
                fileContent.resize(buff_size);
                readed_data_size+=buff_size;
            }else{
                fileContent.resize(file_size - readed_data_size);
                readed_data_size=file_size;
            }
            fin.read(&fileContent[0], fileContent.size());       
        }      
        fin.close();
        return true;
    }
    return false;
}


int main(int argc, char **argv)
{
	std::string data;
    bool a = readFileContent("jsonTestData.json", data);
    if(a){
        std::cout<<data<<std::endl; 
    }else{
        std::cout<<"failed to open and read file..."<<std::endl;
    }
	return 0;
}
