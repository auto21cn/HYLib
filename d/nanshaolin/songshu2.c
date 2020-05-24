// Room: /d/nanshaolin/songshu2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "松树林");
	set("long", @LONG
这是一片松树林。高高的大松树簇在一块，密实的枝叶象一蓬蓬巨
伞般伸向天空，把阳光遮得丝毫也无。一条洁净的青石小径蜿蜒林中。
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"east"  : __DIR__ "lunhuisuo",
		"west"  : __DIR__ "stoneroad1",
		"north" : __DIR__ "songshu1",
		"south" : __DIR__ "songshu3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



