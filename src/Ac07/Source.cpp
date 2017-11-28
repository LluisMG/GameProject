#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "../../dep/inc/XML/rapidxml.hpp"#include "../../dep/inc/XML/rapidxml_utils.hpp"#include "../../dep/inc/XML/rapidxml_iterators.hpp"#include "../../dep/inc/XML/rapidxml_print.hpp"

int main(int, char*[]) {

	rapidxml::xml_document<> doc;	std::ifstream file("../../res/files/enemigos.xml");	std::stringstream buffer;	buffer << file.rdbuf();	file.close();	std::string content(buffer.str());	doc.parse<0>(&content[0]);	
	std::cout << doc.first_node()->name();

	rapidxml::xml_node<> *pRoot = doc.first_node();

	for (rapidxml::xml_node<> *pNode = pRoot->first_node("enemigo");pNode; pNode = pNode->next_sibling()){
		std::cout << pNode->name << ':' << '\n';
		for (rapidxml::xml_node<> *pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
			std::cout << pNodeI->name() << ':' << pNodeI->value() << '\n';
		};
		std::cout << '\n';
	}	
	
	std::getchar();
	return 0;
}