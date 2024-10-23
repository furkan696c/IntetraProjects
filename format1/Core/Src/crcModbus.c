/*
 * crcModbus.c
 *
 *  Created on: Jul 17, 2024
 *      Author: FURKAN ÇALIŞKAN
 */
#include "crcModbus.h"


uint16_t CRC16_Modbus(uint8_t *data, uint16_t length) {
    uint16_t crc = 0xFFFF;
    uint16_t pos, i;

    for (pos = 0; pos < length; pos++) {
        crc ^= (uint16_t)data[pos]; // Verinin ilk byte'ı ile XOR işlemi
        for (i = 8; i != 0; i--) { // Her bit için
            if ((crc & 0x0001) != 0) { // Eğer en düşük bit (LSB) 1 ise
                crc >>= 1; // Sağ kaydırma
                crc ^= 0xA001; // Polinom ile XOR işlemi
            } else { // LSB 0 ise sadece sağ kaydırma
                crc >>= 1;
            }
        }
    }
    return crc;
}

