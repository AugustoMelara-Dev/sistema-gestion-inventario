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

// Función auxiliar
int existe_codigo(int cod) {
    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == cod) return 1;
    }
    return 0;
}

// Gestión de Productos (CRUD) 
int agregar_producto() {
    if (totalProductos >= 100) {
        printf("Inventario lleno (Max 100).\n");
        return 0;
    }

    int tempCodigo;
    printf("\n--- AGREGAR PRODUCTO ---\n");
    printf("Ingrese Codigo: ");
    if (scanf("%d", &tempCodigo) != 1) {
        while(getchar() != '\n');
        return 0;
    }

    if (existe_codigo(tempCodigo) == 1) {
        printf("Error: El codigo %d ya existe.\n", tempCodigo);
        return 0;
    }

    inventario[totalProductos].codigo = tempCodigo;

    printf("Ingrese Nombre: ");
    scanf(" %49[^\n]", inventario[totalProductos].nombre);

    for(int i = 0; inventario[totalProductos].nombre[i] != '\0'; i++) {
        if(inventario[totalProductos].nombre[i] == ',') {
            inventario[totalProductos].nombre[i] = ' '; 
        }
    }

    if (strlen(inventario[totalProductos].nombre) == 0) return 0;

    printf("Ingrese Cantidad: ");
    if (scanf("%d", &inventario[totalProductos].cantidad) != 1) {
        while(getchar() != '\n');
        return 0;
    }
    if (inventario[totalProductos].cantidad < 0) return 0;

    printf("Ingrese Precio: ");
    if (scanf("%f", &inventario[totalProductos].precio) != 1) {
        while(getchar() != '\n');
        return 0;
    }
    if (inventario[totalProductos].precio <= 0) return 0;

    inventario[totalProductos].total = inventario[totalProductos].cantidad * inventario[totalProductos].precio;

    totalProductos++;
    return 1;
}

int modificar_producto() {
    int cod, indice = -1;
    printf("\n--- MODIFICAR PRODUCTO ---\n");
    printf("Ingrese codigo: ");
    if (scanf("%d", &cod) != 1) {
        while(getchar() != '\n');
        return 0;
    }

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == cod) {
            indice = i;
            break;
        }
    }

    if (indice == -1) return 0; 

    printf("Producto: %s | Cantidad: %d | Precio: %.2f | Total: %.2f\n", 
           inventario[indice].nombre, inventario[indice].cantidad, 
           inventario[indice].precio, inventario[indice].total);

    int opcionMod;
    printf("Modificar: 1.Nombre 2.Cantidad 3.Precio: ");
    if (scanf("%d", &opcionMod) != 1) {
        while(getchar() != '\n');
        return 0;
    }

    switch(opcionMod) {
        case 1:
            printf("Nuevo Nombre: ");
            scanf(" %49[^\n]", inventario[indice].nombre);
            for(int i = 0; inventario[indice].nombre[i] != '\0'; i++) {
                if(inventario[indice].nombre[i] == ',') inventario[indice].nombre[i] = ' '; 
            }
            break;

        case 2:
            {
                int nuevaCant;
                printf("Nueva Cantidad: ");
                if (scanf("%d", &nuevaCant) == 1 && nuevaCant >= 0) {
                    inventario[indice].cantidad = nuevaCant;
                    inventario[indice].total = inventario[indice].cantidad * inventario[indice].precio;
                } else {
                    printf("Entrada invalida. Cancelando cambio.\n");
                    while(getchar() != '\n');
                }
            }
            break;

        case 3:
            {
                float nuevoPrecio;
                printf("Nuevo Precio: ");
                if (scanf("%f", &nuevoPrecio) == 1 && nuevoPrecio > 0) {
                    inventario[indice].precio = nuevoPrecio;
                    inventario[indice].total = inventario[indice].cantidad * inventario[indice].precio;
                } else {
                    printf("Precio invalido. Cancelando cambio.\n");
                    while(getchar() != '\n');
                }
            }
            break;
            
        default:
            return 0; 
    }
    return 1;
}