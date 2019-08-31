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
        long bufferSize =1024;
        while(!fin.eof()) {      
	    auto delta = fileContent.size();
	    fileContent.resize(delta + bufferSize);
            fin.read(&fileContent[delta],bufferSize);
	    auto readedSize = fin.gcount();
	    //std::cout<<"readed size was: " << readedSize<<std::endl;
	    if(readedSize < bufferSize) {
                //std::cout<<"read fix size..."<<std::endl;
	        fileContent.resize(delta + readedSize);
	    }
	}
        fin.close();
        return true;
    }
    return false;
}


int main(int argc, char **argv)
{
    std::string data;
    if(readFileContent("jsonTestData.json", data)){
        std::cout<<data<<std::endl; 
    }else{
        std::cout<<"failed to open and read file..."<<std::endl;
    }
	return 0;
}
