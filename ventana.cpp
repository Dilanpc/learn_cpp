#include <windows.h>


LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);


wchar_t NombreClase[] = L"MiVentana";

HWND ventanaPrincipal;

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
    WNDCLASSEX estiloVentana;

    estiloVentana.cbSize = sizeof(WNDCLASSEX);
    estiloVentana.style = CS_DBLCLKS;
    estiloVentana.lpfnWndProc = WindowProcedure;
    estiloVentana.cbClsExtra = 0;
    estiloVentana.cbWndExtra = 0;
    estiloVentana.hInstance = hThisInstance;
    estiloVentana.lpszClassName = NombreClase;
    estiloVentana.lpszClassName = reinterpret_cast<LPCWSTR>(NombreClase);
    estiloVentana.lpszMenuName = NULL;
    estiloVentana.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    // Registrar la clase de la ventana
    if (!RegisterClassEx(&estiloVentana))
        return 0;

    // Crear la ventana a partir de la clase anterior
    ventanaPrincipal = CreateWindowExW(
        0, reinterpret_cast<LPCWSTR>(NombreClase), L"Mi Ventana", WS_OVERLAPPEDWINDOW,
        100, 100, 640, 480, HWND_DESKTOP, NULL, hThisInstance, NULL
    );

    // Hacer que la ventana sea visible
    ShowWindow(ventanaPrincipal, nCmdShow);

    // Bucle de mensajes
    MSG mensaje;
    while (GetMessage(&mensaje, NULL, 0, 0)) {
        TranslateMessage(&mensaje);
        DispatchMessage(&mensaje);
    }

    return mensaje.wParam;
}

// eventos
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
