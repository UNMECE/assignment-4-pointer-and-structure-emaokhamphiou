#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
    item_list[index].price = price;
    item_list[index].sku = malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);
    item_list[index].name = malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
    item_list[index].category = malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);
}

void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }
}

double average_price(Item *item_list, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += item_list[i].price;
    }
    return sum / size;
}

void print_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %.6f\n", item_list[i].price);
        printf("###############\n");
    }
}

int main(int argc, char *argv[]) {
    int size = 5;
    Item *item_list = malloc(size * sizeof(Item));

    add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 2.50, "11111", "snacks", "hot cheetos", 2);
    add_item(item_list, 4.20, "22222", "beverages", "sprite", 3);
    add_item(item_list, 1.80, "00000", "fruits", "grapes", 4);

    print_items(item_list, size);
    printf("average price of items = %.6f\n", average_price(item_list, size));

    if (argc == 2) {
        char *sku_to_find = argv[1];
        int found = 0;
        int ct = 0;
        while (ct < size && strcmp(item_list[ct].sku, sku_to_find) != 0) {
            ct++;
        }
        if (ct < size) {
            printf("Found item:\n");
            printf("item name = %s\n", item_list[ct].name);
            printf("item sku = %s\n", item_list[ct].sku);
            printf("item category = %s\n", item_list[ct].category);
            printf("item price = %.6f\n", item_list[ct].price);
        } else {
            printf("Item not found.\n");
        }
    }

    free_items(item_list, size);
    free(item_list);

    return 0;
}