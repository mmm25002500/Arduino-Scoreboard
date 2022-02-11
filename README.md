# Arduino-Scoreborad

可自定義得勝點，含Deuce功能

>使用Arduino Mega2560執行專案

## 裝置使用實錄
開機用[HOLA]表示已準備就緒!  
![HOLA]()

使用右側加分鈕及扣分鈕設定得勝點 P代表Point呦!  
![Point]()

按下確認鍵開始計分!  
![count]()

10比10 進入Deuce決鬥!! (Deuce指示燈亮起)  
![ten]()

戰到20比21...? 太刺激了  
![the point]()

客隊獲勝~ 用閃爍的點來表示贏家  
![winner]()


## 製作

### 材料
- 麵包板 *1
- 雙位數七段顯示器*2
- 杜邦線 *40
- Led *1
- 按鈕*5
- 330Ω電阻 *33
- 4.7KΩ電阻 *5
- 單芯線 *1

>雙位數七段顯示器腳位  
![seg7](https://github.com/CuteUSB/Arduino-Scoreboard/blob/main/img/seg7.png?raw=true)

1. 腳位設置
```c++
const byte button[]={13,12,11,10,9}; //按鈕順序由左至右
const byte seg_L[]={22,24,26,28,30,32,34,36,23,25,27,29,31,33,35,37}; //左側顯示器 22~36為百位數 23~37為個位數 [A~DP1]
const byte seg_R[]={38,40,42,44,46,48,50,52,39,41,43,45,47,49,51,53}; //右側顯示器 38~52為百位數 39~53為個位數 [a~DP2]
#define deuceled  21 //Deuce狀態指示燈
```

2.硬體接線

![segpin]()  
![buttonpin]()  
![deuceledpin]()  
![button](https://raw.githubusercontent.com/CuteUSB/Arduino-Scoreboard/main/img/PXL_20220210_052925610.jpg?token=GHSAT0AAAAAABRPACYIMIQ7SJFO3UI4B3F2YQPW6SQ)  
![fritzing]()  

3.寫入程式

4.完成~~
