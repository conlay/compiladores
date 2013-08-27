#include <stdio.h>
#include <stdlib.h>
#include "comp_grammar.h"
#include "comp_dict.h"

static inline void __comp_grammar_symbol_init(comp_grammar_symbol_t *grammar_symbol) {
    grammar_symbol->type = IKS_SIMBOLO_INDEFINIDO;
    grammar_symbol->code_line_number = 0;
    grammar_symbol->value = NULL;
}

comp_grammar_symbol_t *new_comp_grammar_symbol() {
    comp_grammar_symbol_t *grammar_symbol;
    grammar_symbol = malloc(sizeof(comp_grammar_symbol_t));
    __comp_grammar_symbol_init(grammar_symbol);
    return grammar_symbol;
}

void comp_grammar_symbol_delete(comp_grammar_symbol_t *grammar_symbol) {
    free(grammar_symbol->value);
    grammar_symbol->value = NULL;
    free(grammar_symbol);
    grammar_symbol = NULL;
}

void comp_grammar_symbol_set(comp_grammar_symbol_t *grammar_symbol, int type, int code_line_number, void *value) {
    grammar_symbol->type = type;
    grammar_symbol->code_line_number = code_line_number;
    grammar_symbol->value = value;
}

void comp_grammar_symbol_print(comp_grammar_symbol_t *grammar_symbol) {
    printf("%s\n",(char *)grammar_symbol->value);
}

void symbol_table_append(char *identifier, comp_grammar_symbol_t *symbol) {
    comp_dict_t *new_entry;
    new_entry = new_comp_dict();
    new_entry->item = new_comp_dict_item();
    comp_dict_item_set(new_entry->item,identifier,(void *)symbol);
    comp_dict_append(symbol_table,new_entry);
}

void symbol_table_init() {
    symbol_table = new_comp_dict();
    comp_grammar_symbol_t *symbol;
    symbol = new_comp_grammar_symbol();
    symbol_table->item = new_comp_dict_item();
    comp_dict_item_set(symbol_table->item,"root",(void *)symbol);
}

void symbol_table_print() {
    comp_dict_print(symbol_table);
}

