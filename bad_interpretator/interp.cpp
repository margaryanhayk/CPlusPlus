#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>  


//xosqi a = 2;
//xosqi b = 4;
//xosqi d = "asd";
//xosqi c = b * 5;
//print c;
//print b;
//print d;

struct S {
    std::string name;
    std::string value;
    std::string type;
};

std::vector<S> variables;
std::vector<std::string> line_to_words(const std::string& str) {
    std::string word;
    std::vector<std::string> line_of_words;
    std::vector<int> index;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '"') {
            index.push_back(i);
        }
    }
    if (index.size() == 0) {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                line_of_words.push_back(word);
                word = "";
            }
            else if (i == str.size() - 1) {
                word += str[i];
                line_of_words.push_back(word);
            }
            else {
                word += str[i];
            }
        }
        return line_of_words;
    }
    else if (index.size() == 2) {
        for (int i = 0; i < index[0]; ++i) {
            if (str[i] == ' ') {
                line_of_words.push_back(word);
                word = "";
            }
            else {
                word += str[i];
            }
        }
        word = "";
        for (int i = index[0]; i < index[1] + 1; ++i) {
            word += str[i];
        }
        line_of_words.push_back(word);
        word = "";
        for (int i = index[1] + 2; i < str.size(); ++i) {
            if ((str[i] == ' ') && (word != "")) {
                line_of_words.push_back(word);
                word = "";
            }
            else if (i == str.size() - 1) {
                word += str[i];
                line_of_words.push_back(word);
            }
            else {
                word += str[i];
            }
        }
        return line_of_words;
    }
    else {
        line_of_words.push_back("Pnti text");
        return line_of_words;
    }
}

int return_index_by_name(std::string name, std::vector<S> variables) {
    for (int i = 0; i < variables.size(); ++i) {
        if (name == variables[i].name) {
            return i;
        }
    }
}
bool string_is_int(const std::string& str) {
    int i = 0;
    if ((str[i] == '-') || (str[i] == '+')) {
        if (str.size() == 1) {
            return false;
        }
        else { ++i; }
    }
    for (; i < str.size(); ++i) {
        if ((str[i] > 57) || (str[i] < 48)) {
            return false;
        }
    }
    return true;
}
bool string_is_var(const std::string& str, std::vector<S> variables) {
    for (int i = 0; i < variables.size(); ++i) {
        if (str == variables[i].name) {
            return true;
        }
    }
    return false;
}
bool string_is_double(const std::string& str) {
    if (str.find('.') == std::string::npos) {
        return false;
    }
    else if (str.find('.') == str.size() - 1) {
        return false;
    }
    else {
        int i = 0;
        if ((str[i] == '-') || (str[i] == '+')) {
            if (str.size() == 1) {
                return false;
            }
            else { ++i; }
        }
        if (str.find('.') == i) {
            return false;
        }
        for (; i < str.find('.'); ++i) {
            if ((str[i] > 57) || (str[i] < 48)) {
                return false;
            }
        }
        for (int k = str.find('.') + 1; k < str.size(); ++k) {
            if ((str[k] > 57) || (str[k] < 48)) {
                return false;
            }
        }
        return true;
    }
}
bool string_is_string(const std::string& str) {
    if (str[0] == '"' && str[str.size() - 1] == '"') {
        return true;
    }
    else {
        return false;
    }
}
std::string check_and_get_clean_string(const std::string& str) {
    if (str[0] == str[str.size() - 1] && str[0] == '"') {
        std::string tmp;
        for (int i = 1; i < str.size() - 1; ++i) {
            tmp += str[i];
        }
        return tmp;
    }
    else {
        return "Pnti text";
    }
}
std::string detect_type(const std::string& str) {
    if (string_is_int(str)) {
        return "int";
    }
    else if (string_is_double(str)) {
        return "double";
    }
    else if (string_is_string(str)) {
        return "string";
    }
    else {
        return "undefined";
    }
}
std::string line_meaning(const std::vector<std::string>& line_of_words) {
    if (line_of_words[0] == "Pnti text") {
        return "Pnti Text";
    }
    else if (line_of_words[0][0] == '*') {
        return "comment";
    }
    else if (line_of_words[0] == "print") {
        return "print";
    }
    else if (line_of_words[0] == "xosqi") {
        return "declaration";
    }
    else if (line_of_words[1] == "=") {
        return "attribution";
    }
    else {
        return "other";
    }
}
std::vector<std::string> logic_operation(std::vector<std::string>& line) {
    std::vector<std::string> new_line;
    S temp1;
    S temp2;
    S temp3;
    for (int i = 1; i < line.size(); ++i) {
        if ((line[i].find('+') != std::string::npos) && (line[i].size() == 1)) {
            if (string_is_var(line[i - 1], variables)) {
                int index = return_index_by_name(line[i - 1], variables);
                temp1.value = variables[index].value;
                temp1.type = variables[index].type;
            }
            else {
                temp1.type = detect_type(line[i - 1]);
                temp1.value = line[i - 1];
            }
            if (string_is_var(line[i + 1], variables)) {
                int index = return_index_by_name(line[i + 1], variables);
                temp2.value = variables[index].value;
                temp2.type = variables[index].type;
            }
            else {
                temp2.type = detect_type(line[i + 1]);
                temp2.value = line[i + 1];
            }
            if ((temp1.type == temp2.type) && (temp1.type == "int")) {
                int x = (std::stoi((temp1.value)) + std::stoi((temp2.value)));
                temp3.value = std::to_string(x);
                temp3.type = temp1.type;
            }
            else if (temp1.type == temp2.type) {
                temp3.value = temp1.value + temp2.value;
                temp3.type = temp1.type;
            }
            else {
                std::cout << "There are different type, this is not JS.." << std::endl;
                new_line.push_back("Sxal hashvark");
                return new_line;
            }
            variables.push_back(temp3);
            for (int j = 0; j < i - 1; ++j) {
                new_line.push_back(line[j]);
            }

            new_line.push_back(temp3.value);

            for (int j = i + 2; j < line.size(); ++j) {
                new_line.push_back(line[j]);
            }
            return new_line;
        }
        if ((line[i].find('-') != std::string::npos) && (line[i].size() == 1)) {
            if (string_is_var(line[i - 1], variables)) {
                int index = return_index_by_name(line[i - 1], variables);
                temp1.value = variables[index].value;
                temp1.type = variables[index].type;
            }
            else {
                temp1.type = detect_type(line[i - 1]);
                temp1.value = line[i - 1];
            }
            if (string_is_var(line[i + 1], variables)) {
              
                int index = return_index_by_name(line[i - 1], variables);
                temp2.value = variables[index].value;
                temp2.type = variables[index].type;
            }
            else {
                temp2.type = detect_type(line[i + 1]);
                temp2.value = line[i + 1];
            }
            if ((temp1.type == temp2.type) && (temp1.type == "int")) {
                int x = (std::stoi((temp1.value)) - std::stoi((temp2.value)));
                temp3.value = std::to_string(x);
                temp3.type = temp1.type;
            }
            else {
                std::cout << "There are different type, this is no JS.." << std::endl;
                new_line.push_back("Sxal hashvark");
                return new_line;
            }
            variables.push_back(temp3);
            for (int j = 0; j < i - 1; ++j) {
                new_line.push_back(line[j]);
            }
            new_line.push_back(temp3.name);
            for (int j = i + 1; j < line.size(); ++j) {
                new_line.push_back(line[j]);
            }
            return new_line;
        }
        if ((line[i].find('/') != std::string::npos) && (line[i].size() == 1)) {
            if (string_is_var(line[i - 1], variables)) {
                int index = return_index_by_name(line[i - 1], variables);
                temp1.value = variables[index].value;
                temp1.type = variables[index].type;
            }
            else {
                temp1.type = detect_type(line[i - 1]);
                temp1.value = line[i - 1];
            }
            if (string_is_var(line[i + 1], variables)) {
                int index = return_index_by_name(line[i - 1], variables);

                temp2.value = variables[index].value;
                temp2.type = variables[index].type;
            }
            else {
                temp2.type = detect_type(line[i + 1]);
                temp2.value = line[i + 1];
            }
            if ((temp1.type == temp2.type) && (temp1.type == "int")) {
                int x = (std::stoi((temp1.value)) / std::stoi((temp2.value)));
                temp3.value = std::to_string(x);
                temp3.type = temp1.type;
            }
            else {
                std::cout << "There are different type, this is no JS.." << std::endl;
                new_line.push_back("Sxal hashvark");
                return new_line;
            }
            variables.push_back(temp3);
            for (int j = 0; j < i - 1; ++j) {
                new_line.push_back(line[j]);
            }
            new_line.push_back(temp3.name);
            for (int j = i + 1; j < line.size(); ++j) {
                new_line.push_back(line[j]);
            }
            return new_line;
        }
        if ((line[i].find('*') != std::string::npos) && (line[i].size() == 1)) {
            if (string_is_var(line[i - 1], variables)) {
      
                int index = return_index_by_name(line[i - 1], variables);
                temp1.value = variables[index].value;
                temp1.type = variables[index].type;
            }
            else {
                temp1.type = detect_type(line[i - 1]);
                temp1.value = line[i - 1];
            }
            if (string_is_var(line[i + 1], variables)) {
                int index = return_index_by_name(line[i - 1], variables);

                temp2.value = variables[index].value;
                temp2.type = variables[index].type;
            }
            else {
                temp2.type = detect_type(line[i + 1]);
                temp2.value = line[i + 1];
            }
            if ((temp1.type == temp2.type) && (temp1.type == "int")) {
                int x = (std::stoi((temp1.value)) * std::stoi((temp2.value)));
                temp3.value = std::to_string(x);
                temp3.type = temp1.type;
            }
            else {
                std::cout << "There are different type, this is no JS.." << std::endl;
                new_line.push_back("Sxal hashvark");
                return new_line;
            }
            variables.push_back(temp3);
            for (int j = 0; j < i - 1; ++j) {
                new_line.push_back(line[j]);
            }
            new_line.push_back(temp3.name);
            for (int j = i + 1; j < line.size(); ++j) {
                new_line.push_back(line[j]);
            }
            return new_line;
        }
    }
    new_line = line;
    return new_line;
}
void analysing_line(std::vector<std::string>& my_line) {
    if (line_meaning(my_line) == "Pnti text") {
        std::cout << "Pnti text" << std::endl;
        return;
    }
    else if (line_meaning(my_line) == "comment") {
        return;
    }
    else if (line_meaning(my_line) == "other") {
        std::cout << "Pnti text" << std::endl;
        return;
    }
    else if (line_meaning(my_line) == "declaration") {
        my_line = logic_operation(my_line);
        S temp;
        for (int i = 0; i < variables.size(); ++i) {
            if (my_line[1] == variables[i].name) {
                std::cout << "variable " << my_line[1] << " is already declarated..." << std::endl;
                return;
            }
        }
        temp.name = my_line[1];
        if (my_line[2] == "=") {
            if (string_is_var(my_line[3] , variables)) {
                temp.value = variables[return_index_by_name(my_line[3], variables)].value;
                temp.type = variables[return_index_by_name(my_line[3], variables)].type;
            }
            else {
                temp.value = my_line[3];
                temp.type = detect_type(my_line[3]);
            }
        }
        else if (my_line[2] == ";") {
            temp.value = "undefined";
            temp.type = "undefined";
        }
        else {
            std::cout << "Please follow to guide <how to use my script> to declare clearly, aper jan" << std::endl;
            return;
        }
        variables.push_back(temp);
        return;
    }
    else if (line_meaning(my_line) == "attribution") {
        my_line = logic_operation(my_line);
        S temp;
        if (!string_is_var(my_line[2], variables)) {
            for (int i = 0; i < variables.size(); ++i) {
                if (my_line[0] == variables[i].name) {
                    variables[i].type = detect_type(my_line[2]);
                    variables[i].value = my_line[2];
                    variables.push_back(temp);
                    return;
                }
            }
            std::cout << "variable " << my_line[0] << " is not declared..." << std::endl;
            return;
        }
        else {
            variables[return_index_by_name(my_line[0], variables)].value = variables[return_index_by_name(my_line[2], variables)].value;
            variables[return_index_by_name(my_line[0], variables)].type = variables[return_index_by_name(my_line[2], variables)].type;
            variables.push_back(temp);
            return;
        }
    }
    else if (line_meaning(my_line) == "print") {
        my_line = logic_operation(my_line);
        for (int i = 0; i < variables.size(); ++i) {
            if (my_line[1] == variables[i].name) {
                if (variables[i].type == "string") {
                   std::cout << check_and_get_clean_string(variables[i].value) << std::endl;
                    return;
                }
                else if (variables[i].type == "int") {
                    std::cout << variables[i].value << std::endl;
                    return;
                }
                else if (variables[i].type == "double") {
                    std::cout << variables[i].value << std::endl;
                    return;
                }
                else if (variables[i].type == "undefined") {
                    std::cout << "[" << variables[i].name << "] is not initilized" << std::endl;
                    return;
                }
                else {

                    std::cout << "[" << variables[i].name << "] popxakany pchacrel es" << std::endl;
                    return;
                }
            }
        }
        if (check_and_get_clean_string(my_line[1]) != "Pnti text") {
            std::cout << check_and_get_clean_string(my_line[1]) << std::endl;
            return;
        }
        else if (string_is_int(my_line[1])) {
            std::cout << my_line[1] << std::endl;
        }
        else {
            std::cout << "Pnti print" << std::endl;
            return;
        }

    }
}
std::vector<std::string> logic_operation(const std::vector<std::string>& line) {
    std::vector<std::string> new_line;
    S temp1;
    S temp2;
    S temp3;
    for (int i = 1; i < line.size(); ++i) {
        if ((line[i].find('+') != std::string::npos) && (line[i].size()==1)) {
            if (string_is_var(line[i - 1], variables)) {
                temp1.value = variables[i-1].value;
                temp1.type = variables[i-1].type;
            }
            else {
                temp1.type = detect_type(line[i-1]);
                temp1.value = line[i - 1];
            }
            if (string_is_var(line[i + 1], variables)) {
                temp2.value = variables[i + 1].value;
                temp2.type = variables[i + 1].type;
            }
            else {
                temp2.type = detect_type(line[i + 1]);
                temp2.value = line[i + 1];
            }
            if ((temp1.type == temp2.type) && (temp1.type == "int") ) {
                temp3.value = (std::stoi((temp1.value)) + std::stoi((temp2.value)));
                temp3.type = temp1.type;
            }
            else if (temp1.type == temp2.type) {
                temp3.value = temp1.value + temp2.value;
                temp3.type = temp1.type;
            }
            else {
                std::cout << "There are different type, this is no JS.." << std::endl;
                new_line.push_back("Sxal hashvark");
                return new_line;
            }
            variables.push_back(temp3);
            for (int j = 0; j < i-1; ++j) {
                new_line.push_back(line[j]);
            }
            new_line.push_back(temp3.name);
            for (int j = i+1; j < line.size() ; ++j) {
                new_line.push_back(line[j]);
            }
            return new_line;
        }
        else if ((line[i].find('-') != std::string::npos) && (line[i].size() == 1)) {
            if (string_is_var(line[i - 1], variables)) {
                temp1.value = variables[i - 1].value;
                temp1.type = variables[i - 1].type;
            }
            else {
                temp1.type = detect_type(line[i - 1]);
                temp1.value = line[i - 1];
            }
            if (string_is_var(line[i + 1], variables)) {
                temp2.value = variables[i + 1].value;
                temp2.type = variables[i + 1].type;
            }
            else {
                temp2.type = detect_type(line[i + 1]);
                temp2.value = line[i + 1];
            }
            if ((temp1.type == temp2.type) && (temp1.type == "int") ) {
                temp3.value =  (std::stoi ((temp1.value)) - std::stoi ((temp2.value)));
                temp3.type = temp1.type;
            }
            else {
                std::cout << "There are different type, this is no JS.." << std::endl;
                new_line.push_back("Sxal hashvark");
                return new_line;
            }
            variables.push_back(temp3);
            for (int j = 0; j < i - 1; ++j) {
                new_line.push_back(line[j]);
            }
            new_line.push_back(temp3.name);
            for (int j = i + 1; j < line.size(); ++j) {
                new_line.push_back(line[j]);
            }
            return new_line;
        }
        else if ((line[i].find('/') != std::string::npos) && (line[i].size() == 1)) {
            if (string_is_var(line[i - 1], variables)) {
                temp1.value = variables[i - 1].value;
                temp1.type = variables[i - 1].type;
            }
            else {
                temp1.type = detect_type(line[i - 1]);
                temp1.value = line[i - 1];
            }
            if (string_is_var(line[i + 1], variables)) {
                temp2.value = variables[i + 1].value;
                temp2.type = variables[i + 1].type;
            }
            else {
                temp2.type = detect_type(line[i + 1]);
                temp2.value = line[i + 1];
            }
            if ((temp1.type == temp2.type) && (temp1.type == "int")) {
                temp3.value = (std::stoi((temp1.value)) / std::stoi((temp2.value)));
                temp3.type = temp1.type;
            }
            else {
                std::cout << "There are different type, this is no JS.." << std::endl;
                new_line.push_back("Sxal hashvark");
                return new_line;
            }
            variables.push_back(temp3);
            for (int j = 0; j < i - 1; ++j) {
                new_line.push_back(line[j]);
            }
            new_line.push_back(temp3.name);
            for (int j = i + 1; j < line.size(); ++j) {
                new_line.push_back(line[j]);
            }
            return new_line;
        }
        else if ((line[i].find('*') != std::string::npos) && (line[i].size() == 1)) {
            if (string_is_var(line[i - 1], variables)) {
                temp1.value = variables[i - 1].value;
                temp1.type = variables[i - 1].type;
            }
            else {
                temp1.type = detect_type(line[i - 1]);
                temp1.value = line[i - 1];
            }
            if (string_is_var(line[i + 1], variables)) {
                temp2.value = variables[i + 1].value;
                temp2.type = variables[i + 1].type;
            }
            else {
                temp2.type = detect_type(line[i + 1]);
                temp2.value = line[i + 1];
            }
            if ((temp1.type == temp2.type) && (temp1.type == "int")) {
                temp3.value = (std::stoi((temp1.value)) * std::stoi((temp2.value)));
                temp3.type = temp1.type;
            }
            else {
                std::cout << "There are different type, this is no JS.." << std::endl;
                new_line.push_back("Sxal hashvark");
                return new_line;
            }
            variables.push_back(temp3);
            for (int j = 0; j < i - 1; ++j) {
                new_line.push_back(line[j]);
            }
            new_line.push_back(temp3.name);
            for (int j = i + 1; j < line.size(); ++j) {
                new_line.push_back(line[j]);
            }
            return new_line;
        }
    }
    new_line = line;
    return new_line;
}

int main()
{
    std::string line;
    std::ifstream myFile("C:/Users/hmargar/Desktop/test1.txt");
    if (myFile.is_open())
    {
        while (std::getline(myFile, line))
        {
            std::vector<std::string> vectorchik = line_to_words(line);
            if (vectorchik.size() != 0) {
                analysing_line(vectorchik);
            }
        }
    }
    else {
        std::cout << "Unable to open file";
    }
}

