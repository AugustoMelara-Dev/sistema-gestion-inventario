# 📦 Sistema de Gestión de Inventario en C

## 📖 Descripción
Sistema profesional de gestión de inventario desarrollado en lenguaje C. Este proyecto implementa una solución robusta para el control de stock, integrando operaciones CRUD, reportes financieros, alertas de existencias y persistencia de datos en archivos planos (CSV).

El sistema ha sido diseñado con un enfoque en la **integridad de datos** y la **seguridad operativa**, implementando validaciones estrictas contra errores de usuario y vulnerabilidades de memoria.

## ✨ Características Principales

### 🛠️ Gestión de Productos (CRUD)
- **Agregar:** Registro de nuevos productos con validación de unicidad por código.
- **Modificar:** Edición flexible de nombre, cantidad o precio, con actualización automática del valor total.
- **Mostrar:** Visualización tabular alineada de todo el inventario.
- **Buscar:** Localización inmediata de productos mediante código único.

### 📊 Reportes y Estadísticas
- **Alerta de Stock Bajo:** Filtra automáticamente productos con menos de 10 unidades.
- **Valoración Financiera:** Cálculo en tiempo real del valor total del inventario (Dinero invertido).
- **Métricas:** Conteo de productos únicos y stock físico total.

### 💾 Persistencia de Datos
- **Base de Datos CSV:** Los datos se guardan en `inventario.txt` separados por comas.
- **Auto-Guardado:** El sistema guarda los cambios automáticamente al cerrar.
- **Auto-Recuperación:** Carga inteligente de datos al iniciar el programa; si el archivo no existe, inicia limpio sin errores.
- **Sanitización:** Reemplazo automático de comas por espacios en los nombres para proteger la estructura del archivo.

## 🔒 Seguridad y Robustez (DevOps Audit)
Este código cumple con estándares altos de programación defensiva:
- ✅ **Protección Buffer Overflow:** Uso de `scanf(" %49[^\n]")` para limitar la lectura de cadenas.
- ✅ **Validación de Tipos:** Verificación del retorno de `scanf` para evitar bucles infinitos si se ingresan letras en lugar de números.
- ✅ **Limpieza de Buffer:** Implementación de `while(getchar() != '\n')` para sanear la entrada estándar.
- ✅ **Integridad Estructural:** El campo `total` se recalcula dinámicamente para asegurar consistencia matemática.

## 📋 Requisitos Técnicos
- **Lenguaje:** C (Estándar C99 o superior).
- **Compilador:** GCC (Recomendado) o compatible.
- **Sistema Operativo:** Windows (Requerido para el funcionamiento estético de `cls` y `pause`).

## 🚀 Instrucciones de Instalación

1.  **Clonar el repositorio:**
    ```bash
    git clone [https://github.com/TU_USUARIO/sistema-gestion-inventario.git](https://github.com/TU_USUARIO/sistema-gestion-inventario.git)
    ```

2.  **Compilar el código fuente:**
    Abre tu terminal en la carpeta del proyecto y ejecuta:
    ```bash
    gcc -o inventario main.c -std=c99 -Wall
    ```

3.  **Ejecutar la aplicación:**
    ```bash
    inventario.exe
    ```

## 📂 Estructura del Proyecto

```text
sistema-gestion-inventario/
├── main.c              # Código fuente (Lógica completa)
├── inventario.txt      # Archivo de persistencia (Generado automáticamente)
├── .gitignore          # Configuración de exclusiones de Git
└── README.md           # Documentación del proyecto
```
## 👨‍💻 Autor
**Augusto José Melara Milla**
*Estudiante de Ingeniería en Ciencias de la Computación*
*Universidad Católica de Honduras (UNICAH)*

📅 **Fecha de Finalización:** 10 de Diciembre, 2025

## 📄 Licencia
Este proyecto es de uso académico y educativo.