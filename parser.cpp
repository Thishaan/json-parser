
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using str_view = std::string_view; 
using json_vector = std::vector<str_view>;
using json_map = std::unordered_map<str_view, json_vector>;

using ss = std::stringstream;


typedef enum state{
    START,
    KEY,
    VALUE,
} state_t;
struct json_parser{



    void parse_json(const std::string& file){
        in.open(file);

        if(!in.is_open()){
            std::cerr << "Error opening file: " << file << std::endl;
            exit(EXIT_FAILURE); //exit program rn
        }
         
        std::string line;
        state_t current_state = START;

        std::string curr_key =  NULL;
        size_t pos_start;
        size_t pos_end;

        while(std::getline(in, line)){
             ss line_stream(line);
           
        switch(current_state){

                if(line.find('{') != std::string_view::npos){
                        current_state = KEY; 
                }
                    goto key;  // bcause ima primitive piece of shit
                    break;
        key:     case KEY:
              
                 if ((pos_start = line.find("\"")) != std::string::npos) {

                        if((pos_end = line.find("\"", pos_start)) != std::string::npos){
                            curr_key =  line.substr(pos_start, pos_end);
                             
                        }else{
                            exit(EXIT_FAILURE);
                        }
                        goto  value;  // why the fuck not
                }else{
                    exit(EXIT_FAILURE);
                }
                
                break;
        value : case VALUE:
                    //parse value
                    if((pos_start = line.find(":")) != std::string::npos){
                        
                         if((pos_start = line.find("[")) != std::string::npos){


                        }

                        // case of a string
                        else if((pos_start = line.find("\"")) != std::string::npos){

                        }

                        // assume misc case like a number or something. 
                        else{


                        }

                    }else{
                            exit(EXIT_FAILURE);
                    }

                    break;
            }
        }

    }

    private:
        std::ifstream in;
        json_map data;
        state_t state;
};


int main(){






    return 0;
}