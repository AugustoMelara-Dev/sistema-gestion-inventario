# 📦 Sistema de Gestión de Inventario en C

## 📖 Descripción
Sistema completo de gestión de inventario desarrollado en C con persistencia de datos en archivos CSV.

## ✨ Características
- ✅ Agregar productos con validación de códigos únicos
- ✅ Modificar productos existentes (nombre, cantidad, precio)
- ✅ Búsqueda por código
- ✅ Reportes de stock bajo (<10 unidades)
- ✅ Estadísticas generales del inventario
- ✅ Persistencia en archivo `inventario.txt` (formato CSV)
- ✅ Validaciones robustas contra buffer overflow

## 🛠️ Tecnologías
- Lenguaje: C (estándar C99)
- Compilador: GCC
- Sistema Operativo: Windows

## 📋 Requisitos
- Compilador GCC instalado
- Sistema operativo Windows (por uso de `system("cls")` y `system("pause")`)

## 🚀 Compilación y Ejecución

### Compilar:
```bash
gcc -o inventario main.c -std=c99 -Wall
Ejecutar:
bash
Copy
inventario.exe
📂 Estructura del Proyecto
sistema-gestion-inventario/
├── main.c              # Código fuente principal
├── inventario.txt      # Archivo de datos (generado automáticamente)
└── README.md           # Documentación
🎯 Funcionalidades Implementadas
1. Menú Principal Interactivo
Validación de entrada con manejo de errores
Ciclo infinito con salida controlada
2. Gestión CRUD
Agregar: Validación de código único, nombre no vacío, cantidad ≥ 0, precio > 0
Modificar: Búsqueda por código, edición de campos específicos
Mostrar: Tabla formateada con todos los productos
3. Búsqueda y Reportes
Búsqueda lineal por código
Reporte de productos con stock bajo (<10)
Estadísticas: total productos, stock físico, valor total
4. Persistencia de Datos
Guardado automático al salir
Carga automática al iniciar
Formato CSV con sanitización de comas
🔒 Seguridad Implementada
✅ Protección contra buffer overflow (scanf limitado a 49 caracteres)
✅ Validación de retorno de scanf para evitar bucles infinitos
✅ Limpieza de buffer con while(getchar() != '\n')
✅ Sanitización de datos (eliminación de comas en nombres)
✅ Bounds checking (límite de 100 productos)
👨‍💻 Autor
Augusto Jose Melara Milla

📅 Fecha
10/12/2025

📄 Licencia
Proyecto académico - Uso educativo