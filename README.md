## 需要掌握的Qt类

+ QPainter：用来绘制图形
+ QPainterPath：控制Painter绘制的路径
+ QRegion：控制图像刷新的范围

+ QGraphicsObject
+ QGraphicsView
+ QGraphicsScene
+ QGraphicsPixmapItem
 
ArchiveManager类负责储存世界的名称，Id，并维护一个worldList，用以记录可用的世界
 World类，实现：
 World(int worldId);
createWorld();
loadWorld();
updateWorld();
deleteWorld();

提供World类一个Id，可以创建，加载，更新，删除世界存档
ArchiveManager类从文件中读取现有的世界的ID和名称
## Introduction and Objective
1. 该游戏为类似于我的世界（Minecraft）的一款2D沙盒游戏
2. 游戏支持由给定的地图种子创建唯一确定的地图
3. 玩家拥有物品栏，可以更换装备
4. 玩家可以通过破坏地图中的方块对方块进行收集
5. 玩家可以使用收集到的方块对地图进行自定义的改造，并可以用来合成设备与装备
6. 玩家的进度可以保存
7. 游戏中存在敌对生物与中立生物，敌对生物主要包括骷髅射手（远程进攻），僵尸（近战）以及爬行者（靠近玩家然后爆炸）；中立生物主要包括牛（提供皮革可以用来合成护甲，提供肉作为食物），羊（提供肉类），鸡（提供羽毛可以用来合成箭矢，提供肉类）。
8. 玩家可以建造工具台，用来合成各种工具。
9. 玩家可以建造箱子用来储存物品。
## Requirements and Functionality
1. Game类：
   1. 渲染地图
   2. 程序主循环
2. Map类：
   1. 创建地图
   2. 更新地图
   3. 保存地图
3. Player类：
   1. 记录，存储与加载player的各项属性
   2. 处理键盘输入（action函数）
4. Animal类：
   1. 记录animal的各项属性
   2. 控制生物活动（action函数）
## Logic Flow 
1. 由种子产生地图或者加载之前以及储存的地图
2. 游戏主循环：
   1. 处理键盘输入，控制玩家与环境交互
   2. 控制NPC活动，对玩家活动做出反应
   3. 渲染更新后的地图以及玩家状态
3. 保存玩家状态以及更新后的地图
## Relation between Data Structure
1. 由一个给定的地图种子（seed）创建一个合理的1000*1000的地图
2. 地图的更新与储存
3. 敌对生物的寻路算法
## Plan and Schedule
1. 大家一起确定主题以及程序架构
2. ？？同学负责中期报告
3. ？？？同学负责最终报告
4. ？？？同学负责展示
5. ？？？同学负责程序的编写







______________________________________________________________________________________________________________________


## 总流程
第一步，确定开发此游戏需要的Qt类与函数
第二步，梳理此程序的逻辑流

## 第一步
QSettings
QGraphicsObject
QGraphicsView
QGraphicsPixmapItem
QPainter
QPainterPath
QRectF
QPixmaps
QObject
QVariant
QGraphicsScene

## 第二步
### 类
#### Setting
管理程序设置
+ loadSetting()
+ updateSetting()

#### Launcher
游戏启动器，提供开始游戏，管理存档（创建，修改，删除，复制），进行设置的功能
+ startGame()
+ createMap()
+ 
 ```C++
 const unsigned int MAP_LEGTH_SIZE = 1000;
const unsigned int MAP_HEIGHT_SIZE = 1000;
const unsigned int WINDOW_SIZE = 100;
const unsigned int WINDOW_SIZE = 100;
const unsigned int PLAYER_MAX_ARTICLE_NUMBER = 10;

struct Point
{
    int x;
    int y;
}

struct Position
{
    float x;
    float y;
};

class Game : public QWidget
{
public:
    virtual void paintEvent(QPaintEvent *event);
    virtual void timerEvent(QTimerEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    void startGame();

private:
    Map map;
    Player player;
    Animal[] animals; 
}

class Map
{
public:
    bool generateMap(int seed);
    bool loadMap();
    bool saveMap();
    unsigned int* window(Point center);
    bool updateMap(unsigned int*);
private:
    Point lastWindowCenter;
    int map[MAP_HEIGHT_SIZE][MAP_LENGTH_SIZE];
}

class Player
{
public:
    Position position;
    Image image;
    unsigned int blood;
    unsigned int level;
    unsigned int armor;
    unsigned int attackPower;
    float speed;
    int facing;
    unsigned int articles[PLAYER_MAX_ARTICLE_NUMBER];
    bool loadPLayerState();
    bool savePlayerState();
    bool action(QKeyEvent *event, unsigned int *playerAround);
}

class Animal
{
public:
    Position position;
    Image image;
    unsigned int blood;
    unsigned int armor;
    float speed;
    int facing;
    bool action();
}
```