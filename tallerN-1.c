#include <stdio.h>
#include <string.h>
 
typedef struct {
    int id;
    char nombre[50];
    int stock;
    float precio;
    float ganancias;
} Producto;
 
void registrarProducto(Producto *p) {
    printf("Ingrese el ID del producto: ");
    scanf("%d", &p->id);
    getchar(); // limpiar buffer
 
    printf("Ingrese el nombre del producto: ");
    fgets(p->nombre, sizeof(p->nombre), stdin);
    p->nombre[strcspn(p->nombre, "\n")] = '\0'; // quitar salto de línea
 
    printf("Ingrese la cantidad en stock: ");
    scanf("%d", &p->stock);
 
    printf("Ingrese el precio unitario: ");
    scanf("%f", &p->precio);
 
    p->ganancias = 0.0;
    printf("\nProducto registrado correctamente.\n\n");
}
 
void venderProducto(Producto *p) {
    int cantidad;
    printf("Ingrese la cantidad a vender: ");
    scanf("%d", &cantidad);
 
    if (cantidad <= 0) {
        printf("Cantidad no válida.\n");
    } else if (cantidad > p->stock) {
        printf("Stock insuficiente. Solo hay %d unidades disponibles.\n", p->stock);
    } else {
        p->stock -= cantidad;
        float venta = cantidad * p->precio;
        p->ganancias += venta;
        printf("Venta realizada con éxito. Ganancia: $%.2f\n", venta);
    }
}
 
void reabastecerProducto(Producto *p) {
    int cantidad;
    printf("Ingrese la cantidad a agregar al stock: ");
    scanf("%d", &cantidad);
 
    if (cantidad > 0) {
        p->stock += cantidad;
        printf("Reabastecimiento exitoso. Nuevo stock: %d\n", p->stock);
    } else {
        printf("Cantidad no válida.\n");
    }
}
 
void consultarProducto(Producto p) {
    printf("\n--- Información del Producto ---\n");
    printf("ID: %d\n", p.id);
    printf("Nombre: %s\n", p.nombre);
    printf("Stock: %d\n", p.stock);
    printf("Precio unitario: $%.2f\n", p.precio);
    printf("Ganancias acumuladas: $%.2f\n\n", p.ganancias);
}
 
int main() {
    Producto producto;
    int opcion;
    int registrado = 0;
 
    do {
        printf("\n===== MENU =====\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Consultar información\n");
        printf("5. Mostrar ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
 
        switch (opcion) {
            case 1:
                registrarProducto(&producto);
                registrado = 1;
                break;
            case 2:
                if (registrado) venderProducto(&producto);
                else printf("Primero debe registrar el producto.\n");
                break;
            case 3:
                if (registrado) reabastecerProducto(&producto);
                else printf("Primero debe registrar el producto.\n");
                break;
            case 4:
                if (registrado) consultarProducto(producto);
                else printf("Primero debe registrar el producto.\n");
                break;
            case 5:
                if (registrado) printf("Ganancias acumuladas: $%.2f\n", producto.ganancias);
                else printf("Primero debe registrar el producto.\n");
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 6);
 
    return 0;
}
 