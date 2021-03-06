# Arduino-記分板

可自定義得勝點，含Deuce功能

>使用Arduino Mega2560執行專案

## 裝置使用實錄

| 釋例 | 說明 |
| ---- | ---- |
| <img src="img/hola.jpg" width="40%"/> | 開機用[HOLA]表示已準備就緒! |
| <img src="img/point.jpg" width="40%"/> | 使用右側加分鈕及扣分鈕設定得勝點 **P代表Point呦!** |
| <img src="img/count.jpg" width="40%"/> | 按下確認鍵開始計分! |
| <img src="img/10v10.gif" width="40%"/> | 10比10 進入Deuce決鬥!! (Deuce指示燈亮起) |
| <img src="img/thepoint.jpg" width="40%"/> | 戰到20比21...? 太刺激了 |
| <img src="img/win.gif" width="40%"/> | 客隊獲勝~ 用閃爍的點來表示贏家 |

# 製作

### 材料
| 名稱 | 數量 |
| ---- | ---- |
| 麵包板 | 1 |
| 雙位數七段顯示器 | 2 |
| 杜邦線 | 40 |
| Led | 1 |
| 按鈕 | 5 |
| 220Ω電阻 | 33 |
| 4.7KΩ電阻 | 5 |
| 單芯線 | 1 |

| 圖例 | 說明 |
| ---- | ---- |
| ![seg7](img/seg7.png) | 雙位數七段顯示器腳位 |

## 設定

### 腳位設置
```c++
const byte button[]={13,12,11,10,9}; //按鈕順序由左至右
const byte seg_L[]={22,24,26,28,30,32,34,36,23,25,27,29,31,33,35,37}; //左側顯示器 22~36為十位數 23~37為個位數 [A~DP1]
const byte seg_R[]={38,40,42,44,46,48,50,52,39,41,43,45,47,49,51,53}; //右側顯示器 38~52為十位數 39~53為個位數 [a~DP2]
#define deuceled  21 //Deuce狀態指示燈
```

### 硬體接線

| 釋例 | 說明 |
| ---- | ---- |
| <img src="img/segpin.jpg" width="40%"/> | Segpin |
| <img src="img/buttonpin.jpg" width="40%"/> | Buttonpin |
| <img src="img/deuceled.jpg" width="40%"/> | Deuceled |
| <img src="img/button.jpg" width="40%"/> | Button |

**各隊下方按鈕，左側加分，右側扣分。正中間按鈕為確認鍵**  

<img src="https://github.com/CuteUSB/Arduino-Scoreboard/blob/main/img/fritzing.png?raw=true" alt="Cover" width="40%"/>

## 貢獻
**Step 1.** 您可以將此專案Fork至本地，您有權對本地專案進行修改/增加/上傳/刪除檔案或任何內容，您可更改所有資訊。
**Step 2.** 當您認為您的本地專案可以為社群做一份貢獻，您可以考慮提交PR(Pull Requests)至源倉庫，我們會進行審核。