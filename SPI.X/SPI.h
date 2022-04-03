/* 
 * File:   SPI.h
 * Author: ahmed
 *
 * Created on March 1, 2022, 3:17 PM
 */

#ifndef SPI_H
#define	SPI_H
#define _spi_pre_4          0x00
#define _spi_pre_16         0x01
#define _spi_pre_64         0x02
#define _spi_pre_128        0x03
#define MOSI    5
#define SS      4
#define MISO    6
#define SCK     7

void spi_clk(char clk);
void spi_mode();
void spi_enable();
void init_spi(char clk);
void SPI_send(char data);
void SPI_SEND_STR(char str[]);
void SPI_SEND_NUM(int num);




#endif	/* SPI_H */

