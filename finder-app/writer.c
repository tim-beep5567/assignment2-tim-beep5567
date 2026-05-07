#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // 1. 初始化 syslog
    // LOG_USER 代表一般使用者等級的訊息
    openlog("aesd-writer", LOG_PID, LOG_USER);

    // 2. 檢查參數數量是否正確
    if (argc != 3) {
        syslog(LOG_ERR, "Error: Invalid number of arguments. Expected 2, got %d", argc - 1);
        fprintf(stderr, "Usage: %s <file_path> <string_to_write>\n", argv[0]);
        closelog();
        return 1;
    }

    const char *file_path = argv[1];
    const char *text_to_write = argv[2];

    // 3. 打開檔案準備寫入 ("w" 會覆蓋原有內容)
    FILE *fp = fopen(file_path, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error opening file %s: %s", file_path, strerror(errno));
        perror("File opening failed");
        closelog();
        return 1;
    }

    // 4. 寫入內容並記錄日誌
    if (fprintf(fp, "%s", text_to_write) < 0) {
        syslog(LOG_ERR, "Error writing to file %s", file_path);
        fclose(fp);
        closelog();
        return 1;
    }

    // 作業要求：使用 LOG_DEBUG 記錄寫入動作
    syslog(LOG_DEBUG, "Writing %s to %s", text_to_write, file_path);

    // 5. 關閉資源
    fclose(fp);
    closelog();

    return 0;
}