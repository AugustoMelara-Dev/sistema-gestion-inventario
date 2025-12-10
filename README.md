# 📦 Sistema de Gestión de Inventario en C

## 📖 Descripción
Sistema completo de gestión de inventario desarrollado en lenguaje C. Este proyecto implementa una solución robusta para el manejo de productos, incluyendo operaciones CRUD (Crear, Leer, Actualizar, Borrar), reportes estadísticos y persistencia de datos mediante archivos planos (CSV).

## ✨ Características Principales
- ✅ **Gestión de Productos:** Agregar ítems con validación de códigos únicos.
- ✅ **Modificación Flexible:** Edición de nombre, cantidad o precio de productos existentes.
- ✅ **Búsqueda Rápida:** Algoritmo de búsqueda lineal por código.
- ✅ **Alertas de Stock:** Reporte automático de productos con bajas existencias (<10 unidades).
- ✅ **Estadísticas:** Cálculo automático de stock físico total y valoración monetaria del inventario.
- ✅ **Persistencia:** Guardado y carga automática en `inventario.txt` (formato CSV).
- ✅ **Integridad de Datos:** Campo `total` calculado y sincronizado automáticamente en la estructura.

## 🛠️ Tecnologías Utilizadas
- **Lenguaje:** C (Estándar C99)
- **Compilador:** GCC
- **IDE Recomendado:** VS Code / Dev-C++
- **Sistema Operativo:** Windows (Optimizado para consola de Windows)

## 📋 Requisitos del Sistema
- Compilador GCC instalado y configurado en el PATH.
- Sistema Operativo Windows (necesario para el funcionamiento estético de `system("cls")` y `system("pause")`).

## 🚀 Instrucciones de Compilación y Ejecución

Para compilar y ejecutar el proyecto, abre tu terminal en la carpeta del proyecto y ejecuta los siguientes comandos:

### 1. Compilar
```bash
gcc -o inventario main.c -std=c99 -Wall
2. Ejecutar
Bash

inventario.exe
📂 Estructura del Proyecto
Plaintext

sistema-gestion-inventario/
├── main.c              # Código fuente principal (Lógica del sistema)
├── inventario.txt      # Base de datos en texto plano (Generado automáticamente)
├── .gitignore          # Archivos ignorados por Git
└── README.md           # Documentación del proyecto
🎯 Funcionalidades Detalladas
1. Menú Interactivo
Interfaz de consola limpia con limpieza de pantalla.

Validación de entradas numéricas para evitar errores de ejecución.

Ciclo infinito con salida controlada por el usuario.

2. Gestión CRUD
Agregar: Valida que el código no exista, que el nombre no esté vacío y que los valores numéricos sean positivos.

Modificar: Permite buscar un producto y editar campos específicos sin perder la información previa.

Mostrar: Despliega una tabla alineada con todos los productos cargados en memoria.

3. Reportes y Búsqueda
Búsqueda: Localiza productos por su código único.

Stock Bajo: Filtra y muestra solo los productos con menos de 10 unidades.

Estadísticas: Muestra la cantidad de productos únicos, el total de artículos y el valor total del inventario ($).

4. Persistencia (Archivos)
Auto-Guardado: Los datos se guardan automáticamente al seleccionar la opción "Salir".

Auto-Carga: Si existe inventario.txt, el sistema lo carga al iniciar.

Formato CSV: Los datos se separan por comas. El sistema sanitiza los nombres (cambiando comas por espacios) para proteger la estructura del archivo.

🔒 Seguridad y Robustez
Este proyecto implementa prácticas de programación defensiva:

🛡️ Protección contra Buffer Overflow: Uso de scanf(" %49[^\n]") para limitar la entrada de cadenas.

🛡️ Validación de Tipos: Verificación del retorno de scanf para evitar bucles infinitos si se ingresan letras en lugar de números.

🛡️ Limpieza de Buffer: Implementación de while(getchar() != '\n') para sanear la entrada estándar.

🛡️ Límites de Array: Verificación de límites (totalProductos < 100) antes de agregar nuevos registros.

👨‍💻 Autor
Augusto José Melara Milla Estudiante de Ingeniería en Ciencias de la Computación

📅 Fecha: 10/12/2025

📄 Licencia
Este proyecto es de uso académico y educativo.