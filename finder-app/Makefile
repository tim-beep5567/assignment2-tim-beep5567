# 1. 定義編譯器：如果外面沒傳變數，預設用 gcc
CROSS_COMPILE ?= 
CC = $(CROSS_COMPILE)gcc
CFLAGS = -g -Wall

# 2. 預設目標
all: writer

# 3. 編譯邏輯
writer: writer.o
	$(CC) $(CFLAGS) -o writer writer.o

writer.o: writer.c
	$(CC) $(CFLAGS) -c writer.c

# 4. 清理邏輯（刪除編譯產物和測試檔）
clean:
	rm -f writer *.o