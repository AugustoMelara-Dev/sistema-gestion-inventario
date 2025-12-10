#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
    int codigo;
    char nombre[50];
    int cantidad;
    float precio;
    float total; 
};

struct Producto inventario[100];
int totalProductos = 0;

int agregar_producto();
int modificar_producto();
int mostrar_todos();
int buscar_producto();
int reporte_stock_bajo();
int reporte_estadisticas();
int guardar_inventario();
int cargar_inventario();
int existe_codigo(int cod);

int main() {
    int opcion = -1;

    cargar_inventario();

    while(1) {
        system("cls"); 
        
        printf("\n----- SISTEMA DE GESTION DE INVENTARIO -----\n");
        printf("1) Agregar Producto\n");
        printf("2) Modificar Producto\n");
        printf("3) Mostrar Todos los Productos\n");
        printf("4) Buscar por Codigo\n");
        printf("5) Reporte: Stock Bajo (<10)\n");
        printf("6) Reporte: Valor Total y Estadisticas\n");
        printf("0) Salir y Guardar\n");
        printf("========================================\n");
        printf("Ingrese una opcion (0-6): ");

        if (scanf("%d", &opcion) != 1) {
            while(getchar() != '\n');
            opcion = -1;
        }

        while (opcion < 0 || opcion > 6) {
            printf("ERROR: Opcion no valida.\n");
            printf("Por favor, ingrese una opcion entre 0 y 6: ");
            if (scanf("%d", &opcion) != 1) {
                while(getchar() != '\n');
                opcion = -1;
            }
        }

        if (opcion == 0) break;

        switch(opcion) {
            case 1:
                if (agregar_producto() == 1) {
                    printf("\n>>> EXITO: Producto agregado.\n");
                } else {
                    printf("\n>>> ERROR: No se pudo agregar.\n");
                }
                system("pause");
                break;

            case 2:
                if (modificar_producto() == 1) {
                    printf("\n>>> EXITO: Producto modificado.\n");
                } else {
                    printf("\n>>> AVISO: No se realizaron cambios.\n");
                }
                system("pause");
                break;

            case 3:
                if (mostrar_todos() == 0) {
                    printf(">>> AVISO: El inventario esta vacio.\n");
                }
                system("pause");
                break;

            case 4:
                if (buscar_producto() == 0) {
                    printf("\n>>> RESULTADO: No existe ningun producto con ese codigo.\n");
                }
                system("pause");
                break;

            case 5:
                if (reporte_stock_bajo() == 0) {
                    printf("\n>>> EXCELENTE: No hay productos con stock bajo.\n");
                }
                system("pause");
                break;

            case 6:
                if (reporte_estadisticas() == 1) {
                    printf(">>> Reporte generado exitosamente.\n");
                } else {
                    printf(">>> AVISO: El inventario esta vacio.\n");
                }
                system("pause");
                break;
        }
    }

    if (guardar_inventario() == 1) {
        printf("Cambios guardados correctamente en 'inventario.txt'.\n");
    } else {
        printf("Error al guardar el archivo.\n");
    }
    
    printf("Saliendo del sistema. Hasta pronto!\n");
    return 0;
}

int existe_codigo(int cod) { return 0; }
int agregar_producto() { return 0; }
int modificar_producto() { return 0; }
int mostrar_todos() { return 0; }
int buscar_producto() { return 0; }
int reporte_stock_bajo() { return 0; }
int reporte_estadisticas() { return 0; }
int guardar_inventario() { return 0; }
int cargar_inventario() { return 0; }