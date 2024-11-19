#ifdef _WIN32
#define EXPORT __declspec(dllimport)  // Usar dllimport en el cliente
#else
#define EXPORT
#endif

extern "C" {
    EXPORT int ingresarEntero(const char* mensaje);
    EXPORT float ingresarFlotante(const char* mensaje);
    EXPORT char ingresarLetra(const char* mensaje);
    EXPORT const char* ingresarString(const char* mensaje);
    EXPORT double ingresarDouble(const char* mensaje);
}
