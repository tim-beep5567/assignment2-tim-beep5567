#!/bin/sh

filesdir=$1
searchstr=$2

# 檢查參數是否都有填
if [ -z "$filesdir" ] || [ -z "$searchstr" ]; then
    echo "錯誤：請提供目錄路徑和搜尋字串。"
    exit 1
fi

# 檢查路徑是否存在且為目錄
if [ ! -d "$filesdir" ]; then
    echo "錯誤：$filesdir 不是一個有效的目錄。"
    exit 1
fi

# 計算檔案數量 (X)
X=$(find "$filesdir" -type f | wc -l)

# 計算符合字串的行數 (Y)
Y=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "The number of files are $X and the number of matching lines are $Y"