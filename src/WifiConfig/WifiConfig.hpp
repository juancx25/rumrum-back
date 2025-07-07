/**
 * @file WifiConfig.hpp
 * @brief Definición de la clase WifiConfig.
 */

#ifndef WIFI_CONFIG
#define WIFI_CONFIG

/**
 * @class WifiConfig
 * @brief Clase que representa la configuración de la red WiFi.
 */
class WifiConfig
{
public:
    const char *SSID;       ///< Nombre de la red WiFi.
    const char *contrasena; ///< Contraseña de la red WiFi.

    /**
     * @brief Constructor de la clase WifiConfig.
     * @param SSID Nombre de la red WiFi.
     * @param contrasena Contraseña de la red WiFi.
     */
    WifiConfig(const char *SSID, const char *contrasena);
};

#endif
