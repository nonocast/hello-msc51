简单观察一下ISP下载程序的协议, 可以通过stcgal --debug观察, 或者通过stcgal source code分析,

```
mkdir -p build && sdcc -o build/ src/app-02.c
stcgal --debug -P stc89 -p /dev/tty.usbserial-14310 build/app-02.ihx 
Waiting for MCU, please cycle power: <- Packet data: 00
<- Packet data: 46 B9 68 00 3B 00 0A 76 0A 76 0A 76 0A 76 0A 76 0A 76 0A 72 0A 76 43 43 FD F0 02 82 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 96 16
done
Target model:
  Name: STC89C52RC/LE52R
  Magic: F002
  Code flash: 8.0 KB
  EEPROM flash: 6.0 KB
Target frequency: 11.016 MHz
Target BSL version: 4.3C
Target options:
  cpu_6t_enabled=False
  bsl_pindetect_enabled=False
  eeprom_erase_enabled=False
  clock_gain=high
  ale_enabled=True
  xram_enabled=True
  watchdog_por_enabled=False
Loading flash: 106 bytes (Intel HEX)
Switching to 19200 baud: checking -> Packet data: 46 B9 6A 00 0C 8F FF EE 00 24 A0 81 37 16
<- Packet data: 46 B9 68 00 0C 8F FF EE 00 24 A0 81 35 16
setting -> Packet data: 46 B9 6A 00 0B 8E FF EE 00 24 A0 B4 16
<- Packet data: 46 B9 68 00 0B 8E FF EE 00 24 A0 B2 16
testing -> Packet data: 46 B9 6A 00 0C 80 00 00 36 01 F0 02 1F 16
<- Packet data: 46 B9 68 00 06 80 EE 16
-> Packet data: 46 B9 6A 00 0C 80 00 00 36 01 F0 02 1F 16
<- Packet data: 46 B9 68 00 06 80 EE 16
-> Packet data: 46 B9 6A 00 0C 80 00 00 36 01 F0 02 1F 16
<- Packet data: 46 B9 68 00 06 80 EE 16
-> Packet data: 46 B9 6A 00 0C 80 00 00 36 01 F0 02 1F 16
<- Packet data: 46 B9 68 00 06 80 EE 16
done
Erasing 2 blocks: -> Packet data: 46 B9 6A 00 0D 84 02 33 33 33 33 33 33 2F 16
<- Packet data: 46 B9 68 00 06 80 EE 16
done
-> Packet data: 46 B9 6A 00 8C 00 00 00 00 00 00 80 02 00 06 02 00 62 75 81 07 12 00 66 E5 82 60 03 02 00 03 79 00 E9 44 00 60 1B 7A 00 90 00 6A 78 01 75 A0 00 E4 93 F2 A3 08 B8 00 02 05 A0 D9 F4 DA F2 75 A0 FF E4 78 FF F6 D8 FD 78 00 E8 44 00 60 0A 79 01 75 A0 00 E4 F3 09 D8 FC 78 00 E8 44 00 60 0C 79 00 90 00 01 E4 F0 A3 D8 FC D9 FA 02 00 03 C2 90 80 FE 75 82 00 22 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF F0 16
<- Packet data: 46 B9 68 00 07 80 7A 69 16
Writing flash:   0%|                                                                                                                                                                 | 0/512 [00:00<?, ? Bytes/s]-> Packet data: 46 B9 6A 00 8C 00 00 00 00 80 00 80 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF 76 16
<- Packet data: 46 B9 68 00 07 80 80 6F 16
Writing flash:  50%|██████████████████████████████████████████████████████████████████████████▌                                                                          | 256/512 [00:00<00:00, 2059.06 Bytes/s]-> Packet data: 46 B9 6A 00 8C 00 00 00 01 00 00 80 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF F7 16
<- Packet data: 46 B9 68 00 07 80 80 6F 16
Writing flash:  75%|███████████████████████████████████████████████████████████████████████████████████████████████████████████████▊                                     | 384/512 [00:00<00:00, 1582.35 Bytes/s]-> Packet data: 46 B9 6A 00 8C 00 00 00 01 80 00 80 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF 77 16
<- Packet data: 46 B9 68 00 07 80 80 6F 16
Writing flash: 640 Bytes [00:00, 1710.35 Bytes/s]                                                                                                                                                                
Setting options: -> Packet data: 46 B9 6A 00 0A 8D FD FF FF FF FB 16
<- Packet data: 46 B9 68 00 0A 8D FD FF FF FF F9 16
done
-> Packet data: 46 B9 6A 00 06 82 F2 16
Disconnected!

```

数据包格式：
包头 + 标识 + 数据包长度 + 命令 + 数据 + 校验和 + 包尾
- 包头为两个字节，0x46，0xb9
- 标识分两种，PC机发送给MCU的为0x6A，MCU回应给PC的是0x68，标识后面还有一个字节固定为0x00。
- 数据包长度为除包头外的数据包总长。
- 命令为一个字节。
- 数据可以有也可以无，最多时有100多个字节。
- 校验和为两字节，为包头之后，校验和之前所有字节相加的值。
- 包尾固定为0x16

举个例子说明：
- PC机发送：46 B9 6A 00 0D 50 05 00 36 01 E6 04 01 ED 16
- MCU回应： 46 B9 68 00 07 8F 00 FE 16
