// Room: /d/gaochang/shijie9.c

inherit ROOM;




void create()
{
	set("short", "石阶");
	set("long", @LONG
眼前遽然出现一大片松林。松林长得极密，石阶上铺满了厚
厚的朽黄的松针。踩在脚下，发出察察的响声。一只小松鼠吱地
在眼前闪过，消失在林海里。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"shijie2",
		"northup" : __DIR__"entrance",
	]));

	set("outdoors", "gaochang");
	setup();
	replace_program(ROOM);
}



