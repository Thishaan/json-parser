
#include <iostream>
#include <fstream>
#include <unordered_map>

using str_view = std::string_view; 
using json_vector = std::vector<str_view>;
using json_map = std::unordered_map<str_view, json_vector>;




enum state{
    START,
    KEY,
    VALUE,
};
struct json_parser{



    void parse_json(const std::string& file){
        in.open(file);

        if(!in.is_open()){
            std::cerr << "Error opening file: " << file << std::endl;
            exit(EXIT_FAILURE); //exit program rn
        }
         

        ///TODO: implement parsing logic here


    }

    private:
        std::ifstream in;
        json_map data;
} 


int main(){






    return 0;
}