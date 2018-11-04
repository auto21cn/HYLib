
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"永恒的沙漠"NOR);
	set("long", YEL @LONG
  由于火元素的影响，这附近全是砂漠，这是一片一望
无际的大沙漠。你一进来就迷失了方向。看来要走出这
块沙漠并非易事。
LONG NOR);
set("magicroom",1);
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong35",
                "north" : __DIR__"dong37",
		"west" : __DIR__"dong32",
                "east" : __DIR__"dong39",

	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong39",
                "north" : __DIR__"dong32",
		"west" : __DIR__"dong34",
                "east" : __DIR__"dong33",
	]));
         set("objects", ([
              __DIR__"npc/lev1" : random(4),
              __DIR__"npc/lev3" : 2,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

