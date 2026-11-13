#ifndef _CONFIG_H
#define _CONFIG_H

#include <esp_system.h>
#include <esp_wifi.h>

/* WIFI CONFIGURATION */
#define DEFAULT_WIFI_SSID           "MagicWifi"
#define DEFAULT_WIFI_PASS           "MagicWifi1234"
#define DEFAULT_WIFI_MAX_CONN       5
#define DEFAULT_WIFI_CHAN           1
#define DEFAULT_WIFI_AUTH           WIFI_AUTH_WPA_WPA2_PSK
#define DEFAULT_WIFI_TX_RATE        WIFI_PHY_RATE_9M


/**
 * @brief Save string value to flash
 * 
 * @param key 
 * @param value 
 */
void save_string_to_nvs(const char* key, const char* value);


/**
 * @brief Read string value from flash
 * 
 * @param key 
 */
esp_err_t read_string_from_nvs(const char* key, char* value);


/**
 * @brief Save int32 to flash
 * 
 * @param key 
 * @param value 
 */
void save_int_to_nvs(const char* key, int32_t value);


/**
 * @brief Read int32_ from Flash
 * 
 * @param key 
 * @param value 
 * @return esp_err_t 
 */
esp_err_t read_int_from_nvs(const char* key, int32_t *value);


/**
 * @brief Save a hidden SSID mapping (BSSID -> SSID) to NVS
 * 
 * @param bssid 6-byte BSSID
 * @param ssid The resolved SSID
 */
void save_hidden_ssid_mapping(const uint8_t *bssid, const char *ssid);


/**
 * @brief Load a hidden SSID mapping from NVS
 * 
 * @param bssid 6-byte BSSID
 * @param ssid Buffer to receive the SSID (must be at least 33 bytes)
 * @return esp_err_t ESP_OK if found, ESP_FAIL if not
 */
esp_err_t load_hidden_ssid_mapping(const uint8_t *bssid, char *ssid);


#endif
