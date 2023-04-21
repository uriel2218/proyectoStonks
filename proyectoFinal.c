#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para los productos
typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

// Función para imprimir el inventario
void imprimirInventario(Producto *inventario, int numProductos) {
    printf("\nInventario:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%s - Cantidad: %d - Precio: $%.2f\n", inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
}

// Función para realizar una venta
void realizarVenta(Producto *inventario, int numProductos) {
    char nombre[50];
    int cantidad;

    printf("\nNombre del producto: ");
    scanf("%s", nombre);

    printf("Cantidad: ");
    scanf("%d", &cantidad);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombre, inventario[i].nombre) == 0) {
            if (inventario[i].cantidad >= cantidad) {
                inventario[i].cantidad -= cantidad;
                printf("\nVenta realizada con éxito.\n");
                return;
            } else {
                printf("\nNo hay suficiente stock.\n");
                return;
            }
        }
    }
    printf("\nProducto no encontrado.\n");
}

// Función para imprimir el balance financiero
void imprimirBalance(Producto *inventario, int numProductos) {
    float ingresos = 0;
    float costos = 0;

    for (int i = 0; i < numProductos; i++) {
        ingresos += (inventario[i].cantidad * inventario[i].precio);
        costos += (inventario[i].cantidad * (inventario[i].precio / 2));
    }

    printf("\nBalance financiero:\n");
    printf("Ingresos: $%.2f\n", ingresos);
    printf("Costos: $%.2f\n", costos);
    printf("Ganancias: $%.2f\n", (ingresos - costos));
}

// Función para editar el inventario
void editarInventario(Producto *inventario, int numProductos) {
    char nombre[50];
    int cantidad;
    float precio;

    printf("\nNombre del producto a editar: ");
    scanf("%s", nombre);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombre, inventario[i].nombre) == 0) {
            printf("Nueva cantidad: ");
            scanf("%d", &cantidad);
            printf("Nuevo precio: ");
            scanf("%f", &precio);
            inventario[i].cantidad = cantidad;
            inventario[i].precio = precio;
            printf("\nProducto editado con éxito.\n");
            return;
        }
    }
    printf("\nProducto no encontrado.\n");
}

int main() {
    int opcion;
    int numProductos = 3;

    Producto inventario[3] = {
        {"Producto A", 10, 10.0},
        {"Producto B", 5, 20.0},
        {"Producto C", 3, 30.0}
    };

    do {
        printf("\n===== Menú Principal =====\n");
        printf("1. Ver inventario\n");
        printf("2. Realizar venta\n");
        printf("3. Ver balance financiero\n");
        printf("4. Editar inventario\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            imprimirInventario(inventario, numProductos);
            break;
        case 2:
            realizarVenta(inventario, numProductos);
            break;
        case 3:
            imprimirBalance(inventario, numProductos);
            break;
        case 4:
            editarInventario(inventario, numProductos);
            break;
        case 5:
            printf("\nHasta pronto!\n");
            break;
        default:
            printf("\nOpción inválida. Por favor seleccione una opción del menú.\n");
            break;
        }
    } while (opcion != 5);

    return 0;
    }

    