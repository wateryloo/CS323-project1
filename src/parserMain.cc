//
// Created by maozunyao on 2021/9/30.
//

#include <cstdio>
#include <iostream>
#include "SyntaxTreeNode.hh"
#include "parser.hpp"

void yyrestart(FILE *pFile);
int yyparse (void);
extern SyntaxTreeNode* root_node;

int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cout<<"PARSER_error_OUTPUT, no input path";
        return 1;
    } else if (argc > 2) {
        std::cout<<"too much input path";
        return 1;
    } else {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            std::cout<<"error of path %s";
            return 1;
        }
        yyrestart(f);
        yyparse();
        root_node->preOrderPrint(root_node,0);
    }
    return 0;
}

