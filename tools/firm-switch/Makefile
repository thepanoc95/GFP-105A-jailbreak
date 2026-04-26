CC := gcc
CFLAGS := -lusb-1.0 -I/usr/include/libusb-1.0
TARGET := mtkflash

all:
	$(CC) main.c $(CFLAGS) -o $(TARGET)

clean:
	rm -rf $(TARGET)