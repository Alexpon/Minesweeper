Minesweeper

Author：Alexpon

Environment：Ubuntu 14.10

How to execute：  make
                  ./project1.exe

Demand：
*Develop an nondeterministic and interactive game
*Include at least two classes(First, Time)
*Display time (in seconds) on screen
*At least 3 levels of difficulty
*Output the map when the game is over(Mine.txt)


程式解說：
我的程式有兩個class，第一個為First，這是用來製作踩地雷地圖的物件，傳一個選擇難度的值進入First裡的SelectLevel函式，此函式會再將值傳給同物件裡的SetMap函式，做出地圖，並存在boomMap這個array中。另一個class為Time，這個物件是用來計算時間的，main function可藉由call Time物件裡的get function 取得時間，並顯示在遊戲畫面中。在main function裡，大多是ncurses的指令，其中有兩個判斷勝敗的條件式，假如按下Tab開啟地圖時，那一格為炸彈，lose=1會使輸的條件成立，會以紅底黑字印出所有炸彈，再按下任意鍵即會結束遊戲，假如剩餘格數加上插旗數等於炸彈數，即會使勝利條件成立，並印出勝利圖示。



UML：


First

──────────────────────────────────

-sizeRow:int

-sizeCol:int

-boomNum:int

-i:int

-j:int

-count:int

-BoomRow:int

-BoomCol:int

-boomMap[100][100]:char

-num:char

────────────────────────────────── 

+First()

+SelectLevel(choose:int):void

+SetMap(col:int, row:int, boom:int):void

+get(y:int, x:int):char



Time

──────────────────────────────────

-start:int

-now:int

-hour:int

-minute:int

-second:int

──────────────────────────────────

+InitialTime():void

+NowTime():void

+Calculate():void

+getHour():int

+getMinute():int

+getSecond():int
