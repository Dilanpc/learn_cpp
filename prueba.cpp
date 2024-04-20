#include <windows.h>

/* Declaración del procedimiento de ventana */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

/* Nombre de la clase para los estilos de ventana */
char NombreClase[] = "MiVentana";

HWND ventanaPrincipal; /* Manejador de la ventana */

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
    WNDCLASSEX estiloVentana;

    estiloVentana.hInstance = hThisInstance;
    estiloVentana.lpszClassName = NombreClase;
    estiloVentana.lpfnWndProc = WindowProcedure;
    estiloVentana.style = CS_DBLCLKS;
    estiloVentana.cbSize = sizeof(WNDCLASSEX);
    estiloVentana.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    estiloVentana.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    estiloVentana.hCursor = LoadCursor(NULL, IDC_ARROW);
    estiloVentana.lpszMenuName = NULL; /* Sin menú */
    estiloVentana.cbClsExtra = 0;
    estiloVentana.cbWndExtra = 0;
    estiloVentana.hbrBackground = (HBRUSH)COLOR_WINDOW; /* Color de fondo de la ventana */

    /* Registramos la clase de la ventana */
    if (!RegisterClassEx(&estiloVentana))
        return 0;

    /* Creamos la ventana a partir de la clase anterior */
    ventanaPrincipal = CreateWindowEx(
        0, NombreClase, "Mi Ventana", WS_OVERLAPPEDWINDOW,
        100, 100, 640, 480, HWND_DESKTOP, NULL, hThisInstance, NULL
    );

    /* Hacemos que la ventana sea visible */
    ShowWindow(ventanaPrincipal, nCmdShow);

    /* Bucle de mensajes */
    MSG mensaje;
    while (GetMessage(&mensaje, NULL, 0, 0)) {
        TranslateMessage(&mensaje);
        DispatchMessage(&mensaje);
    }

    return mensaje.wParam;
}

/* Procedimiento de ventana */
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT mensaje, WPARAM wParam, LPARAM lParam) {
    switch (mensaje) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, mensaje, wParam, lParam);
    }
    return 0;
}
