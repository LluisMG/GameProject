#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "../../dep/inc/XML/rapidxml.hpp"#include "../../dep/inc/XML/rapidxml_utils.hpp"#include "../../dep/inc/XML/rapidxml_iterators.hpp"#include "../../dep/inc/XML/rapidxml_print.hpp"int blabla(int, char*[]) {
	rapidxml::xml_document<> doc;	std::ifstream file("../../res/files/enemigos.xml");	//std::stringstream buffer;	//buffer << file.rdbuf();	file.close();	//std::string content(buffer.str());	//doc.parse<0>(&content[0]);	//std::cout << doc.first_node()->name() << "\n";	return 0;}