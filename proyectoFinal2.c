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

// Función para agregar un producto al inventario
void agregarProducto(Producto *inventario, int *numProductos) {
    Producto nuevoProducto;

    printf("\nNombre del producto a agregar: ");
    scanf("%s", nuevoProducto.nombre);
    printf("Cantidad: ");
    scanf("%d", &nuevoProducto.cantidad);
    printf("Precio: ");
    scanf("%f", &nuevoProducto.precio);

    inventario[*numProductos].nombre = nuevoProducto.nombre;
    inventario[*numProductos].cantidad = nuevoProducto.cantidad;
    inventario[*numProductos].precio = nuevoProducto.precio;
    (*numProductos)++;

printf("\nProducto agregado con éxito.\n");
}

// Función para eliminar un producto del inventario
void eliminarProducto(Producto *inventario, int *numProductos) {
char nombre[50];
printf("\nNombre del producto a eliminar: ");
scanf("%s", nombre);

for (int i = 0; i < *numProductos; i++) {
    if (strcmp(nombre, inventario[i].nombre) == 0) {
        for (int j = i; j < (*numProductos - 1); j++) {
            inventario[j] = inventario[j + 1];
        }
        (*numProductos)--;
        printf("\nProducto eliminado con éxito.\n");
        return;
    }
}
printf("\nProducto no encontrado.\n");
}

int main() {
Producto inventario[100];
int numProductos = 0;
int opcion;

while (1) {
    printf("\n1. Ver inventario\n");
    printf("2. Realizar venta\n");
    printf("3. Ver balance financiero\n");
    printf("4. Editar inventario\n");
    printf("5. Agregar producto al inventario\n");
    printf("6. Eliminar producto del inventario\n");
    printf("7. Salir\n");
    printf("Opción: ");
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
            agregarProducto(inventario, &numProductos);
            break;
        case 6:
            eliminarProducto(inventario, &numProductos);
            break;
        case 7:
            exit(0);
        default:
            printf("\nOpción inválida.\n");
    }
}

return 0;
}